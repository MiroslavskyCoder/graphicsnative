export interface _AdaptiveBlur { 
    sigma: number;
    radius: number;
}

export type ParamsAdaptiveBlur = Omit<Partial<_AdaptiveBlur>, number>;