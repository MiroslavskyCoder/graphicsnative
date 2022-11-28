const fs = require("fs");
const path = require("path");

fs.copyFileSync("deps_image_magick/MagickWand/.libs/libMagickWand-7.Q16HDRI.so", path.join(process.argv[2], "libMagickWand-7.Q16HDRI.so"));
fs.copyFileSync("deps_image_magick/MagickWand/.libs/libMagickCore-7.Q16HDRI.so", path.join(process.argv[2], "libMagickCore-7.Q16HDRI.so"));
fs.copyFileSync("deps_image_magick/MagickWand/.libs/libMagick++-7.Q16HDRI.so", path.join(process.argv[2], "libMagick++-7.Q16HDRI.so"));