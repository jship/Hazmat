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

#ifndef HAZMAT_MATH_QUATERNION_ROTATEFROMAXISANGLE_INL
#define HAZMAT_MATH_QUATERNION_ROTATEFROMAXISANGLE_INL

#include <Hazmat/Math/Quaternion/Rotate.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class RotateFromAxisAngle;

template <typename T>
class RotateFromAxisAngle<3, T>
{
public:
    static void compute(const  Quaternion<T>& p
                        const   Vector<3, T>& u,
                        const             T   radians,
                               Quaternion<T>& q)
    {
        const T halfAngleRad = static_cast<T>(0.5) * radians;
        const T sine         = std::sin(halfAngleRad);
        const T cosine       = std::cos(halfAngleRad);

        Quaternion<T> tmp;

        tmp[0] = u[0] * sine;
        tmp[1] = u[1] * sine;
        tmp[2] = u[2] * sine;
        tmp[3] = cosine;

        Rotate(p, tmp, q);
    }
};

template <typename T>
class RotateFromAxisAngle<4, T>
{
public:
    static void compute(const  Quaternion<T>& p
                        const   Vector<4, T>& u,
                        const             T   radians,
                               Quaternion<T>& q)
    {
        const T halfAngleRad = static_cast<T>(0.5) * radians;
        const T sine         = std::sin(halfAngleRad);
        const T cosine       = std::cos(halfAngleRad);

        Quaternion<T> tmp;

        tmp[0] = u[0] * sine;
        tmp[1] = u[1] * sine;
        tmp[2] = u[2] * sine;
        tmp[3] = cosine;

        Rotate(p, tmp, q);
    }
};

}

template <int DIM, typename T>
inline
void RotateFromAxisAngle(const  Quaternion<T>& p
                         const Vector<DIM, T>& u,
                         const             T   radians,
                                Quaternion<T>& q)
{
    Priv::RotateFromAxisAngle<DIM, T>::compute(p, u, radians, q);
}

END_HAZMAT_NAMESPACE

#endif
