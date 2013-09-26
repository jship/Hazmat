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

#ifndef HAZMAT_MATH_MATRIX_INVERSE_INL
#define HAZMAT_MATH_MATRIX_INVERSE_INL

#include <Hazmat/Math/Matrix/Determinant.h>
#include <Hazmat/Math/Matrix/Identity.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Inverse;

template <typename T>
class Inverse<4, T>
{
public:
    static void compute(const Matrix<4, T>& a, Matrix<4, T>& b)
    {
        T uy = a[1];

        b[0] = a[0];
        b[1] = a[2];
        b[2] = uy;
        b[3] = a[3];
    }
};

template <typename T>
class Inverse<9, T>
{
public:
    static void compute(const Matrix<9, T>& a, Matrix<9, T>& b)
    {
        T uy = a[1], uz = a[2], vz = a[5];

        b[0] = a[0];
        b[1] = a[3];
        b[2] = a[6];
        b[3] = uy;
        b[4] = a[4];
        b[5] = a[7];
        b[6] = uz;
        b[7] = vz;
        b[8] = a[8];
    }
};

template <typename T>
class Inverse<16, T>
{
public:
    static void compute(const Matrix<16, T>& a, Matrix<16, T>& b)
    {
        // For use elsewhere.
        /*
        T ux = a[0], vx = a[4], wx = a[ 8], cx = a[12];
        T uy = a[1], vy = a[5], wy = a[ 9], cy = a[13];
        T uz = a[2], vz = a[6], wz = a[10], cz = a[14];
        T uw = a[3], vw = a[7], ww = a[11], cw = a[15];
        */

        T d = Determinant(a);

        if (d == T())
        {
            Identity(b);
            return;
        }


        d = static_cast<T>(1) / d;

        // TODO
        /*
        
        // These two calls should be replaced with a call to Adjoint.
        Cofactor(a, b);
        Transpose(b, b);

        for (int i = 0; i < b.dimensions; i++)
        {
            b[i] *= d;
        }

        */

    }
};

}

template <int DIM, typename T>
inline
void Inverse(const Matrix<DIM, T>& a, Matrix<DIM, T>& b)
{
    Priv::Inverse<DIM, T>::compute(a, b);
}

END_HAZMAT_NAMESPACE

#endif
