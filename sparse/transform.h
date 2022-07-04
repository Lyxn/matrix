//
// Created by lyxn on 2022/7/2.
//

#ifndef MATRIX_TRANSFORM_H
#define MATRIX_TRANSFORM_H


#include "CoorSchema.h"
#include "LinkedMatrix.h"
#include "PackedMatrix.h"

namespace sparse {

LinkedMatrix buildLinkedFromCoor(const CoorSchema &mat);

PackedMatrix buildPackedFromCoor(const CoorSchema &mat);

} // sparse

#endif //MATRIX_TRANSFORM_H
