import { Geometry } from "../util/Geometry";

export interface _AdaptiveResize extends Omit<Geometry, number> { 
    value: string; 
}

export type ParamsAdaptiveResize = Partial<_AdaptiveResize>;