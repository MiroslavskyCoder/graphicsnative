#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddCircleImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    struct CircleConfigFx {
        int originX; int originY; 
        int perimX; int perimY;
    };
    CircleConfigFx _circle_c;
    
    if (info.Length() >= 4) {
        if (info[0]->IsNumber()) {
            _circle_c.originX = Nan::To<int>(info[0]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"originX\"").ToLocalChecked()); 
            return;
        }
        if (info[1]->IsNumber()) {
            _circle_c.originY = Nan::To<int>(info[1]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"originY\"").ToLocalChecked()); 
            return;
        }
        if (info[2]->IsNumber()) {
            _circle_c.perimX = Nan::To<int>(info[2]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"perimX\"").ToLocalChecked()); 
            return;
        }
        if (info[3]->IsNumber()) {
            _circle_c.perimY = Nan::To<int>(info[3]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"perimY\"").ToLocalChecked()); 
            return;
        }

        try { 
            kEffectNative->addCircle(
                _circle_c.originX, _circle_c.originY,
                _circle_c.perimX, _circle_c.perimY
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }
    }
}
 