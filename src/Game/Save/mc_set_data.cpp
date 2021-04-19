//
// Created by wagrenier on 4/19/2021.
//

#include "mc_set_data.h"
#include "Save.h"


void SetMemoryCardSaveDataToBuff(char *buf_to_write, int album, int save_slot)
{
    int arr_size = 100;
    MC_SAVE_DATA mc_save_data [arr_size];
    bool IsDataLeftRead;

    int mem_card_data_size = GetMemoryCardDataSize(album,save_slot);

    SetMemoryCardSaveDataInfo(mc_save_data,album,save_slot);

    char *data_buf = buf_to_write;

    if ((mc_save_data[0].arr_addr != (byte *)0x0) && (mc_save_data[0].arr_size != -1)) {

        int outer_loop_index = 0;
        int inner_loop_index = 0;
        int length_curr_array = 0;

        do {
            while (IsDataLeftRead = inner_loop_index < length_curr_array, inner_loop_index += 1, IsDataLeftRead) {

                // Reads the current byte from the MC_SAVE_DATA array
                chat curr_byte = *mc_save_data[outer_loop_index].arr_addr;

                // Sets the pointer to the next element of the MC_SAVE_DATA array
                mc_save_data[outer_loop_index].arr_addr = mc_save_data[outer_loop_index].arr_addr + 1;

                // Writes the current byte to the output_buffer
                *data_buf = curr_byte;

                // Moves to the next byte in the buffer data_buf[x + 1]
                data_buf = data_buf + 1;
            }

            outer_loop_index += 1;
            length_curr_array = mc_save_data[outer_loop_index].arr_size;

        } while (((outer_loop_index < arr_size) && (mc_save_data[outer_loop_index - 1].arr_addr = mc_save_data[outer_loop_index].arr_addr,
                          mc_save_data[outer_loop_index].arr_addr != (byte *)0x0)) && (inner_loop_index = 0, mc_save_data[outer_loop_index].arr_size!= -1)
                          );

    }

    mem_card_data_size = CalcMemoryCardDataCheckSum(buf_to_write, mem_card_data_size + -4);
    SetMemoryCardDataCheckSum(data_buf, mem_card_data_size);
}