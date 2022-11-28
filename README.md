### @bymiroslavsky/graphicsnative 

### ImageMagick 
 
1. [Windows](https://imagemagick.org/script/download.php) 
2. [Linux](https://imagemagick.org/script/install-source.php) 

### (Linux) Install dependencies for ImageMagick

```sh
sudo apt update
sudo apt-get install build-essential libcairo2-dev libpango1.0-dev libjpeg-dev libgif-dev librsvg2-dev
```
____

* Setup Environment

```sh
export PATH_IMAGEMAGICK_SOURCE=/path/to/ImageMagick
```
```bat 
set PATH_IMAGEMAGICK_SOURCE=C:/path/to/ImageMagick
```
____

* NPM
```sh
npm install --build-from-source
npm install --save @bymiroslavsky/graphicsnative
```
* YARN
```sh
yarn add @bymiroslavsky/graphicsnative
``` 

____

 ## [GraphicsNative Examples](https://github.com/MiroslavskyCoder/graphicsnative-examples)