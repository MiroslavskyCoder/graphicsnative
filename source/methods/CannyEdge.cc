#include "EffectsNative.h"

NAN_METHOD(EffectsNative::CannyEdgeImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    try { 
        kEffectNative->image.cannyEdge(
            Nan::To<int>(info[0]).FromMaybe(0.0),
            Nan::To<int>(info[1]).FromMaybe(1.0),
            Nan::To<int>(info[2]).FromMaybe(0.1),
            Nan::To<int>(info[3]).FromMaybe(0.3)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 