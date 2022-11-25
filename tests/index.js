const graphicsnative = require("../");
const mlog = require("mocha-logger");

describe('@bymiroslavsky/graphicsnative', function() { 
    this.timeout(50000);
    /**
     * @type {graphicsnative.EffectsNative}
     */
    var e;
    describe("Read Image", function() { 
        it("Read Image EffectsNative", function() { 
            e = new graphicsnative.EffectsNative("tests/test.jpg");
        });
        describe("Get Sizes", function() {
            it("Sizes -> Width x Height", function() {
                mlog.log(`Sizes: ${e.width}x${e.height}`);
            })
        });
        describe("Applys Filters", function() {
            it("Filter: AdaptiveBlur", function() {
                e.adaptiveBlur(1, 5);
            });
            it("Filter: AdaptiveSharpen", function() {
                e.adaptiveSharpen(1, 5);
            });
            it("Filter: AdaptiveSharpenChannel", function() {
                e.adaptiveSharpenChannel("red", 1, 5);
            });
            it("Filter: Blur", function() {
                e.blur(1, 5);
            });
        });
    });
});
