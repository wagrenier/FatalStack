#pragma once

int pre_GameOver_Menu(GPHASE_ENUM gphase);
int one_GameOver_Menu_Load(GPHASE_ENUM gphase);
void GetGameOverMenuTexMem(void **, int);
void init_GameOver_Menu_Album(void);
void end_GameOver_Menu(void);
int one_GameOver_Menu_Top(GPHASE_ENUM gphase);
int after_GameOver_Menu(GPHASE_ENUM gphase);
void end_GameOver_Menu_Album(void);
int one_GameOver_Menu_Album(GPHASE_ENUM gphase);
void end_GameOver_Menu_Top(void);
void GameOverMenuFadeOutReq(void);
void init_GameOver_Menu(void);
void init_GameOver_Menu_Top(void);
void end_GameOver_Menu_Load(void);
void GameOverMenuTexLoadReq(void *, int);
void init_GameOver_Menu_Load(void);
void LiberateGameOverMenuTexMem(void **);