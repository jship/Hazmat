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

#include <Hazmat/Math/Matrix/Transpose.h>

struct TransposeTestData
{
    Matrix2f a2f, b2f;
    Matrix3f a3f, b3f;
    Matrix4f a4f, b4f;
};

DEFINE_TEST_TYPES(TransposeTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Transpose (2x2 matrix)");

    a2f[0] = 0.0f; a2f[2] = 2.0f;
    a2f[1] = 1.0f; a2f[3] = 3.0f;

    jship::Hazmat::Transpose(a2f, b2f);
    
    DOUBLES_EQUAL(a2f[0],  0.0, 1e-5);
    DOUBLES_EQUAL(a2f[1],  1.0, 1e-5);
    DOUBLES_EQUAL(a2f[2],  2.0, 1e-5);
    DOUBLES_EQUAL(a2f[3],  3.0, 1e-5);
    
    DOUBLES_EQUAL(b2f[0], 0.0, 1e-5);
    DOUBLES_EQUAL(b2f[1], 2.0, 1e-5);
    DOUBLES_EQUAL(b2f[2], 1.0, 1e-5);
    DOUBLES_EQUAL(b2f[3], 3.0, 1e-5);
    
    jship::Hazmat::Transpose(a2f, a2f);
    
    DOUBLES_EQUAL(a2f[0], 0.0, 1e-5);
    DOUBLES_EQUAL(a2f[1], 2.0, 1e-5);
    DOUBLES_EQUAL(a2f[2], 1.0, 1e-5);
    DOUBLES_EQUAL(a2f[3], 3.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("Transpose (3x3 matrix)");

    a3f[0] = 0.0f; a3f[3] = 3.0f; a3f[6] = 6.0f;
    a3f[1] = 1.0f; a3f[4] = 4.0f; a3f[7] = 7.0f;
    a3f[2] = 2.0f; a3f[5] = 5.0f; a3f[8] = 8.0f;

    jship::Hazmat::Transpose(a3f, b3f);
    
    DOUBLES_EQUAL(a3f[0],  0.0, 1e-5);
    DOUBLES_EQUAL(a3f[1],  1.0, 1e-5);
    DOUBLES_EQUAL(a3f[2],  2.0, 1e-5);
    DOUBLES_EQUAL(a3f[3],  3.0, 1e-5);
    DOUBLES_EQUAL(a3f[4],  4.0, 1e-5);
    DOUBLES_EQUAL(a3f[5],  5.0, 1e-5);
    DOUBLES_EQUAL(a3f[6],  6.0, 1e-5);
    DOUBLES_EQUAL(a3f[7],  7.0, 1e-5);
    DOUBLES_EQUAL(a3f[8],  8.0, 1e-5);
    
    DOUBLES_EQUAL(b3f[0], 0.0, 1e-5);
    DOUBLES_EQUAL(b3f[1], 3.0, 1e-5);
    DOUBLES_EQUAL(b3f[2], 6.0, 1e-5);
    DOUBLES_EQUAL(b3f[3], 1.0, 1e-5);
    DOUBLES_EQUAL(b3f[4], 4.0, 1e-5);
    DOUBLES_EQUAL(b3f[5], 7.0, 1e-5);
    DOUBLES_EQUAL(b3f[6], 2.0, 1e-5);
    DOUBLES_EQUAL(b3f[7], 5.0, 1e-5);
    DOUBLES_EQUAL(b3f[8], 8.0, 1e-5);
    
    jship::Hazmat::Transpose(a3f, a3f);
    
    DOUBLES_EQUAL(a3f[0], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], 3.0, 1e-5);
    DOUBLES_EQUAL(a3f[2], 6.0, 1e-5);
    DOUBLES_EQUAL(a3f[3], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 4.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], 7.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 2.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 5.0, 1e-5);
    DOUBLES_EQUAL(a3f[8], 8.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("Transpose (4x4 matrix)");

    a4f[ 0] = 0.0f; a4f[ 4] = 4.0f; a4f[ 8] =  8.0f; a4f[12] = 12.0f; 
    a4f[ 1] = 1.0f; a4f[ 5] = 5.0f; a4f[ 9] =  9.0f; a4f[13] = 13.0f; 
    a4f[ 2] = 2.0f; a4f[ 6] = 6.0f; a4f[10] = 10.0f; a4f[14] = 14.0f; 
    a4f[ 3] = 3.0f; a4f[ 7] = 7.0f; a4f[11] = 11.0f; a4f[15] = 15.0f; 

    jship::Hazmat::Transpose(a4f, b4f);
    
    DOUBLES_EQUAL(a4f[ 0],  0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2],  2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],  3.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4],  4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  5.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],  6.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7],  7.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8],  8.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9],  9.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 10.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 11.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 12.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 13.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 14.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 15.0, 1e-5);
    
    DOUBLES_EQUAL(b4f[ 0],  0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 1],  4.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 2],  8.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 3], 12.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 4],  1.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 5],  5.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 6],  9.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 7], 13.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 8],  2.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 9],  6.0, 1e-5);
    DOUBLES_EQUAL(b4f[10], 10.0, 1e-5);
    DOUBLES_EQUAL(b4f[11], 14.0, 1e-5);
    DOUBLES_EQUAL(b4f[12],  3.0, 1e-5);
    DOUBLES_EQUAL(b4f[13],  7.0, 1e-5);
    DOUBLES_EQUAL(b4f[14], 11.0, 1e-5);
    DOUBLES_EQUAL(b4f[15], 15.0, 1e-5);
    
    jship::Hazmat::Transpose(a4f, a4f);
    
    DOUBLES_EQUAL(a4f[ 0],  0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2],  8.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3], 12.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4],  1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  5.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],  9.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7], 13.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8],  2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9],  6.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 10.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 14.0, 1e-5);
    DOUBLES_EQUAL(a4f[12],  3.0, 1e-5);
    DOUBLES_EQUAL(a4f[13],  7.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 11.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 15.0, 1e-5);
}

}
