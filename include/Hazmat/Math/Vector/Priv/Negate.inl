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

#ifndef HAZMAT_MATH_VECTOR_NEGATE_INL
#define HAZMAT_MATH_VECTOR_NEGATE_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Negation;

template <typename T>
class Negation<2, T>
{
public:
    static void compute(const Vector<2, T>& u,
                              Vector<2, T>& v)
    {
        v[X] = -u[X];
        v[Y] = -u[Y];
    }
};

template <typename T>
class Negation<3, T>
{
public:
    static void compute(const Vector<3, T>& u,
                              Vector<3, T>& v)
    {
        v[X] = -u[X];
        v[Y] = -u[Y];
        v[Z] = -u[Z];
    }
};

template <typename T>
class Negation<4, T>
{
public:
    static void compute(const Vector<4, T>& u,
                              Vector<4, T>& v)
    {
        v[X] = -u[X];
        v[Y] = -u[Y];
        v[Z] = -u[Z];
        v[W] = -u[W];
    }
};

}

template <int DIM, typename T>
inline
void Negate(const Vector<DIM, T>& u,
                  Vector<DIM, T>& v)
{
    Priv::Negation<DIM, T>::compute(u, v);
}

template <int DIM, typename T>
inline
Vector<DIM, T> operator-(const Vector<DIM, T>& u)
{
    Vector<DIM, T> v;
    Negate(u, v);
    return v;
}

END_HAZMAT_NAMESPACE

#endif
