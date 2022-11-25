#include "EffectsNative.h"

NAN_METHOD(EffectsNative::StrokeColorImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"color\"").ToLocalChecked()); 
        return;
    } 

    try {
        kEffectNative->image.strokeColor(
            Magick::Color(*Nan::Utf8String(info[0]))
        );
        info.GetReturnValue().SetUndefined();
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}  