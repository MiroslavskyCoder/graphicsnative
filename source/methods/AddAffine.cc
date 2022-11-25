#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddAffineImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    struct AffineConfigFx { 
        int sx; int sy; 
        int rx; int ry;
        int tx; int ty;
    }; 
    AffineConfigFx _affine_c;
    if (info.Length() >= 6) {
        if (info[0]->IsNumber()) {
            _affine_c.sx = Nan::To<int>(info[0]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sx\"").ToLocalChecked()); 
            return;
        }
        if (info[1]->IsNumber()) {
            _affine_c.sy = Nan::To<int>(info[1]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"sy\"").ToLocalChecked()); 
            return;
        }
        if (info[2]->IsNumber()) {
            _affine_c.rx = Nan::To<int>(info[2]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"rx\"").ToLocalChecked()); 
            return;
        }
        if (info[3]->IsNumber()) {
            _affine_c.ry = Nan::To<int>(info[3]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"ry\"").ToLocalChecked()); 
            return;
        }
        if (info[4]->IsNumber()) {
            _affine_c.tx = Nan::To<int>(info[4]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"tx\"").ToLocalChecked()); 
            return;
        }
        if (info[5]->IsNumber()) {
            _affine_c.ty = Nan::To<int>(info[5]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"ty\"").ToLocalChecked()); 
            return;
        }
        try { 
            kEffectNative->addAffine(
                _affine_c.sx, _affine_c.sy,
                _affine_c.rx, _affine_c.ry,
                _affine_c.tx, _affine_c.ty
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    }
} 