#ifndef HAZMAT_MATH_SQUAREDLENGTH_H
#define HAZMAT_MATH_SQUAREDLENGTH_H

#include <Hazmat/Math/Dot.h>

BEGIN_HAZMAT_NAMESPACE

template <size_t DIM, typename T>
inline
T SquaredLength(const Vector<DIM, T>& u)
{
    return Dot(u, u);
}

END_HAZMAT_NAMESPACE

#endif
