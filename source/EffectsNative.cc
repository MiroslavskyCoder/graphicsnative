#include "EffectsNative.h"

#include <vector>

Nan::Persistent<v8::FunctionTemplate> EffectsNative::constructor;

void EffectsNative::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
    Nan::HandleScope scope;
    
    v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(EffectsNative::New);
    
    constructor.Reset(ctor);
    
    ctor->InstanceTemplate()->SetInternalFieldCount(1);
    ctor->SetClassName(Nan::New("EffectsNative").ToLocalChecked()); 
    
    Nan::SetPrototypeMethod(ctor, "adaptiveBlur", AdaptiveBlurImage);
    Nan::SetPrototypeMethod(ctor, "adaptiveResize", AdaptiveResizeImage);
    Nan::SetPrototypeMethod(ctor, "adaptiveSharpen", AdaptiveSharpenImage);
    Nan::SetPrototypeMethod(ctor, "adaptiveSharpenChannel", AdaptiveSharpenChannelImage);
    Nan::SetPrototypeMethod(ctor, "adaptiveThreshold", AdaptiveThresholdImage);
    Nan::SetPrototypeMethod(ctor, "addAffine", AddAffineImage);
    Nan::SetPrototypeMethod(ctor, "addArc", AddArcImage);
    Nan::SetPrototypeMethod(ctor, "addBorder", AddBorderImage);
    Nan::SetPrototypeMethod(ctor, "addCircle", AddCircleImage);
    Nan::SetPrototypeMethod(ctor, "addFrame", AddFrameImage);
    Nan::SetPrototypeMethod(ctor, "addNoise", AddNoiseImage);
    Nan::SetPrototypeMethod(ctor, "addNoiseChannel", AddNoiseChannelImage);
    Nan::SetPrototypeMethod(ctor, "addPolygon", AddPolygonImage);
    Nan::SetPrototypeMethod(ctor, "addRoundRectangle", AddRoundRectangleImage);
    Nan::SetPrototypeMethod(ctor, "addSource", AddSourceImage);
    Nan::SetPrototypeMethod(ctor, "addText", AddTextImage);
    Nan::SetPrototypeMethod(ctor, "adjoin", AdjoinImage);
    Nan::SetPrototypeMethod(ctor, "affineTransform", AffineTransformImage);
    Nan::SetPrototypeMethod(ctor, "alpha", AlphaImage);
    Nan::SetPrototypeMethod(ctor, "animationDelay", AnimationDelayImage);
    Nan::SetPrototypeMethod(ctor, "animationIterations", AnimationIterationsImage);
    Nan::SetPrototypeMethod(ctor, "annotate", AnnotateImage);
    Nan::SetPrototypeMethod(ctor, "artifact", ArtifactImage);
    Nan::SetPrototypeMethod(ctor, "attribute", AttributeImage);
    Nan::SetPrototypeMethod(ctor, "autoGamma", AutoGammaImage);
    Nan::SetPrototypeMethod(ctor, "autoGammaChannel", AutoGammaChannelImage);
    Nan::SetPrototypeMethod(ctor, "autoLevel", AutoLevelImage);
    Nan::SetPrototypeMethod(ctor, "autoLevelChannel", AutoLevelChannelImage);
    Nan::SetPrototypeMethod(ctor, "autoOrient", AutoOrientImage);
    Nan::SetPrototypeMethod(ctor, "autoThreshold", AutoThresholdImage);
    Nan::SetPrototypeMethod(ctor, "backgroundColor", BackgroundColorImage);
    Nan::SetPrototypeMethod(ctor, "backgroundTexture", BackgroundTextureImage);
    Nan::SetPrototypeMethod(ctor, "blackThreshold", BlackThresholdImage);
    Nan::SetPrototypeMethod(ctor, "blackThresholdChannel", BlackThresholdChannelImage);
    Nan::SetPrototypeMethod(ctor, "blueShift", BlueShiftImage);
    Nan::SetPrototypeMethod(ctor, "blur", BlurImage);
    Nan::SetPrototypeMethod(ctor, "blurChannel", BlurChannelImage);
    Nan::SetPrototypeMethod(ctor, "border", BorderImage);
    Nan::SetPrototypeMethod(ctor, "borderColor", BorderColorImage);
    Nan::SetPrototypeMethod(ctor, "boundingBox", BoundingBoxImage);
    Nan::SetPrototypeMethod(ctor, "boxColor", BoxColorImage); 
    Nan::SetPrototypeMethod(ctor, "cannyEdge", CannyEdgeImage);
    Nan::SetPrototypeMethod(ctor, "cdl", CDLImage);
    Nan::SetPrototypeMethod(ctor, "channel", ChannelImage);
    Nan::SetPrototypeMethod(ctor, "channelDepth", ChannelDepthImage);
    Nan::SetPrototypeMethod(ctor, "charcoal", CharcoalImage);
    Nan::SetPrototypeMethod(ctor, "charcoalChannel", CharcoalChannelImage);
    Nan::SetPrototypeMethod(ctor, "chop", ChopImage);
    Nan::SetPrototypeMethod(ctor, "clamp", ClampImage);
    Nan::SetPrototypeMethod(ctor, "clampChannel", ClampChannelImage);
    Nan::SetPrototypeMethod(ctor, "clip", ClipImage);
    Nan::SetPrototypeMethod(ctor, "clipPath", ClipPathImage);
    Nan::SetPrototypeMethod(ctor, "clut", ClutImage);
    Nan::SetPrototypeMethod(ctor, "clutChannel", ClutChannelImage);
    Nan::SetPrototypeMethod(ctor, "colorFuzz", ColorFuzzImage);
    Nan::SetPrototypeMethod(ctor, "colorize", ColorizeImage);
    Nan::SetPrototypeMethod(ctor, "colorMatrix", ColorMatrixImage); 
    Nan::SetPrototypeMethod(ctor, "compare", CompareImage);
    Nan::SetPrototypeMethod(ctor, "compose", ComposeImage);
    Nan::SetPrototypeMethod(ctor, "composite", CompositeImage);
    Nan::SetPrototypeMethod(ctor, "contrast", ContrastImage); 
    Nan::SetPrototypeMethod(ctor, "contrastStretch", ContrastStretchImage);
    Nan::SetPrototypeMethod(ctor, "contrastStretchChannel", ContrastStretchChannelImage);
    Nan::SetPrototypeMethod(ctor, "crop", CropImage);
    Nan::SetPrototypeMethod(ctor, "defineSet", DefineSetImage);
    Nan::SetPrototypeMethod(ctor, "defineValue", DefineValueImage);
    Nan::SetPrototypeMethod(ctor, "display", DisplayImage);
    Nan::SetPrototypeMethod(ctor, "encipher", EncipherImage);
    Nan::SetPrototypeMethod(ctor, "enhance", EnhanceImage); 
    Nan::SetPrototypeMethod(ctor, "extent", ExtentImage);
    Nan::SetPrototypeMethod(ctor, "fillColor", FillColorImage);
    Nan::SetPrototypeMethod(ctor, "fillPattern", FillPatternImage);
    Nan::SetPrototypeMethod(ctor, "fillRule", FillRuleImage);
    Nan::SetPrototypeMethod(ctor, "flip", FlipImage); 
    Nan::SetPrototypeMethod(ctor, "floodFillAlpha", FloodFillAlphaImage);
    Nan::SetPrototypeMethod(ctor, "floodFillColor", FloodFillColorImage); 
    Nan::SetPrototypeMethod(ctor, "floodFillTexture", FloodFillTextureImage); 
    Nan::SetPrototypeMethod(ctor, "font", FontImage);
    Nan::SetPrototypeMethod(ctor, "fontFamily", FontFamilyImage);
    Nan::SetPrototypeMethod(ctor, "fontPointSize", FontPointSizeImage);
    Nan::SetPrototypeMethod(ctor, "fontStyle", FontStyleImage);
    Nan::SetPrototypeMethod(ctor, "fontTypeMetrics", FontTypeMetricsImage);
    Nan::SetPrototypeMethod(ctor, "fontTypeMetricsMultiline", FontTypeMetricsMultilineImage);
    Nan::SetPrototypeMethod(ctor, "fontWeight", FontWeightImage);
    Nan::SetPrototypeMethod(ctor, "fx", FxImage);
    Nan::SetPrototypeMethod(ctor, "gamma", GammaImage);
    Nan::SetPrototypeMethod(ctor, "getData", GetDataImage);
    Nan::SetPrototypeMethod(ctor, "getWidth", GetWidth);
    Nan::SetPrototypeMethod(ctor, "getHeight", GetHeight);
    Nan::SetPrototypeMethod(ctor, "getPixels", GetPixelsImage);
    Nan::SetPrototypeMethod(ctor, "getStrokeWidth", GetStrokeWidthImage);
    Nan::SetPrototypeMethod(ctor, "haldClut", HaldClutImage);
    Nan::SetPrototypeMethod(ctor, "implode", ImplodeImage);
    Nan::SetPrototypeMethod(ctor, "label", LabelImage);
    Nan::SetPrototypeMethod(ctor, "liquidRescale", LiquidRescaleImage);
    Nan::SetPrototypeMethod(ctor, "medianFilter", MedianFilterImage);
    Nan::SetPrototypeMethod(ctor, "modify", ModifyImage);
    Nan::SetPrototypeMethod(ctor, "modulate", ModulateImage);
    Nan::SetPrototypeMethod(ctor, "motionBlur", MotionBlurImage);
    Nan::SetPrototypeMethod(ctor, "negate", NegateImage);
    Nan::SetPrototypeMethod(ctor, "negateChannel", NegateChannelImage);
    Nan::SetPrototypeMethod(ctor, "opaque", OpaqueImage);
    Nan::SetPrototypeMethod(ctor, "orderedDither", OrderedDitherImage);
    Nan::SetPrototypeMethod(ctor, "orderedDitherChannel", OrderedDitherChannelImage);
    Nan::SetPrototypeMethod(ctor, "perceptible", PerceptibleImage);
    Nan::SetPrototypeMethod(ctor, "perceptibleChannel", PerceptibleChannelImage);
    Nan::SetPrototypeMethod(ctor, "process", ProcessImage); 
    Nan::SetPrototypeMethod(ctor, "putPixels", PutPixelsImage);  
    Nan::SetPrototypeMethod(ctor, "quality", QualityImage); 
    Nan::SetPrototypeMethod(ctor, "quantize", QuantizeImage); 
    Nan::SetPrototypeMethod(ctor, "read", ReadImage);
    Nan::SetPrototypeMethod(ctor, "renderingIntent", RenderingIntentImage);
    Nan::SetPrototypeMethod(ctor, "repage", RepageImage);
    Nan::SetPrototypeMethod(ctor, "resize", ResizeImage);
    Nan::SetPrototypeMethod(ctor, "roll", RollImage);
    Nan::SetPrototypeMethod(ctor, "rotate", RotateImage);
    Nan::SetPrototypeMethod(ctor, "rotationalBlur", RotationalBlurImage);
    Nan::SetPrototypeMethod(ctor, "rotationalBlurChannel", RotationalBlurChannelImage);
    Nan::SetPrototypeMethod(ctor, "scale", ScaleImage);
    Nan::SetPrototypeMethod(ctor, "size", SizeImage);
    Nan::SetPrototypeMethod(ctor, "splice", SpliceImage);
    Nan::SetPrototypeMethod(ctor, "stereo", StereoImage);
    Nan::SetPrototypeMethod(ctor, "strokeAntiAlias", StrokeAntiAliasImage);
    Nan::SetPrototypeMethod(ctor, "strokeColor", StrokeColorImage);
    Nan::SetPrototypeMethod(ctor, "strokeDashArray", StrokeDashArrayImage);
    Nan::SetPrototypeMethod(ctor, "strokeDashOffset", StrokeDashOffsetImage);
    Nan::SetPrototypeMethod(ctor, "strokeLineCap", StrokeLineCapImage);
    Nan::SetPrototypeMethod(ctor, "strokeLineJoin", StrokeLineJoinImage);
    Nan::SetPrototypeMethod(ctor, "strokeMiterLimit", StrokeMiterLimitImage);
    Nan::SetPrototypeMethod(ctor, "strokePattern", StrokePatternImage);
    Nan::SetPrototypeMethod(ctor, "strokeWidth", StrokeWidthImage);
    Nan::SetPrototypeMethod(ctor, "subImage", SubImageImage);
    Nan::SetPrototypeMethod(ctor, "subRange", SubRangeImage);
    Nan::SetPrototypeMethod(ctor, "textAntiAlias", TextAntiAliasImage);
    Nan::SetPrototypeMethod(ctor, "textDirection", TextDirectionImage);
    Nan::SetPrototypeMethod(ctor, "textGravity", TextGravityImage);
    Nan::SetPrototypeMethod(ctor, "textInterlineSpacing", TextInterlineSpacingImage);
    Nan::SetPrototypeMethod(ctor, "textInterwordSpacing", TextInterwordSpacingImage);
    Nan::SetPrototypeMethod(ctor, "textKerning", TextKerningImage);
    Nan::SetPrototypeMethod(ctor, "textUnderColor", TextUnderColorImage);
    Nan::SetPrototypeMethod(ctor, "texture", TextureImage);
    Nan::SetPrototypeMethod(ctor, "thumbnail", ThumbnailImage);
    Nan::SetPrototypeMethod(ctor, "tint", TintImage);
    Nan::SetPrototypeMethod(ctor, "toBase64", ToBase64Image);
    Nan::SetPrototypeMethod(ctor, "toBuffer", ToBufferImage);
    Nan::SetPrototypeMethod(ctor, "transformOrigin", TransformOriginImage);
    Nan::SetPrototypeMethod(ctor, "transformReset", TransformResetImage);
    Nan::SetPrototypeMethod(ctor, "transformRotation", TransformRotationImage);
    Nan::SetPrototypeMethod(ctor, "transformScale", TransformScaleImage);
    Nan::SetPrototypeMethod(ctor, "transformSkewX", TransformSkewXImage);
    Nan::SetPrototypeMethod(ctor, "transformSkewY", TransformSkewYImage);
    Nan::SetPrototypeMethod(ctor, "transparent", TransparentImage);
    Nan::SetPrototypeMethod(ctor, "transparentChroma", TransparentChromaImage);
    Nan::SetPrototypeMethod(ctor, "transpose", TransposeImage);
    Nan::SetPrototypeMethod(ctor, "transverse", TransverseImage);
    Nan::SetPrototypeMethod(ctor, "trim", TrimImage);
    Nan::SetPrototypeMethod(ctor, "unsharpmask", UnsharpmaskImage);
    Nan::SetPrototypeMethod(ctor, "unsharpmaskChannel", UnsharpmaskChannelImage);
    Nan::SetPrototypeMethod(ctor, "verbose", VerboseImage);
    Nan::SetPrototypeMethod(ctor, "vignette", VignetteImage);
    Nan::SetPrototypeMethod(ctor, "virtualPixel", VirtualPixelImage);
    Nan::SetPrototypeMethod(ctor, "wave", WaveImage);
    Nan::SetPrototypeMethod(ctor, "waveletDenoise", WaveletDenoiseImage);
    Nan::SetPrototypeMethod(ctor, "whiteThreshold", WhiteThresholdImage);
    Nan::SetPrototypeMethod(ctor, "whiteThresholdChannel", WhiteThresholdChannelImage);
    Nan::SetPrototypeMethod(ctor, "write", WriteImage);
    Nan::SetPrototypeMethod(ctor, "writeFrames", WriteFramesImage);
    Nan::SetPrototypeMethod(ctor, "zoom", ZoomImage);

    v8::Local<v8::Context> ctx = Nan::GetCurrentContext();
    
    Nan::Set(target, Nan::New("EffectsNative").ToLocalChecked(), ctor->GetFunction(ctx).ToLocalChecked());
}

NAN_METHOD(EffectsNative::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Class constructors cannot be invoked without 'new'");
    } 
    
    EffectsNative* kEffectNative = new EffectsNative;
    
    if (info.Length() == 1) {
        if (info[0]->IsString()) {
            Nan::Utf8String strUtf8(info[0]); 
            kEffectNative = new EffectsNative(*strUtf8);
        }
        else if (node::Buffer::HasInstance(info[0])) {
            kEffectNative = new EffectsNative(node::Buffer::Data(info[0]), node::Buffer::Length(info[0]));
        }
    } else if (info.Length() >= 4) {
        int w, h;
        std::string format = "RGB";
        const char* buf = 0;
        if (info[0]->IsNumber()) {
            w = Nan::To<int>(info[0]).FromMaybe(0);
        } else { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked());
            return;
        }
        if (info[1]->IsNumber()) {
            h = Nan::To<int>(info[1]).FromMaybe(0);
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked());
            return;
        }
        if (info[2]->IsString()) {
            Nan::Utf8String strUtf8(info[2]); 
            format = *strUtf8;
        } else { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"format\"").ToLocalChecked());
            return;
        }
        if (node::Buffer::HasInstance(info[3])) {
            buf = node::Buffer::Data(info[3]);
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"buffer\"").ToLocalChecked());
            return;
        }

        kEffectNative = new EffectsNative(w, h, format, buf); 
    }

    kEffectNative->Wrap(info.This()); 
    
    info.GetReturnValue().Set(info.This()); 
}

EffectsNative::EffectsNative() {
    try {
        this->image = Magick::Image();
    } catch (Magick::Exception& err_) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err_.what()).ToLocalChecked());
    } 
    catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Error laod image").ToLocalChecked());
    }
}

EffectsNative::EffectsNative(const char* buf, size_t length) {
    try {
        this->image = Magick::Image(Magick::Blob(buf, length));
    }
    catch (Magick::Exception& err_) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err_.what()).ToLocalChecked());
    } 
    catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Error laod image").ToLocalChecked());
    }
}

EffectsNative::EffectsNative(std::string file) {
    try {
        this->image = Magick::Image(file); 
    } catch (Magick::Exception& err_) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err_.what()).ToLocalChecked());
    }
    catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Error laod image").ToLocalChecked());
    }
}

EffectsNative::EffectsNative(int w, int h, std::string format, const char* buf) {
    try {
        this->image = Magick::Image(w, h, format, Magick::StorageType::CharPixel, buf); 
    } catch (Magick::Exception& err_) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err_.what()).ToLocalChecked());
    }
    catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Error laod image").ToLocalChecked());
    }
}

int EffectsNative::width() {
    return this->image.columns();
}

int EffectsNative::height() {
    return this->image.rows();
}  

void EffectsNative::addImage(int x, int y, int w, int h, EffectsNative* source) { 
    if (!source) {
        return;
    }
    Magick::DrawableCompositeImage composite_(x, y, w, h, source->image, MagickCore::CompositeOperator::OverCompositeOp); 
    this->image.draw(composite_); 
}  

void EffectsNative::addBorderColor(Magick::Color color) {
    Magick::DrawableBorderColor border_(color);
    this->image.draw(border_); 
}

void EffectsNative::addArc(int startX, int startY, int endX, int endY, int startDegrees, int endDegrees) {
    Magick::DrawableArc arc_(startX, startY, endX, endY, startDegrees, endDegrees);
    this->image.draw(arc_); 
}

void EffectsNative::addAffine(int sx, int sy, int rx, int ry, int tx, int ty) {
    Magick::DrawableAffine affine_(sx, sy, rx, ry, tx, ty);
    this->image.draw(affine_);
}

void EffectsNative::addCircle(int originX, int originY, int perimX, int perimY) {
    Magick::DrawableCircle circle_(originX, originY, perimX, perimY);
    this->image.draw(circle_);  
}