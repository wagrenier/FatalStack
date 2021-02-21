#pragma once

#include "../../../GPHASE_ENUM.h"

enum GameOver_Menu_State { INACTIVE, INITIATE, RENDER, SELECTION_MENU, FADE_OUT_MENU };

// DAT_003f4c9c in Ghidra
GameOver_Menu_State current_menu_state;

// 004af6c0 -> 004af6cc
unsigned int gameover_menu_disp[4];

int gameover_menu_ctrl;

void GameOverMenuCtrlInit();
void GameOverMenuMain();
void GameOverMenuDispMain();