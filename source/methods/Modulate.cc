#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ModulateImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (info[0]->IsObject()) {
        
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> brightnessValue = Nan::Get(params, Nan::New<v8::String>("brightness").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> saturationValue = Nan::Get(params, Nan::New<v8::String>("saturation").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> hueValue = Nan::Get(params, Nan::New<v8::String>("hue").ToLocalChecked()).ToLocalChecked();  
        
        if (!brightnessValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"brightness\"").ToLocalChecked()); 
            return;
        }

        if (!saturationValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"saturation\"").ToLocalChecked()); 
            return;
        }

        if (!hueValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"hue\"").ToLocalChecked()); 
            return;
        } 

        try {  
            kEffectNative->image.modulate(
                Nan::To<int>(brightnessValue).ToChecked(),
                Nan::To<int>(saturationValue).ToChecked(),
                Nan::To<int>(hueValue).ToChecked()
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
        
        return;
    }
 
    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"brightness\"").ToLocalChecked()); 
        return;
    }

    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"saturation\"").ToLocalChecked()); 
        return;
    }

    if (!info[2]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"hue\"").ToLocalChecked()); 
        return;
    } 

    try {  
        kEffectNative->image.modulate(
            Nan::To<int>(info[0]).ToChecked(),
            Nan::To<int>(info[1]).ToChecked(),
            Nan::To<int>(info[2]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 