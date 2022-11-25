#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AdaptiveResizeImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    SizesOptions sizes(0, 0);

   if (info[0]->IsString()) { 
        try {
            kEffectNative->image.adaptiveResize(Magick::Geometry(*Nan::Utf8String(info[0])));
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    }
    else if (info[0]->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> valueValue = Nan::Get(params, Nan::New<v8::String>("value").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> widthValue = Nan::Get(params, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> heightValue = Nan::Get(params, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> xValue = Nan::Get(params, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> yValue = Nan::Get(params, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 

        if (valueValue->IsString()) {
            try {
                kEffectNative->image.adaptiveResize(Magick::Geometry(*Nan::Utf8String(valueValue)));
            } catch (Magick::Exception& err) {
                Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
            } catch (...) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
            } 
            return;
        }

        if (!widthValue->IsNumber()) {
            return;
        }

        if (!heightValue->IsNumber()) {
            return;
        } 

        try { 
            kEffectNative->image.adaptiveResize(Magick::Geometry(
                Nan::To<int>(widthValue).ToChecked(),
                Nan::To<int>(heightValue).ToChecked(),
                Nan::To<int>(xValue).FromMaybe(0),
                Nan::To<int>(yValue).FromMaybe(0)
            ));
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 

        return;
    }
    else if (info[0]->IsNumber() && info[1]->IsNumber()) {
        sizes.w = Nan::To<int>(info[0]).ToChecked();
        sizes.h = Nan::To<int>(info[1]).ToChecked();
    } else {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\", \"height\"").ToLocalChecked()); 
        return;
    }
    if (info[2]->IsNumber()) {
        sizes.x = Nan::To<int>(info[2]).FromMaybe(0);
    }
    if (info[3]->IsNumber()) {
        sizes.y = Nan::To<int>(info[3]).FromMaybe(0);
    }
    try { 
        kEffectNative->image.adaptiveResize(Magick::Geometry(sizes.w, sizes.h, sizes.x, sizes.y)); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}