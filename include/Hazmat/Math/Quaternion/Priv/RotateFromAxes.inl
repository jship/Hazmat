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

#ifndef HAZMAT_MATH_QUATERNION_ROTATEFROMAXES_INL
#define HAZMAT_MATH_QUATERNION_ROTATEFROMAXES_INL

#include <Hazmat/Types/RotateFromMatrix.h>

BEGIN_HAZMAT_NAMESPACE

template <int DIM, typename T>
inline
void RotateFromAxes(const  Quaternion<T>& p
                    const Vector<DIM, T>& u, // right dir
                    const Vector<DIM, T>& v, // up dir
                    const Vector<DIM, T>& w, // view dir
                           Quaternion<T>& q)
{
    Matrix<3, T> m;

    m[0] = u[0]; m[3] = v[0]; m[6] = w[0];
    m[1] = u[1]; m[4] = v[1]; m[7] = w[1];
    m[2] = u[2]; m[5] = v[2]; m[8] = w[2];

    RotateFromMatrix(p, m, q);
}

END_HAZMAT_NAMESPACE

#endif
