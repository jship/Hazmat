/* Hazmat Copyright (c) 2013 Jason Shipman
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software in a
 *    product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not
 *    be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef HAZMAT_MATH_VECTOR_NORM_H
#define HAZMAT_MATH_VECTOR_NORM_H

#include <Hazmat/Math/Vector/Scale.h>
#include <Hazmat/Math/Vector/SquaredLength.h>

BEGIN_HAZMAT_NAMESPACE

template <size_t DIM, typename T>
inline
Vector<DIM, T>& Norm(const Vector<DIM, T>& u, Vector<DIM, T>& v)
{
    T length = SquaredLength(u);

    if (!(length > T()))
    {
        return v;
    }

    length = static_cast<T>(1) / std::sqrt(length);
    return Scale(u, length, v);
}

template <size_t DIM, typename T>
inline
Vector<DIM, T>& Norm(Vector<DIM, T>& u)
{
    return Norm(u, u);
}

END_HAZMAT_NAMESPACE

#endif