#include "EffectsNative.h"

NAN_METHOD(EffectsNative::BoundingBoxImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    try { 
        Magick::Geometry box = kEffectNative->image.boundingBox();
        v8::Local<v8::Object> kGeometryObject = Nan::New<v8::Object>();

        Nan::Set(kGeometryObject, Nan::New<v8::String>("limitPixels").ToLocalChecked(), Nan::New<v8::Boolean>(box.limitPixels())); 
        Nan::Set(kGeometryObject, Nan::New<v8::String>("less").ToLocalChecked(), Nan::New<v8::Boolean>(box.less())); 
        Nan::Set(kGeometryObject, Nan::New<v8::String>("width").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(box.width()))); 
        Nan::Set(kGeometryObject, Nan::New<v8::String>("height").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(box.height()))); 
        Nan::Set(kGeometryObject, Nan::New<v8::String>("x").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(box.xOff())));
        Nan::Set(kGeometryObject, Nan::New<v8::String>("y").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(box.yOff()))); 

        info.GetReturnValue().Set(kGeometryObject);
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}