#include "EffectsNative.h"

NAN_METHOD(EffectsNative::FontTypeMetricsMultilineImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    v8::Local<v8::Object> kTargetReturnObject = Nan::New<v8::Object>();

    if (info[0]->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
 
        v8::Local<v8::Value> textValue = Nan::Get(params, Nan::New<v8::String>("text").ToLocalChecked()).ToLocalChecked();  
        
        if (!textValue->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"text\"").ToLocalChecked());
            return;
        }

        v8::Local<v8::Object> kBoundsObject = Nan::New<v8::Object>();
        v8::Local<v8::Object> kOriginObject = Nan::New<v8::Object>();
        v8::Local<v8::Object> kPixelsPerEmObject = Nan::New<v8::Object>();

        Magick::TypeMetric metric;

        try {  
            kEffectNative->image.fontTypeMetricsMultiline(
                std::string(*Nan::Utf8String(textValue)),
                &metric
            );
             
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("ascent").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.ascent()))); 
            Nan::Set(kBoundsObject, Nan::New<v8::String>("width").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().width()))); 
            Nan::Set(kBoundsObject, Nan::New<v8::String>("height").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().height())));
            Nan::Set(kBoundsObject, Nan::New<v8::String>("x").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().xOff())));
            Nan::Set(kBoundsObject, Nan::New<v8::String>("y").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().yOff()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("bounds").ToLocalChecked(), kBoundsObject); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("descent").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.descent())));
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("maxHorizontalAdvance").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.maxHorizontalAdvance())));
            Nan::Set(kOriginObject, Nan::New<v8::String>("x").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.origin().x())));
            Nan::Set(kOriginObject, Nan::New<v8::String>("y").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.origin().y())));  
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("origin").ToLocalChecked(), kOriginObject); 
            Nan::Set(kPixelsPerEmObject, Nan::New<v8::String>("x").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.pixelsPerEm().x())));
            Nan::Set(kPixelsPerEmObject, Nan::New<v8::String>("y").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.pixelsPerEm().y())));  
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("pixelsPerEm").ToLocalChecked(), kPixelsPerEmObject); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("textHeight").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.textHeight()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("textWidth").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.textWidth()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("underlinePosition").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.underlinePosition()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("underlineThickness").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.underlineThickness()))); 
    
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 

    } else {
        if (!info[0]->IsString()) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"text\"").ToLocalChecked());
            return;
        }

        v8::Local<v8::Object> kBoundsObject = Nan::New<v8::Object>();
        v8::Local<v8::Object> kOriginObject = Nan::New<v8::Object>();
        v8::Local<v8::Object> kPixelsPerEmObject = Nan::New<v8::Object>();

        Magick::TypeMetric metric;

        try { 
            kEffectNative->image.fontTypeMetricsMultiline(
                std::string(*Nan::Utf8String(info[0])),
                &metric
            );

            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("ascent").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.ascent()))); 
            Nan::Set(kBoundsObject, Nan::New<v8::String>("width").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().width()))); 
            Nan::Set(kBoundsObject, Nan::New<v8::String>("height").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().height())));
            Nan::Set(kBoundsObject, Nan::New<v8::String>("x").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().xOff())));
            Nan::Set(kBoundsObject, Nan::New<v8::String>("y").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.bounds().yOff()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("bounds").ToLocalChecked(), kBoundsObject); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("descent").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.descent())));
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("maxHorizontalAdvance").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.maxHorizontalAdvance())));
            Nan::Set(kOriginObject, Nan::New<v8::String>("x").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.origin().x())));
            Nan::Set(kOriginObject, Nan::New<v8::String>("y").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.origin().y())));  
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("origin").ToLocalChecked(), kOriginObject); 
            Nan::Set(kPixelsPerEmObject, Nan::New<v8::String>("x").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.pixelsPerEm().x())));
            Nan::Set(kPixelsPerEmObject, Nan::New<v8::String>("y").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.pixelsPerEm().y())));  
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("pixelsPerEm").ToLocalChecked(), kPixelsPerEmObject); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("textHeight").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.textHeight()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("textWidth").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.textWidth()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("underlinePosition").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.underlinePosition()))); 
            Nan::Set(kTargetReturnObject, Nan::New<v8::String>("underlineThickness").ToLocalChecked(), Nan::New<v8::Number>(static_cast<int>(metric.underlineThickness()))); 
    
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 

    } 

    info.GetReturnValue().Set(kTargetReturnObject); 
}