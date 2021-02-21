//
// Created by wagrenier on 2/21/2021.
//

#include "g3dCore.h"

G3DCREATIONDATA g3dApplyLight()
{
    if (s_pObject == 0) {
        _SetLineInfo(0x3aeb10,0x346,0x3aefa8,0x3aebe8);
        g3ddbgAssert(s_pObject != 0,0x3aebf8);
    }

    _ApplyLightDirectional();
    _ApplyLightPoint();
    _ApplyLightSpot();
    g3dSetLightStatus(s_pObject + 0x9c0);

    gcc2_compiled.();

    return 1;
}

void g3dSetAmbient(undefined8 *param_1)
{
    undefined8 uVar1;
    int iVar2;
    G3DCREATIONDATA uVar3;
    G3DCREATIONDATA uVar4;

    if (s_pObject == 0) {
        _SetLineInfo(0x3aeb10,0x1f1,0x3aecc0,0x3aebe8);
        g3ddbgAssert(s_pObject != 0,0x3aebf8);
    }

    iVar2 = s_pObject;
    uVar1 = *param_1;
    uVar3 = *(G3DCREATIONDATA *)(param_1 + 1);
    uVar4 = *(G3DCREATIONDATA *)((int)param_1 + 0xc);
    *(int *)(s_pObject + 0x4b0) = (int)uVar1;
    *(int *)(iVar2 + 0x4b4) = (int)((ulong)uVar1 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x4b8) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x4bc) = uVar4;
    iVar2 = s_pObject;
    uVar1 = *param_1;
    uVar3 = *(G3DCREATIONDATA *)(param_1 + 1);
    uVar4 = *(G3DCREATIONDATA *)((int)param_1 + 0xc);
    *(int *)(s_pObject + 0xb40) = (int)uVar1;
    *(int *)(iVar2 + 0xb44) = (int)((ulong)uVar1 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0xb48) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0xb4c) = uVar4;
    _CalcAmbient();
}

int g3dGetTransformRef(long param_1)
{
    if (s_pObject == 0) {
        _SetLineInfo(0x3aeb10,0x272,0x3aed38,0x3aebe8);
        g3ddbgAssert(s_pObject != 0,0x3aebf8);
    }

    if (4 < param_1) {
        _SetLineInfo(0x3aeb10,0x273,0x3aed38,0x3aecf8);
        g3ddbgAssert(0,0x3f0b10);
    }

    return s_pObject + (int)param_1 * 0x40 + 0x510;
}

void g3dInitialize(G3DCREATIONDATA *param_1)
{
    G3DCREATIONDATA *puVar1;
    int iVar2;
    undefined8 uVar3;
    uint uVar4;

    s_pObject = (G3DCREATIONDATA *)*param_1;
    g3ddbgVerifyVu1MemAddress();
    g3ddbgVerifyGsRegisterAddress();
    puVar1 = s_pObject;
    s_pObject[9] = 1;
    *puVar1 = 1;
    puVar1[1] = 1;
    puVar1[2] = 1;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[0x130] = 0;
    puVar1[0x131] = 0;
    puVar1[0x132] = 0;
    puVar1[0x133] = 0;
    puVar1[0x134] = 0;
    puVar1[0x135] = 0;
    puVar1[0x136] = 0;
    puVar1[0x137] = 0;
    puVar1[0x138] = 0;
    puVar1[0x139] = 0;
    puVar1[0x13a] = 0;
    puVar1[0x13b] = 0;
    puVar1[0x13c] = 0;
    puVar1[0x13d] = 0;
    puVar1[0x13e] = 0;
    puVar1[0x13f] = 0;
    puVar1[0x140] = 0x3f800000;
    puVar1[0x141] = 0;
    puVar1[0x142] = 0;
    puVar1[0x143] = 0;
    puVar1 = s_pObject;
    s_pObject[300] = 0x3f800000;
    puVar1[0x12d] = 0;
    puVar1[0x12e] = 0;
    puVar1[0x12f] = 0;
    uVar4 = 0;

    do {
        puVar1 = s_pObject + uVar4 * 0x20;
        puVar1[0x28] = 0;
        uVar3 = 0;

        if (((2 < uVar4) && (uVar3 = 1, 2 < uVar4 - 3)) && (uVar3 = 2, 2 < uVar4 - 6)) {
            uVar3 = 0x7fffffff;
        }

        uVar4 = uVar4 + 1;
        g3dutilSetLightDefault(puVar1 + 0xc,uVar3);

    } while ((int)uVar4 < 9);

    iVar2 = 0;

    do {
        puVar1 = s_pObject + iVar2 * 0x10;
        puVar1[0x144] = 0x3f800000;
        puVar1[0x145] = 0;
        puVar1[0x146] = 0;
        puVar1[0x147] = 0;
        puVar1[0x148] = 0;
        puVar1[0x149] = 0x3f800000;
        puVar1[0x14a] = 0;
        puVar1[0x14b] = 0;
        puVar1[0x14c] = 0;
        puVar1[0x14d] = 0;
        puVar1[0x14e] = 0x3f800000;
        puVar1[0x14f] = 0;
        puVar1[0x150] = 0;
        puVar1[0x151] = 0;
        puVar1[0x152] = 0;
        puVar1[0x153] = 0x3f800000;
        iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
}

G3DCREATIONDATA g3dSetMaterial(G3DMATERIAL const *param_1)
{
    undefined8 uVar1;
    int iVar2;
    undefined8 *puVar3;
    G3DCREATIONDATA uVar4;
    G3DCREATIONDATA uVar5;

    if (s_pObject == 0) {
        _SetLineInfo(0x3aeb10,0x2c6,0x3aed50,0x3aebe8);
        g3ddbgAssert(s_pObject != 0,0x3aebf8);
    }

    if (param_1 == 0) {
        _SetLineInfo(0x3aeb10,0x2c7,0x3aed50,0x3aed60);
        g3ddbgAssert(0,0x3f0b10);
    }

    iVar2 = s_pObject;
    puVar3 = (undefined8 *)param_1;
    uVar1 = *puVar3;
    uVar4 = *(G3DCREATIONDATA *)(puVar3 + 1);
    uVar5 = *(G3DCREATIONDATA *)((int)puVar3 + 0xc);
    *(int *)(s_pObject + 0x4c0) = (int)uVar1;
    *(int *)(iVar2 + 0x4c4) = (int)((ulong)uVar1 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x4c8) = uVar4;
    *(G3DCREATIONDATA *)(iVar2 + 0x4cc) = uVar5;
    uVar1 = puVar3[2];
    uVar4 = *(G3DCREATIONDATA *)(puVar3 + 3);
    uVar5 = *(G3DCREATIONDATA *)((int)puVar3 + 0x1c);
    *(int *)(iVar2 + 0x4d0) = (int)uVar1;
    *(int *)(iVar2 + 0x4d4) = (int)((ulong)uVar1 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x4d8) = uVar4;
    *(G3DCREATIONDATA *)(iVar2 + 0x4dc) = uVar5;
    uVar1 = puVar3[4];
    uVar4 = *(G3DCREATIONDATA *)(puVar3 + 5);
    uVar5 = *(G3DCREATIONDATA *)((int)puVar3 + 0x2c);
    *(int *)(iVar2 + 0x4e0) = (int)uVar1;
    *(int *)(iVar2 + 0x4e4) = (int)((ulong)uVar1 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x4e8) = uVar4;
    *(G3DCREATIONDATA *)(iVar2 + 0x4ec) = uVar5;
    uVar1 = puVar3[6];
    uVar4 = *(G3DCREATIONDATA *)(puVar3 + 7);
    uVar5 = *(G3DCREATIONDATA *)((int)puVar3 + 0x3c);
    *(int *)(iVar2 + 0x4f0) = (int)uVar1;
    *(int *)(iVar2 + 0x4f4) = (int)((ulong)uVar1 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x4f8) = uVar4;
    *(G3DCREATIONDATA *)(iVar2 + 0x4fc) = uVar5;
    uVar1 = puVar3[8];
    uVar4 = *(G3DCREATIONDATA *)(puVar3 + 9);
    uVar5 = *(G3DCREATIONDATA *)((int)puVar3 + 0x4c);
    *(int *)(iVar2 + 0x500) = (int)uVar1;
    *(int *)(iVar2 + 0x504) = (int)((ulong)uVar1 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x508) = uVar4;
    *(G3DCREATIONDATA *)(iVar2 + 0x50c) = uVar5;
    iVar2 = s_pObject;
    puVar3 = (undefined8 *)(s_pObject + 0x4c0);
    uVar4 = *(G3DCREATIONDATA *)(s_pObject + 0x4c8);
    uVar5 = *(G3DCREATIONDATA *)(s_pObject + 0x4cc);
    *(int *)(s_pObject + 0xaf0) = (int)*puVar3;
    *(int *)(iVar2 + 0xaf4) = (int)((ulong)*puVar3 >> 0x20);

    *(G3DCREATIONDATA *)(iVar2 + 0xaf8) = uVar4;
    *(G3DCREATIONDATA *)(iVar2 + 0xafc) = uVar5;
    *(G3DCREATIONDATA *)(iVar2 + 0xb00) = *(G3DCREATIONDATA *)(iVar2 + 0x4d0);
    *(G3DCREATIONDATA *)(iVar2 + 0xb04) = *(G3DCREATIONDATA *)(iVar2 + 0x4d4);
    *(G3DCREATIONDATA *)(iVar2 + 0xb08) = *(G3DCREATIONDATA *)(iVar2 + 0x4d8);
    *(G3DCREATIONDATA *)(iVar2 + 0xb0c) = *(G3DCREATIONDATA *)(iVar2 + 0x4dc);
    *(G3DCREATIONDATA *)(iVar2 + 0xb10) = *(G3DCREATIONDATA *)(iVar2 + 0x4e0);
    *(G3DCREATIONDATA *)(iVar2 + 0xb14) = *(G3DCREATIONDATA *)(iVar2 + 0x4e4);
    *(G3DCREATIONDATA *)(iVar2 + 0xb18) = *(G3DCREATIONDATA *)(iVar2 + 0x4e8);
    *(G3DCREATIONDATA *)(iVar2 + 0xb1c) = *(G3DCREATIONDATA *)(iVar2 + 0x4ec);
    *(G3DCREATIONDATA *)(iVar2 + 0xb20) = *(G3DCREATIONDATA *)(iVar2 + 0x4f0);
    *(G3DCREATIONDATA *)(iVar2 + 0xb24) = *(G3DCREATIONDATA *)(iVar2 + 0x4f4);
    *(G3DCREATIONDATA *)(iVar2 + 0xb28) = *(G3DCREATIONDATA *)(iVar2 + 0x4f8);
    *(G3DCREATIONDATA *)(iVar2 + 0xb2c) = *(G3DCREATIONDATA *)(iVar2 + 0x4fc);
    *(G3DCREATIONDATA *)(iVar2 + 0xb30) = *(G3DCREATIONDATA *)(iVar2 + 0x500);
    *(G3DCREATIONDATA *)(iVar2 + 0xb34) = *(G3DCREATIONDATA *)(iVar2 + 0x504);
    *(G3DCREATIONDATA *)(iVar2 + 0xb38) = *(G3DCREATIONDATA *)(iVar2 + 0x508);
    *(G3DCREATIONDATA *)(iVar2 + 0xb3c) = *(G3DCREATIONDATA *)(iVar2 + 0x50c);
    *(G3DCREATIONDATA *)(s_pObject + 0xbb0) = *(G3DCREATIONDATA *)(s_pObject + 0x4cc);
    _CalcAmbient();
    gcc2_compiled.();

    return 1;
}

G3DCREATIONDATA g3dSetTexture(long param_1, CTexture *param_2)
{
    int iVar1;
    undefined8 local_60;
    undefined8 local_58;
    undefined8 local_50;
    undefined8 local_48;
    undefined8 local_40;
    undefined8 local_38;
    undefined8 local_30;
    undefined8 local_28;

    if (s_pObject == 0) {
        _SetLineInfo(0x3aeb10,0x35f,0x3aefb8,0x3aebe8);
        g3ddbgAssert(s_pObject != 0,0x3aebf8);
    }

    if (0 < param_1) {
        _SetLineInfo(0x3aeb10,0x360,0x3aefb8,0x3aefc8);
        g3ddbgAssert(param_1 < 1,0x3f0b10);
    }

    iVar1 = (int)param_2;
    *(int *)((int)param_1 * 4 + s_pObject + 0x680) = iVar1;
    if (param_2 != 0) {
        (**(code **)(*(int *)(iVar1 + 4) + 0x14))(iVar1 + *(short *)(*(int *)(iVar1 + 4) + 0x10));
        local_60 = *(undefined8 *)(iVar1 + 0x70);
        local_38 = 6;
        local_50 = *(undefined8 *)(iVar1 + 0x78);
        local_58 = 6;
        local_48 = 0x14;
        local_28 = 0x14;
        local_40 = local_60;
        local_30 = local_50;
        g3dSetGsRegisters(&local_60,2,1);
    }

    return 1;
}

G3DCREATIONDATA g3dLightEnable(long param_1,G3DCREATIONDATA param_2)
{
    if (s_pObject == 0) {
        _SetLineInfo(0x3aeb10,0x2fc,0x3aed88,0x3aebe8);
        g3ddbgAssert(s_pObject != 0,0x3aebf8);
    }
    if (8 < param_1) {
        _SetLineInfo(0x3aeb10,0x2fd,0x3aed88,0x3aed98);
        g3ddbgAsserte(0,0x3aedb8,param_1);
    }
    *(G3DCREATIONDATA *)((int)param_1 * 0x80 + s_pObject + 0xa0) = param_2;
    return 1;
}

G3DCREATIONDATA g3dSetRenderState(G3DRENDERSTATETYPE param_1, unsigned int param_2)
{
    uint uVar1;

    if (s_pObject == 0) {
        _SetLineInfo(0x3aeb10,0x18e,0x3aebd0,0x3aebe8);
        g3ddbgAssert(s_pObject != 0,0x3aebf8);
    }
    if (7 < param_1) {
        _SetLineInfo(0x3aeb10,399,0x3aebd0,0x3aec18);
        g3ddbgAssert(0,0x3f0b10);
    }
    uVar1 = (uint)param_2;
    *(uint *)(s_pObject + param_1 * 4) = uVar1;
    if (param_1 == 7) {
        g3dSetGsRegister
                (param_2 & 0xff | ((long)(int)(uVar1 >> 8) & 0xffU) << 8 |
                 ((long)(int)(uVar1 >> 0x10) & 0xffU) << 0x10,0x3d,1);
    }
    return 1;
}

G3DCREATIONDATA g3dSetLight(int param_1, G3DLIGHT const *param_2)
{
    bool bVar1;
    int iVar2;
    G3DCREATIONDATA uVar3;
    G3DCREATIONDATA uVar4;
    undefined8 *puVar5;
    int iVar6;
    undefined8 uVar7;
    float fVar8;
    float fVar9;

    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x314,0x3aedf0,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (param_2 == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x315,0x3aedf0,0x3f0b18);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    if (8 < (long)param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x316,0x3aedf0,0x3aed98);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    iVar6 = (int)param_1;
    iVar2 = 0;
    if ((2 < param_1) && (iVar2 = 1, 2 < iVar6 - 3U)) {
        iVar2 = 2;
        if (2 < iVar6 - 6U) {
            iVar2 = 0x7fffffff;
        }
    }
    puVar5 = (undefined8 *)param_2;
    if (iVar2 != *(int *)(puVar5 + 10)) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x318,0x3aedf0,0x3aee00);
        iVar2 = 0;
        if ((2 < param_1) && (iVar2 = 1, 2 < iVar6 - 3U)) {
            iVar2 = 2;
            if (2 < iVar6 - 6U) {
                iVar2 = 0x7fffffff;
            }
        }
        g3ddbgAssert__FbPCce(iVar2 == *(int *)(puVar5 + 10),0x3aee30);
    }
    fVar8 = *(float *)(puVar5 + 0xc);
    if (fVar8 < 0.0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x319,0x3aedf0,0x3aee80);
        g3ddbgWarning__FbPCce(0.0 <= *(float *)(puVar5 + 0xc),0x3f0b10);
        fVar8 = *(float *)(puVar5 + 0xc);
        fVar9 = *(float *)((int)puVar5 + 0x5c);
    }
    else {
        fVar9 = *(float *)((int)puVar5 + 0x5c);
    }
    if (fVar9 < fVar8) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x31a,0x3aedf0,0x3aeea0);
        g3ddbgWarning__FbPCce(*(float *)(puVar5 + 0xc) <= *(float *)((int)puVar5 + 0x5c),0x3f0b10);
        fVar8 = *(float *)(puVar5 + 0xb);
    }
    else {
        fVar8 = *(float *)(puVar5 + 0xb);
    }
    if (fVar8 < *(float *)((int)puVar5 + 0x54)) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x31b,0x3aedf0,0x3aeec8);
        g3ddbgWarning__FbPCce(*(float *)((int)puVar5 + 0x54) <= *(float *)(puVar5 + 0xb),0x3f0b10);
    }
    bVar1 = false;
    if (*(int *)(puVar5 + 10) == 1) {
        iVar2 = memcmp(puVar5 + 8,g_v0000,0x10);
        bVar1 = iVar2 != 0;
    }
    if (bVar1) {
        uVar7 = 0;
        _SetLineInfo__FPCciT0T0(0x3aeb10,799,0x3aedf0,0x3aeef8);
        if ((*(int *)(puVar5 + 10) != 1) || (iVar2 = memcmp(puVar5 + 8,g_v0000,0x10), iVar2 == 0)) {
            uVar7 = 1;
        }
        g3ddbgWarning__FbPCce(uVar7,0x3f0b10);
    }
    iVar2 = s_pObject + iVar6 * 0x80;
    uVar7 = *puVar5;
    uVar3 = *(G3DCREATIONDATA *)(puVar5 + 1);
    uVar4 = *(G3DCREATIONDATA *)((int)puVar5 + 0xc);
    *(int *)(iVar2 + 0x30) = (int)uVar7;
    *(int *)(iVar2 + 0x34) = (int)((ulong)uVar7 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x38) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x3c) = uVar4;
    uVar7 = puVar5[2];
    uVar3 = *(G3DCREATIONDATA *)(puVar5 + 3);
    uVar4 = *(G3DCREATIONDATA *)((int)puVar5 + 0x1c);
    *(int *)(iVar2 + 0x40) = (int)uVar7;
    *(int *)(iVar2 + 0x44) = (int)((ulong)uVar7 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x48) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x4c) = uVar4;
    uVar7 = puVar5[4];
    uVar3 = *(G3DCREATIONDATA *)(puVar5 + 5);
    uVar4 = *(G3DCREATIONDATA *)((int)puVar5 + 0x2c);
    *(int *)(iVar2 + 0x50) = (int)uVar7;
    *(int *)(iVar2 + 0x54) = (int)((ulong)uVar7 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x58) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x5c) = uVar4;
    uVar7 = puVar5[6];
    uVar3 = *(G3DCREATIONDATA *)(puVar5 + 7);
    uVar4 = *(G3DCREATIONDATA *)((int)puVar5 + 0x3c);
    *(int *)(iVar2 + 0x60) = (int)uVar7;
    *(int *)(iVar2 + 100) = (int)((ulong)uVar7 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x68) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x6c) = uVar4;
    uVar7 = puVar5[8];
    uVar3 = *(G3DCREATIONDATA *)(puVar5 + 9);
    uVar4 = *(G3DCREATIONDATA *)((int)puVar5 + 0x4c);
    *(int *)(iVar2 + 0x70) = (int)uVar7;
    *(int *)(iVar2 + 0x74) = (int)((ulong)uVar7 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x78) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x7c) = uVar4;
    uVar7 = puVar5[10];
    uVar3 = *(G3DCREATIONDATA *)(puVar5 + 0xb);
    uVar4 = *(G3DCREATIONDATA *)((int)puVar5 + 0x5c);
    *(int *)(iVar2 + 0x80) = (int)uVar7;
    *(int *)(iVar2 + 0x84) = (int)((ulong)uVar7 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x88) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x8c) = uVar4;
    uVar7 = puVar5[0xc];
    uVar3 = *(G3DCREATIONDATA *)(puVar5 + 0xd);
    uVar4 = *(G3DCREATIONDATA *)((int)puVar5 + 0x6c);
    *(int *)(iVar2 + 0x90) = (int)uVar7;
    *(int *)(iVar2 + 0x94) = (int)((ulong)uVar7 >> 0x20);
    *(G3DCREATIONDATA *)(iVar2 + 0x98) = uVar3;
    *(G3DCREATIONDATA *)(iVar2 + 0x9c) = uVar4;
    return 1;
}

G3DCREATIONDATA g3dSetTransform(G3DTRANSFORMSTATETYPE param_1, float const (*)[3] param_2)
{
    int iVar1;
    float *pfVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float fVar15;
    float fVar16;
    float fVar17;
    float fVar18;
    float fVar19;
    float fVar20;
    float fVar21;
    float fVar22;
    float fVar23;
    float fVar24;
    float fVar25;
    float fVar26;
    float fVar27;
    float fVar28;
    float fVar29;
    float fVar30;
    float fVar31;
    float fVar32;
    float fVar33;
    float fVar34;

    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x23c,0x3aece8,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (4 < param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x23d,0x3aece8,0x3aecf8);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    iVar1 = s_pObject + (int)param_1 * 0x40;
    fVar3 = param_2[1];
    fVar4 = param_2[2];
    fVar5 = param_2[3];
    fVar6 = param_2[4];
    fVar7 = param_2[5];
    fVar8 = param_2[6];
    fVar9 = param_2[7];
    fVar10 = param_2[8];
    fVar11 = param_2[9];
    fVar12 = param_2[10];
    fVar13 = param_2[0xb];
    fVar14 = param_2[0xc];
    fVar15 = param_2[0xd];
    fVar16 = param_2[0xe];
    fVar17 = param_2[0xf];
    *(float *)(iVar1 + 0x510) = *param_2;
    *(float *)(iVar1 + 0x514) = fVar3;
    *(float *)(iVar1 + 0x518) = fVar4;
    *(float *)(iVar1 + 0x51c) = fVar5;
    *(float *)(iVar1 + 0x520) = fVar6;
    *(float *)(iVar1 + 0x524) = fVar7;
    *(float *)(iVar1 + 0x528) = fVar8;
    *(float *)(iVar1 + 0x52c) = fVar9;
    *(float *)(iVar1 + 0x530) = fVar10;
    *(float *)(iVar1 + 0x534) = fVar11;
    *(float *)(iVar1 + 0x538) = fVar12;
    *(float *)(iVar1 + 0x53c) = fVar13;
    *(float *)(iVar1 + 0x540) = fVar14;
    *(float *)(iVar1 + 0x544) = fVar15;
    *(float *)(iVar1 + 0x548) = fVar16;
    *(float *)(iVar1 + 0x54c) = fVar17;
    iVar1 = s_pObject;
    switch(param_1) {
        case 0:
            fVar3 = param_2[1];
            fVar4 = param_2[2];
            fVar5 = param_2[3];
            fVar6 = param_2[4];
            fVar7 = param_2[5];
            fVar8 = param_2[6];
            fVar9 = param_2[7];
            fVar10 = param_2[8];
            fVar11 = param_2[9];
            fVar12 = param_2[10];
            fVar13 = param_2[0xb];
            fVar14 = param_2[0xc];
            fVar15 = param_2[0xd];
            fVar16 = param_2[0xe];
            fVar17 = param_2[0xf];
            *(float *)(s_pObject + 0x730) = *param_2;
            *(float *)(iVar1 + 0x734) = fVar3;
            *(float *)(iVar1 + 0x738) = fVar4;
            *(float *)(iVar1 + 0x73c) = fVar5;
            *(float *)(iVar1 + 0x740) = fVar6;
            *(float *)(iVar1 + 0x744) = fVar7;
            *(float *)(iVar1 + 0x748) = fVar8;
            *(float *)(iVar1 + 0x74c) = fVar9;
            *(float *)(iVar1 + 0x750) = fVar10;
            *(float *)(iVar1 + 0x754) = fVar11;
            *(float *)(iVar1 + 0x758) = fVar12;
            *(float *)(iVar1 + 0x75c) = fVar13;
            *(float *)(iVar1 + 0x760) = fVar14;
            *(float *)(iVar1 + 0x764) = fVar15;
            *(float *)(iVar1 + 0x768) = fVar16;
            *(float *)(iVar1 + 0x76c) = fVar17;
            fVar3 = *(float *)(s_pObject + 0x550);
            fVar4 = *(float *)(s_pObject + 0x554);
            fVar5 = *(float *)(s_pObject + 0x558);
            fVar6 = *(float *)(s_pObject + 0x55c);
            fVar7 = *(float *)(s_pObject + 0x560);
            fVar8 = *(float *)(s_pObject + 0x564);
            fVar9 = *(float *)(s_pObject + 0x568);
            fVar10 = *(float *)(s_pObject + 0x56c);
            fVar11 = *(float *)(s_pObject + 0x570);
            fVar12 = *(float *)(s_pObject + 0x574);
            fVar13 = *(float *)(s_pObject + 0x578);
            fVar14 = *(float *)(s_pObject + 0x57c);
            fVar15 = *(float *)(s_pObject + 0x580);
            fVar16 = *(float *)(s_pObject + 0x584);
            fVar17 = *(float *)(s_pObject + 0x588);
            fVar18 = *(float *)(s_pObject + 0x58c);
            fVar19 = *param_2;
            fVar20 = param_2[1];
            fVar21 = param_2[2];
            fVar22 = param_2[3];
            fVar23 = param_2[4];
            fVar24 = param_2[5];
            fVar25 = param_2[6];
            fVar26 = param_2[7];
            fVar27 = param_2[8];
            fVar28 = param_2[9];
            fVar29 = param_2[10];
            fVar30 = param_2[0xb];
            fVar31 = param_2[0xc];
            fVar32 = param_2[0xd];
            fVar33 = param_2[0xe];
            fVar34 = param_2[0xf];
            *(float *)(iVar1 + 0x770) = fVar3 * fVar19 + fVar7 * fVar20 + fVar11 * fVar21 + fVar15 * fVar22;
            *(float *)(iVar1 + 0x774) = fVar4 * fVar19 + fVar8 * fVar20 + fVar12 * fVar21 + fVar16 * fVar22;
            *(float *)(iVar1 + 0x778) = fVar5 * fVar19 + fVar9 * fVar20 + fVar13 * fVar21 + fVar17 * fVar22;
            *(float *)(iVar1 + 0x77c) = fVar6 * fVar19 + fVar10 * fVar20 + fVar14 * fVar21 + fVar18 * fVar22
                    ;
            *(float *)(iVar1 + 0x780) = fVar3 * fVar23 + fVar7 * fVar24 + fVar11 * fVar25 + fVar15 * fVar26;
            *(float *)(iVar1 + 0x784) = fVar4 * fVar23 + fVar8 * fVar24 + fVar12 * fVar25 + fVar16 * fVar26;
            *(float *)(iVar1 + 0x788) = fVar5 * fVar23 + fVar9 * fVar24 + fVar13 * fVar25 + fVar17 * fVar26;
            *(float *)(iVar1 + 0x78c) = fVar6 * fVar23 + fVar10 * fVar24 + fVar14 * fVar25 + fVar18 * fVar26
                    ;
            *(float *)(iVar1 + 0x790) = fVar3 * fVar27 + fVar7 * fVar28 + fVar11 * fVar29 + fVar15 * fVar30;
            *(float *)(iVar1 + 0x794) = fVar4 * fVar27 + fVar8 * fVar28 + fVar12 * fVar29 + fVar16 * fVar30;
            *(float *)(iVar1 + 0x798) = fVar5 * fVar27 + fVar9 * fVar28 + fVar13 * fVar29 + fVar17 * fVar30;
            *(float *)(iVar1 + 0x79c) = fVar6 * fVar27 + fVar10 * fVar28 + fVar14 * fVar29 + fVar18 * fVar30
                    ;
            *(float *)(iVar1 + 0x7a0) = fVar3 * fVar31 + fVar7 * fVar32 + fVar11 * fVar33 + fVar15 * fVar34;
            *(float *)(iVar1 + 0x7a4) = fVar4 * fVar31 + fVar8 * fVar32 + fVar12 * fVar33 + fVar16 * fVar34;
            *(float *)(iVar1 + 0x7a8) = fVar5 * fVar31 + fVar9 * fVar32 + fVar13 * fVar33 + fVar17 * fVar34;
            *(float *)(iVar1 + 0x7ac) = fVar6 * fVar31 + fVar10 * fVar32 + fVar14 * fVar33 + fVar18 * fVar34
                    ;
            break;
        case 1:
            fVar3 = *param_2;
            fVar4 = param_2[1];
            fVar5 = param_2[2];
            fVar6 = param_2[3];
            fVar7 = param_2[4];
            fVar8 = param_2[5];
            fVar9 = param_2[6];
            fVar10 = param_2[7];
            fVar11 = param_2[8];
            fVar12 = param_2[9];
            fVar13 = param_2[10];
            fVar14 = param_2[0xb];
            fVar15 = param_2[0xc];
            fVar16 = param_2[0xd];
            fVar17 = param_2[0xe];
            fVar18 = param_2[0xf];
            fVar19 = *(float *)(s_pObject + 0x510);
            fVar20 = *(float *)(s_pObject + 0x514);
            fVar21 = *(float *)(s_pObject + 0x518);
            fVar22 = *(float *)(s_pObject + 0x51c);
            fVar23 = *(float *)(s_pObject + 0x520);
            fVar24 = *(float *)(s_pObject + 0x524);
            fVar25 = *(float *)(s_pObject + 0x528);
            fVar26 = *(float *)(s_pObject + 0x52c);
            fVar27 = *(float *)(s_pObject + 0x530);
            fVar28 = *(float *)(s_pObject + 0x534);
            fVar29 = *(float *)(s_pObject + 0x538);
            fVar30 = *(float *)(s_pObject + 0x53c);
            fVar31 = *(float *)(s_pObject + 0x540);
            fVar32 = *(float *)(s_pObject + 0x544);
            fVar33 = *(float *)(s_pObject + 0x548);
            fVar34 = *(float *)(s_pObject + 0x54c);
            *(float *)(s_pObject + 0x770) =
                    fVar3 * fVar19 + fVar7 * fVar20 + fVar11 * fVar21 + fVar15 * fVar22;
            *(float *)(iVar1 + 0x774) = fVar4 * fVar19 + fVar8 * fVar20 + fVar12 * fVar21 + fVar16 * fVar22;
            *(float *)(iVar1 + 0x778) = fVar5 * fVar19 + fVar9 * fVar20 + fVar13 * fVar21 + fVar17 * fVar22;
            *(float *)(iVar1 + 0x77c) = fVar6 * fVar19 + fVar10 * fVar20 + fVar14 * fVar21 + fVar18 * fVar22
                    ;
            *(float *)(iVar1 + 0x780) = fVar3 * fVar23 + fVar7 * fVar24 + fVar11 * fVar25 + fVar15 * fVar26;
            *(float *)(iVar1 + 0x784) = fVar4 * fVar23 + fVar8 * fVar24 + fVar12 * fVar25 + fVar16 * fVar26;
            *(float *)(iVar1 + 0x788) = fVar5 * fVar23 + fVar9 * fVar24 + fVar13 * fVar25 + fVar17 * fVar26;
            *(float *)(iVar1 + 0x78c) = fVar6 * fVar23 + fVar10 * fVar24 + fVar14 * fVar25 + fVar18 * fVar26
                    ;
            *(float *)(iVar1 + 0x790) = fVar3 * fVar27 + fVar7 * fVar28 + fVar11 * fVar29 + fVar15 * fVar30;
            *(float *)(iVar1 + 0x794) = fVar4 * fVar27 + fVar8 * fVar28 + fVar12 * fVar29 + fVar16 * fVar30;
            *(float *)(iVar1 + 0x798) = fVar5 * fVar27 + fVar9 * fVar28 + fVar13 * fVar29 + fVar17 * fVar30;
            *(float *)(iVar1 + 0x79c) = fVar6 * fVar27 + fVar10 * fVar28 + fVar14 * fVar29 + fVar18 * fVar30
                    ;
            *(float *)(iVar1 + 0x7a0) = fVar3 * fVar31 + fVar7 * fVar32 + fVar11 * fVar33 + fVar15 * fVar34;
            *(float *)(iVar1 + 0x7a4) = fVar4 * fVar31 + fVar8 * fVar32 + fVar12 * fVar33 + fVar16 * fVar34;
            *(float *)(iVar1 + 0x7a8) = fVar5 * fVar31 + fVar9 * fVar32 + fVar13 * fVar33 + fVar17 * fVar34;
            *(float *)(iVar1 + 0x7ac) = fVar6 * fVar31 + fVar10 * fVar32 + fVar14 * fVar33 + fVar18 * fVar34
                    ;
            break;
        case 2:
            fVar3 = param_2[1];
            fVar4 = param_2[2];
            fVar5 = param_2[3];
            fVar6 = param_2[4];
            fVar7 = param_2[5];
            fVar8 = param_2[6];
            fVar9 = param_2[7];
            fVar10 = param_2[8];
            fVar11 = param_2[9];
            fVar12 = param_2[10];
            fVar13 = param_2[0xb];
            fVar14 = param_2[0xc];
            fVar15 = param_2[0xd];
            fVar16 = param_2[0xe];
            fVar17 = param_2[0xf];
            *(float *)(s_pObject + 0x6b0) = *param_2;
            *(float *)(iVar1 + 0x6b4) = fVar3;
            *(float *)(iVar1 + 0x6b8) = fVar4;
            *(float *)(iVar1 + 0x6bc) = fVar5;
            *(float *)(iVar1 + 0x6c0) = fVar6;
            *(float *)(iVar1 + 0x6c4) = fVar7;
            *(float *)(iVar1 + 0x6c8) = fVar8;
            *(float *)(iVar1 + 0x6cc) = fVar9;
            *(float *)(iVar1 + 0x6d0) = fVar10;
            *(float *)(iVar1 + 0x6d4) = fVar11;
            *(float *)(iVar1 + 0x6d8) = fVar12;
            *(float *)(iVar1 + 0x6dc) = fVar13;
            *(float *)(iVar1 + 0x6e0) = fVar14;
            *(float *)(iVar1 + 0x6e4) = fVar15;
            *(float *)(iVar1 + 0x6e8) = fVar16;
            *(float *)(iVar1 + 0x6ec) = fVar17;
            break;
        case 3:
            pfVar2 = (float *)(s_pObject + 0x6f0);
            goto LAB_0019c2fc;
        case 4:
            pfVar2 = (float *)(s_pObject + 0x7b0);
        LAB_0019c2fc:
            fVar3 = param_2[1];
            fVar4 = param_2[2];
            fVar5 = param_2[3];
            fVar6 = param_2[4];
            fVar7 = param_2[5];
            fVar8 = param_2[6];
            fVar9 = param_2[7];
            fVar10 = param_2[8];
            fVar11 = param_2[9];
            fVar12 = param_2[10];
            fVar13 = param_2[0xb];
            fVar14 = param_2[0xc];
            fVar15 = param_2[0xd];
            fVar16 = param_2[0xe];
            fVar17 = param_2[0xf];
            *pfVar2 = *param_2;
            pfVar2[1] = fVar3;
            pfVar2[2] = fVar4;
            pfVar2[3] = fVar5;
            pfVar2[4] = fVar6;
            pfVar2[5] = fVar7;
            pfVar2[6] = fVar8;
            pfVar2[7] = fVar9;
            pfVar2[8] = fVar10;
            pfVar2[9] = fVar11;
            pfVar2[10] = fVar12;
            pfVar2[0xb] = fVar13;
            pfVar2[0xc] = fVar14;
            pfVar2[0xd] = fVar15;
            pfVar2[0xe] = fVar16;
            pfVar2[0xf] = fVar17;
    }
    return 1;
}

int g3dGetRenderStateRef(G3DRENDERSTATETYPE param_1)
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x1b7,0x3aec38,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (7 < param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x1b8,0x3aec38,0x3aec18);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    return s_pObject + (int)param_1 * 4;
}

int g3dGetMaterialRef()
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x2ee,0x3aed70,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    return s_pObject + 0x4c0;
}

G3DCREATIONDATA g3dIsLightEnable(int param_1)
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x309,0x3aedc8,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (8 < param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x30a,0x3aedc8,0x3aed98);
        g3ddbgAssert__FbPCce(0,0x3aede0,param_1);
    }
    return *(G3DCREATIONDATA *)((int)param_1 * 0x80 + s_pObject + 0xa0);
}

void g3dCalcScreenCoord(float *param_1, sceGsXyz const *param_2)
{
    ushort uVar1;
    ushort uVar2;
    int iVar3;
    int iStack36;

    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x4e2,0x3af100,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    iVar3 = *(int *)(param_2 + 2);
    uVar1 = param_2[1];
    uVar2 = *(ushort *)(s_pObject + 0xe34);
    *param_1 = (float)((uint)*param_2 - (uint)*(ushort *)(s_pObject + 0xe30));
    param_1[1] = (float)((uint)uVar1 - (uint)uVar2);
    param_1[2] = (float)iVar3;
    param_1[3] = (float)iStack36;
    return;
}

G3DCREATIONDATA g3dSetGsRegisters(_sceGifPackAd const *param_1, int param_2, int param_3)
{
    undefined8 uVar1;
    G3DCREATIONDATA *puVar2;
    int iVar3;
    int iVar4;
    G3DCREATIONDATA uVar5;
    G3DCREATIONDATA uVar6;
    undefined8 *puVar7;
    G3DCREATIONDATA *puVar8;
    ulong uVar9;

    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x46a,0x3af048,0x3af060);
        g3ddbgWarning__FbPCce(s_pObject != 0,0x3aebf8);
        g3ddbgPrintf__FPCce(0x3af070,0,0x3aeb10,0x46a,0x3af048,0x3aebe8);
        uVar5 = 0;
    }
    else {
        if (param_3 == -1) {
            iVar4 = 0;
            if (0 < param_2) {
                iVar3 = 0;
                while( true ) {
                    iVar4 = iVar4 + 1;
                    *(undefined8 *)(s_pObject + *(int *)((undefined8 *)(param_1 + iVar3) + 1) * 8 + 0xd70) =
                            *(undefined8 *)(param_1 + iVar3);
                    if (param_2 <= iVar4) break;
                    iVar3 = iVar4 * 0x10;
                }
                return 1;
            }
        }
        else {
            iVar4 = 0;
            puVar2 = (G3DCREATIONDATA *)g3dDmaOpenPacket__Fv();
            puVar2[2] = &DAT_11000000;
            *puVar2 = 0;
            puVar2[1] = 0;
            *(ulong *)(puVar2 + 6) = *(ulong *)(puVar2 + 6) & 0xfffffffffffffff0 | 0xe;
            uVar9 = 0;
            if (0 < param_2) {
                puVar8 = puVar2 + 8;
                do {
                    puVar7 = (undefined8 *)(param_1 + iVar4 * 0x10);
                    iVar3 = s_pObject + *(int *)(puVar7 + 1) * 8;
                    if (0x7f < (ulong)puVar7[1]) {
                        _SetLineInfo__FPCciT0T0(0x3aeb10,0x495,0x3af048,0x3af090);
                        g3ddbgAssert__FbPCce((ulong)puVar7[1] < 0x80,0x3f0b10);
                    }
                    *(undefined8 *)(iVar3 + 0xd70) = *puVar7;
                    uVar1 = *puVar7;
                    uVar5 = *(G3DCREATIONDATA *)(puVar7 + 1);
                    uVar6 = *(G3DCREATIONDATA *)((int)puVar7 + 0xc);
                    *puVar8 = (int)uVar1;
                    puVar8[1] = (int)((ulong)uVar1 >> 0x20);
                    puVar8[2] = uVar5;
                    puVar8[3] = uVar6;
                    iVar4 = iVar4 + 1;
                    uVar9 = SEXT48((int)uVar9 + 1);
                    puVar8 = puVar8 + 4;
                } while (iVar4 < param_2);
            }
            if (uVar9 == 0) {
                g3dDmaCancelPacket__Fv();
                return 0;
            }
            puVar2[3] = (int)uVar9 + 1U | 0x50000000;
            *(ulong *)(puVar2 + 4) = uVar9 | 0x1000000000008000;
            g3dDmaClosePacket__FPCv(puVar2 + (int)uVar9 * 4 + 8);
        }
        uVar5 = 1;
    }
    return uVar5;
}

int g3dGetGlobalStateRef(G3DGLOBALSTATETYPE param_1)
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x1e6,0x3aeca8,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (1 < param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x1e7,0x3aeca8,0x3aec68);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    return s_pObject + (int)param_1 * 4 + 0x20;
}

int g3dGetLightRef(int param_1)
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x33b,0x3aef98,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (8 < param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x33c,0x3aef98,0x3aed98);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    return s_pObject + (int)param_1 * 0x80 + 0x30;
}

void g3dCalcGsPrimitiveCoord(sceGsXyz *param_1, float const *param_2)
{
    float fVar1;
    int iVar2;
    float fVar3;
    short local_30;
    short local_2c;

    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x4cf,0x3af0e8,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    iVar2 = s_pObject;
    local_30 = (short)(int)*param_2;
    local_2c = (short)(int)param_2[1];
    *param_1 = *(short *)(s_pObject + 0xe30) + local_30;
    fVar3 = DAT_003ee368;
    fVar1 = DAT_003ee364;
    param_1[1] = *(short *)(iVar2 + 0xe34) + local_2c;
    fVar3 = (param_2[2] - 0.0) * fVar1 + fVar3;
    if ((byte)((uint)fVar3 >> 0x17) < 0x9e) {
        iVar2 = (int)fVar3;
    }
    else {
        if ((int)fVar3 < 0) {
            iVar2 = 0x7fffffff;
        }
        else {
            iVar2 = -0x80000000;
        }
    }
    *(int *)(param_1 + 2) = iVar2;
    return;
}

G3DCREATIONDATA g3dSetGlobalState(G3DGLOBALSTATETYPE param_1, unsigned int param_2)
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x1c2,0x3aec50,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (1 < param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x1c3,0x3aec50,0x3aec68);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    *(int *)(param_1 * 4 + s_pObject + 0x20) = (int)param_2;
    if ((param_1 == 1) && (2 < param_2)) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x1ca,0x3aec50,0x3aec88);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    return 1;
}

int g3dGetAmbientRef()
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x20a,0x3aecd0,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    return s_pObject + 0x4b0;
}

G3DCREATIONDATA g3dSetGsRegister(long param_1, long param_2, int param_3)
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x43d,0x3af000,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (0x7f < param_2) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x43f,0x3af000,0x3af018);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    *(undefined8 *)(s_pObject + (int)param_2 * 8 + 0xd70) = param_1;
    if (param_3 != -1) {
        g3dDmaSetGsRegister__FUlUl(param_1,param_2);
    }
    return 1;
}

void g3dCalcVertexColor(float *param_1, float const *param_2, float const *param_3, float const *param_4)
{
    undefined8 uVar1;
    int iVar2;
    ulong uVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    int iVar8;
    int iVar9;
    float fVar10;
    float fVar11;
    float local_50;
    float fStack76;
    float fStack72;
    float fStack68;

    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x3f1,0x3aefe8,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    iVar2 = s_pObject;
    iVar9 = *(int *)(s_pObject + 0x24);
    uVar1 = *param_4;
    fVar4 = *(float *)(param_4 + 1);
    fVar5 = *(float *)((int)param_4 + 0xc);
    *param_1 = (float)uVar1;
    param_1[1] = (float)((ulong)uVar1 >> 0x20);
    param_1[2] = fVar4;
    param_1[3] = fVar5;
    uVar3 = *(ulong *)(iVar2 + 0x9c8);
    iVar8 = iVar9 * 4;
    if ((uVar3 & 7) != 0) {
        (**(code **)(s_apfLoadColor + iVar8))(iVar2 + 0x810);
        (**(code **)(s_apfLoadColorCoeff + iVar8))();
        (**(code **)(s_apfCalcVertexColorDirectionalLight + iVar8))(&local_50);
        *param_1 = *param_1 + local_50;
        param_1[1] = param_1[1] + fStack76;
        param_1[2] = param_1[2] + fStack72;
        param_1[3] = param_1[3] + fStack68;
        uVar3 = *(ulong *)(iVar2 + 0x9c8);
    }
    iVar8 = iVar9 * 4;
    if ((uVar3 & 0x70) != 0) {
        (**(code **)(s_apfLoadColor + iVar8))(iVar2 + 0x8a0);
        (**(code **)(s_apfLoadColorCoeff + iVar8))();
        (**(code **)(s_apfCalcVertexColorPointLight + iVar8))(&local_50);
        *param_1 = *param_1 + local_50;
        param_1[1] = param_1[1] + fStack76;
        param_1[2] = param_1[2] + fStack72;
        param_1[3] = param_1[3] + fStack68;
        uVar3 = *(ulong *)(iVar2 + 0x9c8);
    }
    iVar9 = iVar9 * 4;
    if ((uVar3 & 0x700) != 0) {
        (**(code **)(s_apfLoadColor + iVar9))(iVar2 + 0x930);
        (**(code **)(s_apfLoadColorCoeff + iVar9))();
        (**(code **)(s_apfCalcVertexColorSpotLight + iVar9))(&local_50);
        *param_1 = *param_1 + local_50;
        param_1[1] = param_1[1] + fStack76;
        param_1[2] = param_1[2] + fStack72;
        param_1[3] = param_1[3] + fStack68;
    }
    fVar4 = *(float *)(s_pObject + 0xba4);
    fVar5 = *(float *)(s_pObject + 0xba8);
    *param_1 = *param_1 + *(float *)(s_pObject + 0xba0);
    param_1[1] = param_1[1] + fVar4;
    param_1[2] = param_1[2] + fVar5;
    param_1[3] = param_1[3];
    fVar6 = 0.0;
    fVar7 = 1.0;
    fVar4 = *param_1;
    fVar5 = param_1[1];
    fVar10 = param_1[2];
    fVar11 = param_1[3];
    if (fVar4 <= 0.0) {
        fVar4 = fVar6;
    }
    if (fVar5 <= 0.0) {
        fVar5 = fVar6;
    }
    if (fVar10 <= 0.0) {
        fVar10 = fVar6;
    }
    if (fVar11 <= 0.0) {
        fVar11 = fVar6;
    }
    if (1.0 <= fVar4) {
        fVar4 = fVar7;
    }
    if (1.0 <= fVar5) {
        fVar5 = fVar7;
    }
    if (1.0 <= fVar10) {
        fVar10 = fVar7;
    }
    if (1.0 <= fVar11) {
        fVar11 = fVar7;
    }
    *param_1 = fVar4;
    param_1[1] = fVar5;
    param_1[2] = fVar10;
    param_1[3] = fVar11;
}

int g3dGetGsRegisterRef(long param_1)
{
    if (s_pObject == 0) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x4c2,0x3af0d0,0x3aebe8);
        g3ddbgAssert__FbPCce(s_pObject != 0,0x3aebf8);
    }
    if (0x7f < param_1) {
        _SetLineInfo__FPCciT0T0(0x3aeb10,0x4c3,0x3af0d0,0x3af018);
        g3ddbgAssert__FbPCce(0,0x3f0b10);
    }
    return s_pObject + (int)param_1 * 8 + 0xd70;
}
