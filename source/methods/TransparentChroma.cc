#include "EffectsNative.h"

NAN_METHOD(EffectsNative::TransparentChromaImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"low\"").ToLocalChecked()); 
        return;
    }
    if (!info[1]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"high\"").ToLocalChecked()); 
        return;
    }  

    try { 
        kEffectNative->image.transparentChroma(
            Magick::Color(*Nan::Utf8String(info[0])),
            Magick::Color(*Nan::Utf8String(info[1]))
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 