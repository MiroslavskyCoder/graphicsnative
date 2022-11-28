#include "EffectsNative.h"

#include <map>

namespace byMiroslavskyPrivate {
    #define MAKE_SET_TYPEDEF_MAP(a) typedef std::map<std::string, MagickCore::a> a##Map;
    #define MAKE_ENUMS_MAP(E,T,D) \
        E::iterator iter = T.find(value); \
        if (iter != T.end()) { \
            return iter->second; \
        } \
        return D;

    MAKE_SET_TYPEDEF_MAP(ChannelType)
    MAKE_SET_TYPEDEF_MAP(AutoThresholdMethod)
    MAKE_SET_TYPEDEF_MAP(GravityType)
    MAKE_SET_TYPEDEF_MAP(VirtualPixelMethod)
    MAKE_SET_TYPEDEF_MAP(StyleType)
    MAKE_SET_TYPEDEF_MAP(StretchType)
    MAKE_SET_TYPEDEF_MAP(FillRule)
    MAKE_SET_TYPEDEF_MAP(NoiseType) 
    MAKE_SET_TYPEDEF_MAP(DirectionType) 
    MAKE_SET_TYPEDEF_MAP(PixelInterpolateMethod) 
    MAKE_SET_TYPEDEF_MAP(PixelMask) 
    MAKE_SET_TYPEDEF_MAP(RenderingIntent) 
    MAKE_SET_TYPEDEF_MAP(LineJoin) 
    MAKE_SET_TYPEDEF_MAP(LineCap) 
    MAKE_SET_TYPEDEF_MAP(CompositeOperator) 
    MAKE_SET_TYPEDEF_MAP(MetricType) 
    MAKE_SET_TYPEDEF_MAP(PixelTrait) 
    MAKE_SET_TYPEDEF_MAP(ColorspaceType) 
    MAKE_SET_TYPEDEF_MAP(ClassType) 
    
}

MagickCore::ChannelType EffectsNative::stringToChannelType(std::string value) {
    MagickCore::ChannelType channel = MagickCore::ChannelType::UndefinedChannel;
    byMiroslavskyPrivate::ChannelTypeMap mapChannelsTypes = {
        {"a", MagickCore::ChannelType::aChannel},
        {"all", MagickCore::ChannelType::AllChannels},
        {"alpha", MagickCore::ChannelType::AlphaChannel},
        {"b", MagickCore::ChannelType::bChannel},
        {"black", MagickCore::ChannelType::BlackChannel},
        {"blue", MagickCore::ChannelType::BlueChannel},
        {"composite", MagickCore::ChannelType::CompositeChannels},
        {"composite_mask", MagickCore::ChannelType::CompositeMaskChannel},
        {"cyan", MagickCore::ChannelType::CyanChannel},
        {"default", MagickCore::ChannelType::DefaultChannels},
        {"gray", MagickCore::ChannelType::GrayChannel},
        {"grays", MagickCore::ChannelType::GrayChannels},
        {"green", MagickCore::ChannelType::GreenChannel},
        {"index", MagickCore::ChannelType::IndexChannel},
        {"l", MagickCore::ChannelType::LChannel},
        {"magenta", MagickCore::ChannelType::MagentaChannel},
        {"meta", MagickCore::ChannelType::MetaChannel},
        {"opacity", MagickCore::ChannelType::OpacityChannel},
        {"read_mask", MagickCore::ChannelType::ReadMaskChannel},
        {"red", MagickCore::ChannelType::RedChannel},
        {"rgb", MagickCore::ChannelType::RGBChannels},
        {"sync", MagickCore::ChannelType::SyncChannels},
        {"true_alpha", MagickCore::ChannelType::TrueAlphaChannel},
        {"undefined", MagickCore::ChannelType::UndefinedChannel},
        {"write_mask", MagickCore::ChannelType::WriteMaskChannel},
        {"yellow", MagickCore::ChannelType::YellowChannel}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::ChannelTypeMap, mapChannelsTypes, channel)
}

MagickCore::AutoThresholdMethod EffectsNative::stringToAutoThresholdMethod(std::string value) {
    MagickCore::AutoThresholdMethod autoThresholdMethod = MagickCore::AutoThresholdMethod::UndefinedThresholdMethod;
    byMiroslavskyPrivate::AutoThresholdMethodMap autoThresholdMethodMap = {
        {"kapur", MagickCore::AutoThresholdMethod::KapurThresholdMethod},
        {"otsu", MagickCore::AutoThresholdMethod::OTSUThresholdMethod},
        {"triangle", MagickCore::AutoThresholdMethod::TriangleThresholdMethod},
        {"undefined", MagickCore::AutoThresholdMethod::UndefinedThresholdMethod}
    };
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::AutoThresholdMethodMap, autoThresholdMethodMap, autoThresholdMethod)
}

MagickCore::GravityType EffectsNative::stringToGravityType(std::string value) {
    MagickCore::GravityType gravityTypeMethod = MagickCore::GravityType::UndefinedGravity;
    byMiroslavskyPrivate::GravityTypeMap gravityTypeMap = {
        {"center", MagickCore::GravityType::CenterGravity},
        {"east", MagickCore::GravityType::EastGravity},
        {"forget", MagickCore::GravityType::ForgetGravity},
        {"north_east", MagickCore::GravityType::NorthEastGravity},
        {"north", MagickCore::GravityType::NorthGravity},
        {"north_west", MagickCore::GravityType::NorthWestGravity},
        {"south_east", MagickCore::GravityType::SouthEastGravity},
        {"south", MagickCore::GravityType::SouthGravity},
        {"south_west", MagickCore::GravityType::SouthWestGravity},
        {"undefined", MagickCore::GravityType::UndefinedGravity},
        {"west", MagickCore::GravityType::WestGravity}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::GravityTypeMap, gravityTypeMap, gravityTypeMethod)
}

MagickCore::VirtualPixelMethod EffectsNative::stringToVirtualPixelMethod(std::string value) {
    MagickCore::VirtualPixelMethod virtualPixelMethod = MagickCore::VirtualPixelMethod::UndefinedVirtualPixelMethod;
    byMiroslavskyPrivate::VirtualPixelMethodMap virtualPixelMethodMap = {
        {"background", MagickCore::VirtualPixelMethod::BackgroundVirtualPixelMethod},
        {"black", MagickCore::VirtualPixelMethod::BlackVirtualPixelMethod},
        {"checker", MagickCore::VirtualPixelMethod::CheckerTileVirtualPixelMethod},
        {"dither", MagickCore::VirtualPixelMethod::DitherVirtualPixelMethod},
        {"edge", MagickCore::VirtualPixelMethod::EdgeVirtualPixelMethod},
        {"gray", MagickCore::VirtualPixelMethod::GrayVirtualPixelMethod},
        {"horizontal_tile_edge", MagickCore::VirtualPixelMethod::HorizontalTileEdgeVirtualPixelMethod},
        {"horizontal_tile", MagickCore::VirtualPixelMethod::HorizontalTileVirtualPixelMethod},
        {"mask", MagickCore::VirtualPixelMethod::MaskVirtualPixelMethod},
        {"mirror", MagickCore::VirtualPixelMethod::MirrorVirtualPixelMethod},
        {"random", MagickCore::VirtualPixelMethod::RandomVirtualPixelMethod},
        {"tile", MagickCore::VirtualPixelMethod::TileVirtualPixelMethod},
        {"transparent", MagickCore::VirtualPixelMethod::TransparentVirtualPixelMethod},
        {"undefined", MagickCore::VirtualPixelMethod::UndefinedVirtualPixelMethod},
        {"vertical_tile_edge", MagickCore::VirtualPixelMethod::VerticalTileEdgeVirtualPixelMethod},
        {"vertical_tile", MagickCore::VirtualPixelMethod::VerticalTileVirtualPixelMethod},
        {"white", MagickCore::VirtualPixelMethod::WhiteVirtualPixelMethod} 
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::VirtualPixelMethodMap, virtualPixelMethodMap, virtualPixelMethod)
}

MagickCore::StyleType EffectsNative::stringToStyleType(std::string value) {
    MagickCore::StyleType styleType = MagickCore::StyleType::UndefinedStyle;
    byMiroslavskyPrivate::StyleTypeMap styleTypeMap = {
        {"any", MagickCore::StyleType::AnyStyle},
        {"bold", MagickCore::StyleType::BoldStyle},
        {"italic", MagickCore::StyleType::ItalicStyle},
        {"normal", MagickCore::StyleType::NormalStyle},
        {"oblique", MagickCore::StyleType::ObliqueStyle},
        {"undefined", MagickCore::StyleType::UndefinedStyle}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::StyleTypeMap, styleTypeMap, styleType)
}

MagickCore::StretchType EffectsNative::stringToStretchType(std::string value) {
    MagickCore::StretchType stretchType = MagickCore::StretchType::UndefinedStretch;
    byMiroslavskyPrivate::StretchTypeMap stretchTypeMap = {
        {"any", MagickCore::StretchType::AnyStretch}, 
        {"condensed", MagickCore::StretchType::CondensedStretch},
        {"expanded", MagickCore::StretchType::ExpandedStretch},
        {"extra_condensed", MagickCore::StretchType::ExtraCondensedStretch},
        {"extra_expanded", MagickCore::StretchType::ExtraExpandedStretch},
        {"normal", MagickCore::StretchType::NormalStretch},
        {"semi_condensed", MagickCore::StretchType::SemiCondensedStretch},
        {"semi_expanded", MagickCore::StretchType::SemiExpandedStretch},
        {"ultra_condensed", MagickCore::StretchType::UltraCondensedStretch},
        {"ultra_expanded", MagickCore::StretchType::UltraExpandedStretch},
        {"undefined", MagickCore::StretchType::UndefinedStretch}
    };
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::StretchTypeMap, stretchTypeMap, stretchType)
}

MagickCore::FillRule EffectsNative::stringToFillRule(std::string value) {
    MagickCore::FillRule fillRule = MagickCore::FillRule::UndefinedRule;
    byMiroslavskyPrivate::FillRuleMap fillRuleMap = {
        {"even_odd", MagickCore::FillRule::EvenOddRule}, 
        {"non_zero", MagickCore::FillRule::NonZeroRule},
        {"undefined", MagickCore::FillRule::UndefinedRule}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::FillRuleMap, fillRuleMap, fillRule)
}

MagickCore::NoiseType EffectsNative::stringToNoiseType(std::string value) {
    MagickCore::NoiseType noiseType = MagickCore::NoiseType::UndefinedNoise;
    byMiroslavskyPrivate::NoiseTypeMap noiseTypeMap = {
        {"gaussian", MagickCore::NoiseType::GaussianNoise},
        {"impulse", MagickCore::NoiseType::ImpulseNoise},
        {"laplacian", MagickCore::NoiseType::LaplacianNoise},
        {"multiplicative_gaussian", MagickCore::NoiseType::MultiplicativeGaussianNoise},
        {"poisson", MagickCore::NoiseType::PoissonNoise},
        {"random", MagickCore::NoiseType::RandomNoise},
        {"uniform", MagickCore::NoiseType::UniformNoise},
        {"undefined", MagickCore::NoiseType::UndefinedNoise}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::NoiseTypeMap, noiseTypeMap, noiseType)
}

MagickCore::DirectionType EffectsNative::stringToDirectionType(std::string value) {
    MagickCore::DirectionType directionType = MagickCore::DirectionType::UndefinedDirection;
    byMiroslavskyPrivate::DirectionTypeMap directionTypeMap = {
        {"left_to_right", MagickCore::DirectionType::LeftToRightDirection},
        {"right_to_left", MagickCore::DirectionType::RightToLeftDirection},
        {"undefined", MagickCore::DirectionType::UndefinedDirection}
    };
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::DirectionTypeMap, directionTypeMap, directionType)
}

MagickCore::PixelInterpolateMethod EffectsNative::stringToPixelInterpolateMethod(std::string value) {
    MagickCore::PixelInterpolateMethod pixelInterpolateMethod = MagickCore::PixelInterpolateMethod::UndefinedInterpolatePixel;
    byMiroslavskyPrivate::PixelInterpolateMethodMap pixelInterpolateMethodMap = {
        {"average16", MagickCore::PixelInterpolateMethod::Average16InterpolatePixel},
        {"average9", MagickCore::PixelInterpolateMethod::Average9InterpolatePixel},
        {"average", MagickCore::PixelInterpolateMethod::AverageInterpolatePixel},
        {"background", MagickCore::PixelInterpolateMethod::BackgroundInterpolatePixel},
        {"bilinear", MagickCore::PixelInterpolateMethod::BilinearInterpolatePixel},
        {"blend", MagickCore::PixelInterpolateMethod::BlendInterpolatePixel},
        {"catrom", MagickCore::PixelInterpolateMethod::CatromInterpolatePixel},
        {"intege", MagickCore::PixelInterpolateMethod::IntegerInterpolatePixel},
        {"mesh", MagickCore::PixelInterpolateMethod::MeshInterpolatePixel},
        {"nearest", MagickCore::PixelInterpolateMethod::NearestInterpolatePixel},
        {"spline", MagickCore::PixelInterpolateMethod::SplineInterpolatePixel},
        {"undefined", MagickCore::PixelInterpolateMethod::UndefinedInterpolatePixel}
    };
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::PixelInterpolateMethodMap, pixelInterpolateMethodMap, pixelInterpolateMethod)
}

MagickCore::PixelMask EffectsNative::stringToPixelMask(std::string value) {
    MagickCore::PixelMask pixelMask = MagickCore::PixelMask::UndefinedPixelMask;
    byMiroslavskyPrivate::PixelMaskMap pixelMaskMap = {
        {"composite", MagickCore::PixelMask::CompositePixelMask},
        {"read", MagickCore::PixelMask::ReadPixelMask},
        {"write", MagickCore::PixelMask::WritePixelMask},
        {"undefined", MagickCore::PixelMask::UndefinedPixelMask}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::PixelMaskMap, pixelMaskMap, pixelMask)
}

MagickCore::RenderingIntent EffectsNative::stringToRenderingIntent(std::string value) {
    MagickCore::RenderingIntent renderingIntent = MagickCore::RenderingIntent::UndefinedIntent;
    byMiroslavskyPrivate::RenderingIntentMap renderingIntentMap = {
        {"absolute", MagickCore::RenderingIntent::AbsoluteIntent},
        {"perceptual", MagickCore::RenderingIntent::PerceptualIntent},
        {"relative", MagickCore::RenderingIntent::RelativeIntent},
        {"saturation", MagickCore::RenderingIntent::SaturationIntent},
        {"undefined", MagickCore::RenderingIntent::UndefinedIntent}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::RenderingIntentMap, renderingIntentMap, renderingIntent)
}

MagickCore::LineJoin EffectsNative::stringToLineJoin(std::string value) {
    MagickCore::LineJoin lineJoin = MagickCore::LineJoin::UndefinedJoin;
    byMiroslavskyPrivate::LineJoinMap lineJoinMap = {
        {"bevel", MagickCore::LineJoin::BevelJoin},
        {"miter", MagickCore::LineJoin::MiterJoin},
        {"round", MagickCore::LineJoin::RoundJoin},
        {"undefined", MagickCore::LineJoin::UndefinedJoin},
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::LineJoinMap, lineJoinMap, lineJoin)
}

MagickCore::LineCap EffectsNative::stringToLineCap(std::string value) {
    MagickCore::LineCap lineCap = MagickCore::LineCap::UndefinedCap;
    byMiroslavskyPrivate::LineCapMap lineCapMap = {
        {"butt", MagickCore::LineCap::ButtCap},
        {"round", MagickCore::LineCap::RoundCap},
        {"square", MagickCore::LineCap::SquareCap},
        {"undefined", MagickCore::LineCap::UndefinedCap},
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::LineCapMap, lineCapMap, lineCap)
}

MagickCore::CompositeOperator EffectsNative::stringToCompositeOperator(std::string value) {
    MagickCore::CompositeOperator compositeOperator = MagickCore::CompositeOperator::UndefinedCompositeOp;
    byMiroslavskyPrivate::CompositeOperatorMap compositeOperatorMap = {
        {"alpha", MagickCore::CompositeOperator::AlphaCompositeOp},
        {"atop", MagickCore::CompositeOperator::AtopCompositeOp},
        {"blend", MagickCore::CompositeOperator::BlendCompositeOp},
        {"blur", MagickCore::CompositeOperator::BlurCompositeOp},
        {"bumpmap", MagickCore::CompositeOperator::BumpmapCompositeOp},
        {"change_mask", MagickCore::CompositeOperator::ChangeMaskCompositeOp},
        {"clear", MagickCore::CompositeOperator::ClearCompositeOp},
        {"color_burn", MagickCore::CompositeOperator::ColorBurnCompositeOp},
        {"color_dodge", MagickCore::CompositeOperator::ColorDodgeCompositeOp},
        {"colorize", MagickCore::CompositeOperator::ColorizeCompositeOp},
        {"copy_alpha", MagickCore::CompositeOperator::CopyAlphaCompositeOp},
        {"copy_black", MagickCore::CompositeOperator::CopyBlackCompositeOp},
        {"copy_blue", MagickCore::CompositeOperator::CopyBlueCompositeOp},
        {"copy", MagickCore::CompositeOperator::CopyCompositeOp},
        {"copy_cyan", MagickCore::CompositeOperator::CopyCyanCompositeOp},
        {"copy_green", MagickCore::CompositeOperator::CopyGreenCompositeOp},
        {"copy_magenta", MagickCore::CompositeOperator::CopyMagentaCompositeOp},
        {"copy_red", MagickCore::CompositeOperator::CopyRedCompositeOp},
        {"copy_yellow", MagickCore::CompositeOperator::CopyYellowCompositeOp},
        {"darken", MagickCore::CompositeOperator::DarkenCompositeOp},
        {"darken_intensity", MagickCore::CompositeOperator::DarkenIntensityCompositeOp},
        {"difference", MagickCore::CompositeOperator::DifferenceCompositeOp},
        {"displace", MagickCore::CompositeOperator::DisplaceCompositeOp},
        {"dissolve", MagickCore::CompositeOperator::DissolveCompositeOp},
        {"distort", MagickCore::CompositeOperator::DistortCompositeOp},
        {"divide_dst", MagickCore::CompositeOperator::DivideDstCompositeOp},
        {"divide_src", MagickCore::CompositeOperator::DivideSrcCompositeOp},
        {"dst_atop", MagickCore::CompositeOperator::DstAtopCompositeOp},
        {"dst", MagickCore::CompositeOperator::DstCompositeOp},
        {"dst_in", MagickCore::CompositeOperator::DstInCompositeOp},
        {"dst_out", MagickCore::CompositeOperator::DstOutCompositeOp},
        {"dst_over", MagickCore::CompositeOperator::DstOverCompositeOp},
        {"exclusion", MagickCore::CompositeOperator::ExclusionCompositeOp},
        {"freeze", MagickCore::CompositeOperator::FreezeCompositeOp},
        {"hard_light", MagickCore::CompositeOperator::HardLightCompositeOp},
        {"hard_mix", MagickCore::CompositeOperator::HardMixCompositeOp},
        {"hue", MagickCore::CompositeOperator::HueCompositeOp},
        {"in", MagickCore::CompositeOperator::InCompositeOp},
        {"intensity", MagickCore::CompositeOperator::IntensityCompositeOp},
        {"interpolate", MagickCore::CompositeOperator::InterpolateCompositeOp},
        {"lighten", MagickCore::CompositeOperator::LightenCompositeOp},
        {"lighten_intensity", MagickCore::CompositeOperator::LightenIntensityCompositeOp},
        {"linear_burn", MagickCore::CompositeOperator::LinearBurnCompositeOp},
        {"linear_dodge", MagickCore::CompositeOperator::LinearDodgeCompositeOp},
        {"linear_light", MagickCore::CompositeOperator::LinearLightCompositeOp},
        {"luminize", MagickCore::CompositeOperator::LuminizeCompositeOp},
        {"mathematics", MagickCore::CompositeOperator::MathematicsCompositeOp},
        {"minus_dst", MagickCore::CompositeOperator::MinusDstCompositeOp},
        {"minus_src", MagickCore::CompositeOperator::MinusSrcCompositeOp},
        {"modulate", MagickCore::CompositeOperator::ModulateCompositeOp},
        {"modulus_add", MagickCore::CompositeOperator::ModulusAddCompositeOp},
        {"modulus_subtract", MagickCore::CompositeOperator::ModulusSubtractCompositeOp},
        {"multiply", MagickCore::CompositeOperator::MultiplyCompositeOp},
        {"negate", MagickCore::CompositeOperator::NegateCompositeOp},
        {"no", MagickCore::CompositeOperator::NoCompositeOp},
        {"out", MagickCore::CompositeOperator::OutCompositeOp},
        {"over", MagickCore::CompositeOperator::OverCompositeOp},
        {"overlay", MagickCore::CompositeOperator::OverlayCompositeOp},
        {"pegtop_light", MagickCore::CompositeOperator::PegtopLightCompositeOp},
        {"pin_light", MagickCore::CompositeOperator::PinLightCompositeOp},
        {"plus", MagickCore::CompositeOperator::PlusCompositeOp},
        {"reflect", MagickCore::CompositeOperator::ReflectCompositeOp},
        {"replace", MagickCore::CompositeOperator::ReplaceCompositeOp},
        {"rmse", MagickCore::CompositeOperator::RMSECompositeOp},
        {"saliency_blend", MagickCore::CompositeOperator::SaliencyBlendCompositeOp},
        {"saturate", MagickCore::CompositeOperator::SaturateCompositeOp},
        {"screen", MagickCore::CompositeOperator::ScreenCompositeOp},
        {"seamless_blend", MagickCore::CompositeOperator::SeamlessBlendCompositeOp},
        {"soft_burn", MagickCore::CompositeOperator::SoftBurnCompositeOp},
        {"soft_dodge", MagickCore::CompositeOperator::SoftDodgeCompositeOp},
        {"soft_light", MagickCore::CompositeOperator::SoftLightCompositeOp},
        {"src_atop", MagickCore::CompositeOperator::SrcAtopCompositeOp},
        {"src", MagickCore::CompositeOperator::SrcCompositeOp},
        {"src_in", MagickCore::CompositeOperator::SrcInCompositeOp},
        {"src_out", MagickCore::CompositeOperator::SrcOutCompositeOp},
        {"src_over", MagickCore::CompositeOperator::SrcOverCompositeOp},
        {"stamp", MagickCore::CompositeOperator::StampCompositeOp},
        {"stereo", MagickCore::CompositeOperator::StereoCompositeOp},
        {"threshold", MagickCore::CompositeOperator::ThresholdCompositeOp},
        {"undefined", MagickCore::CompositeOperator::UndefinedCompositeOp},
        {"vivid_light", MagickCore::CompositeOperator::VividLightCompositeOp},
        {"xor", MagickCore::CompositeOperator::XorCompositeOp}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::CompositeOperatorMap, compositeOperatorMap, compositeOperator)
}

MagickCore::MetricType EffectsNative::stringToMetricType(std::string value) {
    MagickCore::MetricType metricType = MagickCore::MetricType::UndefinedErrorMetric;
    byMiroslavskyPrivate::MetricTypeMap metricTypeMap = {
        {"absolute", MagickCore::MetricType::AbsoluteErrorMetric},
        {"fuzz", MagickCore::MetricType::FuzzErrorMetric},
        {"mean", MagickCore::MetricType::MeanAbsoluteErrorMetric},
        {"mean_per", MagickCore::MetricType::MeanErrorPerPixelErrorMetric},
        {"mean_squared", MagickCore::MetricType::MeanSquaredErrorMetric},
        {"normalized_cross_correlation", MagickCore::MetricType::NormalizedCrossCorrelationErrorMetric},
        {"peak_absolute", MagickCore::MetricType::PeakAbsoluteErrorMetric},
        {"peak_signal_to_noise_ratio", MagickCore::MetricType::PeakSignalToNoiseRatioErrorMetric},
        {"perceptual_hash", MagickCore::MetricType::PerceptualHashErrorMetric},
        {"root_mean_squared", MagickCore::MetricType::RootMeanSquaredErrorMetric},
        {"structural_dissimilarity", MagickCore::MetricType::StructuralDissimilarityErrorMetric},
        {"structural_similarity", MagickCore::MetricType::StructuralSimilarityErrorMetric},
        {"undefined", MagickCore::MetricType::UndefinedErrorMetric} 
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::MetricTypeMap, metricTypeMap, metricType)
}
 
MagickCore::PixelTrait EffectsNative::stringToPixelTrait(std::string value) {
    MagickCore::PixelTrait pixelTrait = MagickCore::PixelTrait::UndefinedPixelTrait;
    byMiroslavskyPrivate::PixelTraitMap pixelTraitMap = {
        {"blend", MagickCore::PixelTrait::BlendPixelTrait},
        {"copy", MagickCore::PixelTrait::CopyPixelTrait},
        {"undefined", MagickCore::PixelTrait::UndefinedPixelTrait},
        {"update", MagickCore::PixelTrait::UpdatePixelTrait}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::PixelTraitMap, pixelTraitMap, pixelTrait)
}
 
MagickCore::ColorspaceType EffectsNative::stringToColorspaceType(std::string value) {
    MagickCore::ColorspaceType colorspaceType = MagickCore::ColorspaceType::UndefinedColorspace;
    byMiroslavskyPrivate::ColorspaceTypeMap colorspaceTypeMap = {
        {"adobe98", MagickCore::ColorspaceType::Adobe98Colorspace},
        {"cmy", MagickCore::ColorspaceType::CMYColorspace},
        {"cmyk", MagickCore::ColorspaceType::CMYKColorspace},
        {"display_p3", MagickCore::ColorspaceType::DisplayP3Colorspace},
        {"gray", MagickCore::ColorspaceType::GRAYColorspace},
        {"hcl", MagickCore::ColorspaceType::HCLColorspace},
        {"hclp", MagickCore::ColorspaceType::HCLpColorspace},
        {"hsb", MagickCore::ColorspaceType::HSBColorspace},
        {"hsi", MagickCore::ColorspaceType::HSIColorspace},
        {"hsl", MagickCore::ColorspaceType::HSLColorspace},
        {"hsv", MagickCore::ColorspaceType::HSVColorspace},
        {"hwb", MagickCore::ColorspaceType::HWBColorspace},
        {"jzazbz", MagickCore::ColorspaceType::JzazbzColorspace},
        {"lab", MagickCore::ColorspaceType::LabColorspace},
        {"lchab", MagickCore::ColorspaceType::LCHabColorspace},
        {"lch", MagickCore::ColorspaceType::LCHColorspace},
        {"lchuv", MagickCore::ColorspaceType::LCHuvColorspace},
        {"linear_gray", MagickCore::ColorspaceType::LinearGRAYColorspace},
        {"lms", MagickCore::ColorspaceType::LMSColorspace},
        {"log", MagickCore::ColorspaceType::LogColorspace},
        {"luv", MagickCore::ColorspaceType::LuvColorspace},
        {"ohta", MagickCore::ColorspaceType::OHTAColorspace},
        {"pro_photo", MagickCore::ColorspaceType::ProPhotoColorspace},
        {"rec601ycbcr", MagickCore::ColorspaceType::Rec601YCbCrColorspace},
        {"rec709ycbcr", MagickCore::ColorspaceType::Rec709YCbCrColorspace},
        {"rgb", MagickCore::ColorspaceType::RGBColorspace},
        {"scrgb", MagickCore::ColorspaceType::scRGBColorspace},
        {"srgb", MagickCore::ColorspaceType::sRGBColorspace},
        {"transparent", MagickCore::ColorspaceType::TransparentColorspace},
        {"undefined", MagickCore::ColorspaceType::UndefinedColorspace},
        {"xyy", MagickCore::ColorspaceType::xyYColorspace},
        {"xyz", MagickCore::ColorspaceType::XYZColorspace},
        {"ycbcr", MagickCore::ColorspaceType::YCbCrColorspace},
        {"ycc", MagickCore::ColorspaceType::YCCColorspace},
        {"ydbdr", MagickCore::ColorspaceType::YDbDrColorspace},
        {"yiq", MagickCore::ColorspaceType::YIQColorspace},
        {"ypbpr", MagickCore::ColorspaceType::YPbPrColorspace},
        {"yuv", MagickCore::ColorspaceType::YUVColorspace} 
    };
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::ColorspaceTypeMap, colorspaceTypeMap, colorspaceType)
}

MagickCore::ClassType EffectsNative::stringToClassType(std::string value) {
    MagickCore::ClassType classType = MagickCore::ClassType::UndefinedClass;
    byMiroslavskyPrivate::ClassTypeMap classTypeMap = {
        {"direct", MagickCore::ClassType::DirectClass},
        {"pseudo", MagickCore::ClassType::PseudoClass},
        {"undefined", MagickCore::ClassType::UndefinedClass}
    }; 
    MAKE_ENUMS_MAP(byMiroslavskyPrivate::ClassTypeMap, classTypeMap, classType)
}