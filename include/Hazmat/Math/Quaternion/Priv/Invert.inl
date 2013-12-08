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

#ifndef HAZMAT_MATH_QUATERNION_INVERT_INL
#define HAZMAT_MATH_QUATERNION_INVERT_INL

#include <Hazmat/Math/Quaternion/SquaredLength.h>

BEGIN_HAZMAT_NAMESPACE

template <typename T>
inline
void Invert(const Quaternion<T>& p, Quaternion<T>& q)
{
    T len = SquaredLength(p);
    
    if (len == T())
    {
        // q is left unchanged if p has 0 length.
        return;
    }

    len = static_cast<T>(1) / len;

    q[0] = -len * p[0];
    q[1] = -len * p[1];
    q[2] = -len * p[2];
    q[3] =  len * p[3];
}

END_HAZMAT_NAMESPACE

#endif
