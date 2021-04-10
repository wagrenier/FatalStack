//
// Created by wagrenier on 4/10/2021.
//

#include "SndStream.h"

void SndStreamStop(int param_1)
{
    int iVar1;
    int local_20 [4];

    if ((((uint)(&DAT_0040cb14)[param_1 * 0x30] >> 4 & 1) == 0) &&
        ((&DAT_0040cb10)[param_1 * 0x30] != 0)) {
        (&DAT_0040cb14)[param_1 * 0x30] = (&DAT_0040cb14)[param_1 * 0x30] | 0x10;
        (&DAT_0040cb30)[param_1 * 0x60] = 600;
        local_20[0] = param_1;
        iVar1 = iopCommandRegister(0xd,local_20,4);
        if (iVar1 != 0) {
            (&DAT_0040cb10)[param_1 * 0x30] = 4;
        }
    }
}

void SndStreamAllStop()
{
    SndStreamStop(0);
    SndStreamStop(1);
}