import { Geometry } from "../util/Geometry"; 

export interface _FloodFillColor { 
    fillColor: string;
    borderColor?: string;
    point: Partial<Geometry> | string;
    invert?: boolean;
}

export type ParamsFloodFillColor = Partial<_FloodFillColor>;