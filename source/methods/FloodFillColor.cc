#include "EffectsNative.h"

NAN_METHOD(EffectsNative::FloodFillColorImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    try {
        if (info[0]->IsObject()) {
            v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

            v8::Local<v8::Value> pointValue = Nan::Get(params, Nan::New<v8::String>("point").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> fillColorValue = Nan::Get(params, Nan::New<v8::String>("fillColor").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> borderColorValue = Nan::Get(params, Nan::New<v8::String>("borderColor").ToLocalChecked()).ToLocalChecked();  
            v8::Local<v8::Value> invertValue = Nan::Get(params, Nan::New<v8::String>("invert").ToLocalChecked()).ToLocalChecked(); 
            
            Magick::Geometry point;

            if (pointValue->IsString()) {
                point = Magick::Geometry(*Nan::Utf8String(pointValue));
            }
            else if (pointValue->IsObject()) {
                v8::Local<v8::Object> paramsPoint = Nan::To<v8::Object>(pointValue).ToLocalChecked();

                v8::Local<v8::Value> widthPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked(); 
                v8::Local<v8::Value> heightPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked(); 
                v8::Local<v8::Value> xPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked(); 
                v8::Local<v8::Value> yPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 

                point = Magick::Geometry(
                    Nan::To<int>(widthPointValue).FromMaybe(0),
                    Nan::To<int>(heightPointValue).FromMaybe(0),
                    Nan::To<int>(xPointValue).FromMaybe(0),
                    Nan::To<int>(yPointValue).FromMaybe(0)
                );
            } else {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"point\"").ToLocalChecked()); 
                return;
            }

            if (!fillColorValue->IsString()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"fillColor\"").ToLocalChecked()); 
                return;
            }
 
            if (borderColorValue->IsString()) {
                kEffectNative->image.floodFillColor(
                    point,
                    Magick::Color(*Nan::Utf8String(fillColorValue)),
                    Magick::Color(*Nan::Utf8String(borderColorValue)),
                    Nan::To<bool>(invertValue).FromMaybe(false)
                );
            } else {
                kEffectNative->image.floodFillColor(
                    point,
                    Magick::Color(*Nan::Utf8String(fillColorValue)),
                    Nan::To<bool>(invertValue).FromMaybe(false)
                );
            }
        } else {
            Magick::Geometry point;

            if (info[0]->IsString()) {
                point = Magick::Geometry(*Nan::Utf8String(info[0]));
            }
            else if (info[0]->IsObject()) {
                v8::Local<v8::Object> paramsPoint = Nan::To<v8::Object>(info[0]).ToLocalChecked();

                v8::Local<v8::Value> widthPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked(); 
                v8::Local<v8::Value> heightPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked(); 
                v8::Local<v8::Value> xPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked(); 
                v8::Local<v8::Value> yPointValue = Nan::Get(paramsPoint, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 

                point = Magick::Geometry(
                    Nan::To<int>(widthPointValue).FromMaybe(0),
                    Nan::To<int>(heightPointValue).FromMaybe(0),
                    Nan::To<int>(xPointValue).FromMaybe(0),
                    Nan::To<int>(yPointValue).FromMaybe(0)
                );
            } else {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"point\"").ToLocalChecked()); 
                return;
            }

            if (!info[1]->IsString()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"fillColor\"").ToLocalChecked()); 
                return;
            }

            if (info[2]->IsString()) {
                kEffectNative->image.floodFillColor(
                    point,
                    Magick::Color(*Nan::Utf8String(info[1])),
                    Magick::Color(*Nan::Utf8String(info[2])),
                    Nan::To<bool>(info[3]).FromMaybe(false)
                );
            } else {
                kEffectNative->image.floodFillColor(
                    point,
                    Magick::Color(*Nan::Utf8String(info[1])),
                    Nan::To<bool>(info[2]).FromMaybe(false)
                );
            }
        }
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
}