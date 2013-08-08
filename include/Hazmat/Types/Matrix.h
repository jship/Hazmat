#ifndef HAZMAT_MATRIX_H
#define HAZMAT_MATRIX_H

#include <Hazmat/Types/Array.h>

namespace Hazmat
{

template <size_t DIM, typename T>
class Matrix : public Array<DIM, T> { };

}

#endif
