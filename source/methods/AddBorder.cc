#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddBorderImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
  
    Magick::Color _dst_color_border("#fff"); 

    if (info[0]->IsObject()) {
 
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
 
        v8::Local<v8::Value> colorValue = Nan::Get(params, Nan::New<v8::String>("color").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> xValue = Nan::Get(params, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> yValue = Nan::Get(params, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> widthValue = Nan::Get(params, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> heightValue = Nan::Get(params, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked();

        if (!widthValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked()); 
            return;
        }
        if (!heightValue->IsNumber()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked()); 
            return;
        }

        if (colorValue->IsObject()) {
            v8::Local<v8::Object> colorParams = Nan::To<v8::Object>(colorValue).ToLocalChecked();
            
            v8::Local<v8::Value> rColorValue = Nan::Get(colorParams, Nan::New<v8::String>("r").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> gColorValue = Nan::Get(colorParams, Nan::New<v8::String>("g").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> bColorValue = Nan::Get(colorParams, Nan::New<v8::String>("b").ToLocalChecked()).ToLocalChecked(); 

            if (rColorValue->IsNumber()) {
                _dst_color_border = Magick::Color(
                    Nan::To<int>(rColorValue).ToChecked(),
                    Magick::ColorRGB(_dst_color_border).green(),
                    Magick::ColorRGB(_dst_color_border).blue()
                );
            }
            if (gColorValue->IsNumber()) {
                _dst_color_border = Magick::Color(
                    Magick::ColorRGB(_dst_color_border).red(),
                    Nan::To<int>(gColorValue).ToChecked(),
                    Magick::ColorRGB(_dst_color_border).blue()
                );
            }
            if (bColorValue->IsNumber()) {
                _dst_color_border = Magick::Color(
                    Magick::ColorRGB(_dst_color_border).red(),
                    Magick::ColorRGB(_dst_color_border).green(),
                    Nan::To<int>(bColorValue).ToChecked()
                );
            }
        } else if (colorValue->IsString()) {
            _dst_color_border = Magick::Color(*Nan::Utf8String(colorValue));
        } 
        try { 
            kEffectNative->image.borderColor(_dst_color_border);
            kEffectNative->image.border(
                Magick::Geometry(
                    Nan::To<int>(widthValue).ToChecked(),
                    Nan::To<int>(heightValue).ToChecked(),
                    Nan::To<int>(xValue).FromMaybe(0),
                    Nan::To<int>(yValue).FromMaybe(0)
                )
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }
        
    } else { 
        int x = 0, y = 0;
        int w = 1, h = 1;

        if (info[0]->IsNumber() && info[1]->IsNumber()) {
            w = Nan::To<int>(info[0]).ToChecked();
            h = Nan::To<int>(info[1]).ToChecked();
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"w\", \"h\"").ToLocalChecked()); 
            return;
        }
        if (info[2]->IsNumber()) {
            x = Nan::To<int>(info[2]).FromMaybe(0);
        }
        if (info[3]->IsNumber()) {
            y = Nan::To<int>(info[3]).FromMaybe(0);
        }

        try { 
            kEffectNative->image.borderColor(_dst_color_border);
            kEffectNative->image.border(
                Magick::Geometry(w, h, x, y)
            );
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }
    }
}