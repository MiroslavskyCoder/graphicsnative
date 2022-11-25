import { Color } from "../util/Color";

export interface _Colorize {
    opacity: number; 
    opacity_red: number; 
    opacity_green: number; 
    opacity_blue: number; 
    color: Partial<Color> | string; 
}

export type ParamsColorize = Partial<_Colorize>;