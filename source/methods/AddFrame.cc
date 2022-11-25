#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddFrameImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    
    if (!info[0]->IsObject()) {
        kEffectNative->frames.push_back(kEffectNative->image);
        return;
    }

    v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();

    if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
        kEffectNative->frames.push_back(kEffectNative->image);
        return;
    } 
    
    kEffectNative->frames.push_back(
        Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image
    );
} 
