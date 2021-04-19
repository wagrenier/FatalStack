//
// Created by wagrenier on 4/16/2021.
//

#ifndef FATALSTACK_SAVE_H
#define FATALSTACK_SAVE_H

// First load system data of size 2C
// Then load file of size 8D3B

struct MC_SAVE_DATA {
    char* arr_ptr;
    int arr_size;
};

/// The pointer is one of an array
void SetMemoryCardSaveDataInfo(MC_SAVE_DATA *param_1, int album, int save_slot);
void GameDataSaveMcMain();

#endif //FATALSTACK_SAVE_H
