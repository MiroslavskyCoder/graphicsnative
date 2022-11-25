#include "EffectsNative.h"

NAN_METHOD(EffectsNative::AddTextImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());
  
    if (info[0]->IsObject()) {
    
        Magick::DrawableList _list_draws;
        Magick::Color _dst_color_fill("#fff"); 
        Magick::Color _dst_color_stroke("#fff"); 
 
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();

        v8::Local<v8::Value> textValue = Nan::Get(params, Nan::New<v8::String>("text").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> noFillValue = Nan::Get(params, Nan::New<v8::String>("no_fill").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> noStrokeValue = Nan::Get(params, Nan::New<v8::String>("no_stroke").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> colorFillValue = Nan::Get(params, Nan::New<v8::String>("color_fill").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> colorStrokeValue = Nan::Get(params, Nan::New<v8::String>("color_stroke").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> fontValue = Nan::Get(params, Nan::New<v8::String>("font").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> pointSizeValue = Nan::Get(params, Nan::New<v8::String>("size").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> xValue = Nan::Get(params, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> yValue = Nan::Get(params, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked();

        if (!textValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"text\"").ToLocalChecked());
            return;
        }

        if (colorFillValue->IsObject()) {
            v8::Local<v8::Object> colorParams = Nan::To<v8::Object>(colorFillValue).ToLocalChecked();
            
            v8::Local<v8::Value> rColorValue = Nan::Get(colorParams, Nan::New<v8::String>("r").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> gColorValue = Nan::Get(colorParams, Nan::New<v8::String>("g").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> bColorValue = Nan::Get(colorParams, Nan::New<v8::String>("b").ToLocalChecked()).ToLocalChecked(); 

            if (rColorValue->IsNumber()) {
                _dst_color_fill = Magick::Color(
                    Nan::To<int>(rColorValue).ToChecked(),
                    Magick::ColorRGB(_dst_color_fill).green(),
                    Magick::ColorRGB(_dst_color_fill).blue()
                );
            }
            if (gColorValue->IsNumber()) {
                _dst_color_fill = Magick::Color(
                    Magick::ColorRGB(_dst_color_fill).red(),
                    Nan::To<int>(gColorValue).ToChecked(),
                    Magick::ColorRGB(_dst_color_fill).blue()
                );
            }
            if (bColorValue->IsNumber()) {
                _dst_color_fill = Magick::Color(
                    Magick::ColorRGB(_dst_color_fill).red(),
                    Magick::ColorRGB(_dst_color_fill).green(),
                    Nan::To<int>(bColorValue).ToChecked()
                );
            }
        } else if (colorFillValue->IsString()) {
            _dst_color_fill = Magick::Color(*Nan::Utf8String(colorFillValue));
        }

        if (fontValue->IsObject()) {
            v8::Local<v8::Object> fontParams = Nan::To<v8::Object>(fontValue).ToLocalChecked();

            v8::Local<v8::Value> familyFontValue = Nan::Get(fontParams, Nan::New<v8::String>("family").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> styleFontValue = Nan::Get(fontParams, Nan::New<v8::String>("style").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> weightFontValue = Nan::Get(fontParams, Nan::New<v8::String>("weight").ToLocalChecked()).ToLocalChecked();
            v8::Local<v8::Value> stretchFontValue = Nan::Get(fontParams, Nan::New<v8::String>("stretch").ToLocalChecked()).ToLocalChecked();  

            if (!familyFontValue->IsString()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"family\"").ToLocalChecked());
                return;
            } 
            if (!styleFontValue->IsString()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"style\"").ToLocalChecked());
                return;
            } 
            if (!weightFontValue->IsNumber()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"weight\"").ToLocalChecked());
                return;
            } 
            if (!stretchFontValue->IsString()) {
                Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"stretch\"").ToLocalChecked());
                return;
            } 

            _list_draws.push_back(
                Magick::DrawableFont(
                    *Nan::Utf8String(familyFontValue),
                    kEffectNative->stringToStyleType(*Nan::Utf8String(styleFontValue)),
                    Nan::To<int>(weightFontValue).ToChecked(),
                    kEffectNative->stringToStretchType(*Nan::Utf8String(stretchFontValue))
                )
            ); 
        } else if (fontValue->IsString()) {
            _list_draws.push_back(Magick::DrawableFont(*Nan::Utf8String(fontValue))); 
        }

        _list_draws.push_back(
            Magick::DrawablePointSize(Nan::To<int>(pointSizeValue).FromMaybe(20))
        );

        if (!(
            noFillValue->IsBoolean() && 
            Nan::To<bool>(noFillValue).ToChecked() == true
        )) {
            _list_draws.push_back(
                Magick::DrawableFillColor(_dst_color_fill)
            );
        }

        if (!(
            noStrokeValue->IsBoolean() && 
            Nan::To<bool>(noStrokeValue).ToChecked() == true
        )) {
            _list_draws.push_back(
                Magick::DrawableStrokeColor(_dst_color_stroke)
            );
        } 

        _list_draws.push_back(
            Magick::DrawableText(
                Nan::To<int>(xValue).FromMaybe(0),
                Nan::To<int>(yValue).FromMaybe(0),
                *Nan::Utf8String(textValue)
            )
        );
        try { 
            kEffectNative->image.draw(_list_draws);
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        }
    } 
}