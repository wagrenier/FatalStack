//
// Created by wagrenier on 4/20/2021.
//

#include "game_data_save.h"

void GameDataSaveInit(char param_1)
{
    int iVar1;
    int iVar2;

    iVar2 = 0;
    GameDataSaveCtrlInit(param_1);
    MemoryCardExeInit();
    LiberateGameDataSaveMem((void **)&game_data_buff_addr);
    do {
        iVar1 = iVar2 * 4;
        iVar2 += 1;
        LiberateGameDataSaveMem((void **)(game_data_save_snap_addr + iVar1));
        *(undefined4 *)(game_data_save_snap_tex + iVar1) = 0xffffffff;
    } while (iVar2 < 5);
    if (DAT_003fe3f4 == '\0') {
        ingame_wrk[3] = '\0';
    }
    else {
        if (DAT_003fe3f4 == '\x01') {
            ingame_wrk[3] = DAT_003fe3f4;
        }
    }
    return;
}

void GameDataSaveEnd()
{
    void **ppvVar1;
    int iVar2;

    iVar2 = 4;
    LiberateGameDataSaveMem((void **)&game_data_buff_addr);
    ppvVar1 = (void **)game_data_save_snap_addr;
    do {
        iVar2 += -1;
        LiberateGameDataSaveMem(ppvVar1);
        ppvVar1 = ppvVar1 + 1;
    } while (-1 < iVar2);
    MemoryCardEnd();
    return;
}