#include "global.h"

#include <functional>

class SizesOptions { 
    
public:
    SizesOptions(int _w, int _h, int _x = 0, int _y = 0) :
        w(_w), h(_h), x(_x), y(_y) {};

    int w; int h; int x; int y;
};

class EffectsNative:
    public Nan::ObjectWrap 
{
public:
    
	static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target); 

    static NAN_METHOD(New); 

    static NAN_METHOD(AdaptiveBlurImage);
    static NAN_METHOD(AdaptiveResizeImage);
    static NAN_METHOD(AdaptiveSharpenImage);
    static NAN_METHOD(AdaptiveSharpenChannelImage);
    static NAN_METHOD(AdaptiveThresholdImage);
    static NAN_METHOD(AddAffineImage);
    static NAN_METHOD(AddArcImage);
    static NAN_METHOD(AddBorderImage);
    static NAN_METHOD(AddCircleImage);
    static NAN_METHOD(AddFrameImage);
    static NAN_METHOD(AddNoiseImage);
    static NAN_METHOD(AddNoiseChannelImage);
    static NAN_METHOD(AddPolygonImage);
    static NAN_METHOD(AddRoundRectangleImage);
    static NAN_METHOD(AddSourceImage);
    static NAN_METHOD(AddTextImage);
    static NAN_METHOD(AdjoinImage);
    static NAN_METHOD(AffineTransformImage);
    static NAN_METHOD(AlphaImage);
    static NAN_METHOD(AnimationDelayImage);
    static NAN_METHOD(AnimationIterationsImage);
    static NAN_METHOD(AnnotateImage);
    static NAN_METHOD(ArtifactImage);
    static NAN_METHOD(AttributeImage);
    static NAN_METHOD(AutoGammaImage);
    static NAN_METHOD(AutoGammaChannelImage);
    static NAN_METHOD(AutoLevelImage);
    static NAN_METHOD(AutoLevelChannelImage);
    static NAN_METHOD(AutoOrientImage);
    static NAN_METHOD(AutoThresholdImage);
    static NAN_METHOD(BackgroundColorImage);
    static NAN_METHOD(BackgroundTextureImage);
    static NAN_METHOD(BlackThresholdImage);
    static NAN_METHOD(BlackThresholdChannelImage);
    static NAN_METHOD(BlueShiftImage);
    static NAN_METHOD(BlurImage);
    static NAN_METHOD(BlurChannelImage);
    static NAN_METHOD(BorderImage);
    static NAN_METHOD(BorderColorImage);
    static NAN_METHOD(BoundingBoxImage);
    static NAN_METHOD(BoxColorImage);
    static NAN_METHOD(CannyEdgeImage);
    static NAN_METHOD(CDLImage);
    static NAN_METHOD(ChannelImage);
    static NAN_METHOD(ChannelDepthImage);
    static NAN_METHOD(CharcoalImage);
    static NAN_METHOD(CharcoalChannelImage);
    static NAN_METHOD(ChopImage);
    static NAN_METHOD(ClampImage); 
    static NAN_METHOD(ClampChannelImage);
    static NAN_METHOD(ClipImage);
    static NAN_METHOD(ClipPathImage);
    static NAN_METHOD(ClutImage);
    static NAN_METHOD(ClutChannelImage);
    static NAN_METHOD(ColorFuzzImage);
    static NAN_METHOD(ColorizeImage);
    static NAN_METHOD(ColorMatrixImage);
    static NAN_METHOD(CompareImage); 
    static NAN_METHOD(ComposeImage);
    static NAN_METHOD(CompositeImage);
    static NAN_METHOD(ContrastImage);
    static NAN_METHOD(ContrastStretchImage);
    static NAN_METHOD(ContrastStretchChannelImage);
    static NAN_METHOD(CropImage);
    static NAN_METHOD(DefineSetImage);
    static NAN_METHOD(DefineValueImage);
    static NAN_METHOD(DisplayImage);
    static NAN_METHOD(EncipherImage);
    static NAN_METHOD(EnhanceImage);
    static NAN_METHOD(ExtentImage);
    static NAN_METHOD(FillColorImage);
    static NAN_METHOD(FillPatternImage);
    static NAN_METHOD(FillRuleImage);
    static NAN_METHOD(FlipImage); 
    static NAN_METHOD(FloodFillAlphaImage);
    static NAN_METHOD(FloodFillColorImage);
    static NAN_METHOD(FloodFillTextureImage);
    static NAN_METHOD(FontImage);
    static NAN_METHOD(FontFamilyImage);
    static NAN_METHOD(FontPointSizeImage);
    static NAN_METHOD(FontStyleImage);
    static NAN_METHOD(FontTypeMetricsImage);
    static NAN_METHOD(FontTypeMetricsMultilineImage);
    static NAN_METHOD(FontWeightImage);
    static NAN_METHOD(FxImage);
    static NAN_METHOD(GammaImage);
    static NAN_METHOD(GetDataImage);
    static NAN_METHOD(GetWidth);
    static NAN_METHOD(GetHeight);
    static NAN_METHOD(GetPixelsImage);
    static NAN_METHOD(GetStrokeWidthImage);
    static NAN_METHOD(HaldClutImage);
    static NAN_METHOD(ImplodeImage);
    static NAN_METHOD(LabelImage);
    static NAN_METHOD(LiquidRescaleImage);
    static NAN_METHOD(MedianFilterImage);
    static NAN_METHOD(ModifyImage);
    static NAN_METHOD(ModulateImage);
    static NAN_METHOD(MotionBlurImage);
    static NAN_METHOD(NegateImage);
    static NAN_METHOD(NegateChannelImage);
    static NAN_METHOD(OpaqueImage);
    static NAN_METHOD(OrderedDitherImage);
    static NAN_METHOD(OrderedDitherChannelImage);
    static NAN_METHOD(PerceptibleImage);
    static NAN_METHOD(PerceptibleChannelImage);
    static NAN_METHOD(ProcessImage);
    static NAN_METHOD(PutPixelsImage);
    static NAN_METHOD(QualityImage);
    static NAN_METHOD(QuantizeImage);
    static NAN_METHOD(ReadImage);
    static NAN_METHOD(RenderingIntentImage);
    static NAN_METHOD(RepageImage);
    static NAN_METHOD(ResizeImage);
    static NAN_METHOD(RollImage);
    static NAN_METHOD(RotateImage);
    static NAN_METHOD(RotationalBlurImage);
    static NAN_METHOD(RotationalBlurChannelImage);
    static NAN_METHOD(ScaleImage);
    static NAN_METHOD(SizeImage);
    static NAN_METHOD(SpliceImage);
    static NAN_METHOD(StereoImage);
    static NAN_METHOD(StrokeAntiAliasImage);
    static NAN_METHOD(StrokeColorImage);
    static NAN_METHOD(StrokeDashArrayImage);
    static NAN_METHOD(StrokeDashOffsetImage);
    static NAN_METHOD(StrokeLineCapImage);
    static NAN_METHOD(StrokeLineJoinImage);
    static NAN_METHOD(StrokeMiterLimitImage);
    static NAN_METHOD(StrokePatternImage);
    static NAN_METHOD(StrokeWidthImage);
    static NAN_METHOD(SubImageImage);
    static NAN_METHOD(SubRangeImage);
    static NAN_METHOD(TextAntiAliasImage);
    static NAN_METHOD(TextDirectionImage);
    static NAN_METHOD(TextGravityImage);
    static NAN_METHOD(TextInterlineSpacingImage);
    static NAN_METHOD(TextInterwordSpacingImage);
    static NAN_METHOD(TextKerningImage);
    static NAN_METHOD(TextUnderColorImage);
    static NAN_METHOD(TextureImage);
    static NAN_METHOD(ThumbnailImage);
    static NAN_METHOD(TintImage);
    static NAN_METHOD(ToBase64Image);
    static NAN_METHOD(ToBufferImage);
    static NAN_METHOD(TransformOriginImage);
    static NAN_METHOD(TransformResetImage);
    static NAN_METHOD(TransformRotationImage);
    static NAN_METHOD(TransformScaleImage);
    static NAN_METHOD(TransformSkewXImage);
    static NAN_METHOD(TransformSkewYImage);
    static NAN_METHOD(TransparentImage);
    static NAN_METHOD(TransparentChromaImage);
    static NAN_METHOD(TransposeImage);
    static NAN_METHOD(TransverseImage);
    static NAN_METHOD(TrimImage);
    static NAN_METHOD(UnsharpmaskImage);
    static NAN_METHOD(UnsharpmaskChannelImage);
    static NAN_METHOD(VerboseImage);
    static NAN_METHOD(VignetteImage);
    static NAN_METHOD(VirtualPixelImage);
    static NAN_METHOD(WaveImage);
    static NAN_METHOD(WaveletDenoiseImage);
    static NAN_METHOD(WhiteThresholdImage);
    static NAN_METHOD(WhiteThresholdChannelImage);
    static NAN_METHOD(WriteImage);
    static NAN_METHOD(WriteFramesImage);
    static NAN_METHOD(ZoomImage);
        
    EffectsNative();
    EffectsNative(const char* buf, size_t length);
    EffectsNative(std::string file);
    EffectsNative(int w, int h, std::string format, const char* buf);

    MagickCore::ChannelType stringToChannelType(std::string value);
    MagickCore::AutoThresholdMethod stringToAutoThresholdMethod(std::string value);
    MagickCore::GravityType stringToGravityType(std::string value);
    MagickCore::VirtualPixelMethod stringToVirtualPixelMethod(std::string value);
    MagickCore::StyleType stringToStyleType(std::string value);
    MagickCore::StretchType stringToStretchType(std::string value);
    MagickCore::FillRule stringToFillRule(std::string value);
    MagickCore::NoiseType stringToNoiseType(std::string value); 
    MagickCore::DirectionType stringToDirectionType(std::string value);
    MagickCore::PixelInterpolateMethod stringToPixelInterpolateMethod(std::string value);
    MagickCore::PixelMask stringToPixelMask(std::string value);
    MagickCore::RenderingIntent stringToRenderingIntent(std::string value);
    MagickCore::LineJoin stringToLineJoin(std::string value);
    MagickCore::LineCap stringToLineCap(std::string value);
    MagickCore::CompositeOperator stringToCompositeOperator(std::string value);
    MagickCore::MetricType stringToMetricType(std::string value); 
    MagickCore::PixelTrait stringToPixelTrait(std::string value);
    MagickCore::ColorspaceType stringToColorspaceType(std::string value);
    MagickCore::ClassType stringToClassType(std::string value);

    void addImage(int x, int y, int w, int h, EffectsNative* source); 
    void addBorderColor(Magick::Color color); 
    void addArc(int startX, int startY, int endX, int endY, int startDegrees, int endDegrees);
    void addAffine(int sx, int sy, int rx, int ry, int tx, int ty);
    void addCircle(int originX, int originY, int perimX, int perimY);

    int width();
    int height(); 

private:

    Magick::Image image;

    std::vector<Magick::Image> frames;
};

MagickCore::PixelInfo* pixelInfoFromV8(v8::Local<v8::Value> from);