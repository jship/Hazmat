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

struct VectorTestData
{
    Vector2f vector2f;
    Vector3f vector3f;
    Vector4f vector4f;

    float    rawArray2f[2];
    float    rawArray3f[3];
    float    rawArray4f[4];
};

DEFINE_TEST_TYPES(VectorTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Dimensions");

    const int dimensions2f = vector2f.dimensions;
    const int dimensions3f = vector3f.dimensions;
    const int dimensions4f = vector4f.dimensions;

    VALUES_EQUAL(dimensions2f, 2);
    VALUES_EQUAL(dimensions3f, 3);
    VALUES_EQUAL(dimensions4f, 4);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Byte Count");

    const int byteCount2f = vector2f.byteCount;
    const int byteCount3f = vector3f.byteCount;
    const int byteCount4f = vector4f.byteCount;

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
            vector2f[i]   = 2 * i;
            rawArray2f[i] = 2 * i;
        }

        if (i < 3)
        {
            vector3f[i]   = 3 * i;
            rawArray3f[i] = 3 * i;
        }

        if (i < 4)
        {
            vector4f[i]   = 4 * i;
            rawArray4f[i] = 4 * i;
        }
    }
    
    ENSURE(memcmp(vector2f.bytes(), &rawArray2f[0], vector2f.byteCount) == 0);
    ENSURE(memcmp(vector3f.bytes(), &rawArray3f[0], vector3f.byteCount) == 0);
    ENSURE(memcmp(vector4f.bytes(), &rawArray4f[0], vector4f.byteCount) == 0);
}

template <>
template <>
void TestRegistry::test<4>()
{
    set_test_name("Constructor");

    memset(rawArray2f, 0, 2 * sizeof(float));
    memset(rawArray3f, 0, 3 * sizeof(float));
    memset(rawArray4f, 0, 4 * sizeof(float));
    
    ENSURE(memcmp(vector2f.bytes(), &rawArray2f[0], vector2f.byteCount) == 0);
    ENSURE(memcmp(vector3f.bytes(), &rawArray3f[0], vector3f.byteCount) == 0);
    ENSURE(memcmp(vector4f.bytes(), &rawArray4f[0], vector4f.byteCount) == 0);
}

}
