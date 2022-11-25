#include "EffectsNative.h"

NAN_METHOD(EffectsNative::FillPatternImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  

    if (!info[0]->IsObject()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
        return;
    }

    v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();

    if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
        return;
    } 

    try { 
        kEffectNative->image.fillPattern(
            Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 