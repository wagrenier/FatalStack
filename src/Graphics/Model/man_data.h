//
// Created by wagrenier on 4/20/2021.
//

#ifndef FATALSTACK_MAN_DATA_H
#define FATALSTACK_MAN_DATA_H

/// 0x00000000001d85d0      0x70c /home/zero_rom/zero2np/bin/cd_dbin/man_data.o
/// 0x00000000001d8a98                MAN_DATA::ReadyIn(int *, int *, int *)
/// 0x00000000001d8c40                MAN_DATA::ReleaseIn(void)
/// 0x00000000001d86f0                MAN_DATA::MAN_DATA(void)
/// 0x00000000001d8b90                MAN_DATA::ReleaseAnmIn(void)
/// 0x00000000001d89e8                MAN_DATA::InitIn(int, int, int)
/// 0x00000000001d87a0                MAN_DATA::AccessoryDraw(int)
/// 0x00000000001d8718                ManItemSGDDraw(HeaderSection *, ANI_CTRL *, int)
/// 0x00000000001d86a8                MAN_DATA::InitializeIn(void)
/// 0x00000000001d8878                MAN_DATA::SetupIn(int, int, int, int, int)

class MAN_DATA {
public:
    void ReadyIn(int *, int *, int *);
    void ReleaseIn(void);
    void MAN_DATA(void);
    void ReleaseAnmIn(void);
    void InitIn(int, int, int);
    void AccessoryDraw(int);
    void InitializeIn(void);
    void SetupIn(int, int, int, int, int);
    aBoneLabelTbl
};

ManItemSGDDraw(HeaderSection *, ANI_CTRL *, int);

#endif //FATALSTACK_MAN_DATA_H
