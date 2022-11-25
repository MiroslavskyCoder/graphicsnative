import { Size } from "../util/Size";

export interface _AdaptiveThreshold extends Size {
    bias?: number;
}

export type ParamsAdaptiveThreshold = Omit<Partial<_AdaptiveThreshold>, number>;