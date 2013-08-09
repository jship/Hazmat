#ifndef HAZMAT_TYPES_MATRIX_H
#define HAZMAT_TYPES_MATRIX_H

#include <Hazmat/Types/Array.h>

BEGIN_HAZMAT_NAMESPACE

template <size_t DIM, typename T>
class Matrix : public Array<DIM, T> { };

END_HAZMAT_NAMESPACE

#endif
