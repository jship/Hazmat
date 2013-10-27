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

#ifndef HAZMAT_MATH_VECTOR_ADD_INL
#define HAZMAT_MATH_VECTOR_ADD_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class VectorAddition;

template <typename T>
class VectorAddition<2, T>
{
public:
    static void compute(const Vector<2, T>& u,
                        const Vector<2, T>& v,
                              Vector<2, T>& w)
    {
        w[X] = u[X] + v[X];
        w[Y] = u[Y] + v[Y];
    }
};

template <typename T>
class VectorAddition<3, T>
{
public:
    static void compute(const Vector<3, T>& u,
                        const Vector<3, T>& v,
                              Vector<3, T>& w)
    {
        w[X] = u[X] + v[X];
        w[Y] = u[Y] + v[Y];
        w[Z] = u[Z] + v[Z];
    }
};

template <typename T>
class VectorAddition<4, T>
{
public:
    static void compute(const Vector<4, T>& u,
                        const Vector<4, T>& v,
                              Vector<4, T>& w)
    {
        w[X] = u[X] + v[X];
        w[Y] = u[Y] + v[Y];
        w[Z] = u[Z] + v[Z];
        w[W] = u[W] + v[W];
    }
};

}


template <int DIM, typename T>
inline
void Add(const Vector<DIM, T>& u,
         const Vector<DIM, T>& v,
               Vector<DIM, T>& w)
{
    Priv::VectorAddition<DIM, T>::compute(u, v, w);
}

template <int DIM, typename T>
inline
Vector<DIM, T>& operator+=(      Vector<DIM, T>& u,
                           const Vector<DIM, T>& v)
{
    Add(u, v, u);
    return u;
}

template <int DIM, typename T>
inline
Vector<DIM, T> operator+(      Vector<DIM, T>  u,
                         const Vector<DIM, T>& v)
{
    u += v;
    return u;
}

END_HAZMAT_NAMESPACE

#endif
