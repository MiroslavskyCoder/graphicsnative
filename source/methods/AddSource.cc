#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddSourceImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (info[0]->IsObject()) {

        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
            
        v8::Local<v8::Value> xValue = Nan::Get(params, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> yValue = Nan::Get(params, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> widthValue = Nan::Get(params, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> heightValue = Nan::Get(params, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> sourceValue = Nan::Get(params, Nan::New<v8::String>("source").ToLocalChecked()).ToLocalChecked();

        if (!xValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"x\"").ToLocalChecked()); 
            return;
        }

        if (!yValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"y\"").ToLocalChecked()); 
            return;
        }

        if (!widthValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
            return;
        }

        if (!heightValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked()); 
            return;
        }
        
        if (!sourceValue->IsObject()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        }
        
        v8::Local<v8::Object> obj = Nan::To<v8::Object>(sourceValue).ToLocalChecked();

        if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        } 

        try { 
            kEffectNative->addImage(
                Nan::To<int>(xValue).ToChecked(),
                Nan::To<int>(yValue).ToChecked(),
                Nan::To<int>(widthValue).ToChecked(),
                Nan::To<int>(heightValue).ToChecked(),
                Nan::ObjectWrap::Unwrap<EffectsNative>(obj)
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }
  
        return;
    }

    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"x\"").ToLocalChecked()); 
        return;
    }

    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"y\"").ToLocalChecked()); 
        return;
    }

    if (!info[2]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
        return;
    }

    if (!info[3]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked()); 
        return;
    }
    
    if (!info[4]->IsObject()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
        return;
    }

    
    v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[4]).ToLocalChecked();

    if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
        return;
    } 

    try { 
        kEffectNative->addImage(
            Nan::To<int>(info[0]).ToChecked(),
            Nan::To<int>(info[1]).ToChecked(),
            Nan::To<int>(info[2]).ToChecked(),
            Nan::To<int>(info[3]).ToChecked(),
            Nan::ObjectWrap::Unwrap<EffectsNative>(obj)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }
}