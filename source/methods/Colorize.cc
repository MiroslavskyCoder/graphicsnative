#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ColorizeImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());  

    Magick::Color color_(0, 0, 0);
    
    if (info[0]->IsObject()) {

        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> opacityValue = Nan::Get(params, Nan::New<v8::String>("opacity").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> opacityRedValue = Nan::Get(params, Nan::New<v8::String>("opacity_red").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> opacityGreenValue = Nan::Get(params, Nan::New<v8::String>("opacity_green").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> opacityBlueValue = Nan::Get(params, Nan::New<v8::String>("opacity_blue").ToLocalChecked()).ToLocalChecked(); 

        v8::Local<v8::Value> colorValue = Nan::Get(params, Nan::New<v8::String>("color").ToLocalChecked()).ToLocalChecked(); 
  
        if (colorValue->IsObject()) {
            v8::Local<v8::Object> colorParams = Nan::To<v8::Object>(colorValue).ToLocalChecked();
            
            v8::Local<v8::Value> rColorValue = Nan::Get(colorParams, Nan::New<v8::String>("r").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> gColorValue = Nan::Get(colorParams, Nan::New<v8::String>("g").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> bColorValue = Nan::Get(colorParams, Nan::New<v8::String>("b").ToLocalChecked()).ToLocalChecked(); 

            if (rColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Nan::To<int>(rColorValue).ToChecked(),
                    Magick::ColorRGB(color_).green(),
                    Magick::ColorRGB(color_).blue()
                );
            }
            if (gColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Magick::ColorRGB(color_).red(),
                    Nan::To<int>(gColorValue).ToChecked(),
                    Magick::ColorRGB(color_).blue()
                );
            }
            if (bColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Magick::ColorRGB(color_).red(),
                    Magick::ColorRGB(color_).green(),
                    Nan::To<int>(bColorValue).ToChecked()
                );
            }
        } else if (colorValue->IsString()) {
            color_ = Magick::Color(*Nan::Utf8String(colorValue));
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"color\"").ToLocalChecked());
            return;
        }

        if (
            opacityRedValue->IsNumber() &&
            opacityGreenValue->IsNumber() &&
            opacityBlueValue->IsNumber()
        ) {
            try { 
                kEffectNative->image.colorize(
                    Nan::To<int>(opacityRedValue).ToChecked(),
                    Nan::To<int>(opacityGreenValue).ToChecked(),
                    Nan::To<int>(opacityBlueValue).ToChecked(),
                    color_
                );
            } catch (Magick::Exception& err) {
                Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
            } catch (...) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
            } 
            return;
        }
        
        if (opacityValue->IsNumber()) { 
            try { 
                kEffectNative->image.colorize(
                    Nan::To<int>(opacityValue).ToChecked(), 
                    color_
                );
            } catch (Magick::Exception& err) {
                Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
            } catch (...) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
            } 
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"opacity\"").ToLocalChecked());
        }

        return;
    }

    if (info.Length() == 2) { 
        if (info[1]->IsObject()) {
            v8::Local<v8::Object> colorParams = Nan::To<v8::Object>(info[1]).ToLocalChecked();
            
            v8::Local<v8::Value> rColorValue = Nan::Get(colorParams, Nan::New<v8::String>("r").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> gColorValue = Nan::Get(colorParams, Nan::New<v8::String>("g").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> bColorValue = Nan::Get(colorParams, Nan::New<v8::String>("b").ToLocalChecked()).ToLocalChecked(); 

            if (rColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Nan::To<int>(rColorValue).ToChecked(),
                    Magick::ColorRGB(color_).green(),
                    Magick::ColorRGB(color_).blue()
                );
            }
            if (gColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Magick::ColorRGB(color_).red(),
                    Nan::To<int>(gColorValue).ToChecked(),
                    Magick::ColorRGB(color_).blue()
                );
            }
            if (bColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Magick::ColorRGB(color_).red(),
                    Magick::ColorRGB(color_).green(),
                    Nan::To<int>(bColorValue).ToChecked()
                );
            }
        } else if (info[1]->IsString()) {
            color_ = Magick::Color(*Nan::Utf8String(info[1]));
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"color\"").ToLocalChecked());
            return;
        }
        try { 
            kEffectNative->image.colorize(
                Nan::To<int>(info[0]).ToChecked(),
                color_
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
        return;
    } 

    if (info.Length() >= 4) {

        if (!info[0]->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"opacity_red\"").ToLocalChecked());
            return;
        }
        if (!info[1]->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"opacity_green\"").ToLocalChecked());
            return;
        }
        if (!info[2]->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"opacity_blue\"").ToLocalChecked());
            return;
        } 

        if (info[3]->IsObject()) {
            v8::Local<v8::Object> colorParams = Nan::To<v8::Object>(info[3]).ToLocalChecked();
            
            v8::Local<v8::Value> rColorValue = Nan::Get(colorParams, Nan::New<v8::String>("r").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> gColorValue = Nan::Get(colorParams, Nan::New<v8::String>("g").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> bColorValue = Nan::Get(colorParams, Nan::New<v8::String>("b").ToLocalChecked()).ToLocalChecked(); 

            if (rColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Nan::To<int>(rColorValue).ToChecked(),
                    Magick::ColorRGB(color_).green(),
                    Magick::ColorRGB(color_).blue()
                );
            }
            if (gColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Magick::ColorRGB(color_).red(),
                    Nan::To<int>(gColorValue).ToChecked(),
                    Magick::ColorRGB(color_).blue()
                );
            }
            if (bColorValue->IsNumber()) {
                color_ = Magick::Color(
                    Magick::ColorRGB(color_).red(),
                    Magick::ColorRGB(color_).green(),
                    Nan::To<int>(bColorValue).ToChecked()
                );
            }
        } else if (info[3]->IsString()) {
            color_ = Magick::Color(*Nan::Utf8String(info[3]));
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"color\"").ToLocalChecked());
            return;
        } 
        try { 
            kEffectNative->image.colorize(
                Nan::To<int>(info[0]).ToChecked(),
                Nan::To<int>(info[1]).ToChecked(),
                Nan::To<int>(info[2]).ToChecked(),
                color_
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }  
    }
} 