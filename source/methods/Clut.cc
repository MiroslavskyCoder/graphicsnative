#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ClutImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  

    try {     
        if (!info[0]->IsObject()) { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        }

        v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        } 

        if (!info[1]->IsString()) { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"pixel_interpolate\"").ToLocalChecked()); 
            return;
        }
        kEffectNative->image.clut(
            Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
            kEffectNative->stringToPixelInterpolateMethod(*Nan::Utf8String(info[1]))
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }  
} 