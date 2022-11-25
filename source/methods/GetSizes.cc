#include "EffectsNative.h"

NAN_METHOD(EffectsNative::GetWidth) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    info.GetReturnValue().Set(Nan::New<v8::Number>(kEffectNative->width())); 
}

NAN_METHOD(EffectsNative::GetHeight) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    info.GetReturnValue().Set(Nan::New<v8::Number>(kEffectNative->height())); 
}
 