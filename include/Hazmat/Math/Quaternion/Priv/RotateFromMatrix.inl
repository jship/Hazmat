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

// Matrix to quaternion conversion is NOT the Hazmat author's original work.
// This code is available publicly from:
// http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
//
// The Hazmat author changed the code to use templates, flat arrays, and to
// cache the inverse of s (slightly more efficient by avoiding division).

#ifndef HAZMAT_MATH_QUATERNION_ROTATEFROMMATRIX_INL
#define HAZMAT_MATH_QUATERNION_ROTATEFROMMATRIX_INL

#include <Hazmat/Math/Quaternion/Rotate.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class RotateFromMatrix;

template <typename T>
class RotateFromMatrix<9, T>
{
public:
    static void RotateFromMatrix(const Quaternion<T>& p,
                                 const  Matrix<9, T>& a,
                                       Quaternion<T>& q)
    {
        // Should use traits templates for this, but this is fine for now.
        // Also, more readable than static_cast'ing all over the place.
        const T zero    = static_cast<T>(0.00);
        const T quarter = static_cast<T>(0.25);
        const T half    = static_cast<T>(0.50);
        const T one     = static_cast<T>(1.00);
        const T two     = static_cast<T>(2.00);

        const T trace = a[0] + a[4] + a[8];
        
        Quaternion<T> tmp;

        if (trace > zero)
        {
            const T s = half / std::sqrt(trace + one);

            tmp[0] = (a[5] - a[7]) * s;
            tmp[1] = (a[6] - a[2]) * s;
            tmp[2] = (a[1] - a[3]) * s;
            tmp[3] = quarter / s;
        }
        else
        {
            if (a[0] > a[5] && a[0] > a[10])
            {
                const T s    = two * std::sqrt(one + a[0] - a[5] - a[10]);
                const T invS = one / s;

                tmp[0] = quarter * s;
                tmp[1] = (a[3] + a[1]) * invS;
                tmp[2] = (a[6] + a[2]) * invS;
                tmp[3] = (a[5] - a[7]) * invS;
            }
            else if (a[5] > a[10])
            {
                const T s    = two * std::sqrt(one + a[5] - a[0] - a[10]);
                const T invS = one / s;

                tmp[1] = quarter * s;
                tmp[0] = (a[3] + a[1]) * invS;
                tmp[2] = (a[7] + a[5]) * invS;
                tmp[3] = (a[6] - a[2]) * invS;
            }
            else
            {
                const T s    = two * std::sqrt(one + a[10] - a[0] - a[5]);
                const T invS = one / s;

                tmp[2] = quarter * s;
                tmp[0] = (a[6] + a[2]) * invS;
                tmp[1] = (a[7] + a[5]) * invS;
                tmp[3] = (a[1] - a[3]) * invS;
            }
        }

        Rotate(p, tmp, q);
    }
};

template <typename T>
class RotateFromMatrix<16, T>
{
public:
    static void RotateFromMatrix(const Quaternion<T>& p,
                                 const Matrix<16, T>& a,
                                       Quaternion<T>& q)
    {
        // Should use traits templates for this, but this is fine for now.
        // Also, more readable than static_cast'ing all over the place.
        const T zero    = static_cast<T>(0.00);
        const T quarter = static_cast<T>(0.25);
        const T half    = static_cast<T>(0.50);
        const T one     = static_cast<T>(1.00);
        const T two     = static_cast<T>(2.00);

        const T trace = a[0] + a[5] + a[10];

        Quaternion<T> tmp;

        if (trace > zero)
        {
            const T s = half / std::sqrt(trace + one);

            tmp[0] = (a[6] - a[9]) * s;
            tmp[1] = (a[8] - a[2]) * s;
            tmp[2] = (a[1] - a[4]) * s;
            tmp[3] = quarter / s;
        }
        else
        {
            if (a[0] > a[5] && a[0] > a[10])
            {
                const T s    = two * std::sqrt(one + a[0] - a[5] - a[10]);
                const T invS = one / s;

                tmp[0] = quarter * s;
                tmp[1] = (a[4] + a[1]) * invS;
                tmp[2] = (a[8] + a[2]) * invS;
                tmp[3] = (a[6] - a[9]) * invS;
            }
            else if (a[5] > a[10])
            {
                const T s    = two * std::sqrt(one + a[5] - a[0] - a[10]);
                const T invS = one / s;

                tmp[1] = quarter * s;
                tmp[0] = (a[4] + a[1]) * invS;
                tmp[2] = (a[9] + a[6]) * invS;
                tmp[3] = (a[8] - a[2]) * invS;
            }
            else
            {
                const T s    = two * std::sqrt(one + a[10] - a[0] - a[5]);
                const T invS = one / s;

                tmp[2] = quarter * s;
                tmp[0] = (a[8] + a[2]) * invS;
                tmp[1] = (a[9] + a[6]) * invS;
                tmp[3] = (a[1] - a[4]) * invS;
            }
        }

        Rotate(p, tmp, q);
    }
};

}

template <int DIM, typename T>
inline
void RotateFromMatrix(const  Quaternion<T>& p,
                      const Matrix<DIM, T>& a,
                             Quaternion<T>& q)
{
    Priv::RotateFromMatrix<DIM, T>::compute(p, a, q);
}

END_HAZMAT_NAMESPACE

#endif
