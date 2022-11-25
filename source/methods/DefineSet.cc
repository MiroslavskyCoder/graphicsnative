#include "EffectsNative.h"

NAN_METHOD(EffectsNative::DefineSetImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    
    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"magick\"").ToLocalChecked()); 
        return;
    }
    
    if (!info[1]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"key\"").ToLocalChecked()); 
        return;
    } 
    try { 
        kEffectNative->image.defineSet(
            *Nan::Utf8String(info[0]),
            *Nan::Utf8String(info[1]),
            Nan::To<bool>(info[2]).FromMaybe(false)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 