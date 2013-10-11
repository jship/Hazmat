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

#ifndef HAZMAT_MATH_MATRIX_TRANSLATE_INL
#define HAZMAT_MATH_MATRIX_TRANSLATE_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int MDIM, int VDIM, typename T>
class Translate;

template <typename T>
class Translate<9, 2, T>
{
public:
    static void compute(const Matrix<9, T>& a,
                        const Vector<2, T>& u,
                              Matrix<9, T>& b)
    {
        T ux = a[0], vx = a[3];
        T uy = a[1], vy = a[4];
        T uz = a[2], vz = a[5];
        
        b[0] = ux; b[3] = vx;
        b[1] = uy; b[4] = vy;
        b[2] = uz; b[5] = vz;

        b[6] = a[6] + ux * u[X] + vx * u[Y];
        b[7] = a[7] + uy * u[X] + vy * u[Y];
        b[8] = a[8] + uz * u[X] + vz * u[Y];
    }
};

template <typename T>
class Translate<16, 3, T>
{
public:
    static void compute(const Matrix<16, T>& a,
                        const Vector< 3, T>& u,
                              Matrix<16, T>& b)
    {
        T ux = a[0], vx = a[4], wx = a[ 8];
        T uy = a[1], vy = a[5], wy = a[ 9];
        T uz = a[2], vz = a[6], wz = a[10];
        T uw = a[3], vw = a[7], ww = a[11];
        
        b[0] = ux; b[4] = vx; b[ 8] = wx;
        b[1] = uy; b[5] = vy; b[ 9] = wy;
        b[2] = uz; b[6] = vz; b[10] = wz;
        b[3] = uw; b[7] = vw; b[11] = ww;

        b[12] = a[12] + ux * u[X] + vx * u[Y] + wx * u[Z];
        b[13] = a[13] + uy * u[X] + vy * u[Y] + wy * u[Z];
        b[14] = a[14] + uz * u[X] + vz * u[Y] + wz * u[Z];
        b[15] = a[15] + uw * u[X] + vw * u[Y] + ww * u[Z];
    }
};

}

template <int MDIM, int VDIM, typename T>
inline
void Translate(const Matrix<MDIM, T>& a,
               const Vector<VDIM, T>& u,
                     Matrix<MDIM, T>& b)
{
    Priv::Translate<MDIM, VDIM, T>::compute(a, u, b);
}

END_HAZMAT_NAMESPACE

#endif
