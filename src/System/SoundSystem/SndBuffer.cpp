//
// Created by wagrenier on 4/10/2021.
//

#include "SndBuffer.h"

void SndBufAllStop()
{
    undefined2 *puVar1;
    int iVar2;

    puVar1 = &snd_buf_player;
    iVar2 = 0x2f;

    do {
        if ((*(uint *)(puVar1 + 0x14) & 0x10000) != 0) {
            SndBufStopSub(puVar1);
        }
        iVar2 += -1;
        puVar1 = puVar1 + 0x1a;
    } while (-1 < iVar2);
}
