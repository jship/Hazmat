#ifndef HAZMAT_MATH_VECTOR_LENGTH_H
#define HAZMAT_MATH_VECTOR_LENGTH_H

#include <Hazmat/Math/Vector/SquaredLength.h>

BEGIN_HAZMAT_NAMESPACE

template <size_t DIM, typename T>
inline
T Length(const Vector<DIM, T>& u)
{
    return std::sqrt(SquaredLength(u));
}

END_HAZMAT_NAMESPACE

#endif
