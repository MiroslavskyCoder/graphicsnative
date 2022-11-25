#include "EffectsNative.h"

NAN_METHOD(EffectsNative::BlurChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    if (!info[0]->IsString()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked()); 
        return;
    }
    
    try { 
        kEffectNative->image.blurChannel(
            kEffectNative->stringToChannelType(*Nan::Utf8String(info[0])),
            Nan::To<int>(info[1]).FromMaybe(0),
            Nan::To<int>(info[2]).FromMaybe(1)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}