const child = require("child_process");
const fs = require("fs");
const os = require("os");

if (os.platform() == "linux") {
    if (fs.existsSync("deps_image_magick")) {
        if (!fs.statSync("deps_image_magick").isDirectory()) {
            child.execSync("rm deps_image_magick");
        }
        else child.execSync("rm -r deps_image_magick");
    }
    child.execSync("git clone https://github.com/ImageMagick/ImageMagick.git deps_image_magick");
    child.execSync("cd deps_image_magick && bash ./configure --with-modules");
    child.execSync("cd deps_image_magick && make -j 4");
}