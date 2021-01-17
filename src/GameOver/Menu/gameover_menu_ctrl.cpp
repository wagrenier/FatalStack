#include gameover_menu_ctrl.h

void GameOverMenuCtrlInit(void)
{
    current_menu_state = INACTIVE;
}

void GameOverMenuDispMain__Fv(void)

{
    if (INITIATE < current_menu_state) {
        SavePoint_BgDisp(0x4af6c4, 0x4af6c8, 0x4af6cc, gameover_bg_tex_addr);
    }
}

void GameOverMenuMain(void)
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
                SetNextGPhase__F14GPHASE_ID_ENUM(0x35);
                return;
            }
            break;
        default:
            SetAssertPreMessage(0x3b3d10, 0x3b3d40, 0xe8, 0x3b3cf8);
            PrintAssertReal(0x3b3d50, 0x3b3cf8);
    }

    return;
}