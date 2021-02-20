//
// Created by wagrenier on 2/19/2021.
//

#include "g3dCamera.h"

float g3dCalcDistanceToScreen(float param_1, float param_2)
{
    float fVar1;
    fVar1 = tanf(param_1 * 0.5);
    return param_2 / fVar1;
}

void g3dCalcViewClipMatrixOrtho(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8)
{
    // SCE method
    sceVu0UnitMatrix();
    *param_8 = param_2 / param_6;
    param_8[5] = param_3 / param_7;
    param_8[0xe] = (param_5 + param_4) / (param_5 - param_4);
    param_8[10] = -2.0 / (param_5 - param_4);
}

void g3dCalcViewScreenMatrixPerspective(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10)
{
    undefined4 *puVar1;
    float fVar2;
    float in_stack_00000000;
    undefined auStack144 [64];

    fVar2 = (in_stack_00000000 * param_8 * (param_7 - param_6)) / (in_stack_00000000 - param_8);
    sceVu0UnitMatrix();
    puVar1 = (undefined4 *)param_9;
    puVar1[5] = param_1;
    puVar1[0xb] = 0x3f800000;
    puVar1[0xe] = 0x3f800000;
    *puVar1 = param_1;
    puVar1[10] = 0;
    puVar1[0xf] = 0;
    g3dCalcScreenGSPrimitiveMatrix__FPA3_fffffff
            (param_2,param_3,fVar2,param_4,param_5,
             (-param_7 * param_8 + param_6 * in_stack_00000000) / (in_stack_00000000 - param_8),
             auStack144);
    sceVu0MulMatrix(param_9,auStack144,param_9);
}

void g3dCalcViewScreenMatrixOrtho(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10)
{
    float in_stack_00000000;
    float local_50;
    float fStack76;
    float fStack72;
    float fStack68;
    float local_40;
    float fStack60;
    float fStack56;
    float fStack52;
    float local_30;
    float fStack44;
    float fStack40;
    float fStack36;
    float local_20;
    float fStack28;
    float fStack24;
    float fStack20;

    g3dCalcScreenGSPrimitiveMatrix__FPA3_fffffff
            (param_2,param_3,
             (in_stack_00000000 * param_8 * (param_7 - param_6)) / (in_stack_00000000 - param_8),
             param_4,param_5,
             (-param_7 * param_8 + param_6 * in_stack_00000000) / (in_stack_00000000 - param_8),
             &local_50);

    *param_9 = local_50 * 1.0 + local_40 * 0.0 + local_30 * 0.0 + local_20 * 0.0;
    param_9[1] = fStack76 * 1.0 + fStack60 * 0.0 + fStack44 * 0.0 + fStack28 * 0.0;
    param_9[2] = fStack72 * 1.0 + fStack56 * 0.0 + fStack40 * 0.0 + fStack24 * 0.0;
    param_9[3] = fStack68 * 1.0 + fStack52 * 0.0 + fStack36 * 0.0 + fStack20 * 0.0;
    param_9[4] = local_50 * 0.0 + local_40 * 1.0 + local_30 * 0.0 + local_20 * 0.0;
    param_9[5] = fStack76 * 0.0 + fStack60 * 1.0 + fStack44 * 0.0 + fStack28 * 0.0;
    param_9[6] = fStack72 * 0.0 + fStack56 * 1.0 + fStack40 * 0.0 + fStack24 * 0.0;
    param_9[7] = fStack68 * 0.0 + fStack52 * 1.0 + fStack36 * 0.0 + fStack20 * 0.0;
    param_9[8] = local_50 * 0.0 + local_40 * 0.0 + local_30 * 1.0 + local_20 * 0.0;
    param_9[9] = fStack76 * 0.0 + fStack60 * 0.0 + fStack44 * 1.0 + fStack28 * 0.0;
    param_9[10] = fStack72 * 0.0 + fStack56 * 0.0 + fStack40 * 1.0 + fStack24 * 0.0;
    param_9[0xb] = fStack68 * 0.0 + fStack52 * 0.0 + fStack36 * 1.0 + fStack20 * 0.0;
    param_9[0xc] = local_50 * 0.0 + local_40 * 0.0 + local_30 * 0.0 + local_20 * 1.0;
    param_9[0xd] = fStack76 * 0.0 + fStack60 * 0.0 + fStack44 * 0.0 + fStack28 * 1.0;
    param_9[0xe] = fStack72 * 0.0 + fStack56 * 0.0 + fStack40 * 0.0 + fStack24 * 1.0;
    param_9[0xf] = fStack68 * 0.0 + fStack52 * 0.0 + fStack36 * 0.0 + fStack20 * 1.0;
}

void g3dCalcScreenGSPrimitiveMatrix(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7)
{
    sceVu0UnitMatrix();
    param_7[0xe] = param_6;
    *param_7 = param_1;
    param_7[5] = param_2;
    param_7[10] = param_3;
    param_7[0xc] = param_4;
    param_7[0xd] = param_5;
}

void g3dCalcViewClipMatrixPerspective(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8)
{
    param_6 = param_6 * (param_4 / param_1);
    param_7 = param_7 * (param_4 / param_1);

    sceVu0UnitMatrix();

    param_8[0xf] = 0.0;
    param_8[0xb] = 1.0;
    param_8[0xe] = (param_5 * param_4 * -2.0) / (param_5 - param_4);
    param_8[5] = ((param_4 + param_4) * param_3) / (param_7 + param_7);
    *param_8 = ((param_4 + param_4) * param_2) / (param_6 + param_6);
    param_8[10] = (param_5 + param_4) / (param_5 - param_4);
}