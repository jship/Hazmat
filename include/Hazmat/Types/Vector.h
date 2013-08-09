#ifndef HAZMAT_TYPES_VECTOR_H
#define HAZMAT_TYPES_VECTOR_H

#include <Hazmat/Types/Array.h>

BEGIN_HAZMAT_NAMESPACE

template <size_t DIM, typename T>
class Vector : public Array<DIM, T> { };

END_HAZMAT_NAMESPACE

#endif
