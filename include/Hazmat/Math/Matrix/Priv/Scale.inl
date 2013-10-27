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

#ifndef HAZMAT_MATH_MATRIX_SCALE_INL
#define HAZMAT_MATH_MATRIX_SCALE_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int MDIM, int VDIM, typename T>
class Scale;

template <typename T>
class Scale<4, 2, T>
{
public:
    static void compute(const Matrix<4, T>& a,
                        const Vector<2, T>& u,
                              Matrix<4, T>& b)
    {
        b[0] = u[X] * a[0];
        b[1] = u[Y] * a[1];
        b[2] = u[X] * a[2];
        b[3] = u[Y] * a[3];
    }
};

template <typename T>
class Scale<9, 2, T>
{
public:
    static void compute(const Matrix<9, T>& a,
                        const Vector<2, T>& u,
                              Matrix<9, T>& b)
    {
        b[0] = u[X] * a[0];
        b[1] = u[Y] * a[1];
        b[2] =        a[2];
        b[3] = u[X] * a[3];
        b[4] = u[Y] * a[4];
        b[5] =        a[5];
        b[6] = u[X] * a[6];
        b[7] = u[Y] * a[7];
        b[8] =        a[8];
    }
};

template <typename T>
class Scale<16, 3, T>
{
public:
    static void compute(const Matrix<16, T>& a,
                        const Vector< 3, T>& u,
                              Matrix<16, T>& b)
    {
        b[ 0] = u[X] * a[ 0];
        b[ 1] = u[Y] * a[ 1];
        b[ 2] = u[Z] * a[ 2];
        b[ 3] =        a[ 3];
        b[ 4] = u[X] * a[ 4];
        b[ 5] = u[Y] * a[ 5];
        b[ 6] = u[Z] * a[ 6];
        b[ 7] =        a[ 7];
        b[ 8] = u[X] * a[ 8];
        b[ 9] = u[Y] * a[ 9];
        b[10] = u[Z] * a[10];
        b[11] =        a[11];
        b[12] = u[X] * a[12];
        b[13] = u[Y] * a[13];
        b[14] = u[Z] * a[14];
        b[15] =        a[15];
    }
};

}

template <int MDIM, int VDIM, typename T>
inline
void Scale(const Matrix<MDIM, T>& a,
           const Vector<VDIM, T>& u,
                 Matrix<MDIM, T>& b)
{
    Priv::Scale<MDIM, VDIM, T>::compute(a, u, b);
}

END_HAZMAT_NAMESPACE

#endif
