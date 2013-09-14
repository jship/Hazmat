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
