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

#ifndef HAZMAT_MATH_VECTOR_TRANSFORM_INL
#define HAZMAT_MATH_VECTOR_TRANSFORM_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int MDIM, int VDIM, typename T>
class TransformVector;

// 2x2 * 2x1
template <typename T>
class TransformVector<4, 2, T>
{
public:
    static void compute(const Matrix<4, T>& m,
                        const Vector<2, T>& u,
                              Vector<2, T>& v)
    {
        T x = u[X], y = u[Y];

        v[X] = x * m[0] + y * m[2];
        v[Y] = x * m[1] + y * m[3];
    }
};

// 3x3 * 2x1 (for convenience)
template <typename T>
class TransformVector<9, 2, T>
{
public:
    static void compute(const Matrix<9, T>& m,
                        const Vector<2, T>& u,
                              Vector<2, T>& v)
    {
        T x = u[X], y = u[Y];

        v[X] = m[6] + x * m[0] + y * m[3];
        v[Y] = m[7] + x * m[1] + y * m[4];
    }
};

// 4x4 * 2x1 (for convenience)
template <typename T>
class TransformVector<16, 2, T>
{
public:
    static void compute(const Matrix<16, T>& m,
                        const Vector< 2, T>& u,
                              Vector< 2, T>& v)
    {
        T x = u[X], y = u[Y];

        v[X] = m[12] + x * m[0] + y * m[4];
        v[Y] = m[13] + x * m[1] + y * m[5];
    }
};

// 3x3 * 3x1
template <typename T>
class TransformVector<9, 3, T>
{
public:
    static void compute(const Matrix<9, T>& m,
                        const Vector<3, T>& u,
                              Vector<3, T>& v)
    {
        T x = u[X], y = u[Y], z = u[Z];

        v[X] = x * m[0] + y * m[3] + z * m[6];
        v[Y] = x * m[1] + y * m[4] + z * m[7];
        v[Z] = x * m[2] + y * m[5] + z * m[8];
    }
};

// 4x4 * 3x1 (for convenience)
template <typename T>
class TransformVector<16, 3, T>
{
public:
    static void compute(const Matrix<16, T>& m,
                        const Vector< 3, T>& u,
                              Vector< 3, T>& v)
    {
        T x = u[X], y = u[Y], z = u[Z];

        v[X] = m[12] + x * m[ 0] + y * m[ 4] + z * m[ 8];
        v[Y] = m[13] + x * m[ 1] + y * m[ 5] + z * m[ 9];
        v[Z] = m[14] + x * m[ 2] + y * m[ 6] + z * m[10];
    }
};

// 4x4 * 4x1
template <typename T>
class TransformVector<16, 4, T>
{
public:
    static void compute(const Matrix<16, T>& m,
                        const Vector< 4, T>& u,
                              Vector< 4, T>& v)
    {
        T x = u[X], y = u[Y], z = u[Z], w = u[W];

        v[X] = x * m[ 0] + y * m[ 4] + z * m[ 8] + w * m[12];
        v[Y] = x * m[ 1] + y * m[ 5] + z * m[ 9] + w * m[13];
        v[Z] = x * m[ 2] + y * m[ 6] + z * m[10] + w * m[14];
        v[W] = x * m[ 3] + y * m[ 7] + z * m[11] + w * m[15];
    }
};

}

template <int MDIM, int VDIM, typename T>
inline
void Transform(const Matrix<MDIM, T>& m,
               const Vector<VDIM, T>& u,
                     Vector<VDIM, T>& v)
{
    Priv::TransformVector<MDIM, VDIM, T>::compute(m, u, v);
}

template <int MDIM, int VDIM, typename T>
inline
Vector<VDIM, T>& operator*=(      Vector<VDIM, T>& u,
                            const Matrix<MDIM, T>& m)
{
    Transform(m, u, u);
    return u;
}

template <int MDIM, int VDIM, typename T>
inline
Vector<VDIM, T> operator*(const Matrix<MDIM, T>& m,
                                Vector<VDIM, T>  u)
{
    u *= m;
    return u;
}

template <int MDIM, int VDIM, typename T>
inline
Vector<VDIM, T> operator*(      Vector<VDIM, T>  u,
                          const Matrix<MDIM, T>& m)
{
    u *= m;
    return u;
}

END_HAZMAT_NAMESPACE

#endif
