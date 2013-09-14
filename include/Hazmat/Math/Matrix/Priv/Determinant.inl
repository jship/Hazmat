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

#ifndef HAZMAT_MATH_MATRIX_DETERMINANT_INL
#define HAZMAT_MATH_MATRIX_DETERMINANT_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Determinant;

template <typename T>
class Determinant<4, T>
{
public:
    static T compute(const Matrix<4, T>& a)
    {
        return a[0] * a[3] -
               a[1] * a[2];
    }
};

template <typename T>
class Determinant<9, T>
{
public:
    static T compute(const Matrix<9, T>& a)
    {
        return a[0] * a[4] * a[8] +
               a[1] * a[5] * a[6] +
               a[2] * a[3] * a[7] -
               a[2] * a[4] * a[6] -
               a[1] * a[3] * a[8] -
               a[0] * a[5] * a[7];
    }
};

template <typename T>
class Determinant<16, T>
{
public:
    static T compute(const Matrix<16, T>& a)
    {
        return a[ 0] * a[ 6] * a[11] * a[13] +
               a[ 0] * a[ 7] * a[ 9] * a[14] +
               a[ 1] * a[ 4] * a[11] * a[14] +
               a[ 1] * a[ 6] * a[ 8] * a[15] +
               a[ 1] * a[ 7] * a[10] * a[12] +
               a[ 2] * a[ 4] * a[ 9] * a[15] +
               a[ 2] * a[ 5] * a[11] * a[12] +
               a[ 2] * a[ 7] * a[ 8] * a[13] +
               a[ 3] * a[ 4] * a[10] * a[13] +
               a[ 3] * a[ 5] * a[ 8] * a[14] +
               a[ 3] * a[ 6] * a[ 9] * a[12] +
               a[ 0] * a[ 5] * a[10] * a[15] -
               a[ 0] * a[ 5] * a[11] * a[14] -
               a[ 0] * a[ 6] * a[ 9] * a[15] -
               a[ 0] * a[ 7] * a[10] * a[13] -
               a[ 1] * a[ 4] * a[10] * a[15] -
               a[ 1] * a[ 6] * a[11] * a[12] -
               a[ 1] * a[ 7] * a[ 8] * a[14] -
               a[ 2] * a[ 4] * a[11] * a[13] -
               a[ 2] * a[ 5] * a[ 8] * a[15] -
               a[ 2] * a[ 7] * a[ 9] * a[12] -
               a[ 3] * a[ 5] * a[10] * a[12] -
               a[ 3] * a[ 6] * a[ 8] * a[13] -
               a[ 3] * a[ 4] * a[ 9] * a[14];
    }
};

}

template <int DIM, typename T>
inline
T Determinant(const Matrix<DIM, T>& a)
{
    return Priv::Determinant<DIM, T>::compute(a);
}

END_HAZMAT_NAMESPACE

#endif
