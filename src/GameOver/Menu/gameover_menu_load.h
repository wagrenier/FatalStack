#pragma once

#include "../../GPHASE_ENUM.h"
#include "../../System/Language.h"

enum GAMEOVER_LOAD_CTRL { UNKNOW0, UNKNOW1, UNKNOW2, UNKNOW3, UNKNOW4};

int DAT_003f4ca9;

int DAT_003f4cac;

int DAT_003f4cad;

int DAT_003f4cb4;

GAMEOVER_LOAD_CTRL gameover_load_ctrl;

unsigned int gameover_load_cmn_tex_addr;

// Unsure type here, but seems to be storing addresses, so a 32bits must be right
unsigned int gameover_load_snap_addr[4];

void GameOverLoadInit();            // 1ad0a8
void GameOverLoadEnd();             // 1ae570
void GameOverLoadDataLoadReq();     // 1ad260
void GameOverLoadMain();            // 1ad2f8
void ReleaseGameOverLoadTexMem();   // 1ae5e0
void GameOverLoadDispMain();        // 1ae640
void GetGameOverLoadTexMem();       // 1ad198
bool GameOverLoadDataLoadWait();    // 1ad2b0