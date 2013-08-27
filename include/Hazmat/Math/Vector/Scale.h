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

#ifndef HAZMAT_MATH_VECTOR_SCALE_H
#define HAZMAT_MATH_VECTOR_SCALE_H

#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class LinearScaling;

template <typename T>
class LinearScaling<2, T>
{
public:
    static Vector<2, T>& compute(const Vector<2, T>& u, T s, Vector<2, T>& v)
    {
        v[X] = s * u[X];
        v[Y] = s * u[Y];
        return v;
    }
};

template <typename T>
class LinearScaling<3, T>
{
public:
    static Vector<3, T>& compute(const Vector<3, T>& u, T s, Vector<3, T>& v)
    {
        v[X] = s * u[X];
        v[Y] = s * u[Y];
        v[Z] = s * u[Z];
        return v;
    }
};

template <typename T>
class LinearScaling<4, T>
{
public:
    static Vector<4, T>& compute(const Vector<4, T>& u, T s, Vector<4, T>& v)
    {
        v[X] = s * u[X];
        v[Y] = s * u[Y];
        v[Z] = s * u[Z];
        v[W] = s * u[W];
        return v;
    }
};

}

template <int DIM, typename T>
inline
Vector<DIM, T>& Scale(const Vector<DIM, T>& u, T s, Vector<DIM, T>& v)
{
    return Priv::LinearScaling<DIM, T>::compute(u, s, v);
}

template <int DIM, typename T>
inline
Vector<DIM, T>& operator*=(Vector<DIM, T>& u, T s)
{
    return Scale(u, s, u);
}

template <int DIM, typename T>
inline
Vector<DIM, T> operator*(Vector<DIM, T> u, T s)
{
    u *= s;
    return u;
}

template <int DIM, typename T>
inline
Vector<DIM, T> operator*(T s, Vector<DIM, T> u)
{
    u *= s;
    return u;
}

END_HAZMAT_NAMESPACE

#endif
