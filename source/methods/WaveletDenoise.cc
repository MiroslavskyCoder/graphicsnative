#include "EffectsNative.h"

NAN_METHOD(EffectsNative::WaveletDenoiseImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
 
    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"threshold\"").ToLocalChecked()); 
        return;
    }
    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"softness\"").ToLocalChecked()); 
        return;
    } 
 
    try {
        kEffectNative->image.waveletDenoise(
            Nan::To<int>(info[0]).ToChecked(),
            Nan::To<int>(info[1]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
} 