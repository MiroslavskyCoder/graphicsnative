#include "EffectsNative.h"

NAN_METHOD(EffectsNative::OpaqueImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  

    try { 
        if (info[0]->IsObject()) {
            v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

            v8::Local<v8::Value> opaqueValue = Nan::Get(params, Nan::New<v8::String>("opaque").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> penValue = Nan::Get(params, Nan::New<v8::String>("pen").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> invertValue = Nan::Get(params, Nan::New<v8::String>("invert").ToLocalChecked()).ToLocalChecked(); 
                
            if (!opaqueValue->IsString()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"opaque\"").ToLocalChecked()); 
                return;
            }
            if (!penValue->IsString()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"pen\"").ToLocalChecked()); 
                return;
            }
            if (!invertValue->IsBoolean()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"invert\"").ToLocalChecked()); 
                return;
            }
    
            try {  
                kEffectNative->image.opaque(
                    Magick::Color(*Nan::Utf8String(opaqueValue)),
                    Magick::Color(*Nan::Utf8String(penValue)),
                    Nan::To<bool>(invertValue).ToChecked()
                );
            } catch (Magick::Exception& err) {
                Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
            } catch (...) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
            } 

            return;
        }

        if (!info[0]->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"opaque\"").ToLocalChecked()); 
            return;
        }
        if (!info[1]->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"pen\"").ToLocalChecked()); 
            return;
        }
        if (!info[2]->IsBoolean()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"invert\"").ToLocalChecked()); 
            return;
        }

        kEffectNative->image.opaque(
            Magick::Color(*Nan::Utf8String(info[0])),
            Magick::Color(*Nan::Utf8String(info[1])),
            Nan::To<bool>(info[2]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 