#include "EffectsNative.h"

NAN_METHOD(EffectsNative::FxImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"expression\"").ToLocalChecked()); 
        return;
    } 

    if (info[1]->IsString()) {
        try {  
            kEffectNative->image.fx(
                *Nan::Utf8String(info[0]), 
                kEffectNative->stringToChannelType(*Nan::Utf8String(info[1]))
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }  

    } else {
        try {
            kEffectNative->image.fx(*Nan::Utf8String(info[0]));
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    }    
}