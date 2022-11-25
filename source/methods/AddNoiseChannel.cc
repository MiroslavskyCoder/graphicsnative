#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddNoiseChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    
    if (!info[0]->IsString()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked()); 
        return;
    } 

    if (!info[1]->IsString()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"type\"").ToLocalChecked()); 
        return;
    } 

    try { 
        kEffectNative->image.addNoiseChannel(
            kEffectNative->stringToChannelType(*Nan::Utf8String(info[0])),
            kEffectNative->stringToNoiseType(*Nan::Utf8String(info[1])),
            Nan::To<int>(info[2]).FromMaybe(1.0)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }

} 