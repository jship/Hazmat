#include "Common.h"

struct QuaternionTestData
{
    Quaternion4f quaternion;
    float        rawArray4f[4];
};

DEFINE_TEST_TYPES(QuaternionTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Dimensions");

    const int dimensions = quaternion.dimensions;
    VALUES_EQUAL(dimensions, 4);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Byte Count");

    const int byteCount = quaternion.byteCount;
    VALUES_EQUAL(byteCount, 4 * sizeof(float));
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Bytes");

    for (int i = 0; i < 4; i++)
    {
        quaternion[i] = 4 * i;
        rawArray4f[i] = 4 * i;
    }
    
    ENSURE(memcmp(quaternion.bytes(), &rawArray4f[0], quaternion.byteCount) == 0);
}

template <>
template <>
void TestRegistry::test<4>()
{
    set_test_name("Constructor");

    memset(rawArray4f, 0, 4 * sizeof(float));
    ENSURE(memcmp(quaternion.bytes(), &rawArray4f[0], quaternion.byteCount) == 0);
}

}
