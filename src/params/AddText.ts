import { IStretchType, IStyleType } from "../types";
import { Color } from "../util/Color";
import { Pos } from "../util/Pos";

export interface ParamsFont {
    family: string;
    style: IStyleType;
    weight: number;
    stretch: IStretchType;
}

export interface _AddText extends Pos {
    text: string;
    no_fill: boolean;
    no_stroke: boolean;
    font: Partial<ParamsFont> & string;
    size: number;
    color_fill: Partial<Color> & string;
}

export type ParamsAddText = Partial<_AddText>;