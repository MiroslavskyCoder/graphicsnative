 
export interface _AffineTransform { 
    sx: number;
    rx: number;
    ry: number;
    tx: number;
    ty: number;
}

export type ParamsAffineTransform = Partial<_AffineTransform>;