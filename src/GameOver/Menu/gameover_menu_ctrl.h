#pragma once

enum GameOver_Menu_State {INACTIVE, INITIATE, RENDER, SELECTION_MENU, FADE_OUT_MENU};

GameOver_Menu_State current_menu_state;
int gameover_menu_disp;

void GameOverMenuCtrlInit(void);
void GameOverMenuMain(void);