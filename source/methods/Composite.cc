#include "EffectsNative.h"

NAN_METHOD(EffectsNative::CompositeImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    if (info.Length() >= 3) { 
        std::string type = *Nan::Utf8String(info[0]);
        if (type == "gravity") {
            if (
                info[1]->IsObject(),
                info[2]->IsString()
            ) {
                v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[1]).ToLocalChecked();

                if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
                    return;
                } 

                try { 
                    kEffectNative->image.composite(
                        Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
                        kEffectNative->stringToGravityType(*Nan::Utf8String(info[2]))
                    );
                } catch (Magick::Exception& err) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                } catch (...) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                } 
            }
        } else if (type == "geometry") {
            if (
                info[1]->IsObject(),
                info[2]->IsString()
            ) {
                v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[1]).ToLocalChecked();

                if (!Nan::New(EffectsNative::constructor)->HasInstance(obj)) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"source\"").ToLocalChecked()); 
                    return;
                } 

                try { 
                    kEffectNative->image.composite(
                        Nan::ObjectWrap::Unwrap<EffectsNative>(obj)->image,
                        Magick::Geometry(*Nan::Utf8String(info[2]))
                    );
                } catch (Magick::Exception& err) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                } catch (...) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                } 
 
            }
        } 
    } 
}