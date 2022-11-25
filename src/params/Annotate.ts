import { IGravityType } from "../types";
import { Size } from "../util/Size";

export interface _Annotate extends Size { 
    gravity: IGravityType;
    text: string;
}

export type ParamsAnnotate = Partial<_Annotate>;