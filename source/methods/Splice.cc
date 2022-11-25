#include "EffectsNative.h"

NAN_METHOD(EffectsNative::SpliceImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    if (info[0]->IsString()) {
        try { 
            if (info[1]->IsString()) {
                kEffectNative->image.splice(
                    Magick::Geometry(*Nan::Utf8String(info[0])),
                    Magick::Color(*Nan::Utf8String(info[1])),
                    kEffectNative->stringToGravityType(*Nan::Utf8String(info[2]))
                );
            } else {
                kEffectNative->image.splice(Magick::Geometry(*Nan::Utf8String(info[0])));
            }
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    } 
} 