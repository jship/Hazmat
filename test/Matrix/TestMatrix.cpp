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

struct MatrixTestData
{
    Matrix2f matrix2f;
    Matrix3f matrix3f;
    Matrix4f matrix4f;

    float    rawArray4f[4];
    float    rawArray9f[9];
    float    rawArray16f[16];
};

DEFINE_TEST_TYPES(MatrixTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Dimensions");

    const int dimensions2f = matrix2f.dimensions;
    const int dimensions3f = matrix3f.dimensions;
    const int dimensions4f = matrix4f.dimensions;

    VALUES_EQUAL(dimensions2f, 4);
    VALUES_EQUAL(dimensions3f, 9);
    VALUES_EQUAL(dimensions4f, 16);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Byte Count");

    const int byteCount2f = matrix2f.byteCount;
    const int byteCount3f = matrix3f.byteCount;
    const int byteCount4f = matrix4f.byteCount;

    VALUES_EQUAL(byteCount2f,  4 * sizeof(float));
    VALUES_EQUAL(byteCount3f,  9 * sizeof(float));
    VALUES_EQUAL(byteCount4f, 16 * sizeof(float));
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Bytes");

    for (int i = 0; i < 16; i++)
    {
        if (i < 4)
        {
            matrix2f[i]   = 4 * i;
            rawArray4f[i] = 4 * i;
        }

        if (i < 9)
        {
            matrix3f[i]   = 9 * i;
            rawArray9f[i] = 9 * i;
        }

        if (i < 16)
        {
            matrix4f[i]   = 16 * i;
            rawArray16f[i] = 16 * i;
        }
    }
    
    ENSURE(memcmp(matrix2f.bytes(), &rawArray4f[0], matrix2f.byteCount) == 0);
    ENSURE(memcmp(matrix3f.bytes(), &rawArray9f[0], matrix3f.byteCount) == 0);
    ENSURE(memcmp(matrix4f.bytes(), &rawArray16f[0], matrix4f.byteCount) == 0);
}

template <>
template <>
void TestRegistry::test<4>()
{
    set_test_name("Constructor");

    memset(rawArray4f,  0,  4 * sizeof(float));
    memset(rawArray9f,  0,  9 * sizeof(float));
    memset(rawArray16f, 0, 16 * sizeof(float));
    
    ENSURE(memcmp(matrix2f.bytes(), &rawArray4f[0],  matrix2f.byteCount) == 0);
    ENSURE(memcmp(matrix3f.bytes(), &rawArray9f[0],  matrix3f.byteCount) == 0);
    ENSURE(memcmp(matrix4f.bytes(), &rawArray16f[0], matrix4f.byteCount) == 0);
}

}
