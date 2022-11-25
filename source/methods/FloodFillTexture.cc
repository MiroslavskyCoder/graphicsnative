#include "EffectsNative.h"

NAN_METHOD(EffectsNative::FloodFillTextureImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
    
    try {
        if (!info[0]->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"point\"").ToLocalChecked());
            return;
        }
        if (!info[1]->IsObject()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        }

        v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[1]).ToLocalChecked();

        if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        } 
        
        if (info[2]->IsString()) {
            kEffectNative->image.floodFillTexture(
                Magick::Geometry(*Nan::Utf8String(info[0])),
                Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
                Magick::Color(*Nan::Utf8String(info[2])),
                Nan::To<bool>(info[3]).FromMaybe(false)
            ); 
        } else {
            kEffectNative->image.floodFillTexture(
                Magick::Geometry(*Nan::Utf8String(info[0])),
                Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
                Nan::To<bool>(info[2]).FromMaybe(false)
            ); 
        }
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
    // kEffectNative->image.floodFillTexture()
}