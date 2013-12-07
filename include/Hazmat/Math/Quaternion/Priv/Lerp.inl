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

#ifndef HAZMAT_MATH_QUATERNION_LERP_INL
#define HAZMAT_MATH_QUATERNION_LERP_INL

BEGIN_HAZMAT_NAMESPACE

template <typename T>
inline
void Lerp(const Quaternion<T>& p,
          const Quaternion<T>& q,
          const            T   t,
                Quaternion<T>& r)
{
    r[X] = p[X] + t * (q[X] - p[X]);
    r[Y] = p[Y] + t * (q[Y] - p[Y]);
    r[Z] = p[Z] + t * (q[Z] - p[Z]);
    r[W] = p[W] + t * (q[W] - p[W]);
}

END_HAZMAT_NAMESPACE

#endif
