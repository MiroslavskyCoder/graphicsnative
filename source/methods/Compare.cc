#include "EffectsNative.h"

NAN_METHOD(EffectsNative::CompareImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  
    try {
        if (!info[0]->IsObject()) { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        } 

        v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
            return;
        } 

        if (info[1]->IsString()) { 
            if (info[2]->IsArray()) { 
                v8::Local<v8::Array> numbersArray = v8::Local<v8::Array>::Cast(info[2]);
                std::vector<double> numbersVector = {};

                for (unsigned int i = 0; i < numbersArray->Length(); i++) {
                    if (Nan::Has(numbersArray, i).FromJust()) { 
                        v8::Local<v8::Value> value = Nan::Get(numbersArray, i).ToLocalChecked();
                        if (value->IsNumber()) {
                            numbersVector.push_back(
                                static_cast<double>(Nan::To<int>(value).ToChecked())
                            );
                        }
                    }
                }

                kEffectNative->image.compare(
                    Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
                    kEffectNative->stringToMetricType(*Nan::Utf8String(info[1])),
                    numbersVector.data()
                );
            } else { 
                kEffectNative->image.compare(
                    Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
                    kEffectNative->stringToMetricType(*Nan::Utf8String(info[1]))
                );
            }
        } else {
            kEffectNative->image.compare(
                Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image
            );
        }
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }  
} 