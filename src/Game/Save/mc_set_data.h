//
// Created by wagrenier on 4/19/2021.
//

#ifndef FATALSTACK_MC_SET_DATA_H
#define FATALSTACK_MC_SET_DATA_H

/// 0x00000000001e16f0     0x16c0 /home/zero_rom/zero2np/bin/cd_dbin/mc_set_data.o
/// 0x00000000001e1fa8                GetDataMemoryArea(int)
/// 0x00000000001e22b8                GetMemoryCardClearDataFlg(int)
/// 0x00000000001e2810                MemoryCardSetIconTitleName(char *, int)
/// 0x00000000001e1bd0                GetMemoryCardDirSize(int)
/// 0x00000000001e20a8                GetMemoryCardAllFileNum(int)
/// 0x00000000001e24a0                MemoryCardMakeSearchDirPath(char *, int)
/// 0x00000000001e2150                SetMemoryCardPlayDataHead(int, char)
/// 0x00000000001e2328                GetMemoryCardPlayDataClearNum(int)
/// 0x00000000001e1ca8                GetMemoryCardDirSizeCluster(int)
/// 0x00000000001e2a68                MemoryCardDebugReqSizeDisp(void)
/// 0x00000000001e2280                GetMemoryCardPlayDataFlg(int)
/// 0x00000000001e17c8                MemoryCardSoftResetLock(void)
/// 0x00000000001e2008                MemoryCardDataLoadWait(void)
/// 0x00000000001e2410                SetSave_PlayDataHead(MC_SAVE_DATA *)
/// 0x00000000001e1ac8                DevelopMemoryCardLoadData(char *, int, int)
/// 0x00000000001e24f8                MemoryCardSetIconSysPath(char *, int)
/// 0x00000000001e2128                MemoryCardPlayDataHeadInit(void)
/// 0x00000000001e2ce8                MemoryCardWarning(char *,...)
/// 0x00000000001e2398                GetMemoryCardPlayDataPlayTime(int)
/// 0x00000000001e2360                GetMemoryCardPlayDataRoomLabel(int)
/// 0x00000000001e1fe0                MemoryCardDataLoadReq(void *, int)
/// 0x00000000001e28b0                MemoryCardSetIconFileName(char *, int, int)
/// 0x00000000001e19c0                SetMemoryCardSaveDataToBuff(char *, int, int)
/// 0x00000000001e25b0                MemoryCardSetIconSysData(int)
/// 0x00000000001e2928                MemoryCardSetIconFilePath(char *, int, int)
/// 0x00000000001e2a48                GetIconDataSize(int, int)
/// 0x00000000001e1dd0                GetMemoryCardDataSize(int, int)
/// 0x00000000001e1808                MemoryCardSetFilePath(char *, int, int)
/// 0x00000000001e2bc0                MemoryCardPrint(char *,...)
/// 0x00000000001e2028                GetMemoryCardDataFileNum(int)
/// 0x00000000001e1fc0                LiberateDataMemoryArea(void *)
/// 0x00000000001e2428                MemoryCardSetDirName(char *, int)
/// 0x00000000001e2a20                GetIconDataLabel(int, int)
/// 0x00000000001e2c40                MemoryCardAssert(char *,...)
/// 0x00000000001e22f0                GetMemoryCardPlayDataChapter(int)
/// 0x00000000001e17e8                MemoryCardSoftResetUnlock(void)

void SetMemoryCardSaveDataToBuff(char *buf_to_write, int album, int save_slot);

#endif //FATALSTACK_MC_SET_DATA_H
