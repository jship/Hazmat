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

#ifndef HAZMAT_MATH_VECTOR_CROSS_INL
#define HAZMAT_MATH_VECTOR_CROSS_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Cross;

// Cross is mathematically only defined for 3D vectors
// (and this lib is not concerned with 7D!).
template <typename T>
class Cross<3, T>
{
public:
    static Vector<3, T>& compute(const Vector<3, T>& u,
                                 const Vector<3, T>& v,
                                       Vector<3, T>& w)
    {
        w[X] = u[Y] * v[Z] - u[Z] * v[Y];
        w[Y] = u[Z] * v[X] - u[X] * v[Z];
        w[Z] = u[X] * v[Y] - u[Y] * v[X];
        return w;
    }
};

// 4D defined for convenience. Note that w's fourth
// component is set to 0.
template <typename T>
class Cross<4, T>
{
public:
    static Vector<4, T>& compute(const Vector<4, T>& u,
                                 const Vector<4, T>& v,
                                       Vector<4, T>& w)
    {
        w[X] = u[Y] * v[Z] - u[Z] * v[Y];
        w[Y] = u[Z] * v[X] - u[X] * v[Z];
        w[Z] = u[X] * v[Y] - u[Y] * v[X];
        w[W] = T();
        return w;
    }
};

}

END_HAZMAT_NAMESPACE

#endif
