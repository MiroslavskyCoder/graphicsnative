#include "EffectsNative.h"
 
NAN_METHOD(EffectsNative::WriteImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    try {
        if (info[1]->IsString()) { 
            kEffectNative->image.magick(*Nan::Utf8String(info[1]));
        }
        if (info[0]->IsString()) { 
            kEffectNative->image.write(*Nan::Utf8String(info[0]));
        } else { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"path_save\"").ToLocalChecked()); 
        }
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}
