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
                        const Vector<2, T>& t,
                              Matrix<9, T>& b)
    {
        b[0] = a[0] + t[X] * a[2];
        b[1] = a[1] + t[Y] * a[2];
        b[2] = a[2];
        b[3] = a[3] + t[X] * a[5];
        b[4] = a[4] + t[Y] * a[5];
        b[5] = a[5];
        b[6] = a[6] + t[X] * a[8];
        b[7] = a[7] + t[Y] * a[8];
        b[8] = a[8];
    }
};

template <typename T>
class Translate<16, 3, T>
{
public:
    static void compute(const Matrix<16, T>& a,
                        const Vector< 3, T>& t,
                              Matrix<16, T>& b)
    {
        b[ 0] = a[ 0] + t[X] * a[ 3];
        b[ 1] = a[ 1] + t[Y] * a[ 3];
        b[ 2] = a[ 2] + t[Z] * a[ 3];
        b[ 3] = a[ 3];
        b[ 4] = a[ 4] + t[X] * a[ 7];
        b[ 5] = a[ 5] + t[Y] * a[ 7];
        b[ 6] = a[ 6] + t[Z] * a[ 7];
        b[ 7] = a[ 7];
        b[ 8] = a[ 8] + t[X] * a[11];
        b[ 9] = a[ 9] + t[Y] * a[11];
        b[10] = a[10] + t[Z] * a[11];
        b[11] = a[11];
        b[12] = a[12] + t[X] * a[15];
        b[13] = a[13] + t[Y] * a[15];
        b[14] = a[14] + t[Z] * a[15];
        b[15] = a[15];
    }
};

}

template <int MDIM, int VDIM, typename T>
inline
void Translate(const Matrix<MDIM, T>& a,
               const Vector<VDIM, T>& t,
                     Matrix<MDIM, T>& b)
{
    Priv::Translate<MDIM, VDIM, T>::compute(a, t, b);
}

END_HAZMAT_NAMESPACE

#endif
