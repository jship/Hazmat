#ifndef HAZMAT_MATH_VECTOR_SET_H
#define HAZMAT_MATH_VECTOR_SET_H

#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <size_t DIM, typename T>
class Set;

template <typename T>
class Set<2, T>
{
public:
    template <typename TX, typename TY>
    static Vector<2, T>& assign(TX x, TY y, Vector<2, T>& u)
    {
        u[X] = x;
        u[Y] = y;
        return u;
    }
};

template <typename T>
class Set<3, T>
{
public:
    template <typename TX, typename TY, typename TZ>
    static Vector<3, T>& assign(TX x, TY y, TZ z, Vector<3, T>& u)
    {
        u[X] = x;
        u[Y] = y;
        u[Z] = z;
        return u;
    }
};

template <typename T>
class Set<4, T>
{
public:
    template <typename TX, typename TY, typename TZ, typename TW>
    static Vector<4, T>& assign(TX x, TY y, TZ z, TW w, Vector<4, T>& u)
    {
        u[X] = x;
        u[Y] = y;
        u[Z] = z;
        u[W] = w;
        return u;
    }
};

}

template <
             size_t DIM,
             typename T,
             typename TX,
             typename TY
         >
inline
Vector<DIM, T>& Set(TX x, TY y, Vector<DIM, T>& u)
{
    return Priv::Set<DIM, T>::assign(x, y, u);
}

template <
             size_t DIM,
             typename T,
             typename TX,
             typename TY,
             typename TZ
         >
inline
Vector<DIM, T>& Set(TX x, TY y, TZ z, Vector<DIM, T>& u)
{
    return Priv::Set<DIM, T>::assign(x, y, z, u);
}

template <
             size_t DIM,
             typename T,
             typename TX,
             typename TY,
             typename TZ,
             typename TW
         >
inline
Vector<DIM, T>& Set(TX x, TY y, TZ z, TW w, Vector<DIM, T>& u)
{
    return Priv::Set<DIM, T>::assign(x, y, z, w, u);
}

END_HAZMAT_NAMESPACE

#endif
