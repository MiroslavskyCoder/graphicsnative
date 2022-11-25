import { Pos } from "../util/Pos";

export interface _FloodFillAlpha extends Pos { 
    alpha: number;
    target?: string;
    invert?: boolean;
}

export type ParamsFloodFillAlpha = Partial<_FloodFillAlpha>;