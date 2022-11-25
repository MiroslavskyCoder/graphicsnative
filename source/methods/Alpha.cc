#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AlphaImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (info[0]->IsNumber()) {
        try { 
            kEffectNative->image.alpha((const unsigned int)Nan::To<int>(info[0]).ToChecked()); 
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    } else if (info[0]->IsBoolean()) {
        try { 
            kEffectNative->image.alpha((const bool)Nan::To<bool>(info[0]).ToChecked()); 
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    } else {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"alpha\"").ToLocalChecked()); 
    } 
} 