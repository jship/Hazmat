#ifndef HAZMAT_MATH_VECTOR_NEGATION_H
#define HAZMAT_MATH_VECTOR_NEGATION_H

#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <size_t DIM, typename T>
class Negation;

template <typename T>
class Negation<2, T>
{
public:
    static Vector<2, T>& compute(const Vector<2, T>& u,
                                       Vector<2, T>& v)
    {
        v[X] = -u[X];
        v[Y] = -u[Y];
        return v;
    }
};

template <typename T>
class Negation<3, T>
{
public:
    static Vector<3, T>& compute(const Vector<3, T>& u,
                                       Vector<3, T>& v)
    {
        v[X] = -u[X];
        v[Y] = -u[Y];
        v[Z] = -u[Z];
        return v;
    }
};

template <typename T>
class Negation<4, T>
{
public:
    static Vector<4, T>& compute(const Vector<4, T>& u,
                                       Vector<4, T>& v)
    {
        v[X] = -u[X];
        v[Y] = -u[Y];
        v[Z] = -u[Z];
        v[W] = -u[W];
        return v;
    }
};

}

template <size_t DIM, typename T>
inline
Vector<DIM, T>& Negate(const Vector<DIM, T>& u, Vector<DIM, T>& v)
{
    return Priv::Negation<DIM, T>::compute(u, v);
}

template <size_t DIM, typename T>
inline
Vector<DIM, T> operator-(const Vector<DIM, T>& u)
{
    return Negate(u, Vector<DIM, T>());
}

END_HAZMAT_NAMESPACE

#endif
