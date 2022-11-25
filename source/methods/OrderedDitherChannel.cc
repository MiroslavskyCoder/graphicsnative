#include "EffectsNative.h"

NAN_METHOD(EffectsNative::OrderedDitherChannelImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    if (!info[0]->IsObject()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"channel\"").ToLocalChecked()); 
        return;
    } 
    if (!info[1]->IsObject()) { 
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"thresholdMap\"").ToLocalChecked()); 
        return;
    } 
    try {
        kEffectNative->image.orderedDitherChannel( 
            kEffectNative->stringToChannelType(
                *Nan::Utf8String(info[0])
            ),
            *Nan::Utf8String(info[1])
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}