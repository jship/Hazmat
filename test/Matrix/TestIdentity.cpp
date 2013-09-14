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

#include <Hazmat/Math/Matrix/Identity.h>

struct IdentityTestData
{
    Matrix2f m2f;
    Matrix3f m3f;
    Matrix4f m4f;
};

DEFINE_TEST_TYPES(IdentityTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Identity (2x2 matrix)");

    m2f[0] = 0.0f; m2f[2] = 2.0f;
    m2f[1] = 1.0f; m2f[3] = 3.0f;

    jship::Hazmat::Identity(m2f);
    
    DOUBLES_EQUAL(m2f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(m2f[1], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[2], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[3], 1.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Identity (3x3 matrix)");

    m3f[0] = 0.0f; m3f[3] = 3.0f; m3f[6] = 6.0f;
    m3f[1] = 1.0f; m3f[4] = 4.0f; m3f[7] = 7.0f;
    m3f[2] = 2.0f; m3f[5] = 5.0f; m3f[8] = 8.0f;

    jship::Hazmat::Identity(m3f);
    
    DOUBLES_EQUAL(m3f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(m3f[1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[4], 1.0, 1e-5);
    DOUBLES_EQUAL(m3f[5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[8], 1.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Identity (4x4 matrix)");

    m4f[ 0] = 0.0f; m4f[ 4] = 4.0f; m4f[ 8] =  8.0f; m4f[12] = 12.0f; 
    m4f[ 1] = 1.0f; m4f[ 5] = 5.0f; m4f[ 9] =  9.0f; m4f[13] = 13.0f; 
    m4f[ 2] = 2.0f; m4f[ 6] = 6.0f; m4f[10] = 10.0f; m4f[14] = 14.0f; 
    m4f[ 3] = 3.0f; m4f[ 7] = 7.0f; m4f[11] = 11.0f; m4f[15] = 15.0f; 

    jship::Hazmat::Identity(m4f);
    
    DOUBLES_EQUAL(m4f[ 0], 1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 1.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 1.0, 1e-5);
}

}
