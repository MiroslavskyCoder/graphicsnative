#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AnnotateImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (info[0]->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> textValue = Nan::Get(params, Nan::New<v8::String>("text").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> gravityValue = Nan::Get(params, Nan::New<v8::String>("gravity").ToLocalChecked()).ToLocalChecked();
            
        if (!textValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"text\"").ToLocalChecked()); 
            return; 
        }
        
        if (!gravityValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"gravity\"").ToLocalChecked()); 
            return; 
        }

        try { 
            kEffectNative->image.annotate(*Nan::Utf8String(textValue), kEffectNative->stringToGravityType(*Nan::Utf8String(gravityValue)));
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    
        return;
    }

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"text\"").ToLocalChecked()); 
        return; 
    }
    
    if (!info[1]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"gravity\"").ToLocalChecked()); 
        return; 
    }

    try { 
        kEffectNative->image.annotate(*Nan::Utf8String(info[0]), kEffectNative->stringToGravityType(*Nan::Utf8String(info[1])));
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}