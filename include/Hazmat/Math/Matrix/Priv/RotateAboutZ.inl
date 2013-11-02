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

#ifndef HAZMAT_MATH_MATRIX_ROTATEABOUTZ_INL
#define HAZMAT_MATH_MATRIX_ROTATEABOUTZ_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class RotateAboutZ;

template <typename T>
class RotateAboutZ<4, T>
{
public:
    static void compute(const Matrix<4, T>& a, const T radians,
                              Matrix<4, T>& b)
    {
        T ux = a[0], vx = a[2];
        T uy = a[1], vy = a[3];

        T   sine = std::sin(radians);
        T cosine = std::cos(radians);

        b[0] = (cosine * ux) - (sine   * uy);
        b[1] = (sine   * ux) + (cosine * uy);
        b[2] = (cosine * vx) - (sine   * vy);
        b[3] = (sine   * vx) + (cosine * vy);
    }
};

template <typename T>
class RotateAboutZ<9, T>
{
public:
    static void compute(const Matrix<9, T>& a, const T radians,
                              Matrix<9, T>& b)
    {
        T ux = a[0], vx = a[3], wx = a[6];
        T uy = a[1], vy = a[4], wy = a[7];

        T   sine = std::sin(radians);
        T cosine = std::cos(radians);

        b[0] = (cosine * ux) - (sine   * uy);
        b[1] = (sine   * ux) + (cosine * uy);
        b[2] = a[2];
        b[3] = (cosine * vx) - (sine   * vy);
        b[4] = (sine   * vx) + (cosine * vy);
        b[5] = a[5];
        b[6] = (cosine * wx) - (sine   * wy);
        b[7] = (sine   * wx) + (cosine * wy);
        b[8] = a[8];
    }
};

template <typename T>
class RotateAboutZ<16, T>
{
public:
    static void compute(const Matrix<16, T>& a, const T radians,
                              Matrix<16, T>& b)
    {
        T ux = a[0], vx = a[4], wx = a[8], cx = a[12];
        T uy = a[1], vy = a[5], wy = a[9], cy = a[13];

        T   sine = std::sin(radians);
        T cosine = std::cos(radians);

        b[ 0] = (cosine * ux) - (sine   * uy);
        b[ 1] = (sine   * ux) + (cosine * uy);
        b[ 2] = a[ 2];
        b[ 3] = a[ 3];
        b[ 4] = (cosine * vx) - (sine   * vy);
        b[ 5] = (sine   * vx) + (cosine * vy);
        b[ 6] = a[ 6];
        b[ 7] = a[ 7];
        b[ 8] = (cosine * wx) - (sine   * wy);
        b[ 9] = (sine   * wx) + (cosine * wy);
        b[10] = a[10];
        b[11] = a[11];
        b[12] = (cosine * cx) - (sine   * cy);
        b[13] = (sine   * cx) + (cosine * cy);
        b[14] = a[14];
        b[15] = a[15];
    }
};

}

template <int DIM, typename T>
inline
void RotateAboutZ(const Matrix<DIM, T>& a, const T radians,
                        Matrix<DIM, T>& b)
{
    Priv::RotateAboutZ<DIM, T>::compute(a, radians, b);
}

END_HAZMAT_NAMESPACE

#endif
