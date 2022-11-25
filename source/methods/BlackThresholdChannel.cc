#include "EffectsNative.h"

NAN_METHOD(EffectsNative::BlackThresholdChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked()); 
        return;
    }
    
    if (!info[1]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"threshold\"").ToLocalChecked()); 
        return;
    }

    try { 
        kEffectNative->image.blackThresholdChannel(
            kEffectNative->stringToChannelType(*Nan::Utf8String(info[0])),
            *Nan::Utf8String(info[1])
        ); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 