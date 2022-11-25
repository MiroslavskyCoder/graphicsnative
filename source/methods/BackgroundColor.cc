#include "EffectsNative.h"

NAN_METHOD(EffectsNative::BackgroundColorImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
  
    try { 
        if (!info[0]->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"color\"").ToLocalChecked()); 
            return;
        }       
        kEffectNative->image.backgroundColor(
            Magick::Color(*Nan::Utf8String(info[0]))
        ); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
}