 
export interface _AddRoundRectangle { 
    upperLeftX: number;
    upperLeftY: number;
    lowerRightX: number;
    lowerRightY: number;
    cornerWidth: number;
    cornerHeight: number;
}

export type ParamsAddRoundRectangle = Partial<_AddRoundRectangle>;