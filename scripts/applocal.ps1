[cmdletbinding()]
param([string]$targetBinary, [string]$installedDir, [string]$tlogFile, [string]$copiedFilesLog)

$g_searched = @{} 
$g_install_root = Split-Path $installedDir -parent
$g_is_debug = (Split-Path $g_install_root -leaf) -eq 'debug'
 
if ($copiedFilesLog)
{
    Set-Content -Path $copiedFilesLog -Value "" -Encoding UTF8
}

function computeHash([System.Security.Cryptography.HashAlgorithm]$alg, [string]$str) {
    $bytes = [System.Text.Encoding]::UTF8.GetBytes($str)
    $hash = $alg.ComputeHash($bytes)
    return [Convert]::ToBase64String($hash)
}

function getMutex([string]$targetDir) {
    try {
        $sha512Hash = [System.Security.Cryptography.SHA512]::Create()
        if ($sha512Hash) {
            $hash = (computeHash $sha512Hash $targetDir) -replace ('/' ,'-')
            $mtxName = "VcpkgAppLocalDeployBinary-" + $hash
            return New-Object System.Threading.Mutex($false, $mtxName)
        }

        return New-Object System.Threading.Mutex($false, "VcpkgAppLocalDeployBinary")
    }
    catch {
        Write-Error -Message $_ -ErrorAction Stop
    }
}
 
function deployBinary([string]$targetBinaryDir, [string]$SourceDir, [string]$targetBinaryName) {
    try {
        $mtx = getMutex($targetBinaryDir)
        if ($mtx) {
            $mtx.WaitOne() | Out-Null
        }

        $sourceBinaryFilePath = Join-Path $SourceDir $targetBinaryName
        $targetBinaryFilePath = Join-Path $targetBinaryDir $targetBinaryName
        if (Test-Path $targetBinaryFilePath) {
            $sourceModTime = (Get-Item $sourceBinaryFilePath).LastWriteTime
            $destModTime = (Get-Item $targetBinaryFilePath).LastWriteTime
            if ($destModTime -lt $sourceModTime) {
                Write-Verbose "  ${targetBinaryName}: Updating from $sourceBinaryFilePath"
                Copy-Item $sourceBinaryFilePath $targetBinaryDir
            } else {
                Write-Verbose "  ${targetBinaryName}: already present"
            }
        }
        else {
            Write-Verbose "  ${targetBinaryName}: Copying $sourceBinaryFilePath"
            Copy-Item $sourceBinaryFilePath $targetBinaryDir
        }
        if ($copiedFilesLog) { Add-Content $copiedFilesLog $targetBinaryFilePath -Encoding UTF8 }
        if ($tlogFile) { Add-Content $tlogFile $targetBinaryFilePath -Encoding Unicode }
    } finally {
        if ($mtx) {
            $mtx.ReleaseMutex() | Out-Null
            $mtx.Dispose() | Out-Null
        }
    }
}


Write-Verbose "Resolving base path $targetBinary..."
try
{
    $baseBinaryPath = Resolve-Path $targetBinary -erroraction stop
    $baseTargetBinaryDir = Split-Path $baseBinaryPath -parent
}
catch [System.Management.Automation.ItemNotFoundException]
{
    return
}
 
function resolve([string]$targetBinary) {
    Write-Verbose "Resolving $targetBinary..."
    try
    {
        $targetBinaryPath = Resolve-Path $targetBinary -erroraction stop
    }
    catch [System.Management.Automation.ItemNotFoundException]
    {
        return
    }
    $targetBinaryDir = Split-Path $targetBinaryPath -parent

    if (Get-Command "dumpbin" -ErrorAction SilentlyContinue) {
        $a = $(dumpbin /DEPENDENTS $targetBinary | ? { $_ -match "^    [^ ].*\.dll" } | % { $_ -replace "^    ","" })
    } elseif (Get-Command "llvm-objdump" -ErrorAction SilentlyContinue) {
        $a = $(llvm-objdump -p $targetBinary| ? { $_ -match "^ {4}DLL Name: .*\.dll" } | % { $_ -replace "^ {4}DLL Name: ","" })
    } elseif (Get-Command "objdump" -ErrorAction SilentlyContinue) {
        $a = $(objdump -p $targetBinary| ? { $_ -match "^\tDLL Name: .*\.dll" } | % { $_ -replace "^\tDLL Name: ","" })
    } else {
        Write-Error "Neither dumpbin, llvm-objdump nor objdump could be found. Can not take care of dll dependencies."
    }
    $a | % {
        if ([string]::IsNullOrEmpty($_)) {
            return
        }
        if ($g_searched.ContainsKey($_)) {
            Write-Verbose "  ${_}: previously searched - Skip"
            return
        }
        $g_searched.Set_Item($_, $true)
        $installedItemFilePath = Join-Path $installedDir $_
        $targetItemFilePath = Join-Path $targetBinaryDir $_
        if (Test-Path $installedItemFilePath) {
            deployBinary $baseTargetBinaryDir $installedDir "$_"
            if (Test-Path function:\deployPluginsIfQt) { deployPluginsIfQt $baseTargetBinaryDir (Join-Path $g_install_root 'plugins') "$_" }
            if (Test-Path function:\deployOpenNI2) { deployOpenNI2 $targetBinaryDir "$g_install_root" "$_" }
            if (Test-Path function:\deployPluginsIfMagnum) {
                if ($g_is_debug) {
                    deployPluginsIfMagnum $targetBinaryDir (Join-Path (Join-Path "$g_install_root" 'bin') 'magnum-d') "$_"
                } else {
                    deployPluginsIfMagnum $targetBinaryDir (Join-Path (Join-Path "$g_install_root" 'bin') 'magnum') "$_"
                }
            }
            if (Test-Path function:\deployAzureKinectSensorSDK) { deployAzureKinectSensorSDK $targetBinaryDir "$g_install_root" "$_" }
            resolve (Join-Path $baseTargetBinaryDir "$_")
        } elseif (Test-Path $targetItemFilePath) {
            Write-Verbose "  ${_}: $_ not found in $g_install_root; locally deployed"
            resolve "$targetItemFilePath"
        } else {
            Write-Verbose "  ${_}: $installedItemFilePath not found"
        }
    }
    Write-Verbose "Done Resolving $targetBinary."
}
  
resolve($targetBinary)
Write-Verbose $($g_searched | out-string) 