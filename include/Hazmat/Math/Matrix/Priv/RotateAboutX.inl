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
class RotateAboutX<9, T>
{
public:
    static void compute(const Matrix<9, T>& a, const T radians,
                              Matrix<9, T>& b)
    {
        const T uy = a[1], vy = a[4], wy = a[7];
        const T uz = a[2], vz = a[5], wz = a[8];

        const T   sine = std::sin(radians);
        const T cosine = std::cos(radians);

        b[0] = a[0];
        b[1] = (cosine * uy) - (sine   * uz);
        b[2] = (sine   * uy) + (cosine * uz);
        b[3] = a[3];
        b[4] = (cosine * vy) - (sine   * vz);
        b[5] = (sine   * vy) + (cosine * vz);
        b[6] = a[6];
        b[7] = (cosine * wy) - (sine   * wz);
        b[8] = (sine   * wy) + (cosine * wz);
    }
};

template <typename T>
class RotateAboutX<16, T>
{
public:
    static void compute(const Matrix<16, T>& a, const T radians,
                              Matrix<16, T>& b)
    {
        const T uy = a[ 1], vy = a[ 5], wy = a[ 9], cy = a[13];
        const T uz = a[ 2], vz = a[ 6], wz = a[10], cz = a[14];

        const T   sine = std::sin(radians);
        const T cosine = std::cos(radians);

        b[ 0] = a[ 0];
        b[ 1] = (cosine * uy) - (sine   * uz);
        b[ 2] = (sine   * uy) + (cosine * uz);
        b[ 3] = a[ 3];
        b[ 4] = a[ 4];
        b[ 5] = (cosine * vy) - (sine   * vz);
        b[ 6] = (sine   * vy) + (cosine * vz);
        b[ 7] = a[ 7];
        b[ 8] = a[ 8];
        b[ 9] = (cosine * wy) - (sine   * wz);
        b[10] = (sine   * wy) + (cosine * wz);
        b[11] = a[11];
        b[12] = a[12];
        b[13] = (cosine * cy) - (sine   * cz);
        b[14] = (sine   * cy) + (cosine * cz);
        b[15] = a[15];
    }
};

}

template <int DIM, typename T>
inline
void RotateAboutX(const Matrix<DIM, T>& a, const T radians,
                        Matrix<DIM, T>& b)
{
    Priv::RotateAboutX<DIM, T>::compute(a, radians, b);
}

END_HAZMAT_NAMESPACE

#endif
