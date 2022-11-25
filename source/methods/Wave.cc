#include "EffectsNative.h"

NAN_METHOD(EffectsNative::WaveImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
    try {
        kEffectNative->image.wave(
            Nan::To<int>(info[0]).FromMaybe(25.0),
            Nan::To<int>(info[1]).FromMaybe(150.0)
        ); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
} 