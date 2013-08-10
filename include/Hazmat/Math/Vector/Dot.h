#ifndef HAZMAT_MATH_VECTOR_DOT_H
#define HAZMAT_MATH_VECTOR_DOT_H

#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

// Dot is specialized for vectors with dimensions 2-4.
// (Note a loop could be used and only one function would
// be required for all vector types, but this way guarantees
// no branching.)
template <size_t DIM, typename T>
class Dot;

template <typename T>
class Dot<2, T>
{
public:
    static T compute(const Vector<2, T>& u, const Vector<2, T>& v)
    {
        return u[0] * v[0] + u[1] * v[1];
    }
};

template <typename T>
class Dot<3, T>
{
public:
    static T compute(const Vector<3, T>& u, const Vector<3, T>& v)
    {
        return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
    }
};

template <typename T>
class Dot<4, T>
{
public:
    static T compute(const Vector<4, T>& u, const Vector<4, T>& v)
    {
        return u[0] * v[0] + u[1] * v[1] + u[2] * v[2] + u[3] * v[3];
    }
};

}

template <size_t DIM, typename T>
inline
T Dot(const Vector<DIM, T>& u, const Vector<DIM, T>& v)
{
    return Priv::Dot<DIM, T>::compute(u, v);
}

END_HAZMAT_NAMESPACE

#endif
