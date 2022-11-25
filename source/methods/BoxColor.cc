#include "EffectsNative.h"

NAN_METHOD(EffectsNative::BoxColorImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    try { 
        if (!info[0]->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"color\"").ToLocalChecked());
            return;
        } 
        kEffectNative->image.boxColor(
            Magick::Color(*Nan::Utf8String(info[0]))
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}