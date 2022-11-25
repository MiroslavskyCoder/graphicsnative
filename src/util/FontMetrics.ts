import { Geometry } from "./Geometry";

export interface OriginPos { 
    x: number;
    y: number;
}

export interface PixelsPerEm extends OriginPos { }

export type BoundsFontMetrics = Partial<Geometry>;
export type OriginPosFont = Partial<OriginPos>;
export type PixelsPerEmFont = Partial<PixelsPerEm>;

export interface FontMetrics {
    ascent: number;
    bounds: BoundsFontMetrics;
    descent: number;
    maxHorizontalAdvance: number;
    origin: OriginPosFont;
    pixelsPerEm: PixelsPerEmFont;
    textHeight: number;
    textWidth: number;
    underlinePosition: number;
    underlineThickness: number;
}

export interface FontMetricsMultiline extends FontMetrics {}