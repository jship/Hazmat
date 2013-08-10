#ifndef HAZMAT_TYPES_ARRAY_H
#define HAZMAT_TYPES_ARRAY_H

#include <Hazmat/Common.h>

#include <cstring>

BEGIN_HAZMAT_NAMESPACE

template <size_t DIM, typename T>
class Array
{
public:
    typedef T ValueType;

    Array();
    
    T* bytes();
    const T* bytes() const;

    T  operator[](size_t i) const;
    T& operator[](size_t i);
    
    static const size_t dimensions = DIM;
    static const size_t byteCount  = DIM * sizeof(T);

private:
    T mComponents[DIM];
};

template <size_t DIM, typename T>
inline
Array<DIM, T>::Array()
{
    memset(mComponents, 0, byteCount);
}

template <size_t DIM, typename T>
inline
T* Array<DIM, T>::bytes()
{
    return &mComponents[0];
}

template <size_t DIM, typename T>
inline
const T* Array<DIM, T>::bytes() const
{
    return &mComponents[0];
}

template <size_t DIM, typename T>
inline
T Array<DIM, T>::operator[](size_t i) const
{
    // TODO: Debug error checking...
    return mComponents[i];
}

template <size_t DIM, typename T>
inline
T& Array<DIM, T>::operator[](size_t i)
{
    // TODO: Debug error checking...
    return mComponents[i];
}

END_HAZMAT_NAMESPACE

#endif
