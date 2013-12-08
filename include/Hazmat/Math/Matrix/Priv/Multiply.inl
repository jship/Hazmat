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

#ifndef HAZMAT_MATH_MATRIX_MULTIPLY_INL
#define HAZMAT_MATH_MATRIX_MULTIPLY_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Multiply;

template <typename T>
class Multiply<4, T>
{
public:
    static void compute(const Matrix<4, T>& a,
                        const Matrix<4, T>& b,
                              Matrix<4, T>& c)
    {
        const T aux = a[0], avx = a[2];
        const T auy = a[1], avy = a[3];
        
        const T bux = b[0], bvx = b[2];
        const T buy = b[1], bvy = b[3];

        c[0] = (aux * bux) + (avx * buy);
        c[1] = (auy * bux) + (avy * buy);
        c[2] = (aux * bvx) + (avx * bvy);
        c[3] = (auy * bvx) + (avy * bvy);
    }
};

template <typename T>
class Multiply<9, T>
{
public:
    static void compute(const Matrix<9, T>& a,
                        const Matrix<9, T>& b,
                              Matrix<9, T>& c)
    {
        const T aux = a[0], avx = a[3], awx = a[6];
        const T auy = a[1], avy = a[4], awy = a[7];
        const T auz = a[2], avz = a[5], awz = a[8];
        
        const T bux = b[0], bvx = b[3], bwx = b[6];
        const T buy = b[1], bvy = b[4], bwy = b[7];
        const T buz = b[2], bvz = b[5], bwz = b[8];

        c[0] = (aux * bux) + (avx * buy) + (awx * buz);
        c[1] = (auy * bux) + (avy * buy) + (awy * buz);
        c[2] = (auz * bux) + (avz * buy) + (awz * buz);
        c[3] = (aux * bvx) + (avx * bvy) + (awx * bvz);
        c[4] = (auy * bvx) + (avy * bvy) + (awy * bvz);
        c[5] = (auz * bvx) + (avz * bvy) + (awz * bvz);
        c[6] = (aux * bwx) + (avx * bwy) + (awx * bwz);
        c[7] = (auy * bwx) + (avy * bwy) + (awy * bwz);
        c[8] = (auz * bwx) + (avz * bwy) + (awz * bwz);
    }
};

template <typename T>
class Multiply<16, T>
{
public:
    static void compute(const Matrix<16, T>& a,
                        const Matrix<16, T>& b,
                              Matrix<16, T>& c)
    {
        const T aux = a[0], avx = a[4], awx = a[ 8], acx = a[12];
        const T auy = a[1], avy = a[5], awy = a[ 9], acy = a[13];
        const T auz = a[2], avz = a[6], awz = a[10], acz = a[14];
        const T auw = a[3], avw = a[7], aww = a[11], acw = a[15];
        
        const T bux = b[0], bvx = b[4], bwx = b[ 8], bcx = b[12];
        const T buy = b[1], bvy = b[5], bwy = b[ 9], bcy = b[13];
        const T buz = b[2], bvz = b[6], bwz = b[10], bcz = b[14];
        const T buw = b[3], bvw = b[7], bww = b[11], bcw = b[15];

        c[ 0] = (aux * bux) + (avx * buy) + (awx * buz) + (acx * buw);
        c[ 1] = (auy * bux) + (avy * buy) + (awy * buz) + (acy * buw);
        c[ 2] = (auz * bux) + (avz * buy) + (awz * buz) + (acz * buw);
        c[ 3] = (auw * bux) + (avw * buy) + (aww * buz) + (acw * buw);
        c[ 4] = (aux * bvx) + (avx * bvy) + (awx * bvz) + (acx * bvw);
        c[ 5] = (auy * bvx) + (avy * bvy) + (awy * bvz) + (acy * bvw);
        c[ 6] = (auz * bvx) + (avz * bvy) + (awz * bvz) + (acz * bvw);
        c[ 7] = (auw * bvx) + (avw * bvy) + (aww * bvz) + (acw * bvw);
        c[ 8] = (aux * bwx) + (avx * bwy) + (awx * bwz) + (acx * bww);
        c[ 9] = (auy * bwx) + (avy * bwy) + (awy * bwz) + (acy * bww);
        c[10] = (auz * bwx) + (avz * bwy) + (awz * bwz) + (acz * bww);
        c[11] = (auw * bwx) + (avw * bwy) + (aww * bwz) + (acw * bww);
        c[12] = (aux * bcx) + (avx * bcy) + (awx * bcz) + (acx * bcw);
        c[13] = (auy * bcx) + (avy * bcy) + (awy * bcz) + (acy * bcw);
        c[14] = (auz * bcx) + (avz * bcy) + (awz * bcz) + (acz * bcw);
        c[15] = (auw * bcx) + (avw * bcy) + (aww * bcz) + (acw * bcw);
    }
};

}

template <int DIM, typename T>
inline
void Multiply(const Matrix<DIM, T>& a,
              const Matrix<DIM, T>& b,
                    Matrix<DIM, T>& c)
{
    Priv::Multiply<DIM, T>::compute(a, b, c);
}

template <int DIM, typename T>
inline
Matrix<DIM, T> operator*(const Matrix<DIM, T>& a,
                               Matrix<DIM, T>  b)
{
    Multiply(a, b, b);
    return b;
}

END_HAZMAT_NAMESPACE

#endif
