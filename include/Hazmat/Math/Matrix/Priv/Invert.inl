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

#ifndef HAZMAT_MATH_MATRIX_INVERT_INL
#define HAZMAT_MATH_MATRIX_INVERT_INL

#include <Hazmat/Math/Matrix/Adjugate.h>
#include <Hazmat/Math/Matrix/Determinant.h>

BEGIN_HAZMAT_NAMESPACE

template <int DIM, typename T>
inline
void Invert(const Matrix<DIM, T>& a, Matrix<DIM, T>& b)
{
    T d = Determinant(a);
    if (d == T())
    {
        // b is left unchanged if a is singular.
        return;
    }

    d = static_cast<T>(1) / d;
    Adjugate(a, b);

    for (int i = 0; i < b.dimensions; i++)
    {
        b[i] *= d;
    }
}

END_HAZMAT_NAMESPACE

#endif
