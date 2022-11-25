#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddPolygonImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 

    Magick::CoordinateList list_coordinates_;

    for (unsigned int a = 0; a < info.Length(); a++) {

        if (!info[a]->IsArray()) { 
            continue;
        }

        v8::Local<v8::Array> argsArray = v8::Local<v8::Array>::Cast(info[a]);

        for (unsigned int i = 0; i < argsArray->Length(); i++) {
            if (Nan::Has(argsArray, i).FromJust()) { 
                v8::Local<v8::Value> value = Nan::Get(argsArray, i).ToLocalChecked();
                if (!value->IsObject()) {
                    continue;
                }

                v8::Local<v8::Object> params = Nan::To<v8::Object>(value).ToLocalChecked();
                
                v8::Local<v8::Value> xValue = Nan::Get(params, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked();
                v8::Local<v8::Value> yValue = Nan::Get(params, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 
            
                if (!xValue->IsNumber()) {
                    continue;
                }

                if (!yValue->IsNumber()) {
                    continue;
                }

                list_coordinates_.push_back(
                    Magick::Coordinate(
                        Nan::To<int>(xValue).ToChecked(),
                        Nan::To<int>(yValue).ToChecked()
                    )
                );
            }
        }
    } 

    try { 
        kEffectNative->image.draw(
            Magick::DrawablePolygon(list_coordinates_)
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    }

}