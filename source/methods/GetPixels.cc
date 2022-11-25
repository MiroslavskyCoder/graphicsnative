#include "EffectsNative.h"

NAN_METHOD(EffectsNative::GetPixelsImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This()); 
     
    try {
        std::vector<float> _vector_pixels; 

        for (int row = 0; row <= kEffectNative->height(); row++) {
            for (int column = 0; column <= kEffectNative->width(); column++)
            { 
                Magick::ColorRGB color = kEffectNative->image.pixelColor(column, row);
                _vector_pixels.push_back(color.red());
                _vector_pixels.push_back(color.green());
                _vector_pixels.push_back(color.blue());
            }
        }

        info.GetReturnValue().Set(
            Nan::CopyBuffer((const char*)_vector_pixels.data(), _vector_pixels.size()).ToLocalChecked()
        );
    } catch (Magick::Exception& err) {
        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
    } catch (...) {
        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
    } 
}