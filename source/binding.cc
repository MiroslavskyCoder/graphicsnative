#include "global.h"  
#include "EffectsNative.h"

NAN_METHOD(VersionMagick) {
    Nan::HandleScope();

    info.GetReturnValue().Set(Nan::New<v8::String>(MagickLibVersionText).ToLocalChecked());
}

NAN_MODULE_INIT(init) 
{ 
    Nan::SetMethod(target, "versionMagick", VersionMagick); 
    EffectsNative::Initialize(target);
}

NODE_MODULE(graphisnative, init);