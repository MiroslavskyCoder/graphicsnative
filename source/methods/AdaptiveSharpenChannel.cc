#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AdaptiveSharpenChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    if (info[0]->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> channelValue = Nan::Get(params, Nan::New<v8::String>("channel").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> radiusValue = Nan::Get(params, Nan::New<v8::String>("radius").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> sigmaValue = Nan::Get(params, Nan::New<v8::String>("sigma").ToLocalChecked()).ToLocalChecked();

        if (!channelValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked()); 
            return;
        }

        try { 
            kEffectNative->image.adaptiveSharpenChannel(
                kEffectNative->stringToChannelType(*Nan::Utf8String(channelValue)),
                Nan::To<int>(radiusValue).FromMaybe(0),
                Nan::To<int>(sigmaValue).FromMaybe(0) 
            ); 
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
        
    } else if (info[0]->IsString()) { 
        try { 
            kEffectNative->image.adaptiveSharpenChannel(
                kEffectNative->stringToChannelType(*Nan::Utf8String(info[0])),
                Nan::To<int>(info[1]).FromMaybe(0),
                Nan::To<int>(info[2]).FromMaybe(1)
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    }
}
