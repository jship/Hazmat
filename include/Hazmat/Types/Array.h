#ifndef HAZMAT_ARRAY_H
#define HAZMAT_ARRAY_H

#include <cstring>

namespace Hazmat
{

template <size_t DIM, typename T>
class Array
{
public:
    typedef T ValueType;

    Array();
    Array(const Array<DIM, T>& a);
    
    T* bytes();
    const T* bytes() const;

    T  operator[] (size_t i) const;
    T& operator[] (size_t i);
    
    Array<DIM, T>& operator= (const Array<DIM, T>& a);

    static const size_t Dimensions = DIM;
    static const size_t ByteCount  = DIM * sizeof(T);

private:
    T mComponents[DIM];
};

template <size_t DIM, typename T>
Array<DIM, T>::Array()
{
    memset(mComponents, 0, ByteCount);
}

template <size_t DIM, typename T>
Array<DIM, T>::Array<DIM, T>::Array(const Array<DIM, T>& a)
{
    memcpy(mComponents, a.bytes(), ByteCount);
}

template <size_t DIM, typename T>
T* Array<DIM, T>::bytes()
{
    return &mComponents[0];
}

template <size_t DIM, typename T>
const T* Array<DIM, T>::bytes() const
{
    return &mComponents[0];
}

template <size_t DIM, typename T>
T Array<DIM, T>::operator[] (size_t i) const
{
    // TODO: Debug error checking...
    return mComponents[i];
}

template <size_t DIM, typename T>
T& Array<DIM, T>::operator[] (size_t i)
{
    // TODO: Debug error checking...
    return mComponents[i];
}

template <size_t DIM, typename T>
Array<DIM, T>& Array<DIM, T>::operator= (const Array<DIM, T>& a)
{
    if (this != &a)
        memcpy(mComponents, a.bytes(), ByteCount);

    return *this;
}

}

#endif
