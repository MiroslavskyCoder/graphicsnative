#include "EffectsNative.h"

MagickCore::ChannelType EffectsNative::stringToChannelType(std::string value) {
    if (value == "a") {
        return MagickCore::ChannelType::aChannel;
    } else if (value == "all") {
        return MagickCore::ChannelType::AllChannels;
    } else if (value == "alpha") {
        return MagickCore::ChannelType::AlphaChannel;
    } else if (value == "b") {
        return MagickCore::ChannelType::bChannel;
    } else if (value == "black") {
        return MagickCore::ChannelType::BlackChannel;
    } else if (value == "blue") {
        return MagickCore::ChannelType::BlueChannel;
    } else if (value == "composite") {
        return MagickCore::ChannelType::CompositeChannels;
    } else if (value == "composite_mask") {
        return MagickCore::ChannelType::CompositeMaskChannel;
    } else if (value == "cyan") {
        return MagickCore::ChannelType::CyanChannel;
    } else if (value == "default") {
        return MagickCore::ChannelType::DefaultChannels;
    } else if (value == "gray") {
        return MagickCore::ChannelType::GrayChannel;
    } else if (value == "grays") {
        return MagickCore::ChannelType::GrayChannels;
    } else if (value == "green") {
        return MagickCore::ChannelType::GreenChannel; 
    } else if (value == "index") {
        return MagickCore::ChannelType::IndexChannel; 
    } else if (value == "l") {
        return MagickCore::ChannelType::LChannel; 
    } else if (value == "magenta") {
        return MagickCore::ChannelType::MagentaChannel; 
    } else if (value == "meta") {
        return MagickCore::ChannelType::MetaChannel; 
    } else if (value == "opacity") {
        return MagickCore::ChannelType::OpacityChannel; 
    } else if (value == "read_mask") {
        return MagickCore::ChannelType::ReadMaskChannel; 
    } else if (value == "red") {
        return MagickCore::ChannelType::RedChannel; 
    } else if (value == "rgb") {
        return MagickCore::ChannelType::RGBChannels; 
    } else if (value == "sync") {
        return MagickCore::ChannelType::SyncChannels; 
    } else if (value == "true_alpha") {
        return MagickCore::ChannelType::TrueAlphaChannel; 
    } else if (value == "undefined") {
        return MagickCore::ChannelType::UndefinedChannel; 
    } else if (value == "write_mask") {
        return MagickCore::ChannelType::WriteMaskChannel; 
    } else if (value == "yellow") {
        return MagickCore::ChannelType::YellowChannel; 
    } else {
        return MagickCore::ChannelType::UndefinedChannel;
    }
}

MagickCore::AutoThresholdMethod EffectsNative::stringToAutoThresholdMethod(std::string value) {
    if (value == "kapur_threshold") {
        return MagickCore::AutoThresholdMethod::KapurThresholdMethod;
    } else if (value == "otsu_threshold") {
        return MagickCore::AutoThresholdMethod::OTSUThresholdMethod;
    } else if (value == "triangle_threshold") {
        return MagickCore::AutoThresholdMethod::TriangleThresholdMethod;
    } else if (value == "undefined_threshold") {
        return MagickCore::AutoThresholdMethod::UndefinedThresholdMethod;
    } else {
        return MagickCore::AutoThresholdMethod::UndefinedThresholdMethod;
    }
}

MagickCore::GravityType EffectsNative::stringToGravityType(std::string value) {
    if (value == "center") {
        return MagickCore::GravityType::CenterGravity;
    } else if (value == "east") {
        return MagickCore::GravityType::EastGravity;
    } else if (value == "forget") {
        return MagickCore::GravityType::ForgetGravity;
    } else if (value == "north_east") {
        return MagickCore::GravityType::NorthEastGravity;
    } else if (value == "north") {
        return MagickCore::GravityType::NorthGravity;
    } else if (value == "north_west") {
        return MagickCore::GravityType::NorthWestGravity;
    } else if (value == "south_east") {
        return MagickCore::GravityType::SouthEastGravity;
    } else if (value == "south") {
        return MagickCore::GravityType::SouthGravity;
    } else if (value == "south_west") {
        return MagickCore::GravityType::SouthWestGravity;
    } else if (value == "undefined") {
        return MagickCore::GravityType::UndefinedGravity;
    } else if (value == "west") {
        return MagickCore::GravityType::WestGravity;
    } else {
        return MagickCore::GravityType::UndefinedGravity;
    }
}

MagickCore::VirtualPixelMethod EffectsNative::stringToVirtualPixelMethod(std::string value) {
    if (value == "background") {
        return MagickCore::VirtualPixelMethod::BackgroundVirtualPixelMethod;
    } else if (value == "black") {
        return MagickCore::VirtualPixelMethod::BlackVirtualPixelMethod;
    } else if (value == "checker") {
        return MagickCore::VirtualPixelMethod::CheckerTileVirtualPixelMethod;
    } else if (value == "dither") {
        return MagickCore::VirtualPixelMethod::DitherVirtualPixelMethod;
    } else if (value == "edge") {
        return MagickCore::VirtualPixelMethod::EdgeVirtualPixelMethod;
    } else if (value == "gray") {
        return MagickCore::VirtualPixelMethod::GrayVirtualPixelMethod;
    } else if (value == "horizontal_tile_edge") {
        return MagickCore::VirtualPixelMethod::HorizontalTileEdgeVirtualPixelMethod;
    } else if (value == "horizontal_tile") {
        return MagickCore::VirtualPixelMethod::HorizontalTileVirtualPixelMethod;
    } else if (value == "mask") {
        return MagickCore::VirtualPixelMethod::MaskVirtualPixelMethod;
    } else if (value == "mirror") {
        return MagickCore::VirtualPixelMethod::MirrorVirtualPixelMethod;
    } else if (value == "random") {
        return MagickCore::VirtualPixelMethod::RandomVirtualPixelMethod;
    } else if (value == "tile") {
        return MagickCore::VirtualPixelMethod::TileVirtualPixelMethod;
    } else if (value == "transparent") {
        return MagickCore::VirtualPixelMethod::TransparentVirtualPixelMethod;
    } else if (value == "undefined") {
        return MagickCore::VirtualPixelMethod::UndefinedVirtualPixelMethod;
    } else if (value == "vertical_tile_edge") {
        return MagickCore::VirtualPixelMethod::VerticalTileEdgeVirtualPixelMethod;
    } else if (value == "vertical_tile") {
        return MagickCore::VirtualPixelMethod::VerticalTileVirtualPixelMethod;
    } else if (value == "white") {
        return MagickCore::VirtualPixelMethod::WhiteVirtualPixelMethod;
    } else {
        return MagickCore::VirtualPixelMethod::UndefinedVirtualPixelMethod;
    }
}

MagickCore::StyleType EffectsNative::stringToStyleType(std::string value) {
    if (value == "any") {
        return MagickCore::StyleType::AnyStyle;
    } else if (value == "bold") {
        return MagickCore::StyleType::BoldStyle;
    } else if (value == "italic") {
        return MagickCore::StyleType::ItalicStyle;
    } else if (value == "normal") {
        return MagickCore::StyleType::NormalStyle;
    } else if (value == "oblique") {
        return MagickCore::StyleType::ObliqueStyle;
    } else if (value == "undefined") {
        return MagickCore::StyleType::UndefinedStyle;
    } else {
        return MagickCore::StyleType::UndefinedStyle;
    }
}

MagickCore::StretchType EffectsNative::stringToStretchType(std::string value) {
    if (value == "any") {
        return MagickCore::StretchType::AnyStretch;
    } else if (value == "condensed") {
        return MagickCore::StretchType::CondensedStretch;
    } else if (value == "expanded") {
        return MagickCore::StretchType::ExpandedStretch;
    } else if (value == "extra_condensed") {
        return MagickCore::StretchType::ExtraCondensedStretch;
    } else if (value == "extra_expanded") {
        return MagickCore::StretchType::ExtraExpandedStretch;
    } else if (value == "normal") {
        return MagickCore::StretchType::NormalStretch;
    } else if (value == "semi_condensed") {
        return MagickCore::StretchType::SemiCondensedStretch;
    } else if (value == "semi_expanded") {
        return MagickCore::StretchType::SemiExpandedStretch;
    } else if (value == "ultra_condensed") {
        return MagickCore::StretchType::UltraCondensedStretch;
    } else if (value == "ultra_expanded") {
        return MagickCore::StretchType::UltraExpandedStretch;
    } else if (value == "undefined") {
        return MagickCore::StretchType::UndefinedStretch;
    } else {
        return MagickCore::StretchType::UndefinedStretch;
    } 
}

MagickCore::FillRule EffectsNative::stringToFillRule(std::string value) {
    if (value == "even_odd") {
        return MagickCore::FillRule::EvenOddRule;
    } else if (value == "non_zero") {
        return MagickCore::FillRule::NonZeroRule;
    } else if (value == "undefined") {
        return MagickCore::FillRule::UndefinedRule;
    } else {
        return MagickCore::FillRule::UndefinedRule;
    }
}

MagickCore::NoiseType EffectsNative::stringToNoiseType(std::string value) {
    if (value == "gaussian") {
        return MagickCore::NoiseType::GaussianNoise;
    } else if (value == "impulse") {
        return MagickCore::NoiseType::ImpulseNoise;
    } else if (value == "laplacian") {
        return MagickCore::NoiseType::LaplacianNoise;
    } else if (value == "multiplicative_gaussian") {
        return MagickCore::NoiseType::MultiplicativeGaussianNoise;
    } else if (value == "poisson") {
        return MagickCore::NoiseType::PoissonNoise;
    } else if (value == "random") {
        return MagickCore::NoiseType::RandomNoise;
    } else if (value == "uniform") {
        return MagickCore::NoiseType::UniformNoise;
    } else if (value == "undefined") {
        return MagickCore::NoiseType::UndefinedNoise;
    } else {
        return MagickCore::NoiseType::UndefinedNoise;
    }
}

MagickCore::DirectionType EffectsNative::stringToDirectionType(std::string value) {
    if (value == "left_to_right") {
        return MagickCore::DirectionType::LeftToRightDirection;
    } else if (value == "right_to_left") {
        return MagickCore::DirectionType::RightToLeftDirection;
    } else if (value == "undefined") {
        return MagickCore::DirectionType::UndefinedDirection;
    } else {
        return MagickCore::DirectionType::UndefinedDirection;
    }
}

MagickCore::PixelInterpolateMethod EffectsNative::stringToPixelInterpolateMethod(std::string value) {
    if (value == "average16") {
        return MagickCore::PixelInterpolateMethod::Average16InterpolatePixel;
    } else if (value == "average9") {
        return MagickCore::PixelInterpolateMethod::Average9InterpolatePixel;
    } else if (value == "average") {
        return MagickCore::PixelInterpolateMethod::AverageInterpolatePixel;
    } else if (value == "background") {
        return MagickCore::PixelInterpolateMethod::BackgroundInterpolatePixel;
    } else if (value == "bilinear") {
        return MagickCore::PixelInterpolateMethod::BilinearInterpolatePixel;
    } else if (value == "blend") {
        return MagickCore::PixelInterpolateMethod::BlendInterpolatePixel;
    } else if (value == "catrom") {
        return MagickCore::PixelInterpolateMethod::CatromInterpolatePixel;
    } else if (value == "intege") {
        return MagickCore::PixelInterpolateMethod::IntegerInterpolatePixel;
    } else if (value == "mesh") {
        return MagickCore::PixelInterpolateMethod::MeshInterpolatePixel;
    } else if (value == "nearest") {
        return MagickCore::PixelInterpolateMethod::NearestInterpolatePixel;
    } else if (value == "spline") {
        return MagickCore::PixelInterpolateMethod::SplineInterpolatePixel;
    } else if (value == "undefined") {
        return MagickCore::PixelInterpolateMethod::UndefinedInterpolatePixel;
    } else {
        return MagickCore::PixelInterpolateMethod::UndefinedInterpolatePixel;
    }
}

MagickCore::PixelMask EffectsNative::stringToPixelMask(std::string value) {
    if (value == "composite") {
        return MagickCore::PixelMask::CompositePixelMask;
    } else if (value == "read") {
        return MagickCore::PixelMask::ReadPixelMask;
    } else if (value == "write") {
        return MagickCore::PixelMask::WritePixelMask;
    } else if (value == "undefined") {
        return MagickCore::PixelMask::UndefinedPixelMask;
    } else {
        return MagickCore::PixelMask::UndefinedPixelMask;
    }
}

MagickCore::RenderingIntent EffectsNative::stringToRenderingIntent(std::string value) {
    if (value == "absolute") {
        return MagickCore::RenderingIntent::AbsoluteIntent;
    } else if (value == "perceptual") {
        return MagickCore::RenderingIntent::PerceptualIntent;
    } else if (value == "relative") {
        return MagickCore::RenderingIntent::RelativeIntent;
    } else if (value == "saturation") {
        return MagickCore::RenderingIntent::SaturationIntent;
    } else if (value == "undefined") {
        return MagickCore::RenderingIntent::UndefinedIntent;
    } else {
        return MagickCore::RenderingIntent::UndefinedIntent;
    }
}

MagickCore::LineJoin EffectsNative::stringToLineJoin(std::string value) {
    if (value == "bevel") {
        return MagickCore::LineJoin::BevelJoin;
    } else if (value == "miter") {
        return MagickCore::LineJoin::MiterJoin;
    } else if (value == "round") {
        return MagickCore::LineJoin::RoundJoin;
    } else if (value == "undefined") {
        return MagickCore::LineJoin::UndefinedJoin;
    } else {
        return MagickCore::LineJoin::UndefinedJoin;
    }
}

MagickCore::LineCap EffectsNative::stringToLineCap(std::string value) {
    if (value == "butt") {
        return MagickCore::LineCap::ButtCap;
    } else if (value == "round") {
        return MagickCore::LineCap::RoundCap;
    } else if (value == "square") {
        return MagickCore::LineCap::SquareCap;
    } else if (value == "undefined") {
        return MagickCore::LineCap::UndefinedCap;
    } else {
        return MagickCore::LineCap::UndefinedCap;
    }
}

MagickCore::CompositeOperator EffectsNative::stringToCompositeOperator(std::string value) {
    if (value == "alpha") {
        return MagickCore::CompositeOperator::AlphaCompositeOp;
    } else if (value == "atop") {
        return MagickCore::CompositeOperator::AtopCompositeOp;
    } else if (value == "blend") {
        return MagickCore::CompositeOperator::BlendCompositeOp;
    } else if (value == "blur") {
        return MagickCore::CompositeOperator::BlurCompositeOp;
    } else if (value == "bumpmap") {
        return MagickCore::CompositeOperator::BumpmapCompositeOp;
    } else if (value == "change_mask") {
        return MagickCore::CompositeOperator::ChangeMaskCompositeOp;
    } else if (value == "clear") {
        return MagickCore::CompositeOperator::ClearCompositeOp;
    } else if (value == "color_burn") {
        return MagickCore::CompositeOperator::ColorBurnCompositeOp;
    } else if (value == "color_dodge") {
        return MagickCore::CompositeOperator::ColorDodgeCompositeOp;
    } else if (value == "colorize") {
        return MagickCore::CompositeOperator::ColorizeCompositeOp;
    } else if (value == "copy_alpha") {
        return MagickCore::CompositeOperator::CopyAlphaCompositeOp;
    } else if (value == "copy_black") {
        return MagickCore::CompositeOperator::CopyBlackCompositeOp;
    } else if (value == "copy_blue") {
        return MagickCore::CompositeOperator::CopyBlueCompositeOp;
    } else if (value == "copy") {
        return MagickCore::CompositeOperator::CopyCompositeOp;
    } else if (value == "copy_cyan") {
        return MagickCore::CompositeOperator::CopyCyanCompositeOp;
    } else if (value == "copy_green") {
        return MagickCore::CompositeOperator::CopyGreenCompositeOp;
    } else if (value == "copy_magenta") {
        return MagickCore::CompositeOperator::CopyMagentaCompositeOp;
    } else if (value == "copy_red") {
        return MagickCore::CompositeOperator::CopyRedCompositeOp;
    } else if (value == "copy_yellow") {
        return MagickCore::CompositeOperator::CopyYellowCompositeOp;
    } else if (value == "darken") {
        return MagickCore::CompositeOperator::DarkenCompositeOp;
    } else if (value == "darken_intensity") {
        return MagickCore::CompositeOperator::DarkenIntensityCompositeOp;
    } else if (value == "difference") {
        return MagickCore::CompositeOperator::DifferenceCompositeOp;
    } else if (value == "displace") {
        return MagickCore::CompositeOperator::DisplaceCompositeOp;
    } else if (value == "dissolve") {
        return MagickCore::CompositeOperator::DissolveCompositeOp;
    } else if (value == "distort") {
        return MagickCore::CompositeOperator::DistortCompositeOp;
    } else if (value == "divide_dst") {
        return MagickCore::CompositeOperator::DivideDstCompositeOp;
    } else if (value == "divide_src") {
        return MagickCore::CompositeOperator::DivideSrcCompositeOp;
    } else if (value == "dst_atop") {
        return MagickCore::CompositeOperator::DstAtopCompositeOp;
    } else if (value == "dst") {
        return MagickCore::CompositeOperator::DstCompositeOp;
    } else if (value == "dst_in") {
        return MagickCore::CompositeOperator::DstInCompositeOp;
    } else if (value == "dst_out") {
        return MagickCore::CompositeOperator::DstOutCompositeOp;
    } else if (value == "dst_over") {
        return MagickCore::CompositeOperator::DstOverCompositeOp;
    } else if (value == "exclusion") {
        return MagickCore::CompositeOperator::ExclusionCompositeOp;
    } else if (value == "freeze") {
        return MagickCore::CompositeOperator::FreezeCompositeOp;
    } else if (value == "hard_light") {
        return MagickCore::CompositeOperator::HardLightCompositeOp;
    } else if (value == "hard_mix") {
        return MagickCore::CompositeOperator::HardMixCompositeOp;
    } else if (value == "hue") {
        return MagickCore::CompositeOperator::HueCompositeOp;
    } else if (value == "in") {
        return MagickCore::CompositeOperator::InCompositeOp;
    } else if (value == "intensity") {
        return MagickCore::CompositeOperator::IntensityCompositeOp;
    } else if (value == "interpolate") {
        return MagickCore::CompositeOperator::InterpolateCompositeOp;
    } else if (value == "lighten") {
        return MagickCore::CompositeOperator::LightenCompositeOp;
    } else if (value == "lighten_intensity") {
        return MagickCore::CompositeOperator::LightenIntensityCompositeOp;
    } else if (value == "linear_burn") {
        return MagickCore::CompositeOperator::LinearBurnCompositeOp;
    } else if (value == "linear_dodge") {
        return MagickCore::CompositeOperator::LinearDodgeCompositeOp;
    } else if (value == "linear_light") {
        return MagickCore::CompositeOperator::LinearLightCompositeOp;
    } else if (value == "luminize") {
        return MagickCore::CompositeOperator::LuminizeCompositeOp;
    } else if (value == "mathematics") {
        return MagickCore::CompositeOperator::MathematicsCompositeOp;
    } else if (value == "minus_dst") {
        return MagickCore::CompositeOperator::MinusDstCompositeOp;
    } else if (value == "minus_src") {
        return MagickCore::CompositeOperator::MinusSrcCompositeOp;
    } else if (value == "modulate") {
        return MagickCore::CompositeOperator::ModulateCompositeOp;
    } else if (value == "modulus_add") {
        return MagickCore::CompositeOperator::ModulusAddCompositeOp;
    } else if (value == "modulus_subtract") {
        return MagickCore::CompositeOperator::ModulusSubtractCompositeOp;
    } else if (value == "multiply") {
        return MagickCore::CompositeOperator::MultiplyCompositeOp;
    } else if (value == "negate") {
        return MagickCore::CompositeOperator::NegateCompositeOp;
    } else if (value == "no") {
        return MagickCore::CompositeOperator::NoCompositeOp;
    } else if (value == "out") {
        return MagickCore::CompositeOperator::OutCompositeOp;
    } else if (value == "over") {
        return MagickCore::CompositeOperator::OverCompositeOp;
    } else if (value == "overlay") {
        return MagickCore::CompositeOperator::OverlayCompositeOp;
    } else if (value == "pegtop_light") {
        return MagickCore::CompositeOperator::PegtopLightCompositeOp;
    } else if (value == "pin_light") {
        return MagickCore::CompositeOperator::PinLightCompositeOp;
    } else if (value == "plus") {
        return MagickCore::CompositeOperator::PlusCompositeOp;
    } else if (value == "reflect") {
        return MagickCore::CompositeOperator::ReflectCompositeOp;
    } else if (value == "replace") {
        return MagickCore::CompositeOperator::ReplaceCompositeOp;
    } else if (value == "rmse") {
        return MagickCore::CompositeOperator::RMSECompositeOp;
    } else if (value == "saliency_blend") {
        return MagickCore::CompositeOperator::SaliencyBlendCompositeOp;
    } else if (value == "saturate") {
        return MagickCore::CompositeOperator::SaturateCompositeOp;
    } else if (value == "screen") {
        return MagickCore::CompositeOperator::ScreenCompositeOp;
    } else if (value == "seamless_blend") {
        return MagickCore::CompositeOperator::SeamlessBlendCompositeOp;
    } else if (value == "soft_burn") {
        return MagickCore::CompositeOperator::SoftBurnCompositeOp;
    } else if (value == "soft_dodge") {
        return MagickCore::CompositeOperator::SoftDodgeCompositeOp;
    } else if (value == "soft_light") {
        return MagickCore::CompositeOperator::SoftLightCompositeOp;
    } else if (value == "src_atop") {
        return MagickCore::CompositeOperator::SrcAtopCompositeOp;
    } else if (value == "src") {
        return MagickCore::CompositeOperator::SrcCompositeOp;
    } else if (value == "src_in") {
        return MagickCore::CompositeOperator::SrcInCompositeOp;
    } else if (value == "src_out") {
        return MagickCore::CompositeOperator::SrcOutCompositeOp;
    } else if (value == "src_over") {
        return MagickCore::CompositeOperator::SrcOverCompositeOp;
    } else if (value == "stamp") {
        return MagickCore::CompositeOperator::StampCompositeOp;
    } else if (value == "stereo") {
        return MagickCore::CompositeOperator::StereoCompositeOp;
    } else if (value == "threshold") {
        return MagickCore::CompositeOperator::ThresholdCompositeOp;
    } else if (value == "undefined") {
        return MagickCore::CompositeOperator::UndefinedCompositeOp;
    } else if (value == "vivid_light") {
        return MagickCore::CompositeOperator::VividLightCompositeOp;
    } else if (value == "xor") {
        return MagickCore::CompositeOperator::XorCompositeOp;
    } else {
        return MagickCore::CompositeOperator::UndefinedCompositeOp;
    }
}

MagickCore::MetricType EffectsNative::stringToMetricType(std::string value) {
    if (value == "absolute") {
        return MagickCore::MetricType::AbsoluteErrorMetric;
    } else if (value == "fuzz") {
        return MagickCore::MetricType::FuzzErrorMetric;
    } else if (value == "mean") {
        return MagickCore::MetricType::MeanAbsoluteErrorMetric;
    } else if (value == "mean_per") {
        return MagickCore::MetricType::MeanErrorPerPixelErrorMetric;
    } else if (value == "mean_squared") {
        return MagickCore::MetricType::MeanSquaredErrorMetric;
    } else if (value == "normalized_cross_correlation") {
        return MagickCore::MetricType::NormalizedCrossCorrelationErrorMetric;
    } else if (value == "peak_absolute") {
        return MagickCore::MetricType::PeakAbsoluteErrorMetric;
    } else if (value == "peak_signal_to_noise_ratio") {
        return MagickCore::MetricType::PeakSignalToNoiseRatioErrorMetric;
    } else if (value == "perceptual_hash") {
        return MagickCore::MetricType::PerceptualHashErrorMetric;
    } else if (value == "root_mean_squared") {
        return MagickCore::MetricType::RootMeanSquaredErrorMetric;
    } else if (value == "structural_dissimilarity") {
        return MagickCore::MetricType::StructuralDissimilarityErrorMetric;
    } else if (value == "structural_similarity") {
        return MagickCore::MetricType::StructuralSimilarityErrorMetric;
    } else if (value == "undefined") {
        return MagickCore::MetricType::UndefinedErrorMetric;
    } else {
        return MagickCore::MetricType::UndefinedErrorMetric;
    }
}
 
MagickCore::PixelTrait EffectsNative::stringToPixelTrait(std::string value) {
    if (value == "blend") {
        return MagickCore::PixelTrait::BlendPixelTrait;
    } else if (value == "copy") {
        return MagickCore::PixelTrait::CopyPixelTrait;
    } else if (value == "undefined") {
        return MagickCore::PixelTrait::UndefinedPixelTrait;
    } else if (value == "update") {
        return MagickCore::PixelTrait::UpdatePixelTrait;
    } else {
        return MagickCore::PixelTrait::UndefinedPixelTrait;
    }
}
 
MagickCore::ColorspaceType EffectsNative::stringToColorspaceType(std::string value) {
    if (value == "adobe98") {
        return MagickCore::ColorspaceType::Adobe98Colorspace;
    } else if (value == "cmy") {
        return MagickCore::ColorspaceType::CMYColorspace;
    } else if (value == "cmyk") {
        return MagickCore::ColorspaceType::CMYKColorspace;
    } else if (value == "display_p3") {
        return MagickCore::ColorspaceType::DisplayP3Colorspace;
    } else if (value == "gray") {
        return MagickCore::ColorspaceType::GRAYColorspace;
    } else if (value == "hcl") {
        return MagickCore::ColorspaceType::HCLColorspace;
    } else if (value == "hclp") {
        return MagickCore::ColorspaceType::HCLpColorspace;
    } else if (value == "hsb") {
        return MagickCore::ColorspaceType::HSBColorspace;
    } else if (value == "hsi") {
        return MagickCore::ColorspaceType::HSIColorspace;
    } else if (value == "hsl") {
        return MagickCore::ColorspaceType::HSLColorspace;
    } else if (value == "hsv") {
        return MagickCore::ColorspaceType::HSVColorspace;
    } else if (value == "hwb") {
        return MagickCore::ColorspaceType::HWBColorspace;
    } else if (value == "jzazbz") {
        return MagickCore::ColorspaceType::JzazbzColorspace;
    } else if (value == "lab") {
        return MagickCore::ColorspaceType::LabColorspace;
    } else if (value == "lchab") {
        return MagickCore::ColorspaceType::LCHabColorspace;
    } else if (value == "lch") {
        return MagickCore::ColorspaceType::LCHColorspace;
    } else if (value == "lchuv") {
        return MagickCore::ColorspaceType::LCHuvColorspace;
    } else if (value == "linear_gray") {
        return MagickCore::ColorspaceType::LinearGRAYColorspace;
    } else if (value == "lms") {
        return MagickCore::ColorspaceType::LMSColorspace;
    } else if (value == "log") {
        return MagickCore::ColorspaceType::LogColorspace;
    } else if (value == "luv") {
        return MagickCore::ColorspaceType::LuvColorspace;
    } else if (value == "ohta") {
        return MagickCore::ColorspaceType::OHTAColorspace;
    } else if (value == "pro_photo") {
        return MagickCore::ColorspaceType::ProPhotoColorspace;
    } else if (value == "rec601ycbcr") {
        return MagickCore::ColorspaceType::Rec601YCbCrColorspace;
    } else if (value == "rec709ycbcr") {
        return MagickCore::ColorspaceType::Rec709YCbCrColorspace;
    } else if (value == "rgb") {
        return MagickCore::ColorspaceType::RGBColorspace;
    } else if (value == "scrgb") {
        return MagickCore::ColorspaceType::scRGBColorspace;
    } else if (value == "srgb") {
        return MagickCore::ColorspaceType::sRGBColorspace;
    } else if (value == "transparent") {
        return MagickCore::ColorspaceType::TransparentColorspace;
    } else if (value == "undefined") {
        return MagickCore::ColorspaceType::UndefinedColorspace;
    } else if (value == "xyy") {
        return MagickCore::ColorspaceType::xyYColorspace;
    } else if (value == "xyz") {
        return MagickCore::ColorspaceType::XYZColorspace;
    } else if (value == "ycbcr") {
        return MagickCore::ColorspaceType::YCbCrColorspace;
    } else if (value == "ycc") {
        return MagickCore::ColorspaceType::YCCColorspace;
    } else if (value == "ydbdr") {
        return MagickCore::ColorspaceType::YDbDrColorspace;
    } else if (value == "yiq") {
        return MagickCore::ColorspaceType::YIQColorspace;
    } else if (value == "ypbpr") {
        return MagickCore::ColorspaceType::YPbPrColorspace;
    } else if (value == "yuv") {
        return MagickCore::ColorspaceType::YUVColorspace;
    } else {
        return MagickCore::ColorspaceType::UndefinedColorspace; 
    }
}

MagickCore::ClassType EffectsNative::stringToClassType(std::string value) {
    if (value == "direct") {
        return MagickCore::ClassType::DirectClass;
    } else if (value == "pseudo") {
        return MagickCore::ClassType::PseudoClass;
    } else if (value == "undefined") {
        return MagickCore::ClassType::UndefinedClass;
    } else {
        return MagickCore::ClassType::UndefinedClass;
    }
}