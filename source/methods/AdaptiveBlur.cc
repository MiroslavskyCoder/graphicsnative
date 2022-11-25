#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AdaptiveBlurImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    if (info[0]->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> radiusValue = Nan::Get(params, Nan::New<v8::String>("radius").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> sigmaValue = Nan::Get(params, Nan::New<v8::String>("sigma").ToLocalChecked()).ToLocalChecked();

        try { 
            kEffectNative->image.adaptiveBlur(
                Nan::To<int>(radiusValue).FromMaybe(0),
                Nan::To<int>(sigmaValue).FromMaybe(0) 
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    } else {
        try {
            kEffectNative->image.adaptiveBlur(
                Nan::To<int>(info[0]).FromMaybe(0),
                Nan::To<int>(info[1]).FromMaybe(1)
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    }
}