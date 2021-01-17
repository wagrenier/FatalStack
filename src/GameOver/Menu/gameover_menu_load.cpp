#include "gameover_menu_load.h"

void GameOverLoadInit()
{
    IngameWrkInit(0, 0);
    GameOverLoadCtrlInit();
    GameOverLoadDispInit();
    MemoryCardExeInit();

    if (load_data_buff != 0) {
        LiberateDataMemoryArea();
        load_data_buff = 0;
    }

    unsigned int index = 0;

    do {

        unsigned int currMemAddr = gameover_load_snap_addr[index];

        if (currMemAddr != 0) {
            LiberateDataMemoryArea(currMemAddr);

            gameover_load_snap_addr[index] = 0;
        }

        currMemAddr = index + 1;

        _fixed_array_verifyrange__H1Zi_UiUi_PX01(index, 5); // <- Internal EE stuff

        gameover_load_snap_tex[index] = 0xffffffff;

        index = currMemAddr;
    } while (index < 5);
}

void GameOverLoadEnd()
{
    unsigned int *gameover_load_snap_addr_ptr;

    if (load_data_buff != 0) {
        LiberateDataMemoryArea();
        load_data_buff = 0;
    }

    int index = 4;
    gameover_load_snap_addr_ptr = gameover_load_snap_addr;

    do {
        index = index + -1;

        if (*(int *)gameover_load_snap_addr_ptr != 0) {
            LiberateDataMemoryArea();
            *(int *)gameover_load_snap_addr_ptr = 0;
        }

        gameover_load_snap_addr_ptr = (undefined1 *)((int)gameover_load_snap_addr_ptr + 4);
    } while (-1 < index);

    MemoryCardEnd();
}

void GameOverLoadDataLoadReq()
{
    Language defined_language = GetLanguage();

    // 0x1177 -> Address of start of language gameover text(ure?)
    FileLoadReqEE(defined_language + 0x1177, gameover_load_tex_addr, 6, 0, 0);

    // 0x13 -> Address of start of language gameover cmn text(ure?)
    FileLoadReqEE(0x13, gameover_load_cmn_tex_addr, 6, 0, 0);
}

void GameOverLoadMain()
{
    if (gameover_load_ctrl == UNKNOW1) {
        GameOverLoadMcMain();
        return;
    }

    if (gameover_load_ctrl < UNKNOW2) {
        if (gameover_load_ctrl == UNKNOW0) {
            if (!GameOverLoadDataLoadWait()) {
                return;
            }

            gameover_load_ctrl = UNKNOW1;
            DAT_003f4ca9 = 0;
            return;
        }
    }
    else {
        if (gameover_load_ctrl == UNKNOW2) {
            if (gameover_load_disp != UNKNOW4) {
                return;
            }

            SetNextGPhase(GPHASE_ENUM_UNKNOWN0x2b);
            return;
        }
    }

    SetAssertPreMessage(0x3b3df0, 0x3b3e20, 0x179, 0x3b3e58);
    PrintAssertReal(0x3b3e70, 0x3b3e58);
}

void ReleaseGameOverLoadTexMem()
{
    if (gameover_load_tex_addr != 0) {
        mem_utilFreeMem(gameover_load_tex_addr);
        gameover_load_tex_addr = 0;
    }

    if (gameover_load_cmn_tex_addr != 0) {
        mem_utilFreeMem(gameover_load_cmn_tex_addr);
        gameover_load_cmn_tex_addr = 0;
    }
}

void GameOverLoadDispMain()
{
    undefined local_30 [16];

    local_30[0] = 0x80;

    if (gameover_load_ctrl < UNKNOW0) {
        return;
    }

    undefined8 uVar1 = Zero2Anim2D_InOutAnimCtrl__FPcT0ss(0x3f4cb0, 0x3f4cb1, 10, 5);

    if (gameover_load_disp == '\x04') {
        return;
    }

    SaveLoadCmnBaseDisp(0, 0, uVar1, gameover_load_tex_addr, 0);
    SaveLoadTitleFrameDisp(0, 0, uVar1, gameover_load_cmn_tex_addr);
    SaveLoadTitleLoadDisp(0, 0, uVar1, gameover_load_tex_addr);

    switch(DAT_003f4ca9) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 12:
        case 13:
            SaveLoadMcCheckDisp(0, 0, uVar1, gameover_load_tex_addr);
            goto LAB_001ae7bc;
        case 6:
            GameOverLoadFileSelDisp(uVar1);
            Zero2Anim2D_CsrAnimCtrl(0x3f4cb2, local_30);
            SaveLoadCursorDisp(0, 0, uVar1, local_30[0], gameover_load_tex_addr, DAT_003f4cac);
            SaveLoadFileSelMsgWinDisp(0, 0, uVar1);
            SaveLoadFileSelMsgDisp(0, 0, uVar1, 0x22);
            break;
        case 7:
            GameOverLoadFileSelDisp(uVar1);
            SaveLoadFileSelYesNoWinDisp(0, 0, uVar1, DAT_003f4cad);
            SaveLoadFileSelMsgDisp(0, 0, uVar1, DAT_003f4cb4);
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
            GameOverLoadFileSelDisp(uVar1);

        LAB_001ae7bc:
            SaveLoadMcStateMsgWinDisp(0, 0, uVar1);
            SaveLoadMcStateMsgDisp(0, 0, uVar1, DAT_003f4cb4);
            break;
        default:
            SetAssertPreMessage(0x3b3df0, 0x3b3e20, 0x586, 0x3b4010);
            PrintAssertReal(0x3b3e70, 0x3b4010);
    }
}

void GetGameOverLoadTexMem()
{
    undefined8 uVar2;

    ReleaseGameOverLoadTexMem();

    if (gameover_load_tex_addr == 0) {
        int iVar1 = GetLanguage(0x3b3df0, 0x3b3e20, 0x117, 0x3b3dd8);
        uVar2 = GetFileSize(iVar1 + 0x1177);
        gameover_load_tex_addr = mem_utilGetMem(uVar2);
    }
    else {
        SetAssertPreMessage();
        PrintAssertReal(0x3b3e38);
    }

    if (gameover_load_cmn_tex_addr == 0) {
        uVar2 = GetFileSize(0x13);
        gameover_load_cmn_tex_addr = mem_utilGetMem(uVar2);
    }
    else {
        SetAssertPreMessage(0x3b3df0, 0x3b3e20, 0x11f, 0x3b3dd8);
        PrintAssertReal(0x3b3e38);
    }
}

bool GameOverLoadDataLoadWait()
{
    bool bVar3 = false;
    int iVar1 = GetLanguage();
    long lVar2 = FileLoadIsEnd2(iVar1 + 0x1177, gameover_load_tex_addr);

    if (lVar2 != 0) {
        lVar2 = FileLoadIsEnd2(0x13, gameover_load_cmn_tex_addr);
        bVar3 = lVar2 != 0;
    }

    return bVar3;
}