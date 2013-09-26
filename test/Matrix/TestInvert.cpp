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

#include <Hazmat/Math/Matrix/Invert.h>

struct InvertTestData
{
    Matrix2f a2f, b2f;
    Matrix3f a3f, b3f;
    Matrix4f a4f, b4f;

    double scale;
};

DEFINE_TEST_TYPES(InvertTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Invert (non-singular 2x2 matrix)");

    a2f[0] = 3.0f; a2f[2] = 1.0f;
    a2f[1] = 4.0f; a2f[3] = 2.0f;
    
    scale = 1.0 / 2.0;

    jship::Hazmat::Invert(a2f, b2f);
    
    DOUBLES_EQUAL(a2f[0], 3.0, 1e-5);
    DOUBLES_EQUAL(a2f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a2f[2], 1.0, 1e-5);
    DOUBLES_EQUAL(a2f[3], 2.0, 1e-5);
    
    DOUBLES_EQUAL(b2f[0],  2.0 * scale, 1e-5);
    DOUBLES_EQUAL(b2f[1], -4.0 * scale, 1e-5);
    DOUBLES_EQUAL(b2f[2], -1.0 * scale, 1e-5);
    DOUBLES_EQUAL(b2f[3],  3.0 * scale, 1e-5);
    
    jship::Hazmat::Invert(a2f, a2f);
    
    DOUBLES_EQUAL(a2f[0],  2.0 * scale, 1e-5);
    DOUBLES_EQUAL(a2f[1], -4.0 * scale, 1e-5);
    DOUBLES_EQUAL(a2f[2], -1.0 * scale, 1e-5);
    DOUBLES_EQUAL(a2f[3],  3.0 * scale, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Invert (singular 2x2 matrix)");
    
    scale = 2.0f;

    a2f[0] = 2.0f; a2f[2] = 3.0f;
    a2f[1] = 4.0f; a2f[3] = 6.0f;
    
    // Just initializing b to have values that are not the same as a's.
    for (int i = 0; i < b2f.dimensions; i++)
    {
        b2f[i] = scale * a2f[i];
    }
    
    jship::Hazmat::Invert(a2f, b2f);
    
    DOUBLES_EQUAL(a2f[0], 2.0, 1e-5);
    DOUBLES_EQUAL(a2f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a2f[2], 3.0, 1e-5);
    DOUBLES_EQUAL(a2f[3], 6.0, 1e-5);
    
    DOUBLES_EQUAL(b2f[0], a2f[0] * scale, 1e-5);
    DOUBLES_EQUAL(b2f[1], a2f[1] * scale, 1e-5);
    DOUBLES_EQUAL(b2f[2], a2f[2] * scale, 1e-5);
    DOUBLES_EQUAL(b2f[3], a2f[3] * scale, 1e-5);
    
    jship::Hazmat::Invert(a2f, a2f);
    
    DOUBLES_EQUAL(a2f[0], 2.0, 1e-5);
    DOUBLES_EQUAL(a2f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a2f[2], 3.0, 1e-5);
    DOUBLES_EQUAL(a2f[3], 6.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Invert (non-singular 3x3 matrix)");

    a3f[0] = 5.0f; a3f[3] = 6.0f; a3f[6] = 3.0f;
    a3f[1] = 4.0f; a3f[4] = 3.0f; a3f[7] = 1.0f;
    a3f[2] = 1.0f; a3f[5] = 4.0f; a3f[8] = 3.0f;
    
    scale = 1.0 / 2.0;

    jship::Hazmat::Invert(a3f, b3f);
    
    DOUBLES_EQUAL(a3f[0], 5.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[2], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[3], 6.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 3.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 3.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[8], 3.0, 1e-5);
    
    DOUBLES_EQUAL(b3f[0],  -5.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[1],  11.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[2], -13.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[3],   6.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[4], -12.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[5],  14.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[6],   3.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[7],  -7.0 * scale, 1e-5);
    DOUBLES_EQUAL(b3f[8],   9.0 * scale, 1e-5);
    
    jship::Hazmat::Invert(a3f, a3f);
    
    DOUBLES_EQUAL(a3f[0],  -5.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[1],  11.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[2], -13.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[3],   6.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[4], -12.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[5],  14.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[6],   3.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[7],  -7.0 * scale, 1e-5);
    DOUBLES_EQUAL(a3f[8],   9.0 * scale, 1e-5);
}

template <>
template <>
void TestRegistry::test<4>()
{
    set_test_name("Invert (singular 3x3 matrix)");
    
    scale = 2.0f;

    a3f[0] = 1.0f; a3f[3] = 2.0f; a3f[6] = 3.0f;
    a3f[1] = 4.0f; a3f[4] = 5.0f; a3f[7] = 6.0f;
    a3f[2] = 5.0f; a3f[5] = 4.0f; a3f[8] = 3.0f;
    
    // Just initializing b to have values that are not the same as a's.
    for (int i = 0; i < b3f.dimensions; i++)
    {
        b3f[i] = scale * a3f[i];
    }
    
    jship::Hazmat::Invert(a3f, b3f);
    
    DOUBLES_EQUAL(a3f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[2], 5.0, 1e-5);
    DOUBLES_EQUAL(a3f[3], 2.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 5.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 3.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 6.0, 1e-5);
    DOUBLES_EQUAL(a3f[8], 3.0, 1e-5);
    
    DOUBLES_EQUAL(b3f[0], a3f[0] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[1], a3f[1] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[2], a3f[2] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[3], a3f[3] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[4], a3f[4] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[5], a3f[5] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[6], a3f[6] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[7], a3f[7] * scale, 1e-5);
    DOUBLES_EQUAL(b3f[8], a3f[8] * scale, 1e-5);
    
    jship::Hazmat::Invert(a3f, a3f);
    
    DOUBLES_EQUAL(a3f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[2], 5.0, 1e-5);
    DOUBLES_EQUAL(a3f[3], 2.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 5.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 3.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 6.0, 1e-5);
    DOUBLES_EQUAL(a3f[8], 3.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<5>()
{
    set_test_name("Invert (non-singular 4x4 matrix)");

    a4f[ 0] = 1.0f; a4f[ 4] = 2.0f; a4f[ 8] = 3.0f; a4f[12] = 7.0f;
    a4f[ 1] = 4.0f; a4f[ 5] = 5.0f; a4f[ 9] = 6.0f; a4f[13] = 3.0f;
    a4f[ 2] = 5.0f; a4f[ 6] = 4.0f; a4f[10] = 3.0f; a4f[14] = 1.0f;
    a4f[ 3] = 2.0f; a4f[ 7] = 1.0f; a4f[11] = 4.0f; a4f[15] = 3.0f;

    scale = 1.0 / 96.0;

    jship::Hazmat::Invert(a4f, b4f);
    
    DOUBLES_EQUAL(a4f[ 0], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1], 4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2], 5.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3], 2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4], 2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5], 5.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6], 4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8], 3.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 6.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 3.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 4.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 7.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 3.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 3.0, 1e-5);
    
    DOUBLES_EQUAL(b4f[ 0],  -1.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 1],   8.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 2], -15.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 3],  18.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 4], -34.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 5],  32.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 6],  18.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 7], -12.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 8],  37.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 9],  -8.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[10], -21.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[11],   6.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[12],  24.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[13], -48.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[14],  24.0 * scale, 1e-5);
    DOUBLES_EQUAL(b4f[15],   0.0 * scale, 1e-5);
    
    jship::Hazmat::Invert(a4f, a4f);
    
    DOUBLES_EQUAL(a4f[ 0],  -1.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],   8.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 2], -15.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],  18.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 4], -34.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  32.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],  18.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 7], -12.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 8],  37.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[ 9],  -8.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[10], -21.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[11],   6.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[12],  24.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[13], -48.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[14],  24.0 * scale, 1e-5);
    DOUBLES_EQUAL(a4f[15],   0.0 * scale, 1e-5);
}

template <>
template <>
void TestRegistry::test<6>()
{
    set_test_name("Invert (singular 4x4 matrix)");

    scale = 2.0f;

    a4f[ 0] = 1.0f; a4f[ 4] = 5.0f; a4f[ 8] =  9.0f; a4f[12] = 13.0f;
    a4f[ 1] = 2.0f; a4f[ 5] = 6.0f; a4f[ 9] = 10.0f; a4f[13] = 14.0f;
    a4f[ 2] = 3.0f; a4f[ 6] = 7.0f; a4f[10] = 11.0f; a4f[14] = 15.0f;
    a4f[ 3] = 4.0f; a4f[ 7] = 8.0f; a4f[11] = 12.0f; a4f[15] = 16.0f;
    
    // Just initializing b to have values that are not the same as a's.
    for (int i = 0; i < b4f.dimensions; i++)
    {
        b4f[i] = scale * a4f[i];
    }

    jship::Hazmat::Invert(a4f, b4f);
    
    DOUBLES_EQUAL(a4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 16.0, 1e-5);
    
    // b should remain unchanged since a is singular.
    DOUBLES_EQUAL(b4f[ 0], a4f[ 0] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 1], a4f[ 1] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 2], a4f[ 2] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 3], a4f[ 3] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 4], a4f[ 4] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 5], a4f[ 5] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 6], a4f[ 6] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 7], a4f[ 7] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 8], a4f[ 8] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[ 9], a4f[ 9] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[10], a4f[10] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[11], a4f[11] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[12], a4f[12] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[13], a4f[13] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[14], a4f[14] * scale, 1e-5);
    DOUBLES_EQUAL(b4f[15], a4f[15] * scale, 1e-5);
    
    jship::Hazmat::Invert(a4f, a4f);
    
    DOUBLES_EQUAL(a4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 16.0, 1e-5);
}

}
