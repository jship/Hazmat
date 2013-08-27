#include "Common.h"

struct ArrayTestData
{
    Array2f array2f;
    Array3f array3f;
    Array4f array4f;

    float   rawArray2f[2];
    float   rawArray3f[3];
    float   rawArray4f[4];
};

DEFINE_TEST_TYPES(ArrayTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Dimensions");

    const int dimensions2f = array2f.dimensions;
    const int dimensions3f = array3f.dimensions;
    const int dimensions4f = array4f.dimensions;

    VALUES_EQUAL(dimensions2f, 2);
    VALUES_EQUAL(dimensions3f, 3);
    VALUES_EQUAL(dimensions4f, 4);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Byte Count");

    const int byteCount2f = array2f.byteCount;
    const int byteCount3f = array3f.byteCount;
    const int byteCount4f = array4f.byteCount;

    VALUES_EQUAL(byteCount2f, 2 * sizeof(float));
    VALUES_EQUAL(byteCount3f, 3 * sizeof(float));
    VALUES_EQUAL(byteCount4f, 4 * sizeof(float));
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Bytes");

    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
        {
            array2f[i]    = 2 * i;
            rawArray2f[i] = 2 * i;
        }

        if (i < 3)
        {
            array3f[i]    = 3 * i;
            rawArray3f[i] = 3 * i;
        }

        if (i < 4)
        {
            array4f[i]    = 4 * i;
            rawArray4f[i] = 4 * i;
        }
    }
    
    ENSURE(memcmp(array2f.bytes(), &rawArray2f[0], array2f.byteCount) == 0);
    ENSURE(memcmp(array3f.bytes(), &rawArray3f[0], array3f.byteCount) == 0);
    ENSURE(memcmp(array4f.bytes(), &rawArray4f[0], array4f.byteCount) == 0);
}

template <>
template <>
void TestRegistry::test<4>()
{
    set_test_name("Constructor");

    memset(rawArray2f, 0, 2 * sizeof(float));
    memset(rawArray3f, 0, 3 * sizeof(float));
    memset(rawArray4f, 0, 4 * sizeof(float));
    
    ENSURE(memcmp(array2f.bytes(), &rawArray2f[0], array2f.byteCount) == 0);
    ENSURE(memcmp(array3f.bytes(), &rawArray3f[0], array3f.byteCount) == 0);
    ENSURE(memcmp(array4f.bytes(), &rawArray4f[0], array4f.byteCount) == 0);
}

}
