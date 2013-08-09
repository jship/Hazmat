#ifndef HAZMAT_MATH_CROSS_H
#define HAZMAT_MATH_CROSS_H

#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

namespace Priv
{

template <size_t DIM, typename T>
class Cross;

// Cross is only defined for 3D vectors (and this lib is not concerned
// with 7D!)
template <typename T>
class Cross<3, T>
{
public:
    static Vector<3, T>& compute(const Vector<3, T>& u,
                                 const Vector<3, T>& v,
                                       Vector<3, T>& w)
    {
        w[X] = u[Y] * v[Z] - u[Z] * v[Y];
        w[Y] = u[Z] * v[X] - u[X] * v[Z];
        w[Z] = u[X] * v[Y] - u[Y] * v[X];
        return w;
    }
};

}

template <size_t DIM, typename T>
inline
Vector<DIM, T>& Cross(const Vector<DIM, T>& u,
                      const Vector<DIM, T>& v,
                            Vector<DIM, T>& w)
{
    return Priv::Cross<DIM, T>::compute(u, v, w);
}

END_HAZMAT_NAMESPACE

#endif
