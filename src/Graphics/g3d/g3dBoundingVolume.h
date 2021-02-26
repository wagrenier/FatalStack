//
// Created by William on 2/19/2021.
//

#ifndef FATALSTACK_G3DBOUNDINGVOLUME_H
#define FATALSTACK_G3DBOUNDINGVOLUME_H

bool g3dbvIsEllipseInclude(float const (*)[3] param1, float const *param2);

void g3dbvInnerEllipseFromVertices(float (*)[3] param1, float const (*)[3] param2);

void g3dbvBoxFromVertices(float (*)[3] param1, float const (*)[3] param2);

#endif //FATALSTACK_G3DBOUNDINGVOLUME_H
