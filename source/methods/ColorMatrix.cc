#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ColorMatrixImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  

    if (info[0]->IsObject()) {

        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
 
        v8::Local<v8::Value> orderValue = Nan::Get(params, Nan::New<v8::String>("order").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> matrixValue = Nan::Get(params, Nan::New<v8::String>("matrix").ToLocalChecked()).ToLocalChecked(); 

        if (!orderValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"order\"").ToLocalChecked());
            return;
        }
        
        if (!matrixValue->IsArray()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"matrix\"").ToLocalChecked());
            return;
        }

        v8::Local<v8::Array> matrixArray = v8::Local<v8::Array>::Cast(matrixValue);
        std::vector<double> matrixVector = {};

        for (unsigned int i = 0; i < matrixArray->Length(); i++ ) {
            if (Nan::Has(matrixArray, i).FromJust()) { 
                v8::Local<v8::Value> value = Nan::Get(matrixArray, i).ToLocalChecked();
                if (value->IsNumber()) {
                    matrixVector.push_back(
                        static_cast<double>(Nan::To<int>(value).ToChecked())
                    );
                }
            }
        }

        try { 
            kEffectNative->image.colorMatrix(
                Nan::To<int>(orderValue).ToChecked(),
                matrixVector.data()
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 

        return;   
    } 
    
    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"order\"").ToLocalChecked());
        return;
    }
    
    if (!info[1]->IsArray()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"matrix\"").ToLocalChecked());
        return;
    }

    v8::Local<v8::Array> matrixArray = v8::Local<v8::Array>::Cast(info[1]);
    std::vector<double> matrixVector = {};

    for (unsigned int i = 0; i < matrixArray->Length(); i++ ) {
        if (Nan::Has(matrixArray, i).FromJust()) { 
            v8::Local<v8::Value> value = Nan::Get(matrixArray, i).ToLocalChecked();
            if (value->IsNumber()) {
                matrixVector.push_back(
                    static_cast<double>(Nan::To<int>(value).ToChecked())
                );
            }
        }
    }

    try { 
        kEffectNative->image.colorMatrix(
            Nan::To<int>(info[0]).ToChecked(),
            matrixVector.data()
        ); 
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}