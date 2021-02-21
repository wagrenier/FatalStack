#include gameover_menu.h

int pre_GameOver_Menu(GPHASE_ENUM gphase) {
    GameOverMenuMain();
    GameOverMenuDispMain();
    return 0;
}

int pre_GameOver_Menu(GPHASE_ENUM gphase) {
    GameOverMenuMain();
    GameOverMenuDispMain();
    return 0;
}

int one_GameOver_Menu_Load(GPHASE_ENUM gphase) {
    GameOverLoadMain();
    GameOverLoadDispMain();
    return 0;
}

// int *param_1,undefined8 param_2
void GetGameOverMenuTexMem(void **param1, int param2) {
    if (*param_1 != 0) {
        LiberateGameOverMenuTexMem();
    }

    undefined8 uVar2 = GetFileSize(param_2);
    int iVar1 = ol_loadGetHeap(uVar2);
    *param_1 = iVar1;
    return;
}

void init_GameOver_Menu_Album() {
    AlbumInit(0);
}

void end_GameOver_Menu() {
    GameOverMenuMemFree();
    GameOverMenuTopMemFree();
    ReleaseGameOverLoadTexMem();
    AlbumEnd();
    StreamAutoAllStop();
    return;
}

int one_GameOver_Menu_Top(GPHASE_ENUM gphase) {
    if (INITIATE < current_menu_state) {
        if (current_menu_state < FADE_OUT_MENU) {
            GameOverMenuTopMain();
        }

        GameOverMenuTopDisp();
    }

    return 0;
}

int after_GameOver_Menu(GPHASE_ENUM gphase) {
    undefined8 uVar1;

    if (current_menu_state == RENDER) {
        uVar1 = Zero2Anim2D_FadeOutAnimCtrl(0x4af6c0, 0x1e);
        SavePoint_BlackBgDisp__FUc(uVar1);
    } else {
        if (current_menu_state == FADE_OUT_MENU) {
            uVar1 = Zero2Anim2D_FadeInAnimCtrl(0x4af6c0, 0x1e);
            SavePoint_BlackBgDisp(uVar1);
        }
    }

    return 0;
}

void end_GameOver_Menu_Album() {
    return;
}

int one_GameOver_Menu_Album(GPHASE_ENUM gphase) {
    long lVar1 = AlbumMain();

    if (lVar1 != 0) {
        SetNextGPhase(UNKNOWN43);
    }

    AlbumDispMain();

    return 0;
}

void end_GameOver_Menu_Top() {
    return;
}

void GameOverMenuFadeOutReq() {
    current_menu_state = FADE_OUT_MENU;
    gameover_menu_disp[0] = 0;
    StreamAutoFadeOut(gameover_menu_ctrl, 0x1e);
}

void init_GameOver_Menu() {
    GameOverLoadInit();
}

void init_GameOver_Menu_Top() {
    GameOverMenuTopInit();
}

void end_GameOver_Menu_Load() {
    GameOverLoadEnd();
}

// void GameOverMenuTexLoadReq__FPvi(undefined8 param_1,undefined8 param_2)
void GameOverMenuTexLoadReq(void *param_1, int param_2) {
    FileLoadReqEE(param_2, param_1, 2, 0, 0);
}

void init_GameOver_Menu_Load() {
    GameOverLoadInit();
}

// void LiberateGameOverMenuTexMem__FPPv(int *param_1)
void LiberateGameOverMenuTexMem(void *menuPtr) {
    if (*menuPtr != 0) {
        ol_loadFreeHeap(*menuPtr);
        *menuPtr = 0;
    }
}