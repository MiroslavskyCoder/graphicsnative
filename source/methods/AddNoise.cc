#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddNoiseImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    
    if (!info[0]->IsString()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"type\"").ToLocalChecked()); 
        return;
    } 

    try { 
        kEffectNative->image.addNoise(
            kEffectNative->stringToNoiseType(*Nan::Utf8String(info[0])),
            Nan::To<int>(info[1]).FromMaybe(1.0)
        ); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }

} 