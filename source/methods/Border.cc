#include "EffectsNative.h"

NAN_METHOD(EffectsNative::BorderImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
    SizesOptions sizes(0, 0);

    if (info.Length() == 1) {
        if (info[0]->IsString()) { 
            try { 
                kEffectNative->image.border(Magick::Geometry(std::string(*Nan::Utf8String(info[0]))));
            } catch (Magick::Exception& err) {
                Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
            } catch (...) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
            } 
        }
    }
    else if (info.Length() >= 2) {
        if (info[0]->IsNumber() && info[1]->IsNumber()) {
            sizes.w = Nan::To<int>(info[0]).ToChecked();
            sizes.h = Nan::To<int>(info[1]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"w\", \"h\"").ToLocalChecked()); 
            return;
        }
        if (info[2]->IsNumber()) {
            sizes.x = Nan::To<int>(info[2]).FromMaybe(0);
        }
        if (info[3]->IsNumber()) {
            sizes.y = Nan::To<int>(info[3]).FromMaybe(0);
        }

        try { 
            kEffectNative->image.border(Magick::Geometry(sizes.w, sizes.h, sizes.x, sizes.y)); 
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    } 
} 
