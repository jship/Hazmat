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

#ifndef HAZMAT_MATH_QUATERNION_ROTATEABOUTZ_INL
#define HAZMAT_MATH_QUATERNION_ROTATEABOUTZ_INL

BEGIN_HAZMAT_NAMESPACE

template <typename T>
inline
void RotateAboutZ(const Quaternion<T>& p, const T radians,
                        Quaternion<T>& q)
{
    const T halfAngleRad = static_cast<T>(0.5) * radians;

    const T px = p[0];
    const T py = p[1];
    const T pz = p[2], qz = std::sin(halfAngleRad);
    const T pw = p[3], qw = std::cos(halfAngleRad);
        
    q[0] = (qw * px) + (py * qz);
    q[1] = (qw * py) - (px * qz);
    q[2] = (pw * qz) + (qw * pz);
    q[3] = (pw * qw) - (pz * qz);
}

END_HAZMAT_NAMESPACE

#endif
