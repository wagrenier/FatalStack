#include "gameover.h"

void GameOverScreenBgDisp(
        unsigned char param_1,
        unsigned char param_2,
        unsigned char param_3,
        unsigned char param_4,
        unsigned int param_5) {
    uint uVar1;
    int iVar2;
    int iVar3;
    undefined *puVar4;
    undefined auStack208[52];
    int local_9c;
    uint local_68;
    undefined local_64[4];
    undefined local_60[4];
    undefined local_5c[4];
    undefined local_58;
    undefined auStack80[8];
    undefined auStack72[8];
    undefined auStack64[16];

    puVar4 = auStack80 + 7;
    uVar1 = (uint) puVar4 & 7;
    *(ulong * )(puVar4 + -uVar1) =
            *(ulong * )(puVar4 + -uVar1) & -1 << (uVar1 + 1) * 8 | 0x1c000000280U >> (7 - uVar1) * 8;
    auStack80 = 0x1c000000280;
    puVar4 = auStack72 + 7;
    uVar1 = (uint) puVar4 & 7;
    *(ulong * )(puVar4 + -uVar1) =
            *(ulong * )(puVar4 + -uVar1) & -1 << (uVar1 + 1) * 8 | 0U >> (7 - uVar1) * 8;
    auStack72 = 0;
    puVar4 = auStack64 + 7;
    uVar1 = (uint) puVar4 & 7;
    *(ulong * )(puVar4 + -uVar1) =
            *(ulong * )(puVar4 + -uVar1) & -1 << (uVar1 + 1) * 8 | 0xffffff000000a0U >> (7 - uVar1) * 8;
    auStack64._0_8_ = 0xffffff000000a0;
    CopySqrDToSqr__FP9DISP_SQARP8SQAR_DAT(auStack208, auStack80);
    puVar4 = local_64;
    iVar2 = 0;
    do {
        iVar3 = iVar2 + 1;
        *puVar4 = param_2;
        local_60[iVar2] = param_3;
        puVar4 = puVar4 + 1;
        local_5c[iVar2] = param_4;
        iVar2 = iVar3;
    } while (iVar3 < 4);
    local_9c = 0xfffff - (param_5 & 0xfffff);
    local_68 = param_5;
    local_58 = param_1;
    DispSqrD__FP9DISP_SQAR(auStack208);
    return;
}

void end_Story_GameOver_Movie() {
    EndMovieWithTitle();
}

void init_Story_GameOver_Eff() {
    return;
}

GPHASE_ENUM one_Story_GameOver_Movie(GPHASE_ENUM gphase) {
    long lVar1 = PlayMovieWithTitle();
    if (lVar1 != 0) {
        SetNextGPhase(0x2b);
    }
    return 0;
}

void end_Story_GameOver_Eff() {
    return;
}

void end_Story_GameOver_Fade() {
    return;
}

void init_Story_GameOver_Fade() {
    GameOverFadeCtrlInit();
}

GPHASE_ENUM one_Story_GameOver_Fade(GPHASE_ENUM gphase) {
    int uVar1;

    PlayerMainCmn(1);
    SisterMain();
    AutoEnemyMain();
    map_bgmMain();
    uVar1 = GetPlyrAreaNo();
    MhCtlMain(uVar1);
    IngameCameraMain();
    PlayData_PlayTimeCount();
    EnemyMotionWork();
    sis_mdlMotionWork();

    uVar1 = GetPlyrAreaNo();

    MapFogProc(uVar1, plyr_wrk._250_2_, 0x33cda0);
    gra3dDraw();
    InitEffectsEF();
    EffectControl(5);
    BrightnessAdjustmentFilterDraw();
    Graph2dMain();
    GameOverFadeMain();
    GameOverFadeDispMain();
    return 0;
}

GPHASE_ENUM one_Story_GameOver_Eff(GPHASE_ENUM gphase) {
    undefined8 uVar1;

    PlayerMainCmn(1);
    SisterMain();
    AutoEnemyMain();
    map_bgmMain();
    uVar1 = GetPlyrAreaNo();
    MhCtlMain(uVar1);
    IngameCameraMain();
    PlayData_PlayTimeCount();
    EnemyMotionWork();
    sis_mdlMotionWork();

    uVar1 = GetPlyrAreaNo();

    MapFogProc(uVar1, plyr_wrk._250_2_, 0x33cda0);
    gra3dDraw();
    InitEffectsEF();
    EffectControl(5);
    BrightnessAdjustmentFilterDraw();
    Graph2dMain();
    SetNextGPhase__F14GPHASE_ID_ENUM(0x44);
    return 0;
}

void init_Story_GameOver_Movie() {
    StreamAutoAllStop();
    InitMovieWithTitle(0x45, 1);
    return;
}