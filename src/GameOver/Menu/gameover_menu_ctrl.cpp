void GameOverMenuCtrlInit(void)
{
  current_menu_state = 0;
  return;
}

void GameOverMenuMain(void)
{
  long lVar1;
  
  switch(current_menu_state) {
  case 0:
    current_menu_state = INITIATE;
    break;
  case 1:
    lVar1 = GameOverMenuTexLoadWait();
    if (lVar1 != 0) {
      current_menu_state = RENDER;
    }
    break;
  case 2:
    if (0x1d < gameover_menu_disp) {
      current_menu_state = SELECTION_MENU;
    }
    break;
  case 3:
    break;
  case 4:
    if (0x1d < gameover_menu_disp) {
      SetNextGPhase__F14GPHASE_ID_ENUM(0x35);
      return;
    }
    break;
  default:
    SetAssertPreMessage(0x3b3d10,0x3b3d40,0xe8,0x3b3cf8);
    PrintAssertReal(0x3b3d50, 0x3b3cf8);
  }
  return;
}