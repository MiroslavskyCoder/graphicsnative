#include "EffectsNative.h"

NAN_METHOD(EffectsNative::FloodFillAlphaImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
    try {
        if (info[0]->IsObject()) {
            v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
 
            v8::Local<v8::Value> xValue = Nan::Get(params, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> yValue = Nan::Get(params, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> alphaValue = Nan::Get(params, Nan::New<v8::String>("alpha").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> targetValue = Nan::Get(params, Nan::New<v8::String>("target").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> invertValue = Nan::Get(params, Nan::New<v8::String>("invert").ToLocalChecked()).ToLocalChecked();  

            if (!xValue->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"x\"").ToLocalChecked()); 
                return;
            }
            if (!yValue->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"y\"").ToLocalChecked()); 
                return;
            }
            if (!alphaValue->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"alpha\"").ToLocalChecked()); 
                return;
            } 

            if (targetValue->IsString()) {
                kEffectNative->image.floodFillAlpha(
                    Nan::To<int>(xValue).ToChecked(),
                    Nan::To<int>(yValue).ToChecked(),
                    Nan::To<int>(alphaValue).ToChecked(),
                    Magick::Color(*Nan::Utf8String(targetValue)),
                    Nan::To<bool>(invertValue).FromMaybe(false)
                );
            } else {
                kEffectNative->image.floodFillAlpha(
                    Nan::To<int>(xValue).ToChecked(),
                    Nan::To<int>(yValue).ToChecked(),
                    Nan::To<int>(alphaValue).ToChecked(),
                    Nan::To<bool>(invertValue).FromMaybe(false)
                );
            }
        } else {
            if (!info[0]->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"x\"").ToLocalChecked()); 
                return;
            }
            if (!info[1]->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"y\"").ToLocalChecked()); 
                return;
            }
            if (!info[2]->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"alpha\"").ToLocalChecked()); 
                return;
            }

            if (info[3]->IsString()) { 
                kEffectNative->image.floodFillAlpha( 
                    Nan::To<int>(info[0]).ToChecked(),
                    Nan::To<int>(info[1]).ToChecked(),
                    Nan::To<int>(info[2]).ToChecked(),
                    Magick::Color(*Nan::Utf8String(info[3])),
                    Nan::To<bool>(info[4]).FromMaybe(false)
                ); 
            } else { 
                kEffectNative->image.floodFillAlpha( 
                    Nan::To<int>(info[0]).ToChecked(),
                    Nan::To<int>(info[1]).ToChecked(),
                    Nan::To<int>(info[2]).ToChecked(),
                    Nan::To<bool>(info[3]).FromMaybe(false)
                ); 
            }
        }
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}