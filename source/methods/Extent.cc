#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ExtentImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (info.Length() == 1) {
        if (info[0]->IsString()) { 
            try {  
                kEffectNative->image.extent(Magick::Geometry(std::string(*Nan::Utf8String(info[0]))));
            } catch (Magick::Exception& err) {
                Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
            } catch (...) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
            } 
        } else if (info[0]->IsObject()) {
            v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

            v8::Local<v8::Value> valueValue = Nan::Get(params, Nan::New<v8::String>("value").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> widthValue = Nan::Get(params, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> heightValue = Nan::Get(params, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> xValue = Nan::Get(params, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked(); 
            v8::Local<v8::Value> yValue = Nan::Get(params, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 

            if (valueValue->IsString()) {
                kEffectNative->image.extent(Magick::Geometry(*Nan::Utf8String(valueValue)));
                return;
            }
 
            if (!widthValue->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
                return;
            }

            if (!heightValue->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked()); 
                return;
            }

            try { 
                kEffectNative->image.extent(Magick::Geometry(
                    Nan::To<int>(widthValue).ToChecked(),
                    Nan::To<int>(heightValue).ToChecked(),
                    Nan::To<int>(xValue).FromMaybe(0),
                    Nan::To<int>(yValue).FromMaybe(0)
                ));
            } catch (Magick::Exception& err) {
                Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
            } catch (...) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
            } 
            
            return;
        }
    }
    else if (info.Length() >= 2) {
        if (!info[0]->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
            return;
        }

        if (!info[1]->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked()); 
            return;
        }

        try {  
            kEffectNative->image.extent(
                Magick::Geometry( 
                    Nan::To<int>(info[0]).ToChecked(),
                    Nan::To<int>(info[1]).ToChecked(),
                    Nan::To<int>(info[2]).FromMaybe(0),
                    Nan::To<int>(info[3]).FromMaybe(0)
                )
            ); 
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
 
    }
}