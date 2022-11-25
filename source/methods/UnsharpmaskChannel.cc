#include "EffectsNative.h"

NAN_METHOD(EffectsNative::UnsharpmaskChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
     
    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked());  
        return;
    }  
    
    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"radius\"").ToLocalChecked());  
        return;
    }  
    
    if (!info[2]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sigma\"").ToLocalChecked());  
        return;
    }
    
    if (!info[3]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"amount\"").ToLocalChecked()); 
        return;
    }

    if (!info[4]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"threshold\"").ToLocalChecked());  
        return;
    } 

    try { 
        kEffectNative->image.unsharpmaskChannel(
            kEffectNative->stringToChannelType(*Nan::Utf8String(info[0])),
            Nan::To<int>(info[1]).ToChecked(),
            Nan::To<int>(info[2]).ToChecked(),
            Nan::To<int>(info[3]).ToChecked(),
            Nan::To<int>(info[4]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 

} 