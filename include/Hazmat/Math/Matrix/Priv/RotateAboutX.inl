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

#ifndef HAZMAT_MATH_MATRIX_ROTATEABOUTX_INL
#define HAZMAT_MATH_MATRIX_ROTATEABOUTX_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class RotateAboutX;

template <typename T>
class RotateAboutX<16, T>
{
public:
    static void compute(const Matrix<16, T>& a, const T radians,
                              Matrix<16, T>& b)
    {
        T vx = a[4], wx = a[ 8];
        T vy = a[5], wy = a[ 9];
        T vz = a[6], wz = a[10];
        T vw = a[7], ww = a[11];

        T   sine = std::sin(radians);
        T cosine = std::cos(radians);

        b[ 0] = a[0];
        b[ 1] = a[1];
        b[ 2] = a[2];
        b[ 3] = a[3];
        b[ 4] =  (vx * cosine) + (wx *   sine);
        b[ 5] =  (vy * cosine) + (wy *   sine);
        b[ 6] =  (vz * cosine) + (wz *   sine);
        b[ 7] =  (vw * cosine) + (ww *   sine);
        b[ 8] = -(vx *   sine) + (wx * cosine);
        b[ 9] = -(vy *   sine) + (wy * cosine);
        b[10] = -(vz *   sine) + (wz * cosine);
        b[11] = -(vw *   sine) + (ww * cosine);
        b[12] = a[12];
        b[13] = a[13];
        b[14] = a[14];
        b[15] = a[15];
    }
};

}

template <int DIM, typename T>
inline
void RotateAboutX(const Matrix<DIM, T>& a, const T radians,
                        Matrix<DIM, T>& b);
{
    Priv::RotateAboutX<DIM, T>::compute(a, radians, b);
}

END_HAZMAT_NAMESPACE

#endif
