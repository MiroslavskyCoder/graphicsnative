import Module from "module";
import path from "path";
import { 
    FontMetrics, 
    FontMetricsMultiline
} from "./util/FontMetrics";
import {
    ParamsAdaptiveBlur,
    ParamsAdaptiveResize,
    ParamsAdaptiveSharpen,
    ParamsAdaptiveSharpenChannel,
    ParamsAdaptiveThreshold,
    ParamsAddBorder,
    ParamsAddRoundRectangle,
    ParamsAddSource,
    ParamsAddText,
    ParamsAnnotate,
    ParamsAttribute,
    ParamsBlur,
    ParamsColorize,
    ParamsColorMatrix,
    ParamsFloodFillAlpha,
    ParamsFloodFillColor,
    ParamsModulate,
    ParamsOpaque,
    ParamsProcess,
    ParamsRead
} from "./params"; 
import {
    IAutoThresholdMethod,
    IChannelType,
    ICompositeOperator,
    IDirectionType,
    IFillRule,
    IGravityType,
    ILineCap,
    ILineJoin,
    IMetricType,
    INoiseType,
    IPixelInterpolateMethod,
    IRenderingIntent,
    IVirtualPixelMethod
} from "./types";
import { Pos } from "./util/Pos"; 
import { Geometry } from "./util/Geometry";
import { Color } from "./util/Color"; 

export function createRequire() {
    return Module.createRequire(import.meta.url);
} 

const requireNative = createRequire(); 
const binding = requireNative(path.resolve("napi", "GraphicsNative.node"));

/**
 * @class
 */
export class EffectsNative {
    private _image: any;

    /**
     * 
     * @param {Buffer | string | any} value 
     * @constructor
     */
    constructor(value: Buffer | string | any) {
        if (value instanceof binding.EffectsNative) this._image = value; 
        else this._image = new binding.EffectsNative(value);
    }

    /**
     * 
     * @param {number} w 
     * @param {number} h 
     * @return {EffectsNative}
     */
    static createImage(w: number, h: number) {
        const data = Buffer.alloc(w * h * 3);
        return new EffectsNative(new binding.EffectsNative(w, h, "RGB", data));
    } 

    /**
     * @type {number}
     */
    get strokeWidth(): number { 
        return this._image.getStrokeWidth();
    }
    /**
     * @type {number}
     */
    get width(): number {
        return this._image.getWidth();
    }
    /**
     * @type {number}
     */
    get height(): number {
        return this._image.getHeight();
    }
    
    /**
     * @type {any}
     */
    get context() {
        return this._image;
    }

    /**
     * 
     * @param {ParamsAdaptiveBlur | number} value 
     * @param {number} sigma 
     */
    adaptiveBlur(value: ParamsAdaptiveBlur | number, sigma?: number): void { 
        if (arguments.length == 1) {
            this._image.adaptiveBlur(value);
        } else {
            this._image.adaptiveBlur(value, sigma);
        }
    }
    /**
     * 
     * @param {ParamsAdaptiveResize | number | string} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     */
    adaptiveResize(value: ParamsAdaptiveResize | number | string, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.adaptiveResize(value);
        } else {
            this._image.adaptiveResize(value, height, x, y);
        }
    }
    /**
     * 
     * @param {ParamsAdaptiveSharpen | number} value 
     * @param {number} sigma 
     * @return {void}
     */
    adaptiveSharpen(value: ParamsAdaptiveSharpen | number, sigma?: number): void {
        if (arguments.length == 1) {
            this._image.adaptiveSharpen(value);
        } else {
            this._image.adaptiveSharpen(value, sigma);
        }
    }
    /**
     * 
     * @param {ParamsAdaptiveSharpenChannel | IChannelType} value 
     * @param {number} radius 
     * @param {number} sigma 
     * @return {void}
     */
    adaptiveSharpenChannel(value: ParamsAdaptiveSharpenChannel | IChannelType, radius?: number, sigma?: number): void {
        if (arguments.length == 1) {
            this._image.adaptiveSharpenChannel(value);
        } else {
            this._image.adaptiveSharpenChannel(value, radius, sigma);
        }
    }
    /**
     * 
     * @param {ParamsAdaptiveThreshold | number} value 
     * @param {number} height 
     * @param {number} bias 
     * @return {void}
     */
    adaptiveThreshold(value: ParamsAdaptiveThreshold | number, height?: number, bias?: number): void {
        if (arguments.length == 1) {
            this._image.adaptiveThreshold(value);
        } else {
            this._image.adaptiveThreshold(value, height, bias);
        }
    }
    /**
     * 
     * @param {number} sx 
     * @param {number} sy 
     * @param {number} rx 
     * @param {number} ry 
     * @param {number} tx 
     * @param {number} ty 
     * @return {void}
     */
    addAffine(sx: number, sy: number, rx: number, ry: number, tx: number, ty: number): void {
        this._image.addAffine(sx, sy, rx, ry, tx, ty);
    }
    /**
     * 
     * @param {number} startX 
     * @param {number} startY 
     * @param {number} endX 
     * @param {number} endY 
     * @param {number} startDegrees 
     * @param {number} endDegrees 
     * @return {void}
     */
    addArc(startX: number, startY: number, endX: number, endY: number, startDegrees: number, endDegrees: number): void {
        this._image.addArc(startX, startY, endX, endY, startDegrees, endDegrees);
    }
    /**
     * 
     * @param {ParamsAddBorder | number} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    addBorder(value: ParamsAddBorder | number, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.addBorder(value);
        } else {
            this._image.addBorder(value, height, x, y);
        }
    }
    /**
     * 
     * @param {number} originX 
     * @param {number} originY 
     * @param {number} perimX 
     * @param {number} perimY
     * @return {void}
     */
    addCircle(originX: number, originY: number, perimX: number, perimY: number): void {
        this._image.addCircle(originX, originY, perimX, perimY);
    }
    /**
     * 
     * @param {EffectsNative} source 
     * @return {void}
     */
    addFrame(source: EffectsNative): void { 
        if (source instanceof binding.EffectsNative) {
            this._image.addFrame(source);
        } else if (source instanceof EffectsNative) {
            this._image.addFrame(source.context);
        }
    }
    /**
     * 
     * @param {INoiseType} type 
     * @return {void}
     */
    addNoise(type: INoiseType): void {
        this._image.addNoise(type);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {INoiseType} type 
     * @return {void}
     */
    addNoiseChannel(channel: IChannelType, type: INoiseType): void { 
        this._image.addNoiseChannel(channel, type);
    }
    /**
     * 
     * @param {Pos[][]} polygons
     * @return {void}
     */
    addPolygon(...polygons: Pos[][]): void {
        this._image.addPolygon(...polygons);
    }
    /**
     * 
     * @param {ParamsAddRoundRectangle | number} value 
     * @param {number} upperLeftY 
     * @param {number} lowerRightX 
     * @param {number} lowerRightY 
     * @param {number} cornerWidth 
     * @param {number} cornerHeight 
     * @return {void}
     */
    addRoundRectangle(value: ParamsAddRoundRectangle | number, upperLeftY?: number, lowerRightX?: number, lowerRightY?: number, cornerWidth?: number, cornerHeight?: number): void {
        if (arguments.length == 1) {
            this._image.addRoundRectangle(value);
        } else {
            this._image.addRoundRectangle(value, upperLeftY, lowerRightX, lowerRightY, cornerWidth, cornerHeight); 
        }
    }
    /**
     * 
     * @param {ParamsAddSource<EffectsNative | any> | number} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    addSource(value: ParamsAddSource<EffectsNative | any> | number, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.addSource(value);
        } else {
            this._image.addSource(value, height, x, y);
        }
    }
    /**
     * 
     * @param {ParamsAddText} value 
     * @return {void}
     */
    addText(value: ParamsAddText): void {
        this._image.addText(value);
    }
    /**
     * 
     * @param {boolean} flag 
     * @return {void}
     */
    adjoin(flag: boolean): void {
        this._image.adjoin(flag);
    } 
    /**
     * 
     * @param {number} value
     * @param {number} sy 
     * @param {number} rx 
     * @param {number} ry 
     * @param {number} tx 
     * @param {number} ty 
     * @return {void}
     */
    affineTransform(value: number, sy: number, rx: number, ry: number, tx: number, ty: number): void {
        if (arguments.length == 1) {
            this._image.affineTransform(value);
        } else {
            this._image.affineTransform(value, sy, rx, ry, tx, ty);
        }
    }
    /**
     * 
     * @param {boolean | number} flag 
     * @return {void}
     */
    alpha(flag: boolean | number): void {
        this._image.alpha(flag);
    }
    /**
     * 
     * @param {number} delay 
     * @return {void}
     */
    animationDelay(delay: number): void {
        this._image.animationDelay(delay);
    }
    /**
     * 
     * @param {number} iterations 
     * @return {void}
     */
    animationIterations(iterations: number): void {
        this._image.animationIterations(iterations); 
    }
    /**
     * 
     * @param {ParamsAnnotate | string} value 
     * @param {IGravityType} gravity 
     * @return {void}
     */
    annotate(value: ParamsAnnotate | string, gravity?: IGravityType): void {
        if (arguments.length == 1) {
            this._image.annotate(value);
        } else {
            this._image.annotate(value, gravity);
        }
    }
    /**
     * 
     * @param {string} name 
     * @return {void}
     */
    artifact(name: string): void {
        this._image.artifact(name);
    }
    /**
     * 
     * @param {ParamsAttribute | string} key 
     * @param {string} value 
     * @return {void}
     */
    attribute(key: ParamsAttribute | string, value?: string): void {
        if (arguments.length == 1) {
            this._image.attribute(key);
        } else {
            this._image.attribute(key, value);
        }
    }
    /**
     * @return {void}
     */
    autoGamma(): void {
        this._image.autoGamma();
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @return {void}
     */
    autoGammaChannel(channel: IChannelType): void {
        this._image.autoGammaChannel(channel);
    }
    /**
     * @return {void}
     */
    autoLevel(): void {
        this._image.autoLevel();
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @return {void}
     */
    autoLevelChannel(channel: IChannelType): void {
        this._image.autoLevelChannel(channel);
    }
    /**
     * @return {void}
     */
    autoOrient(): void {
        this._image.autoOrient();
    }
    /**
     * 
     * @param {IAutoThresholdMethod} type 
     * @return {void}
     */
    autoThreshold(type: IAutoThresholdMethod): void {
        this._image.autoThreshold(type); 
    }
    /**
     * 
     * @param {string} color 
     * @return {void}
     */
    backgroundColor(color: string): void {
        this._image.backgroundColor(color);
    }
    /**
     * 
     * @param {string} name 
     * @return {void}
     */
    backgroundTexture(name: string): void {
        this._image.backgroundTexture(name);
    }
    /**
     * 
     * @param {string} threshold 
     * @return {void}
     */
    blackThreshold(threshold: string): void {
        this._image.blackThreshold(threshold);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {string} threshold 
     * @return {void}
     */
    blackThresholdChannel(channel: IChannelType, threshold: string): void {
        this._image.blackThresholdChannel(channel, threshold);
    }
    /**
     * 
     * @param {number} radius 
     * @return {void}
     */
    blueShift(radius?: number): void {
        this._image.blueShift(typeof(radius)=="number"?radius:2.5);
    }
    /**
     * 
     * @param {ParamsBlur | number} value 
     * @param {number} sigma 
     * @return {void}
     */
    blur(value: ParamsBlur | number, sigma?: number): void {
        if (arguments.length == 1) {
            this._image.blur(value);
        } else {
            this._image.blur(value, sigma);
        }
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {number} radius 
     * @param {number} sigma 
     * @return {void}
     */
    blurChannel(channel: IChannelType, radius: number, sigma: number): void {
        this._image.blurChannel(channel, radius, sigma);
    }
    /**
     * 
     * @param {number | string} value
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    border(value: number | string, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.border(value);
        } else {
            this._image.border(value, height, x, y);
        }
    }
    /**
     * 
     * @param {string} color 
     * @return {void}
     */
    borderColor(color: string): void {
        this._image.borderColor(color);
    }
    /**
     * 
     * @return {Geometry & { less: boolean, limitPixels: boolean }}
     */
    boundingBox(): Geometry & { less: boolean, limitPixels: boolean } {
        return this._image.boundingBox();
    }
    /**
     * 
     * @param {string} color 
     * @return {void}
     */
    boxColor(color: string): void {
        this._image.boxColor(color);
    }
    /**
     * 
     * @param {number} radius 
     * @param {number} sigma 
     * @param {number} lower 
     * @param {number} upper 
     * @return {void}
     */
    cannyEdge(radius?: number, sigma?: number, lower?: number, upper?: number): void {
        this._image.cannyEdge(radius, sigma, lower, upper);
    }
    /**
     * 
     * @param {string} cdl 
     * @return {void}
     */
    cdl(cdl: string): void {
        this._image.cdl(cdl);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @return {void}
     */
    channel(channel: IChannelType): void {
        this._image.channel(channel);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {number} depth 
     * @return {void}
     */
    channelDepth(channel: IChannelType, depth: number): void {
        this._image.channelDepth(channel, depth);
    }
    /**
     * 
     * @param {number} radius 
     * @param {number} sigma 
     * @return {void}
     */
    charcoal(radius: number, sigma: number): void {
        this._image.charcoal(radius, sigma);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {number} radius 
     * @param {number} sigma 
     * @return {void}
     */
    charcoalChannel(channel: IChannelType, radius: number, sigma: number): void {
        this._image.charcoalChannel(channel, radius, sigma);
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    chop(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.chop(value);
        } else {
            this._image.chop(value, height, x, y);
        }
    }
    /**
     * @return {void}
     */
    clamp(): void {
        this._image.clamp();
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @return {void}
     */
    clampChannel(channel: IChannelType): void {
        this._image.clampChannel(channel);
    }
    /**
     * @return {void}
     */
    clip(): void {
        this._image.clip();
    }
    /**
     * 
     * @param {string} pathname 
     * @param {string} inside 
     * @return {void}
     */
    clipPath(pathname: string, inside: boolean): void {
        this._image.clipPath(pathname, inside);
    }
    /**
     * 
     * @param {EffectsNative | any} source 
     * @param {IPixelInterpolateMethod} pixel_interpolate
     * @return {void} 
     */
    clut(source: EffectsNative | any, pixel_interpolate: IPixelInterpolateMethod): void {
        if (source instanceof binding.EffectsNative) this._image.clut(source, pixel_interpolate);
        else if (source instanceof EffectsNative) this._image.clut(source.context, pixel_interpolate);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {EffectsNative | any} source 
     * @param {IPixelInterpolateMethod} pixel_interpolate 
     * @return {void}
     */
    clutChannel(channel: IChannelType, source: EffectsNative | any, pixel_interpolate: IPixelInterpolateMethod): void { 
        if (source instanceof binding.EffectsNative) this._image.clutChannel(channel, source, pixel_interpolate);
        else if (source instanceof EffectsNative) this._image.clutChannel(channel, source.context, pixel_interpolate);
    }
    /**
     * 
     * @param {number} fuzz 
     * @return {void}
     */
    colorFuzz(fuzz: number): void {
        this._image.colorFuzz(fuzz);
    }
    /**
     * 
     * @param {ParamsColorize | number} value 
     * @param {Partial<Color> | string} color 
     * @return {void}
     */
    colorize(value: ParamsColorize | number, color?: Partial<Color> | string): void {
        if (arguments.length == 0) {
            this._image.colorize(value);
        } else {
            this._image.colorize(value, color);
        }
    }
    /**
     * 
     * @param {ParamsColorMatrix | number} value 
     * @param {number[]} matrix 
     * @return {void}
     */
    colorMatrix(value: ParamsColorMatrix | number, matrix?: number[]): void {
        if (arguments.length == 1) {
            this._image.colorMatrix(value);
        } else {
            this._image.colorMatrix(value, matrix);
        }
    }
    /**
     * 
     * @param {EffectsNative | any} source 
     * @return {void}
     */
    compare(source: EffectsNative | any, metric?: IMetricType, distortion?: number[]): void {
        if (arguments.length == 1) {
            if (source instanceof binding.EffectsNative) this._image.compare(source); 
            else if (source instanceof EffectsNative) this._image.compare(source.context);
        } else {
            if (source instanceof binding.EffectsNative) this._image.compare(source, metric, distortion); 
            else if (source instanceof EffectsNative) this._image.compare(source.context, metric, distortion);
        }
    }
    /**
     * 
     * @param {ICompositeOperator} type 
     * @return {void}
     */
    compose(type: ICompositeOperator): void {
        this._image.compose(type);
    }
    /**
     * 
     * @param {"gravity" | "geometry"} type 
     * @param {EffectsNative | any} source 
     * @param {string} value
     * @return {void} 
     */
    composite(type: "gravity" | "geometry", source: EffectsNative | any, value: string): void { 
        if (source instanceof binding.EffectsNative) this._image.composite(type, source, value); 
        else if (source instanceof EffectsNative) this._image.composite(type, source.context, value);
    }
    /**
     * 
     * @param {number} sharpen 
     * @return {void} 
     */
    contrast(sharpen: number): void {
        this._image.contrast(sharpen);
    }
    /**
     * 
     * @param {number} blackPoint 
     * @param {number} whitePoint 
     * @return {void}
     */
    contrastStretch(blackPoint: number, whitePoint: number): void {
        this._image.contrastStretch(blackPoint, whitePoint);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {number} blackPoint 
     * @param {number} whitePoint
     * @return {void} 
     */
    contrastStretchChannel(channel: IChannelType, blackPoint: number, whitePoint: number): void {
        this._image.contrastStretchChannel(channel, blackPoint, whitePoint);
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    crop(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.crop(value);
        } else {
            this._image.crop(value, height, x, y);
        }
    }
    /**
     * 
     * @param {string} magick 
     * @param {string} key 
     * @param {boolean} flag 
     * @return {void}
     */
    defineSet(magick: string, key: string, flag?: boolean): void {
        this._image.defineSet(magick, key, flag);
    }
    /**
     * 
     * @param {string} magick 
     * @param {string} key 
     * @param {string} value 
     * @return {void}
     */
    defineValue(magick: string, key: string, value: string): void {
        this._image.defineValue(magick, key, value); 
    }
    /**
     * 
     * @param {string} title 
     * @return {void}
     */
    display(title: string): void {
        this._image.display(title);
    }
    /**
     * 
     * @param {string} passphrase 
     * @return {void}
     */
    encipher(passphrase: string): void {
        this._image.encipher(passphrase);
    }
    /**
     * @return {void}
     */
    enhance(): void {
        this._image.enhance();
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    extent(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.extent(value);
        } else {
            this._image.extent(value, height, x, y);
        }
    }
    /**
     * 
     * @param {string} color 
     * @return {void}
     */
    fillColor(color: string): void { 
        this._image.fillColor(color);
    }
    /**
     * 
     * @param {EffectsNative | any} source 
     * @return {void}
     */
    fillPattern(source: EffectsNative | any): void {
        if (source instanceof binding.EffectsNative) {
            this._image.fillPattern(source);
        } else if (source instanceof EffectsNative) {
            this._image.fillPattern(source.context);
        }
    }
    /**
     * 
     * @param {IFillRule} rule 
     * @return {void}
     */
    fillRule(rule: IFillRule): void {
        this._image.fillRule(rule);
    }
    /**
     * @return {void}
     */
    flip(): void {
        this._image.flip();
    }
    /**
     * 
     * @param {ParamsFloodFillAlpha | number} value 
     * @param {number} y 
     * @param {number} alpha 
     * @param {...args[]} args 
     * @return {void}
     */
    floodFillAlpha(value: ParamsFloodFillAlpha | number, y?: number, alpha?: number, ...args: any[]): void {
        if (arguments.length == 1) {
            this._image.floodFillAlpha(value);
        } else {
            this._image.floodFillAlpha(value, y, alpha, ...args);
        }
    }
    /**
     * 
     * @param {ParamsFloodFillColor | string} value 
     * @param {string} color 
     * @param {...args[]} args 
     * @return {void}
     */
    floodFillColor(value: ParamsFloodFillColor | string, color?: string, ...args: any[]): void {
        if (arguments.length == 1) {
            this._image.floodFillColor(value);
        } else {
            this._image.floodFillColor(value, color, ...args);
        }
    }
    /**
     * 
     * @param {string} point 
     * @param {EffectsNative | any} source 
     * @param {...args[]} args 
     * @return {void}
     */
    floodFillTexture(point: string, source: EffectsNative | any, ...args: any[]): void {
        if (source instanceof binding.EffectsNative) {
            this._image.floodFillTexture(point, source, ...args);
        } else if (source instanceof EffectsNative) {
            this._image.floodFillTexture(point, source.context, ...args);
        }
    }
    /**
     * 
     * @param {string} name 
     * @return {void}
     */
    font(name: string): void {
        this._image.font(name);
    }
    /**
     * 
     * @param {string} family 
     * @return {void}
     */
    fontFamily(family: string): void {
        this._image.fontFamily(family);
    }
    /**
     * 
     * @param {number} size 
     * @return {void}
     */
    fontPointsize(size: number): void {
        this._image.fontPointsize(size);
    }
    /**
     * 
     * @param style 
     * @return {void}
     */
    fontStyle(style: string): void {
        this._image.fontStyle(style);
    }
    /**
     * 
     * @return {FontMetrics}
     */
    fontTypeMetrics(): FontMetrics {
        return this._image.fontTypeMetrics();
    }
    /**
     * 
     * @return {FontMetricsMultiline}
     */
    fontTypeMetricsMultiline(): FontMetricsMultiline {
        return this._image.fontTypeMetricsMultiline();
    } 
    /**
     * 
     * @param {number} weight 
     * @return {void}
     */
    fontWeight(weight: number): void {
        this._image.fontWeight(weight);
    }
    /**
     * 
     * @param {string} expression 
     * @param {IChannelType} channel 
     * @return {void}
     */
    fx(expression: string, channel?: IChannelType): void {
        this._image.fx(expression, channel);
    }
    /**
     * 
     * @param {number} gamma 
     * @return {void}
     */
    gamma(gamma: number): void {
        this._image.gamma(gamma);
    }
    /**
     * @return {Buffer}
     */
    getPixels(): Buffer {
        return this._image.getPixels();
    }
    /**
     * 
     * @param {EffectsNative | any} source 
     * @return {void}
     */
    haldClut(source: EffectsNative | any): void {
        if (source instanceof binding.EffectsNative) {
            this._image.haldClut(source);
        } else if (source instanceof EffectsNative) {
            this._image.haldClut(source.context);
        }
    }
    /**
     * 
     * @param {number} radius 
     * @return {void}
     */
    implode(radius: number): void {
        this._image.implode(radius);
    }
    /**
     * 
     * @param {string} label 
     * @return {void}
     */
    label(label: string): void {
        this._image.label(label);
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    liquid(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.liquidRescale(value);
        } else {
            this._image.liquidRescale(value, height, x, y);
        }
    }
    /**
     * 
     * @param {number} radius 
     * @return {void}
     */
    medianFilter(radius: number): void {
        this._image.medianFilter(radius);
    }
    /**
     * @return {void}
     */
    modify(): void {
        this._image.modify();
    }
    /**
     * 
     * @param {ParamsModulate | number} value 
     * @param {number} saturation 
     * @param {number} hue 
     * @return {void}
     */
    modulate(value: ParamsModulate | number, saturation?: number, hue?: number): void {
        if (arguments.length == 1) {
            this._image.modulate(value);
        } else {
            this._image.modulate(value, saturation, hue);
        }
    }
    /**
     * 
     * @param {number} radius 
     * @param {number} sigma 
     * @param {number} angle 
     * @return {void}
     */
    motionBlur(radius: number, sigma: number, angle: number): void {
        this._image.motionBlur(radius, sigma, angle);
    }
    /**
     * 
     * @param {boolean} grayscale
     * @return {void}
     */
    negate(grayscale?: boolean): void {
        this._image.negate(grayscale);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {boolean} grayscale
     * @return {void} 
     */
    negateChannel(channel: IChannelType, grayscale?: boolean): void {
        this._image.negateChannel(channel, grayscale);
    }
    /**
     * 
     * @param {ParamsOpaque | string} value 
     * @param {string} pen 
     * @param {boolean} invert
     * @return {void} 
     */
    opaque(value: ParamsOpaque | string, pen?: string, invert?: boolean): void {
        if (arguments.length == 1) {
            this._image.opaque(value);
        } else {
            this._image.opaque(value, pen, invert);
        }
    }
    /**
     * 
     * @param {string} thresholdMap 
     * @return {void}
     */
    orderedDither(thresholdMap: string): void {
        this._image.orderedDither(thresholdMap);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {string} thresholdMap
     * @return {void} 
     */
    orderedDitherChannel(channel: IChannelType, thresholdMap: string): void {
        this._image.orderedDitherChannel(channel, thresholdMap);
    }
    /**
     * 
     * @param {number} epsilon 
     * @return {void}
     */
    perceptible(epsilon: number): void {
        this._image.perceptible(epsilon);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {number} epsilon 
     * @return {void}
     */
    perceptibleChannel(channel: IChannelType, epsilon: number): void {
        this._image.perceptibleChannel(channel, epsilon);
    }
    /**
     * 
     * @param {ParamsProcess | string} value 
     * @param {string[]} args 
     * @return {void}
     */
    process(value: ParamsProcess | string, args: string[]): void {
        if (arguments.length == 1) {
            this._image.process(value);
        } else {
            this._image.process(value, args);
        }
    }
    /**
     * 
     * @param {Buffer} pixels 
     * @return {void}
     */
    putPixels(pixels: Buffer): void {
        this._image.putPixels(pixels);
    }
    /**
     * 
     * @param {number} quality 
     * @return {void}
     */
    quality(quality: number): void {
        this._image.quality(quality);
    }
    /**
     * 
     * @param {boolean} measureError 
     * @return {void}
     */
    quantize(measureError: boolean): void {
        this._image.quantize(measureError);
    }
    /**
     * 
     * @param {ParamsRead | number} value 
     * @param {number} height 
     * @param {string} format 
     * @param {Buffer} buffer
     * @return {void} 
     */
    read(value: ParamsRead | number, height?: number, format?: string, buffer?: Buffer): void {
        if (arguments.length == 1) {
            this._image.read(value);
        } else {
            this._image.read(value, height, format, buffer);
        }
    }
    /**
     * 
     * @param {IRenderingIntent} type 
     * @return {void}
     */
    renderingIntent(type: IRenderingIntent): void {
        this._image.renderingIntent(type);
    }
    /**
     * @return {void}
     */
    repage(): void {
        this._image.repage();
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    resize(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.resize(value);
        } else {
            this._image.resize(value, height, x, y);
        }
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    roll(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.roll(value);
        } else {
            this._image.roll(value, height, x, y);
        }
    }
    /**
     * 
     * @param {number} degrees 
     * @return {void}
     */
    rotate(degrees: number): void {
        degrees %= 360;
        this._image.rotate(degrees);
    }
    /**
     * 
     * @param {number} angle 
     * @return {void}
     */
    rotationalBlur(angle: number): void {
        this._image.angle(angle);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {number} angle 
     * @return {void}
     */
    rotationalBlurChannel(channel: IChannelType, angle: number): void {
        this._image.rotationalBlurChannel(channel, angle);
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    scale(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.scale(value);
        } else {
            this._image.scale(value, height, x, y);
        }
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    size(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.size(value);
        } else {
            this._image.size(value, height, x, y);
        }
    }
    /**
     * 
     * @param {...any[]} args 
     * @return {void}
     */
    splice(...args: any[]): void {
        this._image.splice(...args);
    }
    /**
     * 
     * @param {EffectsNative | any} source 
     * @return {void}
     */
    stereo(source: EffectsNative | any): void {
        if (source instanceof binding.EffectsNative) {
            this._image.stereo(source);
        } else if (source instanceof EffectsNative) {
            this._image.stereo(source.context);
        }
    }
    /**
     * 
     * @param {boolean} flag 
     * @return {void}
     */
    strokeAntiAlias(flag?: boolean): void {
        this._image.strokeAntiAlias(flag);
    }
    /**
     * 
     * @param {string} color 
     * @return {void}
     */
    strokeColor(color: string): void {
        this._image.strokeColor(color);
    }
    /**
     * 
     * @param {number[]} dash_array 
     * @return {void}
     */
    strokeDashArray(dash_array: number[]): void {
        this._image.strokeDashArray(dash_array);
    }
    /**
     * 
     * @param {number} dash_offset 
     * @return {void}
     */
    strokeDashOffset(dash_offset: number): void {
        this._image.strokeDashOffset(dash_offset);
    }
    /**
     * 
     * @param {ILineCap} lineCap 
     * @return {void}
     */
    strokeLineCap(lineCap: ILineCap): void {
        this._image.strokeLineCap(lineCap);
    } 
    /**
     * 
     * @param {ILineJoin} lineJoin 
     * @return {void}
     */
    strokeLineJoin(lineJoin: ILineJoin): void {
        this._image.strokeLineJoin(lineJoin);
    }
    /**
     * 
     * @param {number} miter_limit 
     * @return {void}
     */
    strokeMiterLimit(miter_limit: number): void {
        this._image.strokeMiterLimit(miter_limit);
    }
    /**
     * 
     * @param {EffectsNative | any} source 
     * @return {void}
     */
    strokePattern(source: EffectsNative | any): void {
        if (source instanceof binding.EffectsNative) {
            this._image.strokePattern(source);
        } else if (source instanceof EffectsNative) {
            this._image.strokePattern(source.context);
        }
    }
    /**
     * 
     * @param {number} sub_image 
     * @return {void}
     */
    subImage(sub_image: number): void {
        this._image.subImage(sub_image);
    }
    /**
     * 
     * @param {number} sub_range 
     * @return {void}
     */
    subRange(sub_range: number): void {
        this._image.subRange(sub_range);
    }
    /**
     * 
     * @param {boolean} flag 
     * @return {void}
     */
    textAntiAlias(flag: boolean): void {
        this._image.textAntiAlias(flag);
    } 
    /**
     * 
     * @param {IDirectionType} direction 
     * @return {void}
     */
    textDirection(direction: IDirectionType): void {
        this._image.textDirection(direction);
    }
    /**
     * 
     * @param {IGravityType} gravity 
     * @return {void}
     */
    textGravity(gravity: IGravityType): void {
        this._image.textGravity(gravity);
    }
    /**
     * 
     * @param {number} spacing 
     * @return {void}
     */
    textInterlineSpacing(spacing: number): void {
        this._image.textInterlineSpacing(spacing);
    }
    /**
     * 
     * @param {number} spacing 
     * @return {void}
     */
    textInterwordSpacing(spacing: number): void {
        this._image.textInterwordSpacing(spacing);
    } 
    /**
     * 
     * @param {number} kerning 
     * @return {void}
     */
    textKerning(kerning: number): void {
        this._image.textKerning(kerning);
    }
    /**
     * 
     * @param {string} color 
     * @return {void}
     */
    textUnderColor(color: string): void {
        this._image.textUnderColor(color);
    }
    /**
     * 
     * @param {EffectsNative | any} source 
     * @return {void}
     */
    texture(source: EffectsNative | any): void {
        if (source instanceof binding.EffectsNative) {
            this._image.texture(source);
        } else if (source instanceof EffectsNative) {
            this._image.texture(source.context);
        }
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    thumbnail(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.thumbnail(value);
        } else {
            this._image.thumbnail(value, height, x, y);
        }
    }
    /**
     * 
     * @param {number} opacity 
     * @return {void}
     */
    tint(opacity: number): void {
        this._image.tint(opacity);
    }
    /**
     * 
     * @param {string} format 
     * @return {string}
     */
    toBase64(format?: string): string {
        return this._image.toBase64(format);
    }
    /**
     * 
     * @param {string} format 
     * @return {Buffer}
     */
    toBuffer(format?: string): Buffer {
        return this._image.toBuffer(format);
    }
    /**
     * 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    transformOrigin(x: number, y: number): void {
        this._image.transformOrigin(x, y);
    }
    /**
     * @return {void}
     */
    transformReset(): void {
        this._image.transformReset();
    }
    /**
     * 
     * @param {number} angle 
     * @return {void}
     */
    transformRotation(angle: number): void {
        this._image.transformRotation(angle);
    }
    /**
     * 
     * @param {number} sx 
     * @param {number} sy 
     * @return {void}
     */
    transformScale(sx: number, sy: number): void {
        this._image.transformScale(sx, sy);
    }
    /**
     * 
     * @param {number} x 
     * @return {void}
     */
    transformSkewX(x: number): void {
        this._image.transformSkewX(x);
    }
    /**
     * 
     * @param {number} y 
     * @return {void}
     */
    transformSkewY(y: number): void {
        this._image.transformSkewY(y);
    }
    /**
     * 
     * @param {string} color 
     * @param {boolean} inverse
     * @return {void} 
     */
    transparent(color: string, inverse?: boolean): void {
        this._image.transparent(color, inverse);
    }
    /**
     * 
     * @param {string} low 
     * @param {string} high
     * @return {void} 
     */
    transparentChroma(low: string, high: string): void {
        this._image.transparentChroma(low, high);
    }
    /**
     * @return {void}
     */
    transpose(): void {
        this._image.transpose();
    }
    /**
     * @return {void}
     */
    transverse(): void {
        this._image.transverse();
    }
    /**
     * @return {void}
     */
    trim(): void {
        this._image.trim();
    }
    /**
     * 
     * @param {number} radius 
     * @param {number} sigma 
     * @param {number} amount 
     * @param {number} threshold
     * @return {void} 
     */
    unsharpmask(radius: number, sigma: number, amount: number, threshold: number): void {
        this._image.unsharpmask(radius, sigma, amount, threshold);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {number} radius 
     * @param {number} sigma 
     * @param {number} amount 
     * @param {number} threshold 
     * @return {void}
     */
    unsharpmaskChannel(channel: IChannelType, radius: number, sigma: number, amount: number, threshold: number): void {
        this._image.unsharpmaskChannel(channel, radius, sigma, amount, threshold);
    }
    /**
     * 
     * @param {boolean} flag 
     * @return {void}
     */
    verbose(flag: boolean): void {
        this._image.verbose(flag);
    }
    /**
     * 
     * @param {number} radius 
     * @param {number} sigma 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    vignette(radius: number, sigma: number, x: number, y: number): void {
        this._image.vignette(radius, sigma, x, y);
    }
    /**
     * 
     * @param {IVirtualPixelMethod} method 
     * @return {void}
     */
    virtualPixel(method: IVirtualPixelMethod): void {
        this._image.virtualPixelMethod(method);
    }
    /**
     * 
     * @param {number} amplitude 
     * @param {number} wavelength
     * @return {void} 
     */
    wave(amplitude?: number, wavelength?: number): void {
        this._image.wave(amplitude, wavelength);
    }
    /**
     * 
     * @param {number} threshold 
     * @param {number} softness 
     * @return {void}
     */
    waveletDenoise(threshold: number, softness: number): void {
        this._image.waveletDenoise(threshold, softness);
    }
    /**
     * 
     * @param {string} threshold 
     * @return {void}
     */
    whiteThreshold(threshold: string): void {
        this._image.whiteThreshold(threshold);
    }
    /**
     * 
     * @param {IChannelType} channel 
     * @param {string} threshold
     * @return {void} 
     */
    whiteThresholdChannel(channel: IChannelType, threshold: string): void {
        this._image.whiteThresholdChannel(channel, threshold);
    }
    /**
     * 
     * @param {string} path 
     * @param {string} format
     * @return {void} 
     */
    write(path: string, format?: string): void {
        this._image.write(path, format);
    }
    /**
     * 
     * @param {string} path 
     * @return {void}
     */
    writeFrames(path: string): void {
        this._image.writeFrames(path);
    }
    /**
     * 
     * @param {string | number | Partial<Geometry & { value: string }>} value 
     * @param {number} height 
     * @param {number} x 
     * @param {number} y 
     * @return {void}
     */
    zoom(value: string | number | Partial<Geometry & { value: string }>, height?: number, x?: number, y?: number): void {
        if (arguments.length == 1) {
            this._image.zoom(value);
        } else {
            this._image.zoom(value, height, x, y);
        }
    }
} 