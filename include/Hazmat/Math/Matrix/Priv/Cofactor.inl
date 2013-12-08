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

#ifndef HAZMAT_MATH_MATRIX_COFACTOR_INL
#define HAZMAT_MATH_MATRIX_COFACTOR_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Cofactor;

template <typename T>
class Cofactor<4, T>
{
public:
    static void compute(const Matrix<4, T>& a, Matrix<4, T>& b)
    {
        const T ux = a[0], vx = a[2];
        const T uy = a[1], vy = a[3];
        
        b[0] =  vy;
        b[1] = -vx;
        b[2] = -uy;
        b[3] =  ux;
    }
};

template <typename T>
class Cofactor<9, T>
{
public:
    static void compute(const Matrix<9, T>& a, Matrix<9, T>& b)
    {
        const T ux = a[0], vx = a[3], wx = a[6];
        const T uy = a[1], vy = a[4], wy = a[7];
        const T uz = a[2], vz = a[5], wz = a[8];
        
        b[0] = vy * wz - vz * wy;
        b[1] = vz * wx - vx * wz;
        b[2] = vx * wy - vy * wx;
        b[3] = uz * wy - uy * wz;
        b[4] = ux * wz - uz * wx;
        b[5] = uy * wx - ux * wy;
        b[6] = uy * vz - uz * vy;
        b[7] = uz * vx - ux * vz;
        b[8] = ux * vy - uy * vx;
    }
};

template <typename T>
class Cofactor<16, T>
{
public:
    static void compute(const Matrix<16, T>& a, Matrix<16, T>& b)
    {
        const T ux = a[0], vx = a[4], wx = a[ 8], cx = a[12];
        const T uy = a[1], vy = a[5], wy = a[ 9], cy = a[13];
        const T uz = a[2], vz = a[6], wz = a[10], cz = a[14];
        const T uw = a[3], vw = a[7], ww = a[11], cw = a[15];
        
        b[ 0] =  (vy*wz*cw) - (vy*ww*cz) - (vz*wy*cw) + (vz*ww*cy) + (vw*wy*cz) - (vw*wz*cy);
        b[ 1] = -(vx*wz*cw) + (vx*ww*cz) + (vz*wx*cw) - (vz*ww*cx) - (vw*wx*cz) + (vw*wz*cx);
        b[ 2] =  (vx*wy*cw) - (vx*ww*cy) - (vy*wx*cw) + (vy*ww*cx) + (vw*wx*cy) - (vw*wy*cx);
        b[ 3] = -(vx*wy*cz) + (vx*wz*cy) + (vy*wx*cz) - (vy*wz*cx) - (vz*wx*cy) + (vz*wy*cx);
        b[ 4] = -(uy*wz*cw) + (uy*ww*cz) + (uz*wy*cw) - (uz*ww*cy) - (uw*wy*cz) + (uw*wz*cy);
        b[ 5] =  (ux*wz*cw) - (ux*ww*cz) - (uz*wx*cw) + (uz*ww*cx) + (uw*wx*cz) - (uw*wz*cx);
        b[ 6] = -(ux*wy*cw) + (ux*ww*cy) + (uy*wx*cw) - (uy*ww*cx) - (uw*wx*cy) + (uw*wy*cx);
        b[ 7] =  (ux*wy*cz) - (ux*wz*cy) - (uy*wx*cz) + (uy*wz*cx) + (uz*wx*cy) - (uz*wy*cx);
        b[ 8] =  (uy*vz*cw) - (uy*vw*cz) - (uz*vy*cw) + (uz*vw*cy) + (uw*vy*cz) - (uw*vz*cy);
        b[ 9] = -(ux*vz*cw) + (ux*vw*cz) + (uz*vx*cw) - (uz*vw*cx) - (uw*vx*cz) + (uw*vz*cx);
        b[10] =  (ux*vy*cw) - (ux*vw*cy) - (uy*vx*cw) + (uy*vw*cx) + (uw*vx*cy) - (uw*vy*cx);
        b[11] = -(ux*vy*cz) + (ux*vz*cy) + (uy*vx*cz) - (uy*vz*cx) - (uz*vx*cy) + (uz*vy*cx);
        b[12] = -(uy*vz*ww) + (uy*vw*wz) + (uz*vy*ww) - (uz*vw*wy) - (uw*vy*wz) + (uw*vz*wy);
        b[13] =  (ux*vz*ww) - (ux*vw*wz) - (uz*vx*ww) + (uz*vw*wx) + (uw*vx*wz) - (uw*vz*wx);
        b[14] = -(ux*vy*ww) + (ux*vw*wy) + (uy*vx*ww) - (uy*vw*wx) - (uw*vx*wy) + (uw*vy*wx);
        b[15] =  (ux*vy*wz) - (ux*vz*wy) - (uy*vx*wz) + (uy*vz*wx) + (uz*vx*wy) - (uz*vy*wx);
    }
};

}

template <int DIM, typename T>
inline
void Cofactor(const Matrix<DIM, T>& a, Matrix<DIM, T>& b)
{
    Priv::Cofactor<DIM, T>::compute(a, b);
}

END_HAZMAT_NAMESPACE

#endif
