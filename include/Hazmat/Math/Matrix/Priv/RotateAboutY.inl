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
class RotateAboutY<9, T>
{
public:
    static void compute(const Matrix<9, T>& a, const T radians,
                              Matrix<9, T>& b)
    {
        T ux = a[0], vx = a[3], wx = a[6];
        T uz = a[2], vz = a[5], wz = a[8];

        T   sine = std::sin(radians);
        T cosine = std::cos(radians);

        b[0] = (cosine * ux) + (sine   * uz);
        b[1] = a[1];
        b[2] = (-sine  * ux) + (cosine * uz);
        b[3] = (cosine * vx) + (sine   * vz);
        b[4] = a[4];
        b[5] = (-sine  * vx) + (cosine * vz);
        b[6] = (cosine * wx) + (sine   * wz);
        b[7] = a[7];
        b[8] = (-sine  * wx) + (cosine * wz);
    }
};

template <typename T>
class RotateAboutY<16, T>
{
public:
    static void compute(const Matrix<16, T>& a, const T radians,
                              Matrix<16, T>& b)
    {
        T ux = a[ 0], vx = a[ 4], wx = a[ 8], cx = a[12];
        T uz = a[ 2], vz = a[ 6], wz = a[10], cz = a[14];

        T   sine = std::sin(radians);
        T cosine = std::cos(radians);

        b[ 0] = (cosine * ux) + (sine   * uz);
        b[ 1] = a[ 1];
        b[ 2] = (-sine  * ux) + (cosine * uz);
        b[ 3] = a[ 3];
        b[ 4] = (cosine * vx) + (sine   * vz);
        b[ 5] = a[ 5];
        b[ 6] = (-sine  * vx) + (cosine * vz);
        b[ 7] = a[ 7];
        b[ 8] = (cosine * wx) + (sine   * wz);
        b[ 9] = a[ 9];
        b[10] = (-sine  * wx) + (cosine * wz);
        b[11] = a[11];
        b[12] = (cosine * cx) + (sine   * cz);
        b[13] = a[13];
        b[14] = (-sine  * cx) + (cosine * cz);
        b[15] = a[15];
    }
};

}

template <int DIM, typename T>
inline
void RotateAboutY(const Matrix<DIM, T>& a, const T radians,
                        Matrix<DIM, T>& b)
{
    Priv::RotateAboutY<DIM, T>::compute(a, radians, b);
}

END_HAZMAT_NAMESPACE

#endif
