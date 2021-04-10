//
// Created by wagrenier on 4/10/2021.
//

#include "SndSys.h"
#include "SndBuffer.h"

void SndSetMono()
{
    snd_sys = MONO;
}

void SndSetStereo()
{
    snd_sys = STEREO;
}

void SndSetGroupVolume(int groupIndex, float volume)
{
    sndGroup[groupIndex] = volume;
}

float SndGetGroupVolume(int groupIndex)
{
    return sndGroup[groupIndex];
}

bool SndIsMono()
{
    return snd_sys == MONO;
}

undefined8 SndInit(int param_1,undefined8 param_2)
{
    undefined8 uVar1;
    int iVar2;
    undefined4 local_50;
    undefined4 local_4c;
    undefined4 local_48;
    undefined4 local_40;
    undefined4 local_3c;
    undefined4 local_38;
    undefined4 local_34;
    undefined2 local_30;
    undefined2 local_2e;
    int iVar3;

    /// PS2 Specific Init
    SPUMemoryInit();
    InitSPUVoice();
    /// PS2 Specific Init

    local_50 = 0x800;

    if (*(int *)(param_1 + 0x18) != 2)
    {
        local_50 = 0;
    }

    local_4c = 0x3fff;

    local_48 = GetSPUMemory(0x10);
    iopCommandRegister(5,&local_50,0xc);

    Snd3DInit();
    SndBufInit();
    SndStreamInit(*(undefined4 *)(param_1 + 0x2c));
    SndPCMStreamInit();

    uVar1 = SndBankInitAll(param_2,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x30));
    uVar1 = StreamAutoPlayInit(uVar1,*(undefined4 *)(param_1 + 0x24));
    uVar1 = snd_utilAutoBDInit(uVar1,*(undefined4 *)(param_1 + 0x28));

    local_30 = 0x2fff;
    snd_sys = 0;
    local_2e = 0x2fff;
    local_34 = 3;
    local_38 = 0;
    local_40 = 0;

    effect_adrs = GetSPUEffectMemory(eff_use_size_tbl._12_4_);

    local_3c = effect_adrs;
    iopCommandRegister(6,&local_40,0x1c);

    iVar3 = 0;

    do
    {
        iVar2 = iVar3 + 1;
        SndSetGroupVolume(iVar3,0x100);
        iVar3 = iVar2;
    } while (iVar2 < 5);

    ee_iopMain();
    ee_iopMain();

    return uVar1;
}

void SndMain()
{
    Snd3DMain();
    StreamAutoPlayMain();
    snd_utilAutoBDMain();
    SndStreamMain();
    SndPCMStreamMain();
    SndBufPlayMain();
}

void SndAllStop()
{
    SndBufAllStop();
    SndStreamAllStop();
}

void SndCalcValue(float param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
                  int groupIndex, long param_8, short *param_9_00, short *param_9)
{
    // Param1 to param8 seem to be within a first param structure (snd_wrk)
    // Param2 seems to be a value within the header for the file
    // param1 => 0x3200, param2 => 0x80, param3 => 0x19, param4 => 0x1000, param5 => 0xEB3, param6 => 0, param7 => 0, param8 => 0x1FFFC00
    short sVar1;

    // Probably a global var made local
    short local_60;
    short local_5e;

    int snd_group_volume = SndGetGroupVolume(groupIndex);

    // ((param_2 * param_4 >> 7) * snd_group_volume >> 8) -> Point to the first value of the snd_wrk structure
    // snd_group_volume = snd_wrk->

    snd_group_volume = (param_2 * param_4 >> 7) * snd_group_volume >> 8;

    *param_9_00 = (short)(snd_group_volume * (0x80 - param_3) >> 7);
    param_9_00[1] = (short)(snd_group_volume * param_3 >> 7);

    if (param_8 == 0)
    {
        *param_9 = (short)param_6;
    }
    else
    {
        Snd3DGetVal(param_8,&local_60,param_9);
        *param_9_00 = (short)((int)*param_9_00 * (int)local_60 >> 0xe);
        param_9_00[1] = (short)((int)param_9_00[1] * (int)local_5e >> 0xe);
        *param_9 = (short)(param_6 * *param_9 >> 0xc);
    }

    param_1 = (float)(param_5 * *param_9 * 0x10 >> 0x10) * param_1;

    if ((byte)((uint)param_1 >> 0x17) < 0x9e)
    {
        sVar1 = (short)(int)param_1;
    }
    else
    {
        if ((int)param_1 < 0)
        {
            sVar1 = -1;
        }
        else {
            sVar1 = 0;
        }
    }

    *param_9 = sVar1;

    bool sndIsMono = SndIsMono();

    if (sndIsMono)
    {
        sVar1 = (short)((int)param_9_00[1] + (int)*param_9_00 >> 1);
        param_9_00[1] = sVar1;
        *param_9_00 = sVar1;
    }
}
