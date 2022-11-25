#include "EffectsNative.h"

NAN_METHOD(EffectsNative::RenderingIntentImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"type\"").ToLocalChecked()); 
        return;
    }
 
    try { 
        kEffectNative->image.renderingIntent(
            kEffectNative->stringToRenderingIntent(
                *Nan::Utf8String(info[0])
            )
        );
        info.GetReturnValue().SetUndefined();
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
}