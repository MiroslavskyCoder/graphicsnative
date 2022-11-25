import { Geometry } from "../util/Geometry";

export interface _Read {
    buffer: Buffer;
    size: Partial<Geometry> | string;
    spec: string;
    magick: string;
    depth: number;
    width: number;
    height: number;
    map: string;
    pixels: Buffer;
}

export type ParamsRead = Partial<_Read>;