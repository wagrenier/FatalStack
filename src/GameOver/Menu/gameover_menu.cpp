#include gameover_menu.h

int pre_GameOver_Menu(GPHASE_ENUM gphase)
{
  GameOverMenuMain();
  GameOverMenuDispMain();
  return 0;
}

int pre_GameOver_Menu(GPHASE_ENUM gphase)
{
}

int one_GameOver_Menu_Load(GPHASE_ENUM gphase)
{
}

void GetGameOverMenuTexMem(void **, int)
{
}

void init_GameOver_Menu_Album(void)
{
}

void end_GameOver_Menu(void)
{
}

int one_GameOver_Menu_Top(GPHASE_ENUM gphase)
{
}

int after_GameOver_Menu(GPHASE_ENUM gphase)
{
	
	undefined8 uVar1;
  
	if (current_menu_state == RENDER) {
		uVar1 = Zero2Anim2D_FadeOutAnimCtrl__FPis(0x4af6c0,0x1e);
		SavePoint_BlackBgDisp__FUc(uVar1);
	}
	else {
		if (current_menu_state == FADE_OUT_MENU) {
			uVar1 = Zero2Anim2D_FadeInAnimCtrl__FPis(0x4af6c0,0x1e);
			SavePoint_BlackBgDisp__FUc(uVar1);
		}
	}
  return 0;
}

void end_GameOver_Menu_Album(void)
{
}

int one_GameOver_Menu_Album(GPHASE_ENUM gphase)
{
}

void end_GameOver_Menu_Top(void)
{
}

void GameOverMenuFadeOutReq(void)
{
	current_menu_state = FADE_OUT_MENU;
	gameover_menu_disp = 0;
	StreamAutoFadeOut(gameover_menu_ctrl,0x1e);
	return;
}

void init_GameOver_Menu(void)
{
}

void init_GameOver_Menu_Top(void)
{
}

void end_GameOver_Menu_Load(void)
{
}

void GameOverMenuTexLoadReq(void *, int)
{
}

void init_GameOver_Menu_Load(void)
{
}

void LiberateGameOverMenuTexMem(void **)
{
}