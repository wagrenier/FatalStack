//
// Created by wagrenier on 4/19/2021.
//

#ifndef FATALSTACK_MC_CMN_H
#define FATALSTACK_MC_CMN_H

/// 0x00000000001dfc88                MemoryCardExeEndSync(int *) SCE Function
/// 0x00000000001dfd00                SetMemoryCardDataCheckSum(char *, int)
/// 0x00000000001dfcd0                CalcMemoryCardDataCheckSum(char *, int)   DONE
/// 0x00000000001dfca8                GetMemoryCardFreeSizeForBrowser(void)

//***** Fully Implemented Functions ***** //
/// Calculates the sum of data in the array
int CalcMemoryCardDataCheckSum(char *data_buf, int buf_size);

//***** Unimplemented Functions ***** //
void SetMemoryCardDataCheckSum(char *data_buf, int buf_size);
int GetMemoryCardFreeSizeForBrowser();

#endif //FATALSTACK_MC_CMN_H
