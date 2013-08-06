#ifndef HAZMAT_VECTOR_H
#define HAZMAT_VECTOR_H

#include <Hazmat/Types/Array.h>

namespace Hazmat
{

template <typename T>
class Vector2 : public Array<2, T> { };

template <typename T>
class Vector3 : public Array<3, T> { };

template <typename T>
class Vector4 : public Array<4, T> { };

}

#endif
