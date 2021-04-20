//
// Created by wagrenier on 2/19/2021.
//

#include "g3dBoundingVolume.h"

bool g3dbvIsEllipseInclude(float const (*)[3] param1, float const *param2) {
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float in_vf1x;
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
    float fVar16

    fVar5 = *param1;
    fVar6 = param1[1];
    fVar7 = param1[2];
    fVar8 = param1[4];
    fVar9 = param1[5];
    fVar10 = param1[6];
    fVar11 = param1[8];
    fVar12 = param1[9];
    fVar13 = param1[10];
    fVar14 = fVar9 * fVar13 - fVar12 * fVar10;
    fVar15 = fVar10 * fVar11 - fVar13 * fVar8;
    fVar16 = fVar8 * fVar12 - fVar11 * fVar9;

    fVar1 = 1.0 / (fVar5 * fVar14 + fVar6 * fVar15 + in_vf1x * fVar7 * fVar16) + 0.0;

    fVar2 = (0.0 - param1[0xc]) + *param2;
    fVar3 = (0.0 - param1[0xd]) + param2[1];
    fVar4 = (0.0 - param1[0xe]) + param2[2];

    fVar14 = fVar14 * fVar1 * fVar2 + fVar15 * fVar1 * fVar3 + fVar16 * fVar1 * fVar4;

    fVar11 = (fVar12 * fVar7 - fVar6 * fVar13) * fVar1 * fVar2 +
             (fVar13 * fVar5 - fVar7 * fVar11) * fVar1 * fVar3 +
             (fVar11 * fVar6 - fVar5 * fVar12) * fVar1 * fVar4;

    fVar1 = (fVar6 * fVar10 - fVar9 * fVar7) * fVar1 * fVar2 +
            (fVar7 * fVar8 - fVar10 * fVar5) * fVar1 * fVar3 +
            (fVar5 * fVar9 - fVar8 * fVar6) * fVar1 * fVar4;

    return SQRT(fVar14 * fVar14 + fVar11 * fVar11 + in_vf1x * fVar1 * fVar1) + 0.0 <= 1.0;
}

void g3dbvInnerEllipseFromVertices(float (*)[3] param1, float const (*)[3] param2) {
    g3dbvBoxFromVertices(param1, param2);
}

void g3dbvBoxFromVertices(float (*)[3] param1, float const (*)[3] param2) {
    float fVar1;
    float fVar2;
    float fVar3;
    float extraout_vf1x;
    float fVar4;
    float fVar5;
    float fVar6;

    memset(param_1, 0, 0x40);
    fVar4 = param_2[7];
    fVar5 = param_2[3];
    fVar2 = param_2[4] - *param_2;
    fVar1 = param_2[5] - param_2[1];
    fVar3 = param_2[6] - param_2[2];

    fVar6 = 1.0 / SQRT(fVar2 * fVar2 + fVar1 * fVar1 + extraout_vf1x * fVar3 * fVar3);

    *param_1 = fVar2 * fVar6;
    param_1[1] = fVar1 * fVar6;
    param_1[2] = fVar3 * fVar6;
    param_1[3] = (fVar4 - fVar5) * 1.0;
    fVar4 = param_2[0xb];
    fVar5 = param_2[3];
    fVar2 = param_2[8] - *param_2;
    fVar1 = param_2[9] - param_2[1];
    fVar3 = param_2[10] - param_2[2];
    fVar6 = 1.0 / SQRT(fVar2 * fVar2 + fVar1 * fVar1 + extraout_vf1x * fVar3 * fVar3);
    param_1[4] = fVar2 * fVar6;
    param_1[5] = fVar1 * fVar6;
    param_1[6] = fVar3 * fVar6;
    param_1[7] = (fVar4 - fVar5) * 1.0;
    fVar4 = param_2[0x13];
    fVar5 = param_2[3];
    fVar2 = param_2[0x10] - *param_2;
    fVar1 = param_2[0x11] - param_2[1];
    fVar3 = param_2[0x12] - param_2[2];

    fVar6 = 1.0 / SQRT(fVar2 * fVar2 + fVar1 * fVar1 + extraout_vf1x * fVar3 * fVar3);

    param_1[8] = fVar2 * fVar6;
    param_1[9] = fVar1 * fVar6;
    param_1[10] = fVar3 * fVar6;
    param_1[0xb] = (fVar4 - fVar5) * 1.0;

    fVar2 = param_2[4] - *param_2;

    fVar1 = (SQRT(fVar2 * fVar2 + (param_2[5] - param_2[1]) * (param_2[5] - param_2[1]) +
                  extraout_vf1x * (param_2[6] - param_2[2]) * (param_2[6] - param_2[2])) + 0.0) * 0.5;

    fVar2 = param_2[8] - *param_2;

    fVar3 = (SQRT(fVar2 * fVar2 + (param_2[9] - param_2[1]) * (param_2[9] - param_2[1]) +
                  extraout_vf1x * (param_2[10] - param_2[2]) * (param_2[10] - param_2[2])) + 0.0) *
            0.5;
    fVar2 = param_2[0x10] - *param_2;
    fVar2 = (SQRT(fVar2 * fVar2 + (param_2[0x11] - param_2[1]) * (param_2[0x11] - param_2[1]) +
                  extraout_vf1x * (param_2[0x12] - param_2[2]) * (param_2[0x12] - param_2[2])) + 0.0)
                          * 0.5;
    param_1[0xc] = param_1[0xc];
    param_1[0xd] = param_1[0xd];
    param_1[0xe] = param_1[0xe];
    param_1[0xf] = param_1[0xf];
    *param_1 = *param_1 * fVar1;
    param_1[1] *= fVar1;
    param_1[2] *= fVar1;
    param_1[3] *= fVar1;
    param_1[4] *= fVar3;
    param_1[5] *= fVar3;
    param_1[6] *= fVar3;
    param_1[7] *= fVar3;
    param_1[8] *= fVar2;
    param_1[9] *= fVar2;
    param_1[10] *= fVar2;
    param_1[0xb] = param_1[0xb] * fVar2;
    fVar2 = param_2[1];
    fVar1 = param_2[2];
    fVar3 = param_2[3];
    fVar4 = param_2[0x1d];
    fVar5 = param_2[0x1e];
    param_1[0xc] = *param_2 * 0.5 + param_2[0x1c] * 0.5;
    param_1[0xd] = fVar2 * 0.5 + fVar4 * 0.5;
    param_1[0xe] = fVar1 * 0.5 + fVar5 * 0.5;
    param_1[0xf] = fVar3;
}