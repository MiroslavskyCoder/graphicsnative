#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddRoundRectangleImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (info[0]->IsObject()) {
        
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> upperLeftXValue = Nan::Get(params, Nan::New<v8::String>("upperLeftX").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> upperLeftYValue = Nan::Get(params, Nan::New<v8::String>("upperLeftY").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> lowerRightXValue = Nan::Get(params, Nan::New<v8::String>("lowerRightX").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> lowerRightYValue = Nan::Get(params, Nan::New<v8::String>("lowerRightY").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> cornerWidthValue = Nan::Get(params, Nan::New<v8::String>("cornerWidth").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> cornerHeightValue = Nan::Get(params, Nan::New<v8::String>("cornerHeight").ToLocalChecked()).ToLocalChecked();

        if (!upperLeftXValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"upperLeftX\"").ToLocalChecked()); 
            return;
        }
        if (!upperLeftYValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"upperLeftY\"").ToLocalChecked()); 
            return;
        } 
        if (!lowerRightXValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"lowerRightX\"").ToLocalChecked()); 
            return;
        } 
        if (!lowerRightYValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"lowerRightY\"").ToLocalChecked()); 
            return;
        } 
        if (!cornerWidthValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"cornerWidth\"").ToLocalChecked()); 
            return;
        } 
        if (!cornerHeightValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"cornerHeight\"").ToLocalChecked()); 
            return;
        }

        Magick::DrawableRoundRectangle round_(
            Nan::To<int>(upperLeftXValue).ToChecked(),
            Nan::To<int>(upperLeftYValue).ToChecked(),
            Nan::To<int>(lowerRightXValue).ToChecked(),
            Nan::To<int>(lowerRightYValue).ToChecked(),
            Nan::To<int>(cornerWidthValue).ToChecked(),
            Nan::To<int>(cornerHeightValue).ToChecked()
        );

        kEffectNative->image.draw(round_);
        info.GetReturnValue().SetUndefined();
        return;
    }
    
    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"upperLeftX\"").ToLocalChecked()); 
        return;
    }
    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"upperLeftY\"").ToLocalChecked()); 
        return;
    } 
    if (!info[2]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"lowerRightX\"").ToLocalChecked()); 
        return;
    } 
    if (!info[3]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"lowerRightY\"").ToLocalChecked()); 
        return;
    } 
    if (!info[4]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"cornerWidth\"").ToLocalChecked()); 
        return;
    } 
    if (!info[5]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"cornerHeight\"").ToLocalChecked()); 
        return;
    }

    Magick::DrawableRoundRectangle round_(
        Nan::To<int>(info[0]).ToChecked(),
        Nan::To<int>(info[1]).ToChecked(),
        Nan::To<int>(info[2]).ToChecked(),
        Nan::To<int>(info[3]).ToChecked(),
        Nan::To<int>(info[4]).ToChecked(),
        Nan::To<int>(info[5]).ToChecked()
    );

    kEffectNative->image.draw(round_); 
    info.GetReturnValue().SetUndefined(); 
}