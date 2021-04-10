//
// Created by wagrenier on 4/10/2021.
//

#include "InitSystem.h"

void InitOptionSetup(OPTION_WRK *option_wrk)
{
    option_wrk->Brightness = 128;
    option_wrk->IsVibration = true;
    option_wrk->Volume = 256;
    option_wrk->Is3dMovement = false;
    option_wrk->ControlType = A;
    option_wrk->IsSubtitleOn = false;
    option_wrk->IsMonoSound = false;
    option_wrk->IsLookInverted = false;
    option_wrk->IsAnalogStickInverse = false;
    OptSoundSetupRef(option_wrk);
}

void OptSoundSetupRef(OPTION_WRK *option_wrk)
{
    int currentVolume;

    if (option_wrk->IsMonoSound) {
        SndSetMono();
        currentVolume = option_wrk->Volume;
    }
    else {
        SndSetStereo();
        currentVolume = option_wrk->Volume;
    }

    SndSetGroupVolume(1, currentVolume);
    SndSetGroupVolume(0, option_wrk->Volume);
}

void init_super()
{
    InitCostume();
    soft_reset_disable = 0;
    InitSystemON();
    InitGraph2dBoot();
    playPssInit();
    InitLogo();
    LoadingInit();
    TitleInit();
    InitOptionSetup((OPTION_WRK *)game_options_wrk);
    ClearFlgCtrlInit();


    /// Setting up PS2 hardware specific registers
    MemoryCardInit();
    MemoryCardDebugReqSizeDisp();
    dmaVif1Init((void *)0x0,0,(void *)0x31aa1500,0x1ec30);
    InitDrawEnv__FPFv_PA3_iT0PFPA3_i_vT2(0x128908,0x128908,0x128920,0x128920);
    SetPrintWarning(0x222880);
    SetPrintAssert(0x1a7d78);
    gra3dInit((void *)0x1a91b00,64000);
    FinderBankSetup();
    SceneEffectInit();
}