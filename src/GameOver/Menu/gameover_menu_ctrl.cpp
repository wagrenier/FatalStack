#include "gameover_menu_ctrl.h"

void GameOverMenuCtrlInit()
{
    current_menu_state = INACTIVE;
}

void GameOverMenuDispMain()
{
    if (INITIATE < current_menu_state) {
        SavePoint_BgDisp(gameover_menu_disp[1], gameover_menu_disp[2], gameover_menu_disp[3], gameover_bg_tex_addr);
    }
}

void GameOverMenuMain()
{
    switch(current_menu_state) {
        case INACTIVE:
            current_menu_state = INITIATE;
            break;
        case INITIATE:
            long lVar1 = GameOverMenuTexLoadWait();
            if (lVar1 != 0) {
                current_menu_state = RENDER;
            }
            break;
        case RENDER:
            if (0x1d < gameover_menu_disp) {
                current_menu_state = SELECTION_MENU;
            }
            break;
        case SELECTION_MENU:
            break;
        case FADE_OUT_MENU:
            if (0x1d < gameover_menu_disp) {
                SetNextGPhase(GPHASE_ENUM_UNKNOWN0x35);
                return;
            }
            break;
        default:
            SetAssertPreMessage(0x3b3d10, 0x3b3d40, 0xe8, 0x3b3cf8);
            PrintAssertReal(0x3b3d50, 0x3b3cf8);
    }

    return;
}