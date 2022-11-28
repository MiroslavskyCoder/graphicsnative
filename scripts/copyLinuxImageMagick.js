const fs = require("fs");
const path = require("path");

fs.copyFileSync(path.resolve("deps_image_magick/MagickWand/.libs/libMagickWand-7.Q16HDRI.so.10.0.0"), path.join(process.argv[2], "libMagickWand-7.Q16HDRI.so"));
fs.copyFileSync(path.resolve("deps_image_magick/MagickCore/.libs/libMagickCore-7.Q16HDRI.so.10.0.0"), path.join(process.argv[2], "libMagickCore-7.Q16HDRI.so"));
fs.copyFileSync(path.resolve("deps_image_magick/Magick++/lib/.libs/libMagick++-7.Q16HDRI.so.5.0.0"), path.join(process.argv[2], "libMagick++-7.Q16HDRI.so"));