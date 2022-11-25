#include "EffectsNative.h"

NAN_METHOD(EffectsNative::QualityImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    try { 
        if (!info[0]->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"quality\"").ToLocalChecked()); 
            return;
        } 
        kEffectNative->image.quality(
            Nan::To<int>(info[0]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}