#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ChannelDepthImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked());
        return;
    }
    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"depth\"").ToLocalChecked());
        return;
    }

    try { 
        kEffectNative->image.channelDepth(
            kEffectNative->stringToChannelType(*Nan::Utf8String(info[0])),
            Nan::To<int>(info[1]).ToChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}