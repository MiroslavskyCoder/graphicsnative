#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AdaptiveThresholdImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
 
    if (info[0]->IsObject()) { 
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> widthValue = Nan::Get(params, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> heightValue = Nan::Get(params, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> biasValue = Nan::Get(params, Nan::New<v8::String>("bias").ToLocalChecked()).ToLocalChecked(); 

        if (!widthValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
            return;
        }

        if (!heightValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked()); 
            return;
        }

        try { 
            kEffectNative->image.adaptiveThreshold(
                Nan::To<int>(widthValue).ToChecked(),
                Nan::To<int>(heightValue).ToChecked(),
                Nan::To<int>(biasValue).FromMaybe(0)
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 

        return; 
    }

    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
        return;
    }

    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked()); 
        return;
    }

    try { 
        kEffectNative->image.adaptiveThreshold(
            Nan::To<int>(info[0]).ToChecked(),
            Nan::To<int>(info[1]).ToChecked(),
            Nan::To<int>(info[2]).FromMaybe(0)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 

}