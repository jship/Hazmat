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

#include <Hazmat/Math/Matrix/Adjugate.h>

struct AdjugateTestData
{
    Matrix2f a2f, b2f;
    Matrix3f a3f, b3f;
    Matrix4f a4f, b4f;
};

DEFINE_TEST_TYPES(AdjugateTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Adjugate (2x2 matrix)");

    // Determinant of this matrix is 2
    a2f[0] = 3.0f; a2f[2] = 1.0f;
    a2f[1] = 4.0f; a2f[3] = 2.0f;

    jship::Hazmat::Adjugate(a2f, b2f);

    DOUBLES_EQUAL(a2f[0], 3.0, 1e-5);
    DOUBLES_EQUAL(a2f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a2f[2], 1.0, 1e-5);
    DOUBLES_EQUAL(a2f[3], 2.0, 1e-5);
    
    DOUBLES_EQUAL(b2f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(b2f[1], -4.0, 1e-5);
    DOUBLES_EQUAL(b2f[2], -1.0, 1e-5);
    DOUBLES_EQUAL(b2f[3],  3.0, 1e-5);
    
    jship::Hazmat::Adjugate(a2f, a2f);
    
    DOUBLES_EQUAL(a2f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(a2f[1], -4.0, 1e-5);
    DOUBLES_EQUAL(a2f[2], -1.0, 1e-5);
    DOUBLES_EQUAL(a2f[3],  3.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Adjugate (3x3 matrix)");

    // Determinant of this matrix is -2
    a3f[0] = 5.0f; a3f[3] = 6.0f; a3f[6] = 3.0f;
    a3f[1] = 4.0f; a3f[4] = 3.0f; a3f[7] = 1.0f;
    a3f[2] = 1.0f; a3f[5] = 4.0f; a3f[8] = 3.0f;

    jship::Hazmat::Adjugate(a3f, b3f);

    DOUBLES_EQUAL(a3f[0], 5.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[2], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[3], 6.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 3.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 3.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[8], 3.0, 1e-5);
    
    DOUBLES_EQUAL(b3f[0],   5.0, 1e-5);
    DOUBLES_EQUAL(b3f[1], -11.0, 1e-5);
    DOUBLES_EQUAL(b3f[2],  13.0, 1e-5);
    DOUBLES_EQUAL(b3f[3],  -6.0, 1e-5);
    DOUBLES_EQUAL(b3f[4],  12.0, 1e-5);
    DOUBLES_EQUAL(b3f[5], -14.0, 1e-5);
    DOUBLES_EQUAL(b3f[6],  -3.0, 1e-5);
    DOUBLES_EQUAL(b3f[7],   7.0, 1e-5);
    DOUBLES_EQUAL(b3f[8],  -9.0, 1e-5);
    
    jship::Hazmat::Adjugate(a3f, a3f);
    
    DOUBLES_EQUAL(a3f[0],   5.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], -11.0, 1e-5);
    DOUBLES_EQUAL(a3f[2],  13.0, 1e-5);
    DOUBLES_EQUAL(a3f[3],  -6.0, 1e-5);
    DOUBLES_EQUAL(a3f[4],  12.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], -14.0, 1e-5);
    DOUBLES_EQUAL(a3f[6],  -3.0, 1e-5);
    DOUBLES_EQUAL(a3f[7],   7.0, 1e-5);
    DOUBLES_EQUAL(a3f[8],  -9.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Adjugate (4x4 matrix)");

    // Determinant of this matrix is 192
    a4f[ 0] = 1.0f; a4f[ 4] = 2.0f; a4f[ 8] = 3.0f; a4f[12] = 7.0f; 
    a4f[ 1] = 4.0f; a4f[ 5] = 5.0f; a4f[ 9] = 6.0f; a4f[13] = 3.0f; 
    a4f[ 2] = 5.0f; a4f[ 6] = 4.0f; a4f[10] = 3.0f; a4f[14] = 1.0f; 
    a4f[ 3] = 2.0f; a4f[ 7] = 1.0f; a4f[11] = 4.0f; a4f[15] = 3.0f; 

    jship::Hazmat::Adjugate(a4f, b4f);
    
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
    
    DOUBLES_EQUAL(b4f[ 0],  -2.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 1],  16.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 2], -30.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 3],  36.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 4], -68.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 5],  64.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 6],  36.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 7], -24.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 8],  74.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 9], -16.0, 1e-5);
    DOUBLES_EQUAL(b4f[10], -42.0, 1e-5);
    DOUBLES_EQUAL(b4f[11],  12.0, 1e-5);
    DOUBLES_EQUAL(b4f[12],  48.0, 1e-5);
    DOUBLES_EQUAL(b4f[13], -96.0, 1e-5);
    DOUBLES_EQUAL(b4f[14],  48.0, 1e-5);
    DOUBLES_EQUAL(b4f[15],   0.0, 1e-5);
    
    jship::Hazmat::Adjugate(a4f, a4f);
    
    DOUBLES_EQUAL(a4f[ 0],  -2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  16.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2], -30.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],  36.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4], -68.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  64.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],  36.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7], -24.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8],  74.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], -16.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], -42.0, 1e-5);
    DOUBLES_EQUAL(a4f[11],  12.0, 1e-5);
    DOUBLES_EQUAL(a4f[12],  48.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], -96.0, 1e-5);
    DOUBLES_EQUAL(a4f[14],  48.0, 1e-5);
    DOUBLES_EQUAL(a4f[15],   0.0, 1e-5);
}

}
