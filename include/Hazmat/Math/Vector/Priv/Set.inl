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

#ifndef HAZMAT_MATH_VECTOR_SET_INL
#define HAZMAT_MATH_VECTOR_SET_INL

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <int DIM, typename T>
class Set;

template <typename T>
class Set<2, T>
{
public:
    template <typename TX, typename TY>
    static void assign(TX x, TY y, Vector<2, T>& u)
    {
        u[X] = static_cast<T>(x);
        u[Y] = static_cast<T>(y);
    }
};

template <typename T>
class Set<3, T>
{
public:
    template <typename TX, typename TY, typename TZ>
    static void assign(TX x, TY y, TZ z, Vector<3, T>& u)
    {
        u[X] = static_cast<T>(x);
        u[Y] = static_cast<T>(y);
        u[Z] = static_cast<T>(z);
    }
};

template <typename T>
class Set<4, T>
{
public:
    template <typename TX, typename TY, typename TZ, typename TW>
    static void assign(TX x, TY y, TZ z, TW w, Vector<4, T>& u)
    {
        u[X] = static_cast<T>(x);
        u[Y] = static_cast<T>(y);
        u[Z] = static_cast<T>(z);
        u[W] = static_cast<T>(w);
    }
};

}

template <int DIM, typename T, typename TX, typename TY>
inline
void Set(TX x, TY y, Vector<DIM, T>& u)
{
    Priv::Set<DIM, T>::assign(x, y, u);
}

template <int DIM, typename T, typename TX, typename TY, typename TZ>
inline
void Set(TX x, TY y, TZ z, Vector<DIM, T>& u)
{
    Priv::Set<DIM, T>::assign(x, y, z, u);
}

template <int DIM, typename T, typename TX, typename TY, typename TZ, typename TW>
inline
void Set(TX x, TY y, TZ z, TW w, Vector<DIM, T>& u)
{
    Priv::Set<DIM, T>::assign(x, y, z, w, u);
}

END_HAZMAT_NAMESPACE

#endif
