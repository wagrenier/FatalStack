//
// Created by wagrenier on 4/20/2021.
//

#ifndef FATALSTACK_GAME_DATA_SAVE_H
#define FATALSTACK_GAME_DATA_SAVE_H

/// 0x00000000001a7d58     0x2998 /home/zero_rom/zero2np/bin/cd_dbin/game_data_save.o
/// 0x00000000001a7f30                GameDataSaveBackGroundLoadReq(void *(*)(int), void (*)(void *))
/// 0x00000000001a7e30                GameDataSaveInit(char)
/// 0x00000000001aa0e8                GameDataSaveEnd(void)
/// 0x00000000001aa1d0                GameDataSaveDispMain(void)
/// 0x00000000001a80a8                GameDataSaveMain(void)
/// 0x00000000001aa140                GameDataSaveTexMemFree(void)

//***** Fully Implemented Functions ***** //


//***** Unimplemented Functions ***** //
void GameDataSaveInit(char param_1);
void GameDataSaveEnd();

#endif //FATALSTACK_GAME_DATA_SAVE_H
