#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ProcessImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    if (info[0]->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
 
        v8::Local<v8::Value> moduleValue = Nan::Get(params, Nan::New<v8::String>("module").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> argsValue = Nan::Get(params, Nan::New<v8::String>("args").ToLocalChecked()).ToLocalChecked(); 
        
        if (!moduleValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"module\"").ToLocalChecked());
            return;
        }

        if (!argsValue->IsArray()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"args\"").ToLocalChecked());
            return;
        }

        v8::Local<v8::Array> argsArray = v8::Local<v8::Array>::Cast(argsValue);
        std::vector<const char*> argsVector = {};

        for (unsigned int i = 0; i < argsArray->Length(); i++ ) {
            if (Nan::Has(argsArray, i).FromJust()) { 
                v8::Local<v8::Value> value = Nan::Get(argsArray, i).ToLocalChecked();
                if (value->IsString()) {
                    argsVector.push_back(*Nan::Utf8String(value));
                }
            }
        }

        try { 
            kEffectNative->image.process(*Nan::Utf8String(moduleValue), argsVector.size(), argsVector.data()); 
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
        return;
    }

    if (!info[0]->IsString()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"module\"").ToLocalChecked());
        return;
    }

    if (!info[1]->IsArray()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"args\"").ToLocalChecked());
        return;
    }

    v8::Local<v8::Array> argsArray = v8::Local<v8::Array>::Cast(info[1]);
    std::vector<const char*> argsVector = {};

    for (unsigned int i = 0; i < argsArray->Length(); i++ ) {
        if (Nan::Has(argsArray, i).FromJust()) { 
            v8::Local<v8::Value> value = Nan::Get(argsArray, i).ToLocalChecked();
            if (value->IsString()) {
                argsVector.push_back(*Nan::Utf8String(value));
            }
        }
    }
    
    try { 
        kEffectNative->image.process(*Nan::Utf8String(info[0]), argsVector.size(), argsVector.data()); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
} 