#include "EffectsNative.h"

NAN_METHOD(EffectsNative::StrokeMiterLimitImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"miter_limit\"").ToLocalChecked()); 
        return;
    }  

    try { 
        kEffectNative->image.strokeMiterLimit(
            Nan::To<int>(info[0]).ToChecked()
        );
        info.GetReturnValue().SetUndefined();
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}  