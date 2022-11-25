#include "EffectsNative.h"

NAN_METHOD(EffectsNative::GetDataImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    std::vector<char> pixelsStr;
    try {
        kEffectNative->image.write(0, 0, kEffectNative->width(), kEffectNative->height(), "RGB", MagickCore::StorageType::CharPixel, pixelsStr.data());
        info.GetReturnValue().Set(Nan::CopyBuffer(pixelsStr.data(), pixelsStr.size()).ToLocalChecked());    
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}