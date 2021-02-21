#include "file_handler.h"

/* WARNING: Removing unreachable block (ram,0x0026f1e8) */
void thFileLoad()
{
    void *pvVar1;
    int iVar2;
    void *pvVar3;
    int iVar4;
    int iVar6;
    undefined4 *puVar7;
    long lVar8;
    bool bVar9;
    size_t __nmemb;
    int iVar10;
    undefined auStack384 [304];
    long lVar5;

    do {
        lVar8 = 0;
        iVar6 = 0;
        WaitSema(load_req_sema_id);
        __nmemb = SEXT48(file_load_sys);
        qsort(file_load_wrk,__nmemb,0x28,cmpFileWrkPri);
        lVar5 = 0;
        iVar2 = 0;
        iVar4 = *(int *)((int)file_load_wrk + 0x14);
        pvVar3 = file_load_wrk;
        if (0 < (long)__nmemb) {
            iVar10 = 0;
            pvVar1 = file_load_wrk;
            do {
                iVar2 = *(int *)((int)pvVar1 + 0x14);
                iVar10 = iVar10 + 0x28;
                if (iVar2 != iVar4) {
                    qsort((void *)((int)pvVar3 + (int)lVar5 * 0x28),(long)((int)lVar8 - (int)lVar5),0x28,
                          cmpFileWrkSector);
                    lVar5 = lVar8;
                    pvVar3 = file_load_wrk;
                    iVar4 = iVar2;
                }
                iVar2 = (int)lVar5;
                iVar6 = (int)lVar8 + 1;
                lVar8 = (long)iVar6;
                pvVar1 = (void *)(iVar10 + (int)pvVar3);
            } while (lVar8 < (long)__nmemb);
        }
        qsort((void *)((int)pvVar3 + iVar2 * 0x28),(long)(iVar6 - iVar2),0x28,cmpFileWrkSector);
        rpcFileLoadReqSub((int)file_load_wrk + file_load_sys * 0x28 + -0x28);
        if (*(int *)((int)file_load_wrk + file_load_sys * 0x28 + -0x18) == 2) {
            cmp_eeiopWaitSema();
        }
        WaitSema(rpc_sema_id);
        pvVar3 = (void *)((int)file_load_wrk + file_load_sys * 0x28);
        puVar7 = (undefined4 *)((int)pvVar3 + -0x28);
        if (DAT_004bd7c4 == 1) {
            iVar4 = *(int *)((int)pvVar3 + -0xc) + iop_fileload_ret;
            *(int *)((int)pvVar3 + -0xc) = iVar4;
            if (iVar4 < *(int *)((int)pvVar3 + -8)) {
                bVar9 = false;
                SignalSema(load_req_sema_id,1,1);
            }
            else {
                bVar9 = true;
            }
        }
        else {
            if (DAT_004bd7c4 == 0) {
                bVar9 = true;
            }
            else {
                if (DAT_004bd7c4 != 2) {
                    if (DAT_004bd7c4 != 3) {
                        bVar9 = false;
                        SetAssertPreMessage(0x3e7110,0x3e7140);
                        PrintAssertReal(0x3e72f8);
                        goto LAB_0026f138;
                    }
                    WakeupThread(DAT_004bd7d0);
                }
                bVar9 = false;
                if (DAT_004bd7c8 != (code *)0x0) {
                    (*DAT_004bd7c8)(*(undefined4 *)((int)pvVar3 + -0x20),DAT_004bd7cc);
                }
                file_load_sys = file_load_sys + -1;
            }
        }
        LAB_0026f138:
        DAT_004bd7c4 = 0;
        if (bVar9) {
            GetFileNameBuffer(*puVar7,auStack384);
            lVar5 = cddatIsCmpFile(*puVar7);
            if (lVar5 == 0) {
                printf("LoadEnd no[% 4d] id[%06x] adrs[0x%08x] size[%x] [%s]\n",*puVar7,
                       *(undefined4 *)((int)pvVar3 + -4),*(undefined4 *)((int)pvVar3 + -0x20),
                       *(undefined4 *)((int)pvVar3 + -8),auStack384);
            }
            else {
                printf("LoadEnd no[% 4d] id[%06x] adrs[0x%08x] size[%x] [%s] << This Is Compressed File\n",
                       *puVar7,*(undefined4 *)((int)pvVar3 + -4),*(undefined4 *)((int)pvVar3 + -0x20),
                       *(undefined4 *)((int)pvVar3 + -8),auStack384);
            }
            file_load_sys = file_load_sys + -1;
            if (*(code **)((int)pvVar3 + -0x1c) != (code *)0x0) {
                (**(code **)((int)pvVar3 + -0x1c))
                        (*(undefined4 *)((int)pvVar3 + -0x20),*(undefined4 *)((int)pvVar3 + -0x10));
            }
        }
    } while( true );
}


/* WARNING: Removing unreachable block (ram,0x0026e968) */
/* WARNING: Removing unreachable block (ram,0x0026e96c) */
/* WARNING: Removing unreachable block (ram,0x0026e9c0) */
void rpcFileLoadReqSub(undefined4 *param_1)
{
    char cVar1;
    char cVar2;
    undefined4 uVar3;
    uint uVar4;
    ulong *puVar5;
    long lVar6;
    ulong *puVar7;
    ulong *puVar8;
    ulong *puVar9;
    char *pcVar10;
    ulong uVar11;
    ulong uVar12;
    ulong uVar13;
    char *pcVar14;
    ulong auStack336 [32];
    ulong auStack80 [4];

    if (param_1[4] == 2) {

        cmp_eeiopCreateDecodeThread(auStack336,param_1[8],param_1[2],param_1[1],DAT_004bd7e4);
        puVar5 = &iop_fileload_cmd;
        puVar8 = auStack336;

        do {
            puVar7 = puVar8;
            puVar9 = puVar5;
            uVar11 = puVar7[1];
            uVar12 = puVar7[2];
            uVar13 = puVar7[3];
            *puVar9 = *puVar7;
            puVar9[1] = uVar11;
            puVar9[2] = uVar12;
            puVar9[3] = uVar13;
            puVar8 = puVar7 + 4;
            puVar5 = puVar9 + 4;
        } while (puVar8 != auStack80);

        uVar11 = *puVar8;
        uVar12 = puVar7[5];
        uVar13 = puVar7[6];
        uVar3 = *(undefined4 *)(puVar7 + 7);
        uVar4 = (int)puVar9 + 0x27U & 7;
        puVar5 = (ulong *)(((int)puVar9 + 0x27U) - uVar4);
        *puVar5 = *puVar5 & -1 << (uVar4 + 1) * 8 | uVar11 >> (7 - uVar4) * 8;
        puVar9[4] = uVar11;
        uVar4 = (int)puVar9 + 0x2fU & 7;
        puVar5 = (ulong *)(((int)puVar9 + 0x2fU) - uVar4);
        *puVar5 = *puVar5 & -1 << (uVar4 + 1) * 8 | uVar12 >> (7 - uVar4) * 8;
        puVar9[5] = uVar12;
        uVar4 = (int)puVar9 + 0x37U & 7;
        puVar5 = (ulong *)(((int)puVar9 + 0x37U) - uVar4);
        *puVar5 = *puVar5 & -1 << (uVar4 + 1) * 8 | uVar13 >> (7 - uVar4) * 8;
        puVar9[6] = uVar13;
        *(undefined4 *)(puVar9 + 7) = uVar3;
    }
    else {
        DAT_004bd848._0_4_ = param_1[2] + param_1[7];
        DAT_004bd858._0_4_ = param_1[8] - param_1[7];
        DAT_004bd850._4_4_ = param_1[1] + ((int)param_1[7] >> 0xb);
        iop_fileload_cmd._0_4_ = param_1[4];
    }

    DAT_004bd850._0_4_ = DAT_004bd7d4;
    DAT_004bd848._4_4_ = DAT_004bd7d8;
    lVar6 = cddatIsCmpFile(*param_1);
    pcVar14 = (char *)((int)&DAT_004bd858 + 4);

    if (lVar6 == 0) {
        GetFileNameBuffer(*param_1,0x4bd85c);
    }
    else {
        GetFileNameBuffer(*param_1,0x4bd85c);
        pcVar10 = (char *)0x0;
        cVar2 = DAT_004bd858._4_1_;
        cVar1 = DAT_004bd858._4_1_;
        while (cVar1 != '\0') {
            if (cVar2 == '.') {
                pcVar10 = pcVar14;
            }
            pcVar14 = pcVar14 + 1;
            cVar1 = *pcVar14;
            cVar2 = *pcVar14;
        }
        if (pcVar10 != (char *)0x0) {
            *pcVar10 = '_';
        }
        strcat((char *)((int)&DAT_004bd858 + 4),&DAT_003f4960);
    }

    if ((int)DAT_004bd848 == 0) {
        SetAssertPreMessage(0x3e7110,0x3e7140,0x260,0x3e7238);
        PrintAssertReal(0x3e7250);
    }
    FlushCache(0);
    sceSifCallRpc(0x4bd980,0,1,0x4bd840,0x140,0x4bd800,0x40,0x26eee8,0);

    return;
}
