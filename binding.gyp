{
    "variables": {
        "DIR_NAPI_OUTPUT": "napi"
    },
    "conditions": [
        ['OS=="win"', {
            "variables": { 
                "IMAGEMAGICK_ROOT": "<!(node ./scripts/pathImageMagick.js)"
            }
        }],
        ['OS=="linux"', {
            "targets": [
                {
                    
                    "target_name": "BuildImageMagick",
                    "type": "none",
                    "actions": [
                        {
                            "action_name": "ImageMagick",
                            "action": [
                                "git clone https://github.com/ImageMagick/ImageMagick.git deps/ImageMagick" 
                            ]
                        }
                    ]
                }
            ]
        }]
    ], 
    "targets": [
        {
            "target_name": "GraphicsNative",
            'include_dirs': [ 
                'include',
                "<!(node -e \"require('nan')\")",
            ], 
            "sources": [ 
                "source/binding.cc",
                "source/EffectsNative.cc",
                "source/Types.cc",
                "source/Util.cc",
                "source/methods/AdaptiveBlur.cc",
                "source/methods/AdaptiveResize.cc",
                "source/methods/AdaptiveSharpen.cc",
                "source/methods/AdaptiveSharpenChannel.cc",
                "source/methods/AdaptiveThreshold.cc",
                "source/methods/AddAffine.cc",
                "source/methods/AddArc.cc",
                "source/methods/AddBorder.cc",
                "source/methods/AddCircle.cc",
                "source/methods/AddFrame.cc",
                "source/methods/AddNoise.cc",
                "source/methods/AddNoiseChannel.cc",
                "source/methods/AddPolygon.cc",
                "source/methods/AddRoundRectangle.cc",
                "source/methods/AddSource.cc",
                "source/methods/AddText.cc",
                "source/methods/Adjoin.cc",
                "source/methods/AffineTransform.cc",
                "source/methods/Alpha.cc",
                "source/methods/AnimationDelay.cc",
                "source/methods/AnimationIterations.cc",
                "source/methods/Annotate.cc",
                "source/methods/Artifact.cc",
                "source/methods/Attribute.cc",
                "source/methods/AutoGamma.cc",
                "source/methods/AutoGammaChannel.cc",
                "source/methods/AutoLevel.cc",
                "source/methods/AutoLevelChannel.cc",
                "source/methods/AutoOrient.cc",
                "source/methods/AutoThreshold.cc",
                "source/methods/BackgroundColor.cc",
                "source/methods/BackgroundTexture.cc",
                "source/methods/BlackThreshold.cc",
                "source/methods/BlackThresholdChannel.cc",
                "source/methods/BlueShift.cc",
                "source/methods/Blur.cc",
                "source/methods/BlurChannel.cc",
                "source/methods/Border.cc",
                "source/methods/BorderColor.cc",
                "source/methods/BoundingBox.cc",
                "source/methods/BoxColor.cc",
                "source/methods/CannyEdge.cc",
                "source/methods/CDL.cc",
                "source/methods/Channel.cc",
                "source/methods/ChannelDepth.cc",
                "source/methods/Charcoal.cc",
                "source/methods/CharcoalChannel.cc",
                "source/methods/Chop.cc",
                "source/methods/Clamp.cc",
                "source/methods/ClampChannel.cc",
                "source/methods/Clip.cc",
                "source/methods/ClipPath.cc",
                "source/methods/Clut.cc",
                "source/methods/ClutChannel.cc",
                "source/methods/ColorFuzz.cc",
                "source/methods/Colorize.cc",
                "source/methods/ColorMatrix.cc",
                "source/methods/Compare.cc",
                "source/methods/Compose.cc",
                "source/methods/Composite.cc",
                "source/methods/Contrast.cc",
                "source/methods/ContrastStretch.cc",
                "source/methods/ContrastStretchChannel.cc",
                "source/methods/Crop.cc",
                "source/methods/DefineSet.cc",
                "source/methods/DefineValue.cc",
                "source/methods/Display.cc",
                "source/methods/Encipher.cc",
                "source/methods/Enhance.cc",
                "source/methods/Extent.cc",
                "source/methods/FillColor.cc",
                "source/methods/FillPattern.cc",
                "source/methods/FillRule.cc",
                "source/methods/Flip.cc", 
                "source/methods/FloodFillAlpha.cc",
                "source/methods/FloodFillColor.cc",
                "source/methods/FloodFillTexture.cc",
                "source/methods/Font.cc",
                "source/methods/FontFamily.cc",
                "source/methods/FontPointSize.cc",
                "source/methods/FontStyle.cc",
                "source/methods/FontTypeMetrics.cc",
                "source/methods/FontTypeMetricsMultiline.cc",
                "source/methods/FontWeight.cc",
                "source/methods/Fx.cc",
                "source/methods/Gamma.cc",
                "source/methods/GetData.cc",
                "source/methods/GetPixels.cc",
                "source/methods/GetSizes.cc",
                "source/methods/GetStrokeWidth.cc",
                "source/methods/HaldClut.cc",
                "source/methods/Implode.cc",
                "source/methods/Label.cc",
                "source/methods/LiquidRescale.cc",
                "source/methods/MedianFilter.cc",
                "source/methods/Modify.cc",
                "source/methods/Modulate.cc",
                "source/methods/MotionBlur.cc",
                "source/methods/Negate.cc",
                "source/methods/NegateChannel.cc",
                "source/methods/Opaque.cc",
                "source/methods/OrderedDither.cc",
                "source/methods/OrderedDitherChannel.cc",
                "source/methods/Perceptible.cc",
                "source/methods/PerceptibleChannel.cc",
                "source/methods/Process.cc",
                "source/methods/PutPixels.cc",
                "source/methods/Quality.cc",
                "source/methods/Quantize.cc",
                "source/methods/Read.cc",
                "source/methods/RenderingIntent.cc",
                "source/methods/Repage.cc",
                "source/methods/Resize.cc",
                "source/methods/Roll.cc",
                "source/methods/Rotate.cc",
                "source/methods/RotationalBlur.cc",
                "source/methods/RotationalBlurChannel.cc",
                "source/methods/Scale.cc",
                "source/methods/Size.cc",
                "source/methods/Splice.cc",
                "source/methods/Stereo.cc",
                "source/methods/StrokeAntiAlias.cc",
                "source/methods/StrokeColor.cc",
                "source/methods/StrokeDashArray.cc",
                "source/methods/StrokeDashOffset.cc",
                "source/methods/StrokeLineCap.cc",
                "source/methods/StrokeLineJoin.cc",
                "source/methods/StrokeMiterLimit.cc",
                "source/methods/StrokePattern.cc",
                "source/methods/StrokeWidth.cc",
                "source/methods/SubImage.cc",
                "source/methods/SubRange.cc",
                "source/methods/TextAntiAlias.cc",
                "source/methods/TextDirection.cc",
                "source/methods/TextGravity.cc",
                "source/methods/TextInterlineSpacing.cc",
                "source/methods/TextInterwordSpacing.cc",
                "source/methods/TextKerning.cc",
                "source/methods/TextUnderColor.cc",
                "source/methods/Texture.cc",
                "source/methods/Thumbnail.cc",
                "source/methods/Tint.cc",
                "source/methods/ToBase64.cc",
                "source/methods/ToBuffer.cc",
                "source/methods/TransformOrigin.cc",
                "source/methods/TransformReset.cc",
                "source/methods/TransformRotation.cc",
                "source/methods/TransformScale.cc",
                "source/methods/TransformSkewX.cc",
                "source/methods/TransformSkewY.cc",
                "source/methods/Transparent.cc",
                "source/methods/TransparentChroma.cc",
                "source/methods/Transpose.cc",
                "source/methods/Transverse.cc",
                "source/methods/Trim.cc",
                "source/methods/Unsharpmask.cc",
                "source/methods/UnsharpmaskChannel.cc",
                "source/methods/Verbose.cc",
                "source/methods/Vignette.cc",
                "source/methods/VirtualPixel.cc",
                "source/methods/Wave.cc",
                "source/methods/WaveletDenoise.cc",
                "source/methods/WhiteThreshold.cc",
                "source/methods/WhiteThresholdChannel.cc",
                "source/methods/Write.cc",
                "source/methods/WriteFrames.cc",
                "source/methods/Zoom.cc"
            ], 
            "conditions": [
                ['OS=="win"', {
                    "libraries": [
                        '<(IMAGEMAGICK_ROOT)/lib/*.lib'
                    ],
                    "include_dirs": [
                        "<(IMAGEMAGICK_ROOT)/include"
                    ], 
                    "msvs_settings": {
                        "VCCLCompilerTool": {
                            "AdditionalOptions": [
                                "/EHsc" 
                            ] 
                        }
                    },
                    "configurations": {
                        "Debug_x64": {
                            "inherit_from": ["Debug"],
                            "msvs_configuration_platform": "x64" 
                        },
                        "Release_x64": {
                            "inherit_from": ["Release"],
                            "msvs_configuration_platform": "x64"
                        },
                    } 
                }], 
                ['OS=="linux"', {
                    'libraries': [
                        '<!@(pkg-config Magick++ --libs)'
                    ],
                    'include_dirs': [
                        '<!@(pkg-config Magick++ --cflags-only-I | sed s/-I//g)', 
                    ],
                    'cflags': [
                        "-Wno-cast-function-type"
                    ],
                    'cflags!': [
                        "-fno-exceptions"
                    ],
                    'cflags_cc!': [
                        "-fno-exceptions",
                        "-fexceptions",
                        "-Wcast-function-type"
                    ]  
                }]
            ] 
        },
        {
            "target_name": "action_after_build",
            "type": "none",
            "dependencies": [
                "<(module_name)"
            ], 
            "copies": [
                {
                    "files": [ 
                        "<(PRODUCT_DIR)/<(module_name).node"
                    ],
                    "destination": "<(DIR_NAPI_OUTPUT)"
                }
            ],
            "conditions": [ 
                ['OS=="win"', {
                    "actions": [
                        {
                            "action_name": "CopyRelease",
                            "inputs": [
                                "scripts/applocal.ps1"
                            ],
                            "outputs": [
                                "<(DIR_NAPI_OUTPUT)/<(module_name).node"
                            ],
                            "action": [
                                "powershell -ExecutionPolicy Bypass -noprofile -File \"../scripts/applocal.ps1\" \"../<(DIR_NAPI_OUTPUT)/<(module_name).node\" \"<(IMAGEMAGICK_ROOT)\""
                            ]
                        }
                    ]
                }]
            ]
        }
    ]
}