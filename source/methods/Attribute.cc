#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AttributeImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (info[0]->IsObject()) {

        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> keyValue = Nan::Get(params, Nan::New<v8::String>("key").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> valueValue = Nan::Get(params, Nan::New<v8::String>("value").ToLocalChecked()).ToLocalChecked();
            
        if (keyValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"key\"").ToLocalChecked()); 
            return; 
        }
        
        if (valueValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"value\"").ToLocalChecked()); 
            return; 
        }

        try { 
            kEffectNative->image.attribute(
                *Nan::Utf8String(keyValue),
                *Nan::Utf8String(valueValue)
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
        
        return;
    }

    if (info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"key\"").ToLocalChecked()); 
        return; 
    }
    
    if (info[1]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"value\"").ToLocalChecked()); 
        return; 
    }

    try { 
        kEffectNative->image.attribute(
            *Nan::Utf8String(info[0]),
            *Nan::Utf8String(info[1])
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}