#include "EffectsNative.h" 

NAN_METHOD(EffectsNative::StrokeDashArrayImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (!info[0]->IsArray()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"dash_array\"").ToLocalChecked()); 
        return;
    } 

    v8::Local<v8::Array> numbersArrayValue = v8::Local<v8::Array>::Cast(info[0]);
    std::vector<double> intsVector = {};

    for (unsigned int i = 0; i < numbersArrayValue->Length(); i++) {
        if (Nan::Has(numbersArrayValue, i).FromJust()) { 
            v8::Local<v8::Value> value = Nan::Get(numbersArrayValue, i).ToLocalChecked();
            if (value->IsNumber()) {
                intsVector.push_back((double)Nan::To<int>(value).ToChecked());
            }
        }
    } 

    try {
        kEffectNative->image.strokeDashArray(intsVector.data());
        info.GetReturnValue().SetUndefined();
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}  