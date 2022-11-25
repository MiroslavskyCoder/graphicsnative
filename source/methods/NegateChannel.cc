#include "EffectsNative.h"

NAN_METHOD(EffectsNative::NegateChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked());
        return;
    } 

    try { 
        kEffectNative->image.negateChannel(
            kEffectNative->stringToChannelType(
                *Nan::Utf8String(info[0])
            ),
            Nan::To<bool>(info[1]).FromMaybe(false)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}