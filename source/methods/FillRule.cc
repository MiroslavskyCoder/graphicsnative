#include "EffectsNative.h"

NAN_METHOD(EffectsNative::FillRuleImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    
    if (!info[0]->IsString()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"type\"").ToLocalChecked()); 
        return;
    } 

    try { 
        kEffectNative->image.fillRule(
            kEffectNative->stringToFillRule(*Nan::Utf8String(info[0]))
        ); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 

} 