#include "EffectsNative.h"

NAN_METHOD(EffectsNative::MedianFilterImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    
    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"radius\"").ToLocalChecked()); 
        return;
    } 
     
    try { 
        kEffectNative->image.medianFilter(
            Nan::To<int>(info[0]).FromMaybe(1.0)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 