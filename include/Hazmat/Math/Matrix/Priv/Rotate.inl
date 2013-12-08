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

#ifndef HAZMAT_MATH_MATRIX_ROTATE_INL
#define HAZMAT_MATH_MATRIX_ROTATE_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int MDIM, int VDIM, typename T>
class MatrixRotate;

template <typename T>
class MatrixRotate<16, 3, T>
{
public:
    static void compute(const Matrix<16, T>& a,
                        const            T   radians,
                        const Vector< 3, T>& axis,
                              Matrix<16, T>& b)
    {
        const T aux = a[ 0], avx = a[ 4], awx = a[ 8], acx = a[12];
        const T auy = a[ 1], avy = a[ 5], awy = a[ 9], acy = a[13];
        const T auz = a[ 2], avz = a[ 6], awz = a[10], acz = a[14];
        
        const T   sine = std::sin(radians);
        const T cosine = std::cos(radians);
        const T cosTo1 = 1 - cosine;
        
        const T axisX = axis[X];
        const T axisY = axis[Y];
        const T axisZ = axis[Z];
    
        const T rux = (cosTo1 * axisX * axisX) + cosine;
        const T ruy = (cosTo1 * axisX * axisY) +  (sine * axisZ);
        const T ruz = (cosTo1 * axisX * axisZ) -  (sine * axisY);
        const T rvx = (cosTo1 * axisY * axisX) -  (sine * axisZ);
        const T rvy = (cosTo1 * axisY * axisY) + cosine;
        const T rvz = (cosTo1 * axisY * axisZ) +  (sine * axisX);
        const T rwx = (cosTo1 * axisZ * axisX) +  (sine * axisY);
        const T rwy = (cosTo1 * axisZ * axisY) -  (sine * axisX);
        const T rwz = (cosTo1 * axisZ * axisZ) + cosine;

        b[ 0] = (rux * aux) + (rvx * auy) + (rwx * auz);
        b[ 1] = (ruy * aux) + (rvy * auy) + (rwy * auz);
        b[ 2] = (ruz * aux) + (rvz * auy) + (rwz * auz);
        b[ 3] = a[ 3];
        b[ 4] = (rux * avx) + (rvx * avy) + (rwx * avz);
        b[ 5] = (ruy * avx) + (rvy * avy) + (rwy * avz);
        b[ 6] = (ruz * avx) + (rvz * avy) + (rwz * avz);
        b[ 7] = a[ 7];
        b[ 8] = (rux * awx) + (rvx * awy) + (rwx * awz);
        b[ 9] = (ruy * awx) + (rvy * awy) + (rwy * awz);
        b[10] = (ruz * awx) + (rvz * awy) + (rwz * awz);
        b[11] = a[11];
        b[12] = (rux * acx) + (rvx * acy) + (rwx * acz);
        b[13] = (ruy * acx) + (rvy * acy) + (rwy * acz);
        b[14] = (ruz * acx) + (rvz * acy) + (rwz * acz);
        b[15] = a[15];
    }
};

}

template <int MDIM, int VDIM, typename T>
inline
void Rotate(const Matrix<MDIM, T>& a,
            const              T   radians,
            const Vector<VDIM, T>& axis,
                  Matrix<MDIM, T>& b)
{
    Priv::MatrixRotate<MDIM, VDIM, T>::compute(a, radians, axis, b);
}

END_HAZMAT_NAMESPACE

#endif
