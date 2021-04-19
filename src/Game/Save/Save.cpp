//
// Created by wagrenier on 4/16/2021.
//

#include "Save.h"

void SetMemoryCardSaveDataInfo(MC_SAVE_DATA *param_1, int album, int save_slot)
{
    bool loop_check false;
    int index = 0;
    code **save_func;

    do {
        if (album == 0) {
            if (game_save_data[save_slot] == (undefined *)0x0) {
                LAB_001b0708:
                loop_check = true;
            }
            else {
                save_func = (code **)(game_save_data[save_slot][index]);
                LAB_001b0714:
                if (*save_func == (code *)0x0) {
                    param_1->arr_addr = (undefined *)0x0;
                    loop_check = true;
                    param_1->arr_size = -1;
                }
                else {
                    (**save_func)(param_1);
                    param_1 = param_1 + 1;
                }
            }
        }
        else {
            if ((-1 < album) && (album < 6)) {
                if ((&album_save_data)[save_slot] == (undefined *)0x0) {
                    goto LAB_001b0708;
                }

                save_func = (code **)((&album_save_data)[save_slot][index]);

                goto LAB_001b0714;
            }
            MemoryCardAssert("Error! SetMemoryCardSaveDataInfo");
        }
        if ((loop_check) || (index += 1, 99 < index)) {
            return;
        }
    } while( true );
}

void GameDataSaveMcMain()
{
    switch(DAT_003fe3f1) {
        case 0:
            GameDataSaveMcCheckInit();
        case 1:
            GameDataSaveMcCheckWait();
            return;
        case 2:
            GameDataSaveMcHeadLoadInit();
        case 3:
            GameDataSaveMcHeadLoadWait();
            return;
        case 4:
            GameDataSaveMcSnapLoadInit();
        case 5:
            GameDataSaveMcSnapLoadWait();
            return;
        case 6:
            GameDataSaveMcSaveFileSel();
            return;
        case 7:
            GameDataSaveMcSaveConf();
            return;
        case 8:
            GameDataSaveMcSystemLoadInit();
        case 9:
            GameDataSaveMcSystemLoadWait();
            return;
        case 10:
            GameDataSaveMcSaveInit();
        case 0xb:
            GameDataSaveMcSaveWait();
            return;
        case 0xc:
            GameDataSaveMcErrorConfInit();
        case 0xd:
            GameDataSaveMcErrorConfWait();
            return;
        case 0xe:
            GameDataSaveMcEndConf();
            return;
        case 0xf:
            GameDataSaveMcRemakeConfInit();
        case 0x10:
            GameDataSaveMcRemakeConfWait();
            return;
        case 0x11:
            GameDataSaveMcRemakeDirDelInit();
        case 0x12:
            GameDataSaveMcRemakeDirDelWait();
            return;
        case 0x13:
            GameDataSaveMcNewMakeConfInit();
        case 0x14:
            GameDataSaveMcNewMakeConfWait();
            return;
        case 0x15:
            GameDataSaveMcNewMakeInit();
        case 0x16:
            GameDataSaveMcNewMakeWait();
            return;
        case 0x17:
            GameDataSaveMcNewMakeSaveInit();
        case 0x18:
            GameDataSaveMcNewMakeSaveWait();
            return;
        case 0x19:
            GameDataSaveMcFormatConfInit();
        case 0x1a:
            GameDataSaveMcFormatConfWait();
            return;
        case 0x1b:
            GameDataSaveMcFormatInit();
        case 0x1c:
            GameDataSaveMcFormatWait();
            return;
        default:
            return;
    }
}
