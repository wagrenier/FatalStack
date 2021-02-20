//
// Created by wagrenier on 2/19/2021.
//

#ifndef FATALSTACK_G3DCAMERA_H
#define FATALSTACK_G3DCAMERA_H

float g3dCalcDistanceToScreen(float param_1, float param_2);
void g3dCalcViewClipMatrixOrtho(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8);
void g3dCalcViewScreenMatrixPerspective(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10);
void g3dCalcViewScreenMatrixOrtho(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10);
void g3dCalcScreenGSPrimitiveMatrix(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7);
void g3dCalcViewClipMatrixPerspective(float (*)[3] param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8);

#endif //FATALSTACK_G3DCAMERA_H
