#include "EffectsNative.h"

NAN_METHOD(EffectsNative::GetStrokeWidthImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    int _strokeWidth = static_cast<int>(kEffectNative->image.strokeWidth());
    info.GetReturnValue().Set(Nan::New<v8::Number>(_strokeWidth));
}
 