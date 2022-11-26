import jsonPlugin from '@rollup/plugin-json';
import typescriptPlugin from 'rollup-plugin-typescript2';
import babel from 'rollup-plugin-babel';
import resolve from '@rollup/plugin-node-resolve'; 
import sourceMaps from 'rollup-plugin-sourcemaps';
import commonjs from 'rollup-plugin-commonjs';
import replace from 'rollup-plugin-replace';
import uglify from 'rollup-plugin-uglify-es';

import modulePkg from "./package.json"; 

import { tmpdir } from 'os';
import { builtinModules } from 'module';
import { join as pathJoin } from 'path';

const env = process.env.NODE_ENV || 'prod';
const coreModules = builtinModules.filter(name => !/(^_|\/)/.test(name));
const cacheRoot = pathJoin(tmpdir(), '.rpt2_cache');

function makePathOutput() {
    return [
        {
            file: pathJoin("lib", 'index.js'),
            format: 'cjs',
            exports: 'named'
        },
        {
            file: pathJoin("lib", 'index.es.mjs'),
            format: "es",
            sourcemap: true
        },
        {
            file: pathJoin("lib", 'index.mjs'),
            format: "esm"
        } 
    ];
}

const input = pathJoin("src", 'index.ts');
 
const pluginsCommon = [
    babel(), 
    resolve({ 
        extensions: [ ".ts" ] 
    }),  
    jsonPlugin(),
    commonjs(),  
    sourceMaps(), 
    replace({
        exclude: 'node_modules/**',
        'process.env.NODE_ENV': JSON.stringify(env),
    })
]

const external = [
    ...Object.keys(modulePkg.dependencies || {}),
    ...Object.keys(modulePkg.peerDependencies || {}), 
    ...coreModules
];
 
const commonRollupConfig = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig.json",
            tsconfigOverride: {
                outDir: "lib",
                rootDir: "src",
                include: ["src"]
            },
            clean: true
        }) 
    ],
    external,
    output: [
        ...makePathOutput()
    ]
}
 
 
export default [
    commonRollupConfig
];