#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ClipPathImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"pathname\"").ToLocalChecked()); 
        return;
    }
    if (!info[1]->IsBoolean()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"inside\"").ToLocalChecked()); 
        return;
    }
    
    try { 
        kEffectNative->image.clipPath(
            *Nan::Utf8String(info[0]),
            Nan::To<bool>(info[1]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}
