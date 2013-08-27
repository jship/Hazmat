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

#ifndef HAZMAT_MATH_MATRIX_IDENTITY_H
#define HAZMAT_MATH_MATRIX_IDENTITY_H

#include <Hazmat/Types/Matrix.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Identity;

template <typename T>
class Identity<4, T>
{
public:
    static Matrix<4, T>& set(Matrix<4, T>& a)
    {
        a[0] = static_cast<T>(1);
        a[1] = T();
        a[2] = T();
        a[3] = static_cast<T>(1);
        return a;
    }
};

template <typename T>
class Identity<9, T>
{
public:
    static Matrix<9, T>& set(Matrix<9, T>& a)
    {
        a[0] = static_cast<T>(1);
        a[1] = T();
        a[2] = T();
        a[3] = T();
        a[4] = static_cast<T>(1);
        a[5] = T();
        a[6] = T();
        a[7] = T();
        a[8] = static_cast<T>(1);
        return a;
    }
};

template <typename T>
class Identity<16, T>
{
public:
    static Matrix<16, T>& set(Matrix<16, T>& a)
    {
        a[ 0] = static_cast<T>(1);
        a[ 1] = T();
        a[ 2] = T();
        a[ 3] = T();
        a[ 4] = T();
        a[ 5] = static_cast<T>(1);
        a[ 6] = T();
        a[ 7] = T();
        a[ 8] = T();
        a[ 9] = T();
        a[10] = static_cast<T>(1);
        a[11] = T();
        a[12] = T();
        a[13] = T();
        a[14] = T();
        a[15] = static_cast<T>(1);
        return a;
    }
};

}

template <int DIM, typename T>
inline
Matrix<DIM, T>& Identity(Matrix<DIM, T>& a)
{
    return Priv::Identity<DIM, T>::set(a);
}

END_HAZMAT_NAMESPACE

#endif
