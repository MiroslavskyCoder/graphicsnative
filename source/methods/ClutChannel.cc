#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ClutChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
 
    if (!info[0]->IsString()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked()); 
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

    if (!info[2]->IsString()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"pixel_interpolate\"").ToLocalChecked()); 
        return;
    } 

    try { 
        kEffectNative->image.clutChannel(
            kEffectNative->stringToChannelType(*Nan::Utf8String(info[0])),
            Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
            kEffectNative->stringToPixelInterpolateMethod(*Nan::Utf8String(info[2]))
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 