#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AffineTransformImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (info[0]->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
        
        v8::Local<v8::Value> sxValue = Nan::Get(params, Nan::New<v8::String>("sx").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> syValue = Nan::Get(params, Nan::New<v8::String>("sy").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> rxValue = Nan::Get(params, Nan::New<v8::String>("rx").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> ryValue = Nan::Get(params, Nan::New<v8::String>("ry").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> txValue = Nan::Get(params, Nan::New<v8::String>("tx").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> tyValue = Nan::Get(params, Nan::New<v8::String>("ty").ToLocalChecked()).ToLocalChecked();

        if (!sxValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sx\"").ToLocalChecked()); 
            return; 
        }
        if (!syValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sy\"").ToLocalChecked()); 
            return; 
        }
        if (!rxValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"rx\"").ToLocalChecked()); 
            return; 
        }
        if (!ryValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"ry\"").ToLocalChecked()); 
            return;
        }
        if (!txValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"tx\"").ToLocalChecked()); 
            return; 
        }
        if (!tyValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"ty\"").ToLocalChecked()); 
            return; 
        } 

        try { 
            kEffectNative->image.affineTransform(
                Magick::DrawableAffine(
                    Nan::To<int>(sxValue).ToChecked(),
                    Nan::To<int>(syValue).ToChecked(),
                    Nan::To<int>(rxValue).ToChecked(),
                    Nan::To<int>(ryValue).ToChecked(),
                    Nan::To<int>(txValue).ToChecked(),
                    Nan::To<int>(tyValue).ToChecked()
                )
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 

        return;
    }

    if (!info[0]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sx\"").ToLocalChecked()); 
        return; 
    }
    if (!info[1]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sy\"").ToLocalChecked()); 
        return; 
    }
    if (!info[2]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"rx\"").ToLocalChecked()); 
        return; 
    }
    if (!info[3]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"ry\"").ToLocalChecked()); 
        return;
    }
    if (!info[4]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"tx\"").ToLocalChecked()); 
        return; 
    }
    if (!info[5]->IsNumber()) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"ty\"").ToLocalChecked()); 
        return; 
    } 

    try { 
        kEffectNative->image.affineTransform(
            Magick::DrawableAffine(
                Nan::To<int>(info[0]).ToChecked(),
                Nan::To<int>(info[1]).ToChecked(),
                Nan::To<int>(info[2]).ToChecked(),
                Nan::To<int>(info[3]).ToChecked(),
                Nan::To<int>(info[4]).ToChecked(),
                Nan::To<int>(info[5]).ToChecked()
            )
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}
