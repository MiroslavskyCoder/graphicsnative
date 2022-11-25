#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddArcImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    struct ArcConfigFx { 
        int startX; int startY; 
        int endX; int endY;
        int startDegrees; int endDegrees;
    };
    ArcConfigFx _arc_c;
    if (info.Length() >= 6) {
        if (info[0]->IsNumber()) {
            _arc_c.startX = Nan::To<int>(info[0]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"startX\"").ToLocalChecked()); 
            return;
        }
        if (info[1]->IsNumber()) {
            _arc_c.startY = Nan::To<int>(info[1]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"startY\"").ToLocalChecked()); 
            return;
        }
        if (info[2]->IsNumber()) {
            _arc_c.endX = Nan::To<int>(info[2]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"endX\"").ToLocalChecked()); 
            return;
        }
        if (info[3]->IsNumber()) {
            _arc_c.endY = Nan::To<int>(info[3]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"endY\"").ToLocalChecked()); 
            return;
        }
        if (info[4]->IsNumber()) {
            _arc_c.startDegrees = Nan::To<int>(info[4]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"startDegrees\"").ToLocalChecked()); 
            return;
        }
        if (info[5]->IsNumber()) {
            _arc_c.endDegrees = Nan::To<int>(info[5]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"endDegrees\"").ToLocalChecked()); 
            return;
        }
        try { 
            kEffectNative->addArc(
                _arc_c.startX, _arc_c.startY,
                _arc_c.endX, _arc_c.endY,
                _arc_c.startDegrees, _arc_c.endDegrees
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }
    } 
}