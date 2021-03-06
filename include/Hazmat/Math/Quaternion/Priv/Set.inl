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

#ifndef HAZMAT_MATH_QUATERNION_SET_INL
#define HAZMAT_MATH_QUATERNION_SET_INL

BEGIN_HAZMAT_NAMESPACE

template <typename T, typename TX, typename TY, typename TZ, typename TW>
inline
void Set(TX x, TY y, TZ z, TW w, Quaternion<T>& p)
{
    p[X] = static_cast<T>(x);
    p[Y] = static_cast<T>(y);
    p[Z] = static_cast<T>(z);
    p[W] = static_cast<T>(w);
}

END_HAZMAT_NAMESPACE

#endif
