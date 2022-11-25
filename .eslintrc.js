export default {
    extends: [
        "eslint:recommended", 
        "plugin:@typescript-eslint/recommended"
    ],
    parser: "@typescript-eslint/parser",
    plugins: [
        "@typescript-eslint"
    ],
    root: true,
    rules: {
        "linebreak-style": "off",
        "eol-last": "off",
        "@typescript-eslint/no-shadow": "off",
        "no-param-reassign": "off",
        "space-infix-ops": "off",
        "space-unary-ops": "off",
        "max-len": "off",
        "eqeqeq": "off",
        "lines-between-class-members": "off",
        "@typescript-eslint/no-explicit-any": "off",
        "@typescript-eslint/naming-convention": "off",
        "no-underscore-dangle": "off",
        "no-trailing-spaces": "off",
        "@typescript-eslint/indent": "off", 
        "quotes": "off"
    }
}