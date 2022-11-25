#include "EffectsNative.h"

NAN_METHOD(EffectsNative::StrokeDashOffsetImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"dash_offset\"").ToLocalChecked()); 
        return;
    }  

    try {
        kEffectNative->image.strokeDashOffset(
            Nan::To<int>(info[0]).ToChecked()
        );
        info.GetReturnValue().SetUndefined();
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}  