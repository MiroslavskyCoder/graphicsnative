#include "EffectsNative.h"

NAN_METHOD(EffectsNative::ReadImage) {
    EffectsNative *kEffectNative = Nan::ObjectWrap::Unwrap<EffectsNative>(info.This());

    if (info[0]->IsObject()) { 
        v8::Local<v8::Object> params = Nan::To<v8::Object>(info[0]).ToLocalChecked();
 
        v8::Local<v8::Value> bufferValue = Nan::Get(params, Nan::New<v8::String>("buffer").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> sizeValue = Nan::Get(params, Nan::New<v8::String>("size").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> specValue = Nan::Get(params, Nan::New<v8::String>("spec").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> magickValue = Nan::Get(params, Nan::New<v8::String>("magick").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> depthValue = Nan::Get(params, Nan::New<v8::String>("depth").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> widthValue = Nan::Get(params, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> heightValue = Nan::Get(params, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked();
        v8::Local<v8::Value> mapValue = Nan::Get(params, Nan::New<v8::String>("map").ToLocalChecked()).ToLocalChecked(); 
        v8::Local<v8::Value> pixelsValue = Nan::Get(params, Nan::New<v8::String>("pixels").ToLocalChecked()).ToLocalChecked(); 

        if (node::Buffer::HasInstance(bufferValue)) { 
            if (sizeValue->IsString()) {
                if (magickValue->IsString()) { 
                    if (depthValue->IsNumber()) {
                        try { 
                            kEffectNative->image.read(
                                Magick::Blob(node::Buffer::Data(bufferValue), node::Buffer::Length(bufferValue)),
                                Magick::Geometry(*Nan::Utf8String(sizeValue)),
                                Nan::To<int>(depthValue).ToChecked(),
                                *Nan::Utf8String(magickValue)
                            );
                        } catch (Magick::Exception& err) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                        } catch (...) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                        } 
                        return;
                    }
                    else { 
                        try { 
                            kEffectNative->image.read(
                                Magick::Blob(node::Buffer::Data(bufferValue), node::Buffer::Length(bufferValue)),
                                Magick::Geometry(*Nan::Utf8String(sizeValue)),
                                *Nan::Utf8String(magickValue)
                            );
                        } catch (Magick::Exception& err) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                        } catch (...) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                        } 
                        return;
                    }
                } else {
                    try {  
                        kEffectNative->image.read(
                            Magick::Blob(node::Buffer::Data(bufferValue), node::Buffer::Length(bufferValue)),
                            Magick::Geometry(*Nan::Utf8String(sizeValue))
                        );
                    } catch (Magick::Exception& err) {
                        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                    } catch (...) {
                        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                    }
                    return;
                } 
            } else if (sizeValue->IsObject()) {
                v8::Local<v8::Object> paramsSize = Nan::To<v8::Object>(sizeValue).ToLocalChecked();
 
                v8::Local<v8::Value> widthValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked();
                v8::Local<v8::Value> heightValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked();
                v8::Local<v8::Value> xValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked();
                v8::Local<v8::Value> yValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked();

                if (!widthValueSize->IsNumber()) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"size.width\"").ToLocalChecked());
                    return;
                }

                if (!heightValueSize->IsNumber()) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"size.height\"").ToLocalChecked());
                    return;
                }

                if (magickValue->IsString()) {
                    if (depthValue->IsNumber()) {
                        try {  
                            kEffectNative->image.read(
                                Magick::Blob(node::Buffer::Data(bufferValue), node::Buffer::Length(bufferValue)),
                                Magick::Geometry(
                                    Nan::To<int>(widthValueSize).ToChecked(),
                                    Nan::To<int>(heightValueSize).ToChecked(),
                                    Nan::To<int>(xValueSize).FromMaybe(0),
                                    Nan::To<int>(yValueSize).FromMaybe(0)
                                ),
                                Nan::To<int>(depthValue).ToChecked(),
                                *Nan::Utf8String(magickValue)
                            );
                        } catch (Magick::Exception& err) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                        } catch (...) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                        } 
                        return;
                    }
                    else {
                        try {
                            kEffectNative->image.read(
                                Magick::Blob(node::Buffer::Data(bufferValue), node::Buffer::Length(bufferValue)),
                                Magick::Geometry(
                                    Nan::To<int>(widthValueSize).ToChecked(),
                                    Nan::To<int>(heightValueSize).ToChecked(),
                                    Nan::To<int>(xValueSize).FromMaybe(0),
                                    Nan::To<int>(yValueSize).FromMaybe(0)
                                ),
                                *Nan::Utf8String(magickValue)
                            );
                        } catch (Magick::Exception& err) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                        } catch (...) {
                            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                        }
                        return;
                    }
                } else { 
                    try {
                        kEffectNative->image.read(
                            Magick::Blob(node::Buffer::Data(bufferValue), node::Buffer::Length(bufferValue)),
                            Magick::Geometry(
                                Nan::To<int>(widthValueSize).ToChecked(),
                                Nan::To<int>(heightValueSize).ToChecked(),
                                Nan::To<int>(xValueSize).FromMaybe(0),
                                Nan::To<int>(yValueSize).FromMaybe(0)
                            )
                        ); 
                    } catch (Magick::Exception& err) {
                        Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                    } catch (...) {
                        Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                    }
                    return;
                }
                return;
            } else {
                try {
                    kEffectNative->image.read(Magick::Blob(node::Buffer::Data(bufferValue), node::Buffer::Length(bufferValue)));
                } catch (Magick::Exception& err) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                } catch (...) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                } 
                return;
            } 
        } 

        if (specValue->IsString()) {
            if (sizeValue->IsString()) {
                try {
                    kEffectNative->image.read(
                        Magick::Geometry(*Nan::Utf8String(sizeValue)),
                        *Nan::Utf8String(specValue)
                    );
                } catch (Magick::Exception& err) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                } catch (...) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                } 
                return;
            } else if (sizeValue->IsObject()) {
                v8::Local<v8::Object> paramsSize = Nan::To<v8::Object>(sizeValue).ToLocalChecked();
 
                v8::Local<v8::Value> widthValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("width").ToLocalChecked()).ToLocalChecked();
                v8::Local<v8::Value> heightValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("height").ToLocalChecked()).ToLocalChecked();
                v8::Local<v8::Value> xValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("x").ToLocalChecked()).ToLocalChecked();
                v8::Local<v8::Value> yValueSize = Nan::Get(paramsSize, Nan::New<v8::String>("y").ToLocalChecked()).ToLocalChecked();

                if (!widthValueSize->IsNumber()) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"size.width\"").ToLocalChecked());
                    return;
                }

                if (!heightValueSize->IsNumber()) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"size.height\"").ToLocalChecked());
                    return;
                }

                try {
                    kEffectNative->image.read(
                        Magick::Geometry(
                            Nan::To<int>(widthValueSize).ToChecked(),
                            Nan::To<int>(heightValueSize).ToChecked(),
                            Nan::To<int>(xValueSize).FromMaybe(0),
                            Nan::To<int>(yValueSize).FromMaybe(0)
                        ),
                        *Nan::Utf8String(specValue)
                    );
                } catch (Magick::Exception& err) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                } catch (...) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                } 
                return;
            } else {
                try {
                    kEffectNative->image.read(*Nan::Utf8String(specValue));
                } catch (Magick::Exception& err) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                } catch (...) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                } 
                
                return;
            }
        } else {
            if (
                node::Buffer::HasInstance(pixelsValue) &&
                widthValue->IsNumber() && 
                heightValue->IsNumber() 
            ) {
                std::string map_ = "RGB";
                if (mapValue->IsString()) {
                    map_ = *Nan::Utf8String(mapValue);
                }
                try {
                    kEffectNative->image.read(
                        Nan::To<int>(widthValue).ToChecked(),
                        Nan::To<int>(heightValue).ToChecked(),
                        map_, 
                        MagickCore::StorageType::CharPixel,
                        node::Buffer::Data(pixelsValue)
                    );
                } catch (Magick::Exception& err) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
                } catch (...) {
                    Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
                } 
                
                return;
            }
        }
    } else if (info[0]->IsString()) {
        try {
            kEffectNative->image.read(*Nan::Utf8String(info[0]));
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
        return;
    } else if (info.Length() >= 4) {
        int w, h;
        std::string format = "RGB";
        const char* buf = 0;
        if (info[0]->IsNumber()) {
            w = Nan::To<int>(info[0]).FromMaybe(0);
        } else { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"width\"").ToLocalChecked());
            return;
        }
        if (info[1]->IsNumber()) {
            h = Nan::To<int>(info[1]).FromMaybe(0);
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"height\"").ToLocalChecked());
            return;
        }
        if (info[2]->IsString()) {
            Nan::Utf8String strUtf8(info[2]); 
            format = *strUtf8;
        } else { 
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"format\"").ToLocalChecked());
            return;
        }
        if (node::Buffer::HasInstance(info[3])) {
            buf = node::Buffer::Data(info[3]);
        } else {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown value \"buffer\"").ToLocalChecked());
            return;
        }
        try {
            kEffectNative->image.read(w, h, format, MagickCore::StorageType::CharPixel, buf);
        } catch (Magick::Exception& err) {
            Nan::ThrowReferenceError(Nan::New<v8::String>(err.what()).ToLocalChecked());
        } catch (...) {
            Nan::ThrowReferenceError(Nan::New<v8::String>("Unknown error").ToLocalChecked());
        } 
    }
} 