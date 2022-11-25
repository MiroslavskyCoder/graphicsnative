import jsonPlugin from '@rollup/plugin-json';
import typescriptPlugin from 'rollup-plugin-typescript2';
import babel from 'rollup-plugin-babel';
import resolve from '@rollup/plugin-node-resolve';
import { terser } from 'rollup-plugin-terser'; 
import sourceMaps from 'rollup-plugin-sourcemaps';
import commonjs from 'rollup-plugin-commonjs';
import replace from 'rollup-plugin-replace';
import uglify from 'rollup-plugin-uglify-es';

import modulePkg from "./package.json"; 

import { tmpdir } from 'os';
import { builtinModules } from 'module';
import { join as pathJoin } from 'path';

const env = process.env.NODE_ENV || 'development';
const coreModules = builtinModules.filter(name => !/(^_|\/)/.test(name));
const cacheRoot = pathJoin(tmpdir(), '.rpt2_cache');

function makePathOutput(target = "cjs") {
    return [
        {
            file: pathJoin("lib", target, 'index.js'),
            format: 'cjs',
            exports: 'named'
        },
        {
            file: pathJoin("lib", target, 'index.es.mjs'),
            format: "es",
            sourcemap: true
        },
        {
            file: pathJoin("lib", target, 'index.mjs'),
            format: "esm"
        },
        {
            file: pathJoin("lib", target, 'index.umd.js'),
            format: 'umd',
            sourcemap: true,
            name: "graphicsnative"
        }
    ];
}

const input = pathJoin("src", 'index.ts');
 
const pluginsCommon = [
    babel(), 
    resolve({ 
        extensions: [ ".ts", ".tsx", ".js", ".jsx", ".mjs", ".cjs" ] 
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
 
const rollupES5 = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig-esm5.json",
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
        ...makePathOutput("es5")
    ]
}
const rollupES6 = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig-esm6.json",
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
        ...makePathOutput("es6")
    ]
}
const rollupES2018 = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig-es2018.json",
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
        ...makePathOutput("es2018")
    ]
}
const rollupES2019 = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig-es2019.json",
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
        ...makePathOutput("es2019")
    ]
}
const rollupES2020 = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig-es2020.json",
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
        ...makePathOutput("es2020")
    ]
}
const rollupES2021 = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig-es2021.json",
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
        ...makePathOutput("es2021")
    ]
}
const rollupES2022 = {
    input,
    plugins: [ 
        ...pluginsCommon,
        uglify(),
        typescriptPlugin({
            cacheRoot, 
            useTsconfigDeclarationDir: false, 
            tsconfig: "./tsconfig-es2022.json",
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
        ...makePathOutput("es2022")
    ]
}

export default [
    rollupES5,
    rollupES6,
    rollupES2018,
    rollupES2019,
    rollupES2020,
    rollupES2021,
    rollupES2022
];