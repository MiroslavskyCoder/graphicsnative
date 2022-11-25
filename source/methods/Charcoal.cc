#include "EffectsNative.h"

NAN_METHOD(EffectsNative::CharcoalImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"radius\"").ToLocalChecked()); 
        return;
    }
    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sigma\"").ToLocalChecked()); 
        return;
    }

    try { 
        kEffectNative->image.charcoal(
            Nan::To<int>(info[0]).ToChecked(),
            Nan::To<int>(info[1]).ToChecked() 
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}