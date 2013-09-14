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

#ifndef HAZMAT_MATH_MATRIX_TRANSPOSE_H
#define HAZMAT_MATH_MATRIX_TRANSPOSE_H

#include <Hazmat/Types/Matrix.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Transpose;

template <typename T>
class Transpose<4, T>
{
public:
    static Matrix<4, T>& compute(const Matrix<4, T>& a, Matrix<4, T>& b)
    {
        T uy = a[1];

        b[0] = a[0];
        b[1] = a[2];
        b[2] = uy;
        b[3] = a[3];
        return b;
    }
};

template <typename T>
class Transpose<9, T>
{
public:
    static Matrix<9, T>& compute(const Matrix<9, T>& a, Matrix<9, T>& b)
    {
        T uy = a[1], uz = a[2], vz = a[5];

        b[0] = a[0];
        b[1] = a[3];
        b[2] = a[6];
        b[3] = uy;
        b[4] = a[4];
        b[5] = a[7];
        b[6] = uz;
        b[7] = vz;
        b[8] = a[8];
        return b;
    }
};

template <typename T>
class Transpose<16, T>
{
public:
    static Matrix<16, T>& compute(const Matrix<16, T>& a, Matrix<16, T>& b)
    {
        T uy = a[1], uz = a[2], uw = a[3], vz = a[6], vw = a[7], ww = a[11];

        b[ 0] = a[ 0];
        b[ 1] = a[ 4];
        b[ 2] = a[ 8];
        b[ 3] = a[12];
        b[ 4] = uy;
        b[ 5] = a[ 5];
        b[ 6] = a[ 9];
        b[ 7] = a[13];
        b[ 8] = uz;
        b[ 9] = vz;
        b[10] = a[10];
        b[11] = a[14];
        b[12] = uw;
        b[13] = vw;
        b[14] = ww;
        b[15] = a[15];
        return b;
    }
};

}

template <int DIM, typename T>
inline
Matrix<DIM, T>& Transpose(const Matrix<DIM, T>& a, Matrix<DIM, T>& b)
{
    return Priv::Transpose<DIM, T>::compute(a, b);
}

END_HAZMAT_NAMESPACE

#endif
