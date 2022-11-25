import { IChannelType } from "../types";

export interface _AdaptiveSharpenChannel { 
    sigma: number;
    channel: IChannelType;
    radius: number;
}

export type ParamsAdaptiveSharpenChannel = Omit<Partial<_AdaptiveSharpenChannel>, any>;