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

#include <Hazmat/Math/Matrix/Determinant.h>

struct DeterminantTestData
{
    Matrix2f m2f;
    Matrix3f m3f;
    Matrix4f m4f;

    float result;
};

DEFINE_TEST_TYPES(DeterminantTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Determinant (2x2 matrix)");

    m2f[0] = 1.0f; m2f[2] = 3.0f;
    m2f[1] = 2.0f; m2f[3] = 4.0f;

    result = jship::Hazmat::Determinant(m2f);
    
    DOUBLES_EQUAL(m2f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(m2f[1], 2.0, 1e-5);
    DOUBLES_EQUAL(m2f[2], 3.0, 1e-5);
    DOUBLES_EQUAL(m2f[3], 4.0, 1e-5);
    
    DOUBLES_EQUAL(result, -2.0, 1e-5);
    
    m2f[0] =  1.0f; m2f[2] =  2.0f;
    m2f[1] = -3.0f; m2f[3] =  1.0f;
    
    result = jship::Hazmat::Determinant(m2f);
    
    DOUBLES_EQUAL(m2f[0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[1], -3.0, 1e-5);
    DOUBLES_EQUAL(m2f[2],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[3],  1.0, 1e-5);

    DOUBLES_EQUAL(result, 7.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Determinant (3x3 matrix)");

    m3f[0] = 1.0f; m3f[3] = 4.0f; m3f[6] = 7.0f;
    m3f[1] = 2.0f; m3f[4] = 5.0f; m3f[7] = 8.0f;
    m3f[2] = 3.0f; m3f[5] = 6.0f; m3f[8] = 9.0f;

    result = jship::Hazmat::Determinant(m3f);
    
    DOUBLES_EQUAL(m3f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(m3f[1], 2.0, 1e-5);
    DOUBLES_EQUAL(m3f[2], 3.0, 1e-5);
    DOUBLES_EQUAL(m3f[3], 4.0, 1e-5);
    DOUBLES_EQUAL(m3f[4], 5.0, 1e-5);
    DOUBLES_EQUAL(m3f[5], 6.0, 1e-5);
    DOUBLES_EQUAL(m3f[6], 7.0, 1e-5);
    DOUBLES_EQUAL(m3f[7], 8.0, 1e-5);
    DOUBLES_EQUAL(m3f[8], 9.0, 1e-5);
    
    DOUBLES_EQUAL(result, 0.0, 1e-5);
    
    m3f[0] =  1.0f; m3f[3] =  2.0f; m3f[6] =  2.0f;
    m3f[1] = -3.0f; m3f[4] =  1.0f; m3f[7] = -2.0f;
    m3f[2] = 10.0f; m3f[5] = -4.0f; m3f[8] =  1.0f;
    
    result = jship::Hazmat::Determinant(m3f);
    
    DOUBLES_EQUAL(m3f[0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[1], -3.0, 1e-5);
    DOUBLES_EQUAL(m3f[2], 10.0, 1e-5);
    DOUBLES_EQUAL(m3f[3],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[4],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[5], -4.0, 1e-5);
    DOUBLES_EQUAL(m3f[6],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[7], -2.0, 1e-5);
    DOUBLES_EQUAL(m3f[8],  1.0, 1e-5);

    DOUBLES_EQUAL(result, -37.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Determinant (4x4 matrix)");

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f; 
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f; 
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f; 
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f; 

    result = jship::Hazmat::Determinant(m4f);
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(result, 0.0, 1e-5);

    m4f[ 0] =  1.0f; m4f[ 4] =  2.0f; m4f[ 8] =  2.0f; m4f[12] = 1.0f; 
    m4f[ 1] = -3.0f; m4f[ 5] =  1.0f; m4f[ 9] = -2.0f; m4f[13] = 2.0f; 
    m4f[ 2] = 10.0f; m4f[ 6] = -4.0f; m4f[10] =  1.0f; m4f[14] = 3.0f; 
    m4f[ 3] =  1.0f; m4f[ 7] =  2.0f; m4f[11] =  3.0f; m4f[15] = 1.0f; 

    result = jship::Hazmat::Determinant(m4f);
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], -3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], -4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], -2.0, 1e-5);
    DOUBLES_EQUAL(m4f[10],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[11],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[12],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[13],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[14],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[15],  1.0, 1e-5);

    DOUBLES_EQUAL(result, -71.0, 1e-5);
}

}
