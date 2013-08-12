#ifndef HAZMAT_MATH_VECTOR_ADDITION_H
#define HAZMAT_MATH_VECTOR_ADDITION_H

#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <size_t DIM, typename T>
class Addition;

template <typename T>
class Addition<2, T>
{
public:
    static Vector<2, T>& compute(const Vector<2, T>& u,
                                 const Vector<2, T>& v,
                                       Vector<2, T>& w)
    {
        w[X] = u[X] + v[X];
        w[Y] = u[Y] + v[Y];
        return w;
    }
};

template <typename T>
class Addition<3, T>
{
public:
    static Vector<3, T>& compute(const Vector<3, T>& u,
                                 const Vector<3, T>& v,
                                       Vector<3, T>& w)
    {
        w[X] = u[X] + v[X];
        w[Y] = u[Y] + v[Y];
        w[Z] = u[Z] + v[Z];
        return w;
    }
};

template <typename T>
class Addition<4, T>
{
public:
    static Vector<4, T>& compute(const Vector<4, T>& u,
                                 const Vector<4, T>& v,
                                       Vector<4, T>& w)
    {
        w[X] = u[X] + v[X];
        w[Y] = u[Y] + v[Y];
        w[Z] = u[Z] + v[Z];
        w[W] = u[W] + v[W];
        return w;
    }
};

}

template <size_t DIM, typename T>
inline
Vector<DIM, T>& Add(const Vector<DIM, T>& u,
                    const Vector<DIM, T>& v,
                          Vector<DIM, T>& w)
{
    return Priv::Addition<DIM, T>::compute(u, v, w);
}

template <size_t DIM, typename T>
inline
Vector<DIM, T>& operator+=(      Vector<DIM, T>& u,
                           const Vector<DIM, T>& v)
{
    return Add(u, v, u);
}

template <size_t DIM, typename T>
inline
Vector<DIM, T> operator+(      Vector<DIM, T>  u,
                         const Vector<DIM, T>& v)
{
    u += v;
    return u;
}

END_HAZMAT_NAMESPACE

#endif
