#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ClampChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    try { 
        if (!info[0]->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked());
            return;
        } 
        kEffectNative->image.clampChannel(
            kEffectNative->stringToChannelType(*Nan::Utf8String(info[0]))
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}