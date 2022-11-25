import { Geometry } from "../util/Geometry";

export interface _AddSource<E> extends Geometry {
    source: E;
}

export type ParamsAddSource<E> = Omit<Partial<_AddSource<E>>, number>;