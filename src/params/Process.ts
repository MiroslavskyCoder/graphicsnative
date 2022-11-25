export interface _Process {
    module: string;
    args: string[];
}

export type ParamsProcess = Partial<_Process>;