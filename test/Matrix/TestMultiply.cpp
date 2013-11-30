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

#include <Hazmat/Math/Matrix/Multiply.h>

struct MultiplyMatrixTestData
{
    Matrix2f a2f, b2f, c2f;
    Matrix3f a3f, b3f, c3f;
    Matrix4f a4f, b4f, c4f;
};

DEFINE_TEST_TYPES(MultiplyMatrixTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Multiply (2x2 matrices)");

    a2f[0] = 1.0f; a2f[2] = 3.0f;
    a2f[1] = 2.0f; a2f[3] = 4.0f;
    
    b2f[0] = 2.0f; b2f[2] = 4.0f;
    b2f[1] = 3.0f; b2f[3] = 5.0f;

    jship::Hazmat::Multiply(a2f, b2f, c2f);
    
    DOUBLES_EQUAL(a2f[0],  1.0, 1e-5);
    DOUBLES_EQUAL(a2f[1],  2.0, 1e-5);
    DOUBLES_EQUAL(a2f[2],  3.0, 1e-5);
    DOUBLES_EQUAL(a2f[3],  4.0, 1e-5);

    DOUBLES_EQUAL(b2f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(b2f[1],  3.0, 1e-5);
    DOUBLES_EQUAL(b2f[2],  4.0, 1e-5);
    DOUBLES_EQUAL(b2f[3],  5.0, 1e-5);
    
    DOUBLES_EQUAL(c2f[0], 11.0, 1e-5);
    DOUBLES_EQUAL(c2f[1], 16.0, 1e-5);
    DOUBLES_EQUAL(c2f[2], 19.0, 1e-5);
    DOUBLES_EQUAL(c2f[3], 28.0, 1e-5);

    jship::Hazmat::Multiply(a2f, b2f, a2f);
    
    DOUBLES_EQUAL(a2f[0], c2f[0], 1e-5);
    DOUBLES_EQUAL(a2f[1], c2f[1], 1e-5);
    DOUBLES_EQUAL(a2f[2], c2f[2], 1e-5);
    DOUBLES_EQUAL(a2f[3], c2f[3], 1e-5);
    
    a2f[0] = 1.0f; a2f[2] = 3.0f;
    a2f[1] = 2.0f; a2f[3] = 4.0f;
    
    jship::Hazmat::Multiply(a2f, b2f, b2f);
    
    DOUBLES_EQUAL(b2f[0], c2f[0], 1e-5);
    DOUBLES_EQUAL(b2f[1], c2f[1], 1e-5);
    DOUBLES_EQUAL(b2f[2], c2f[2], 1e-5);
    DOUBLES_EQUAL(b2f[3], c2f[3], 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("operator* (2x2 matrices)");

    a2f[0] = 1.0f; a2f[2] = 3.0f;
    a2f[1] = 2.0f; a2f[3] = 4.0f;
    
    b2f[0] = 2.0f; b2f[2] = 4.0f;
    b2f[1] = 3.0f; b2f[3] = 5.0f;

    c2f = a2f * b2f;
    
    DOUBLES_EQUAL(a2f[0],  1.0, 1e-5);
    DOUBLES_EQUAL(a2f[1],  2.0, 1e-5);
    DOUBLES_EQUAL(a2f[2],  3.0, 1e-5);
    DOUBLES_EQUAL(a2f[3],  4.0, 1e-5);

    DOUBLES_EQUAL(b2f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(b2f[1],  3.0, 1e-5);
    DOUBLES_EQUAL(b2f[2],  4.0, 1e-5);
    DOUBLES_EQUAL(b2f[3],  5.0, 1e-5);
    
    DOUBLES_EQUAL(c2f[0], 11.0, 1e-5);
    DOUBLES_EQUAL(c2f[1], 16.0, 1e-5);
    DOUBLES_EQUAL(c2f[2], 19.0, 1e-5);
    DOUBLES_EQUAL(c2f[3], 28.0, 1e-5);

    a2f = a2f * b2f;
    
    DOUBLES_EQUAL(a2f[0], c2f[0], 1e-5);
    DOUBLES_EQUAL(a2f[1], c2f[1], 1e-5);
    DOUBLES_EQUAL(a2f[2], c2f[2], 1e-5);
    DOUBLES_EQUAL(a2f[3], c2f[3], 1e-5);
    
    a2f[0] = 1.0f; a2f[2] = 3.0f;
    a2f[1] = 2.0f; a2f[3] = 4.0f;
    
    b2f = a2f * b2f;
    
    DOUBLES_EQUAL(b2f[0], c2f[0], 1e-5);
    DOUBLES_EQUAL(b2f[1], c2f[1], 1e-5);
    DOUBLES_EQUAL(b2f[2], c2f[2], 1e-5);
    DOUBLES_EQUAL(b2f[3], c2f[3], 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Multiply (3x3 matrices)");

    a3f[0] = 1.0f; a3f[3] = 4.0f; a3f[6] = 7.0f;
    a3f[1] = 2.0f; a3f[4] = 5.0f; a3f[7] = 8.0f;
    a3f[2] = 3.0f; a3f[5] = 6.0f; a3f[8] = 9.0f;
    
    b3f[0] = 2.0f; b3f[3] = 5.0f; b3f[6] =  8.0f;
    b3f[1] = 3.0f; b3f[4] = 6.0f; b3f[7] =  9.0f;
    b3f[2] = 4.0f; b3f[5] = 7.0f; b3f[8] = 10.0f;

    jship::Hazmat::Multiply(a3f, b3f, c3f);
    
    DOUBLES_EQUAL(a3f[0],  1.0, 1e-5);
    DOUBLES_EQUAL(a3f[1],  2.0, 1e-5);
    DOUBLES_EQUAL(a3f[2],  3.0, 1e-5);
    DOUBLES_EQUAL(a3f[3],  4.0, 1e-5);
    DOUBLES_EQUAL(a3f[4],  5.0, 1e-5);
    DOUBLES_EQUAL(a3f[5],  6.0, 1e-5);
    DOUBLES_EQUAL(a3f[6],  7.0, 1e-5);
    DOUBLES_EQUAL(a3f[7],  8.0, 1e-5);
    DOUBLES_EQUAL(a3f[8],  9.0, 1e-5);

    DOUBLES_EQUAL(b3f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(b3f[1],  3.0, 1e-5);
    DOUBLES_EQUAL(b3f[2],  4.0, 1e-5);
    DOUBLES_EQUAL(b3f[3],  5.0, 1e-5);
    DOUBLES_EQUAL(b3f[4],  6.0, 1e-5);
    DOUBLES_EQUAL(b3f[5],  7.0, 1e-5);
    DOUBLES_EQUAL(b3f[6],  8.0, 1e-5);
    DOUBLES_EQUAL(b3f[7],  9.0, 1e-5);
    DOUBLES_EQUAL(b3f[8], 10.0, 1e-5);
    
    DOUBLES_EQUAL(c3f[0],  42.0, 1e-5);
    DOUBLES_EQUAL(c3f[1],  51.0, 1e-5);
    DOUBLES_EQUAL(c3f[2],  60.0, 1e-5);
    DOUBLES_EQUAL(c3f[3],  78.0, 1e-5);
    DOUBLES_EQUAL(c3f[4],  96.0, 1e-5);
    DOUBLES_EQUAL(c3f[5], 114.0, 1e-5);
    DOUBLES_EQUAL(c3f[6], 114.0, 1e-5);
    DOUBLES_EQUAL(c3f[7], 141.0, 1e-5);
    DOUBLES_EQUAL(c3f[8], 168.0, 1e-5);

    jship::Hazmat::Multiply(a3f, b3f, a3f);
    
    DOUBLES_EQUAL(a3f[0], c3f[0], 1e-5);
    DOUBLES_EQUAL(a3f[1], c3f[1], 1e-5);
    DOUBLES_EQUAL(a3f[2], c3f[2], 1e-5);
    DOUBLES_EQUAL(a3f[3], c3f[3], 1e-5);
    DOUBLES_EQUAL(a3f[4], c3f[4], 1e-5);
    DOUBLES_EQUAL(a3f[5], c3f[5], 1e-5);
    DOUBLES_EQUAL(a3f[6], c3f[6], 1e-5);
    DOUBLES_EQUAL(a3f[7], c3f[7], 1e-5);
    DOUBLES_EQUAL(a3f[8], c3f[8], 1e-5);
    
    a3f[0] = 1.0f; a3f[3] = 4.0f; a3f[6] = 7.0f;
    a3f[1] = 2.0f; a3f[4] = 5.0f; a3f[7] = 8.0f;
    a3f[2] = 3.0f; a3f[5] = 6.0f; a3f[8] = 9.0f;
    
    jship::Hazmat::Multiply(a3f, b3f, b3f);
    
    DOUBLES_EQUAL(b3f[0], c3f[0], 1e-5);
    DOUBLES_EQUAL(b3f[1], c3f[1], 1e-5);
    DOUBLES_EQUAL(b3f[2], c3f[2], 1e-5);
    DOUBLES_EQUAL(b3f[3], c3f[3], 1e-5);
    DOUBLES_EQUAL(b3f[4], c3f[4], 1e-5);
    DOUBLES_EQUAL(b3f[5], c3f[5], 1e-5);
    DOUBLES_EQUAL(b3f[6], c3f[6], 1e-5);
    DOUBLES_EQUAL(b3f[7], c3f[7], 1e-5);
    DOUBLES_EQUAL(b3f[8], c3f[8], 1e-5);
}

template <>
template <>
void TestRegistry::test<4>()
{
    set_test_name("operator* (3x3 matrices)");

    a3f[0] = 1.0f; a3f[3] = 4.0f; a3f[6] = 7.0f;
    a3f[1] = 2.0f; a3f[4] = 5.0f; a3f[7] = 8.0f;
    a3f[2] = 3.0f; a3f[5] = 6.0f; a3f[8] = 9.0f;
    
    b3f[0] = 2.0f; b3f[3] = 5.0f; b3f[6] =  8.0f;
    b3f[1] = 3.0f; b3f[4] = 6.0f; b3f[7] =  9.0f;
    b3f[2] = 4.0f; b3f[5] = 7.0f; b3f[8] = 10.0f;

    c3f = a3f * b3f;
    
    DOUBLES_EQUAL(a3f[0],  1.0, 1e-5);
    DOUBLES_EQUAL(a3f[1],  2.0, 1e-5);
    DOUBLES_EQUAL(a3f[2],  3.0, 1e-5);
    DOUBLES_EQUAL(a3f[3],  4.0, 1e-5);
    DOUBLES_EQUAL(a3f[4],  5.0, 1e-5);
    DOUBLES_EQUAL(a3f[5],  6.0, 1e-5);
    DOUBLES_EQUAL(a3f[6],  7.0, 1e-5);
    DOUBLES_EQUAL(a3f[7],  8.0, 1e-5);
    DOUBLES_EQUAL(a3f[8],  9.0, 1e-5);

    DOUBLES_EQUAL(b3f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(b3f[1],  3.0, 1e-5);
    DOUBLES_EQUAL(b3f[2],  4.0, 1e-5);
    DOUBLES_EQUAL(b3f[3],  5.0, 1e-5);
    DOUBLES_EQUAL(b3f[4],  6.0, 1e-5);
    DOUBLES_EQUAL(b3f[5],  7.0, 1e-5);
    DOUBLES_EQUAL(b3f[6],  8.0, 1e-5);
    DOUBLES_EQUAL(b3f[7],  9.0, 1e-5);
    DOUBLES_EQUAL(b3f[8], 10.0, 1e-5);
    
    DOUBLES_EQUAL(c3f[0],  42.0, 1e-5);
    DOUBLES_EQUAL(c3f[1],  51.0, 1e-5);
    DOUBLES_EQUAL(c3f[2],  60.0, 1e-5);
    DOUBLES_EQUAL(c3f[3],  78.0, 1e-5);
    DOUBLES_EQUAL(c3f[4],  96.0, 1e-5);
    DOUBLES_EQUAL(c3f[5], 114.0, 1e-5);
    DOUBLES_EQUAL(c3f[6], 114.0, 1e-5);
    DOUBLES_EQUAL(c3f[7], 141.0, 1e-5);
    DOUBLES_EQUAL(c3f[8], 168.0, 1e-5);

    a3f = a3f * b3f;
    
    DOUBLES_EQUAL(a3f[0], c3f[0], 1e-5);
    DOUBLES_EQUAL(a3f[1], c3f[1], 1e-5);
    DOUBLES_EQUAL(a3f[2], c3f[2], 1e-5);
    DOUBLES_EQUAL(a3f[3], c3f[3], 1e-5);
    DOUBLES_EQUAL(a3f[4], c3f[4], 1e-5);
    DOUBLES_EQUAL(a3f[5], c3f[5], 1e-5);
    DOUBLES_EQUAL(a3f[6], c3f[6], 1e-5);
    DOUBLES_EQUAL(a3f[7], c3f[7], 1e-5);
    DOUBLES_EQUAL(a3f[8], c3f[8], 1e-5);
    
    a3f[0] = 1.0f; a3f[3] = 4.0f; a3f[6] = 7.0f;
    a3f[1] = 2.0f; a3f[4] = 5.0f; a3f[7] = 8.0f;
    a3f[2] = 3.0f; a3f[5] = 6.0f; a3f[8] = 9.0f;
    
    b3f = a3f * b3f;
    
    DOUBLES_EQUAL(b3f[0], c3f[0], 1e-5);
    DOUBLES_EQUAL(b3f[1], c3f[1], 1e-5);
    DOUBLES_EQUAL(b3f[2], c3f[2], 1e-5);
    DOUBLES_EQUAL(b3f[3], c3f[3], 1e-5);
    DOUBLES_EQUAL(b3f[4], c3f[4], 1e-5);
    DOUBLES_EQUAL(b3f[5], c3f[5], 1e-5);
    DOUBLES_EQUAL(b3f[6], c3f[6], 1e-5);
    DOUBLES_EQUAL(b3f[7], c3f[7], 1e-5);
    DOUBLES_EQUAL(b3f[8], c3f[8], 1e-5);
}

template <>
template <>
void TestRegistry::test<5>()
{
    set_test_name("Multiply (4x4 matrices)");

    a4f[ 0] = 1.0f; a4f[ 4] = 5.0f; a4f[ 8] =  9.0f; a4f[12] = 13.0f;
    a4f[ 1] = 2.0f; a4f[ 5] = 6.0f; a4f[ 9] = 10.0f; a4f[13] = 14.0f;
    a4f[ 2] = 3.0f; a4f[ 6] = 7.0f; a4f[10] = 11.0f; a4f[14] = 15.0f;
    a4f[ 3] = 4.0f; a4f[ 7] = 8.0f; a4f[11] = 12.0f; a4f[15] = 16.0f;
    
    b4f[ 0] = 2.0f; b4f[ 4] = 6.0f; b4f[ 8] = 10.0f; b4f[12] = 14.0f;
    b4f[ 1] = 3.0f; b4f[ 5] = 7.0f; b4f[ 9] = 11.0f; b4f[13] = 15.0f;
    b4f[ 2] = 4.0f; b4f[ 6] = 8.0f; b4f[10] = 12.0f; b4f[14] = 16.0f;
    b4f[ 3] = 5.0f; b4f[ 7] = 9.0f; b4f[11] = 13.0f; b4f[15] = 17.0f;

    jship::Hazmat::Multiply(a4f, b4f, c4f);
    
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

    DOUBLES_EQUAL(b4f[ 0],  2.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 1],  3.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 2],  4.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 3],  5.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 4],  6.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 5],  7.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 6],  8.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 7],  9.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 8], 10.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 9], 11.0, 1e-5);
    DOUBLES_EQUAL(b4f[10], 12.0, 1e-5);
    DOUBLES_EQUAL(b4f[11], 13.0, 1e-5);
    DOUBLES_EQUAL(b4f[12], 14.0, 1e-5);
    DOUBLES_EQUAL(b4f[13], 15.0, 1e-5);
    DOUBLES_EQUAL(b4f[14], 16.0, 1e-5);
    DOUBLES_EQUAL(b4f[15], 17.0, 1e-5);
    
    DOUBLES_EQUAL(c4f[ 0], 118.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 1], 132.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 2], 146.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 3], 160.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 4], 230.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 5], 260.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 6], 290.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 7], 320.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 8], 342.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 9], 388.0, 1e-5);
    DOUBLES_EQUAL(c4f[10], 434.0, 1e-5);
    DOUBLES_EQUAL(c4f[11], 480.0, 1e-5);
    DOUBLES_EQUAL(c4f[12], 454.0, 1e-5);
    DOUBLES_EQUAL(c4f[13], 516.0, 1e-5);
    DOUBLES_EQUAL(c4f[14], 578.0, 1e-5);
    DOUBLES_EQUAL(c4f[15], 640.0, 1e-5);

    jship::Hazmat::Multiply(a4f, b4f, a4f);
    
    DOUBLES_EQUAL(a4f[ 0], c4f[ 0], 1e-5);
    DOUBLES_EQUAL(a4f[ 1], c4f[ 1], 1e-5);
    DOUBLES_EQUAL(a4f[ 2], c4f[ 2], 1e-5);
    DOUBLES_EQUAL(a4f[ 3], c4f[ 3], 1e-5);
    DOUBLES_EQUAL(a4f[ 4], c4f[ 4], 1e-5);
    DOUBLES_EQUAL(a4f[ 5], c4f[ 5], 1e-5);
    DOUBLES_EQUAL(a4f[ 6], c4f[ 6], 1e-5);
    DOUBLES_EQUAL(a4f[ 7], c4f[ 7], 1e-5);
    DOUBLES_EQUAL(a4f[ 8], c4f[ 8], 1e-5);
    DOUBLES_EQUAL(a4f[ 9], c4f[ 9], 1e-5);
    DOUBLES_EQUAL(a4f[10], c4f[10], 1e-5);
    DOUBLES_EQUAL(a4f[11], c4f[11], 1e-5);
    DOUBLES_EQUAL(a4f[12], c4f[12], 1e-5);
    DOUBLES_EQUAL(a4f[13], c4f[13], 1e-5);
    DOUBLES_EQUAL(a4f[14], c4f[14], 1e-5);
    DOUBLES_EQUAL(a4f[15], c4f[15], 1e-5);
    
    a4f[ 0] = 1.0f; a4f[ 4] = 5.0f; a4f[ 8] =  9.0f; a4f[12] = 13.0f;
    a4f[ 1] = 2.0f; a4f[ 5] = 6.0f; a4f[ 9] = 10.0f; a4f[13] = 14.0f;
    a4f[ 2] = 3.0f; a4f[ 6] = 7.0f; a4f[10] = 11.0f; a4f[14] = 15.0f;
    a4f[ 3] = 4.0f; a4f[ 7] = 8.0f; a4f[11] = 12.0f; a4f[15] = 16.0f;
    
    jship::Hazmat::Multiply(a4f, b4f, b4f);
    
    DOUBLES_EQUAL(b4f[ 0], c4f[ 0], 1e-5);
    DOUBLES_EQUAL(b4f[ 1], c4f[ 1], 1e-5);
    DOUBLES_EQUAL(b4f[ 2], c4f[ 2], 1e-5);
    DOUBLES_EQUAL(b4f[ 3], c4f[ 3], 1e-5);
    DOUBLES_EQUAL(b4f[ 4], c4f[ 4], 1e-5);
    DOUBLES_EQUAL(b4f[ 5], c4f[ 5], 1e-5);
    DOUBLES_EQUAL(b4f[ 6], c4f[ 6], 1e-5);
    DOUBLES_EQUAL(b4f[ 7], c4f[ 7], 1e-5);
    DOUBLES_EQUAL(b4f[ 8], c4f[ 8], 1e-5);
    DOUBLES_EQUAL(b4f[ 9], c4f[ 9], 1e-5);
    DOUBLES_EQUAL(b4f[10], c4f[10], 1e-5);
    DOUBLES_EQUAL(b4f[11], c4f[11], 1e-5);
    DOUBLES_EQUAL(b4f[12], c4f[12], 1e-5);
    DOUBLES_EQUAL(b4f[13], c4f[13], 1e-5);
    DOUBLES_EQUAL(b4f[14], c4f[14], 1e-5);
    DOUBLES_EQUAL(b4f[15], c4f[15], 1e-5);
}

template <>
template <>
void TestRegistry::test<6>()
{
    set_test_name("operator* (4x4 matrices)");

    a4f[ 0] = 1.0f; a4f[ 4] = 5.0f; a4f[ 8] =  9.0f; a4f[12] = 13.0f;
    a4f[ 1] = 2.0f; a4f[ 5] = 6.0f; a4f[ 9] = 10.0f; a4f[13] = 14.0f;
    a4f[ 2] = 3.0f; a4f[ 6] = 7.0f; a4f[10] = 11.0f; a4f[14] = 15.0f;
    a4f[ 3] = 4.0f; a4f[ 7] = 8.0f; a4f[11] = 12.0f; a4f[15] = 16.0f;
    
    b4f[ 0] = 2.0f; b4f[ 4] = 6.0f; b4f[ 8] = 10.0f; b4f[12] = 14.0f;
    b4f[ 1] = 3.0f; b4f[ 5] = 7.0f; b4f[ 9] = 11.0f; b4f[13] = 15.0f;
    b4f[ 2] = 4.0f; b4f[ 6] = 8.0f; b4f[10] = 12.0f; b4f[14] = 16.0f;
    b4f[ 3] = 5.0f; b4f[ 7] = 9.0f; b4f[11] = 13.0f; b4f[15] = 17.0f;

    c4f = a4f * b4f;
    
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

    DOUBLES_EQUAL(b4f[ 0],  2.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 1],  3.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 2],  4.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 3],  5.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 4],  6.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 5],  7.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 6],  8.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 7],  9.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 8], 10.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 9], 11.0, 1e-5);
    DOUBLES_EQUAL(b4f[10], 12.0, 1e-5);
    DOUBLES_EQUAL(b4f[11], 13.0, 1e-5);
    DOUBLES_EQUAL(b4f[12], 14.0, 1e-5);
    DOUBLES_EQUAL(b4f[13], 15.0, 1e-5);
    DOUBLES_EQUAL(b4f[14], 16.0, 1e-5);
    DOUBLES_EQUAL(b4f[15], 17.0, 1e-5);
    
    DOUBLES_EQUAL(c4f[ 0], 118.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 1], 132.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 2], 146.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 3], 160.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 4], 230.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 5], 260.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 6], 290.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 7], 320.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 8], 342.0, 1e-5);
    DOUBLES_EQUAL(c4f[ 9], 388.0, 1e-5);
    DOUBLES_EQUAL(c4f[10], 434.0, 1e-5);
    DOUBLES_EQUAL(c4f[11], 480.0, 1e-5);
    DOUBLES_EQUAL(c4f[12], 454.0, 1e-5);
    DOUBLES_EQUAL(c4f[13], 516.0, 1e-5);
    DOUBLES_EQUAL(c4f[14], 578.0, 1e-5);
    DOUBLES_EQUAL(c4f[15], 640.0, 1e-5);

    a4f = a4f * b4f;
    
    DOUBLES_EQUAL(a4f[ 0], c4f[ 0], 1e-5);
    DOUBLES_EQUAL(a4f[ 1], c4f[ 1], 1e-5);
    DOUBLES_EQUAL(a4f[ 2], c4f[ 2], 1e-5);
    DOUBLES_EQUAL(a4f[ 3], c4f[ 3], 1e-5);
    DOUBLES_EQUAL(a4f[ 4], c4f[ 4], 1e-5);
    DOUBLES_EQUAL(a4f[ 5], c4f[ 5], 1e-5);
    DOUBLES_EQUAL(a4f[ 6], c4f[ 6], 1e-5);
    DOUBLES_EQUAL(a4f[ 7], c4f[ 7], 1e-5);
    DOUBLES_EQUAL(a4f[ 8], c4f[ 8], 1e-5);
    DOUBLES_EQUAL(a4f[ 9], c4f[ 9], 1e-5);
    DOUBLES_EQUAL(a4f[10], c4f[10], 1e-5);
    DOUBLES_EQUAL(a4f[11], c4f[11], 1e-5);
    DOUBLES_EQUAL(a4f[12], c4f[12], 1e-5);
    DOUBLES_EQUAL(a4f[13], c4f[13], 1e-5);
    DOUBLES_EQUAL(a4f[14], c4f[14], 1e-5);
    DOUBLES_EQUAL(a4f[15], c4f[15], 1e-5);
    
    a4f[ 0] = 1.0f; a4f[ 4] = 5.0f; a4f[ 8] =  9.0f; a4f[12] = 13.0f;
    a4f[ 1] = 2.0f; a4f[ 5] = 6.0f; a4f[ 9] = 10.0f; a4f[13] = 14.0f;
    a4f[ 2] = 3.0f; a4f[ 6] = 7.0f; a4f[10] = 11.0f; a4f[14] = 15.0f;
    a4f[ 3] = 4.0f; a4f[ 7] = 8.0f; a4f[11] = 12.0f; a4f[15] = 16.0f;
    
    b4f = a4f * b4f;
    
    DOUBLES_EQUAL(b4f[ 0], c4f[ 0], 1e-5);
    DOUBLES_EQUAL(b4f[ 1], c4f[ 1], 1e-5);
    DOUBLES_EQUAL(b4f[ 2], c4f[ 2], 1e-5);
    DOUBLES_EQUAL(b4f[ 3], c4f[ 3], 1e-5);
    DOUBLES_EQUAL(b4f[ 4], c4f[ 4], 1e-5);
    DOUBLES_EQUAL(b4f[ 5], c4f[ 5], 1e-5);
    DOUBLES_EQUAL(b4f[ 6], c4f[ 6], 1e-5);
    DOUBLES_EQUAL(b4f[ 7], c4f[ 7], 1e-5);
    DOUBLES_EQUAL(b4f[ 8], c4f[ 8], 1e-5);
    DOUBLES_EQUAL(b4f[ 9], c4f[ 9], 1e-5);
    DOUBLES_EQUAL(b4f[10], c4f[10], 1e-5);
    DOUBLES_EQUAL(b4f[11], c4f[11], 1e-5);
    DOUBLES_EQUAL(b4f[12], c4f[12], 1e-5);
    DOUBLES_EQUAL(b4f[13], c4f[13], 1e-5);
    DOUBLES_EQUAL(b4f[14], c4f[14], 1e-5);
    DOUBLES_EQUAL(b4f[15], c4f[15], 1e-5);
}

}
