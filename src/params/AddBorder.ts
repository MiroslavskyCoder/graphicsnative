import { Color } from "../util/Color";
import { Size } from "../util/Size";

export interface _AddBorder extends Size {
    color: Partial<Color> | string;
}

export type ParamsAddBorder = Omit<Partial<_AddBorder>, number>;