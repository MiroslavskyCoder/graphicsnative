#include "EffectsNative.h"

NAN_METHOD(EffectsNative::QuantizeImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    try {
        kEffectNative->image.quantize(
            Nan::To<bool>(info[0]).FromMaybe(false)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}