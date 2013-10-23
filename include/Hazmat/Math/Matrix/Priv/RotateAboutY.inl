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

#ifndef HAZMAT_MATH_MATRIX_ROTATEABOUTY_INL
#define HAZMAT_MATH_MATRIX_ROTATEABOUTY_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class RotateAboutY;

template <typename T>
class RotateAboutY<16, T>
{
public:
    static void compute(const Matrix<16, T>& a, const T radians,
                              Matrix<16, T>& b)
    {
        T ux = a[0], wx = a[ 8];
        T uy = a[1], wy = a[ 9];
        T uz = a[2], wz = a[10];
        T uw = a[3], ww = a[11];

        T   sine = std::sin(radians);
        T cosine = std::cos(radians);

        b[ 0] = (ux * cosine) - (wx *   sine);
        b[ 1] = (uy * cosine) - (wy *   sine);
        b[ 2] = (uz * cosine) - (wz *   sine);
        b[ 3] = (uw * cosine) - (ww *   sine);
        b[ 4] = a[4];
        b[ 5] = a[5];
        b[ 6] = a[6];
        b[ 7] = a[7];
        b[ 8] = (ux *   sine) + (wx * cosine);
        b[ 9] = (uy *   sine) + (wy * cosine);
        b[10] = (uz *   sine) + (wz * cosine);
        b[11] = (uw *   sine) + (ww * cosine);
        b[12] = a[12];
        b[13] = a[13];
        b[14] = a[14];
        b[15] = a[15];
    }
};

}

template <int DIM, typename T>
inline
void RotateAboutY(const Matrix<DIM, T>& a, const T radians,
                        Matrix<DIM, T>& b);
{
    Priv::RotateAboutY<DIM, T>::compute(a, radians, b);
}

END_HAZMAT_NAMESPACE

#endif
