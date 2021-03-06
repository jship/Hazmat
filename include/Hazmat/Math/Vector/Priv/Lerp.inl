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

#ifndef HAZMAT_MATH_VECTOR_LERP_INL
#define HAZMAT_MATH_VECTOR_LERP_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class VectorLerp;

template <typename T>
class VectorLerp<2, T>
{
public:
    static void compute(const Vector<2, T>& u,
                        const Vector<2, T>& v,
                        const           T   t,
                              Vector<2, T>& w)
    {
        w[X] = u[X] + t * (v[X] - u[X]);
        w[Y] = u[Y] + t * (v[Y] - u[Y]);
    }
};

template <typename T>
class VectorLerp<3, T>
{
public:
    static void compute(const Vector<3, T>& u,
                        const Vector<3, T>& v,
                        const           T   t,
                              Vector<3, T>& w)
    {
        w[X] = u[X] + t * (v[X] - u[X]);
        w[Y] = u[Y] + t * (v[Y] - u[Y]);
        w[Z] = u[Z] + t * (v[Z] - u[Z]);
    }
};

template <typename T>
class VectorLerp<4, T>
{
public:
    static void compute(const Vector<4, T>& u,
                        const Vector<4, T>& v,
                        const           T   t,
                              Vector<4, T>& w)
    {
        w[X] = u[X] + t * (v[X] - u[X]);
        w[Y] = u[Y] + t * (v[Y] - u[Y]);
        w[Z] = u[Z] + t * (v[Z] - u[Z]);
        w[W] = u[W] + t * (v[W] - u[W]);
    }
};

}

template <int DIM, typename T>
inline
void Lerp(const Vector<DIM, T>& u,
          const Vector<DIM, T>& v,
          const             T   t,
                Vector<DIM, T>& w)
{
    Priv::VectorLerp<DIM, T>::compute(u, v, t, w);
}

END_HAZMAT_NAMESPACE

#endif
