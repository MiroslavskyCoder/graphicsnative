#include "EffectsNative.h"

NAN_METHOD(EffectsNative::VerboseImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
    
    if (!info[0]->IsBoolean()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"flag\"").ToLocalChecked()); 
        return;
    } 

    try { 
        kEffectNative->image.verbose(
            Nan::To<bool>(info[0]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 