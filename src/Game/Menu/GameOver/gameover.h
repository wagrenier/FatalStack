#pragma once

void GameOverScreenBgDisp(unsigned char param_1, unsigned char param_2,
                          unsigned char param_3, unsigned char param_4,
                          unsigned int param_5);            // 1ac650

void end_Story_GameOver_Movie();                            // 1ac948
void init_Story_GameOver_Eff();                             // 1ac740
GPHASE_ENUM one_Story_GameOver_Movie(GPHASE_ENUM gphase);   // 1ac918
void end_Story_GameOver_Eff();                              // 1ac800
void end_Story_GameOver_Fade();                             // 1ac8e8
void init_Story_GameOver_Fade();                            // 1ac808
GPHASE_ENUM one_Story_GameOver_Fade(GPHASE_ENUM gphase);    // 1ac828
GPHASE_ENUM one_Story_GameOver_Eff(GPHASE_ENUM gphase);     // 1ac748
void init_Story_GameOver_Movie();                           // 1ac8f0

