//
// Created by wagrenier on 4/19/2021.
//

#include "mc_cmn.h"

int CalcMemoryCardDataCheckSum(char *data_buf, int buf_size)
{
    char cVar1;
    int iVar2 = 0

    if (0 < buf_size) {
        do {
            cVar1 = *data_buf;
            data_buf = data_buf + 1;
            buf_size += -1;
            iVar2 += cVar1;
        } while (buf_size != 0);
    }

    return iVar2;
}

void SetMemoryCardDataCheckSum(char *data_buf, int buf_size)
{
    int iVar1;
    int *piVar2;
    int local_10 [4];
    char current_char;

    piVar2 = local_10;
    iVar1 = 3;
    local_10[0] = buf_size;
    do {
        current_char = *(char *)piVar2;
        piVar2 = (int *)((int)piVar2 + 1);
        iVar1 += -1;
        *data_buf = current_char;
        data_buf = data_buf + 1;
    } while (-1 < iVar1);
}

int GetMemoryCardFreeSizeForBrowser(void)
{
    int iVar1;

    iVar1 = GetAccessMemoryCardFreeCluster();
    iVar1 += -2;
    if (iVar1 < 0) {
        iVar1 = 0;
    }
    return iVar1;
}