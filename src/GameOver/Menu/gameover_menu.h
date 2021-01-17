#pragma once

// 0x00000000001ac968      0x668 /home/zero_rom/zero2np/bin/cd_dbin/gameover_menu.o

int pre_GameOver_Menu(GPHASE_ENUM gphase);
int one_GameOver_Menu_Load(GPHASE_ENUM gphase);
void GetGameOverMenuTexMem(void **, int);
void init_GameOver_Menu_Album();
void end_GameOver_Menu();
int one_GameOver_Menu_Top(GPHASE_ENUM gphase);
int after_GameOver_Menu(GPHASE_ENUM gphase);
void end_GameOver_Menu_Album();
int one_GameOver_Menu_Album(GPHASE_ENUM gphase);
void end_GameOver_Menu_Top();
void GameOverMenuFadeOutReq();
void init_GameOver_Menu();
void init_GameOver_Menu_Top();
void end_GameOver_Menu_Load();
void GameOverMenuTexLoadReq(void *, int);
void init_GameOver_Menu_Load();
void LiberateGameOverMenuTexMem(void **);