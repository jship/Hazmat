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

#ifndef HAZMAT_TYPES_ARRAY_H
#define HAZMAT_TYPES_ARRAY_H

#include <Hazmat/Common.h>

BEGIN_HAZMAT_NAMESPACE

template <int DIM, typename T>
class Array
{
public:
    typedef T ValueType;

    Array();
    
    T* bytes();
    const T* bytes() const;

    T  operator[](int i) const;
    T& operator[](int i);
    
    static const int dimensions = DIM;
    static const int byteCount  = DIM * sizeof(T);

private:
    T mComponents[DIM];
};

template <int DIM, typename T>
inline
Array<DIM, T>::Array()
{
    memset(mComponents, 0, byteCount);
}

template <int DIM, typename T>
inline
T* Array<DIM, T>::bytes()
{
    return &mComponents[0];
}

template <int DIM, typename T>
inline
const T* Array<DIM, T>::bytes() const
{
    return &mComponents[0];
}

template <int DIM, typename T>
inline
T Array<DIM, T>::operator[](int i) const
{
    // TODO: Debug error checking...
    return mComponents[i];
}

template <int DIM, typename T>
inline
T& Array<DIM, T>::operator[](int i)
{
    // TODO: Debug error checking...
    return mComponents[i];
}

END_HAZMAT_NAMESPACE

#endif
