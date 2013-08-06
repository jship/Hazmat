#ifndef HAZMAT_MATRIX_H
#define HAZMAT_MATRIX_H

#include <Hazmat/Types/Array.h>

namespace Hazmat
{

template <typename T>
class Matrix2 : public Array<4, T> { };

template <typename T>
class Matrix3 : public Array<9, T> { };

template <typename T>
class Matrix4 : public Array<16, T> { };

}

#endif
