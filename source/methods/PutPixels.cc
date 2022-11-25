#include "EffectsNative.h"

NAN_METHOD(EffectsNative::PutPixelsImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
    
    try {
        if (!node::Buffer::HasInstance(info[0])) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"pixels\"").ToLocalChecked());
            return;
        }

        kEffectNative->image.writePixels(MagickCore::QuantumType::RGBQuantum, (unsigned char*)node::Buffer::Data(info[0]));
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
}