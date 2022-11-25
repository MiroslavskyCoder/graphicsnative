#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ToBase64Image) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    try { 
        if (info[0]->IsString()) {
            kEffectNative->image.magick(*Nan::Utf8String(info[0]));
        } else {
            kEffectNative->image.magick("jpg");
        }
        Magick::Blob blobBuf; 
        kEffectNative->image.write(&blobBuf);
        info.GetReturnValue().Set(Nan::New<v8::String>(blobBuf.base64().c_str()).ToLocalChecked());
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}