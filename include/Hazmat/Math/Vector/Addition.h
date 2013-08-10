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
                                 const Vector<2, T>& v)
    {
        return T();
    }
};

template <typename T>
class Addition<3, T>
{
public:
    static T compute(const Vector<3, T>& u, const Vector<3, T>& v)
    {
        return T();
    }
};

template <typename T>
class Addition<4, T>
{
public:
    static T compute(const Vector<4, T>& u, const Vector<4, T>& v)
    {
        return T();
    }
};

}

template <size_t DIM, typename T>
inline
T Add(const Vector<DIM, T>& u, const Vector<DIM, T>& v)
{
    return Priv::Addition<DIM, T>::compute(u, v);
}

END_HAZMAT_NAMESPACE

#endif
