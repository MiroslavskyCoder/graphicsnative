#include "EffectsNative.h"

NAN_METHOD(EffectsNative::StrokeWidthImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
        return;
    }

    try { 
        kEffectNative->image.strokeWidth(
            Nan::To<int>(info[0]).ToChecked()
        ); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}
