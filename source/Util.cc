#include "EffectsNative.h"

MagickCore::PixelInfo* pixelInfoFromV8(EffectsNative* target, v8::Local<v8::Value> from) {
    MagickCore::PixelInfo* pixelInfo = new MagickCore::PixelInfo;
    if (from->IsObject()) {
        v8::Local<v8::Object> params = Nan::To<v8::Object>(from).ToLocalChecked();

        v8::Local<v8::Value> alphaValue = Nan::Get(params, Nan::New<v8::String>("alpha").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> alphaTraitValue = Nan::Get(params, Nan::New<v8::String>("alpha_trait").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> blackValue = Nan::Get(params, Nan::New<v8::String>("black").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> blueValue = Nan::Get(params, Nan::New<v8::String>("blue").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> colorspaceValue = Nan::Get(params, Nan::New<v8::String>("colorspace").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> countValue = Nan::Get(params, Nan::New<v8::String>("count").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> depthValue = Nan::Get(params, Nan::New<v8::String>("depth").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> fuzzValue = Nan::Get(params, Nan::New<v8::String>("fuzz").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> greenValue = Nan::Get(params, Nan::New<v8::String>("green").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> indexValue = Nan::Get(params, Nan::New<v8::String>("index").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> redValue = Nan::Get(params, Nan::New<v8::String>("red").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> storageClassValue = Nan::Get(params, Nan::New<v8::String>("storage_class").ToLocalChecked()).ToLocalChecked(); 

        if (alphaValue->IsNumber()) {
            pixelInfo->alpha = static_cast<double>(Nan::To<int>(alphaValue).ToChecked());
        } 
        if (alphaTraitValue->IsString()) {
            pixelInfo->alpha_trait = target->stringToPixelTrait(*Nan::Utf8String(alphaTraitValue));
        }
        if (blackValue->IsNumber()) {
            pixelInfo->black = static_cast<double>(Nan::To<int>(blackValue).ToChecked());
        } 
        if (blueValue->IsNumber()) {
            pixelInfo->blue = static_cast<double>(Nan::To<int>(blueValue).ToChecked());
        } 
        if (colorspaceValue->IsString()) {
            pixelInfo->colorspace = target->stringToColorspaceType(*Nan::Utf8String(colorspaceValue));
        } 
        if (countValue->IsNumber()) {
            pixelInfo->count = Nan::To<int>(countValue).ToChecked();
        } 
        if (depthValue->IsNumber()) {
            pixelInfo->depth = Nan::To<int>(depthValue).ToChecked(); 
        }
        if (fuzzValue->IsNumber()) {
            pixelInfo->fuzz = Nan::To<int>(fuzzValue).ToChecked();
        }
        if (greenValue->IsNumber()) {
            pixelInfo->green = static_cast<double>(Nan::To<int>(greenValue).ToChecked());
        }
        if (indexValue->IsNumber()) {
            pixelInfo->index = static_cast<double>(Nan::To<int>(indexValue).ToChecked());
        }
        if (redValue->IsNumber()) {
            pixelInfo->red = static_cast<double>(Nan::To<int>(redValue).ToChecked());
        } 
        if (storageClassValue->IsString()) {
            pixelInfo->storage_class = target->stringToClassType(*Nan::Utf8String(storageClassValue));
        }
    }

    return pixelInfo;
}