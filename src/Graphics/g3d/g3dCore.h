//
// Created by wagrenier on 2/21/2021.
//

#ifndef FATALSTACK_G3DCORE_H
#define FATALSTACK_G3DCORE_H

G3DCREATIONDATA g3dApplyLight();
void g3dSetAmbient(float const * param_1); // 0019bfd8
int  g3dGetTransformRef(G3DTRANSFORMSTATETYPE param_1); // 0019c338
void g3dInitialize(G3DCREATIONDATA const *param_1); // 0x0019bb20
G3DCREATIONDATA g3dSetMaterial(G3DMATERIAL const *param_1); //0x0019c3e0
G3DCREATIONDATA g3dSetTexture(int param_1, CTexture *param_2); // 0x0019cb68
G3DCREATIONDATA g3dLightEnable(int param_1, int param_2); // 0x000000000019c550
G3DCREATIONDATA g3dSetRenderState(G3DRENDERSTATETYPE param_1, unsigned int param_2);
G3DCREATIONDATA g3dSetLight(int param_1, G3DLIGHT const *param_2);
G3DCREATIONDATA g3dSetTransform(G3DTRANSFORMSTATETYPE param_1, float const (*)[3] param_2);
int g3dGetRenderStateRef(G3DRENDERSTATETYPE param_1);
int g3dGetMaterialRef();
G3DCREATIONDATA g3dIsLightEnable(int param_1);
void g3dCalcScreenCoord(float *param_1, sceGsXyz const *param_2);
G3DCREATIONDATA g3dSetGsRegisters(_sceGifPackAd const *param_1, int param_2, int param_3);
int g3dGetGlobalStateRef(G3DGLOBALSTATETYPE param_1);
int g3dGetLightRef(int param_1);
void g3dCalcGsPrimitiveCoord(sceGsXyz *param_1, float const *param_2);
G3DCREATIONDATA g3dSetGlobalState(G3DGLOBALSTATETYPE param_1, unsigned int param_2);
int g3dGetAmbientRef();
int g3dSetGsRegister(long param_1, long param_2, int param_3);
void g3dCalcVertexColor(float *param_1, float const *param_2, float const *param_3, float const *param_4);
int g3dGetGsRegisterRef(long param_1);

#endif //FATALSTACK_G3DCORE_H
