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

#include <Hazmat/Math/Matrix/RotateAboutZ.h>

struct RotateAboutZTestData
{
    Matrix2f a2f, b2f;
    Matrix3f a3f, b3f;
    Matrix4f a4f, b4f;
    
    float degrees;
    float radians;
    float c;
    float s;
};

DEFINE_TEST_TYPES(RotateAboutZTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("RotateAboutZ (2x2 matrix)");

    a2f[0] = 2.0f; a2f[2] = 4.0f;
    a2f[1] = 3.0f; a2f[3] = 5.0f;
    
    degrees = 123.4f;
    radians = toRadians(degrees);
    c       = std::cos(radians);
    s       = std::sin(radians);

    jship::Hazmat::RotateAboutZ(a2f, radians, b2f);
    
    DOUBLES_EQUAL(a2f[ 0],  2.0, 1e-5);
    DOUBLES_EQUAL(a2f[ 1],  3.0, 1e-5);
    DOUBLES_EQUAL(a2f[ 2],  4.0, 1e-5);
    DOUBLES_EQUAL(a2f[ 3],  5.0, 1e-5);
   
    DOUBLES_EQUAL(b2f[ 0], 2.0f * c - 3.0f * s, 1e-5);
    DOUBLES_EQUAL(b2f[ 1], 3.0f * c + 2.0f * s, 1e-5);
    DOUBLES_EQUAL(b2f[ 2], 4.0f * c - 5.0f * s, 1e-5);
    DOUBLES_EQUAL(b2f[ 3], 5.0f * c + 4.0f * s, 1e-5);
    
    jship::Hazmat::RotateAboutZ(a2f, radians, a2f);
    
    DOUBLES_EQUAL(a2f[ 0], 2.0f * c - 3.0f * s, 1e-5);
    DOUBLES_EQUAL(a2f[ 1], 3.0f * c + 2.0f * s, 1e-5);
    DOUBLES_EQUAL(a2f[ 2], 4.0f * c - 5.0f * s, 1e-5);
    DOUBLES_EQUAL(a2f[ 3], 5.0f * c + 4.0f * s, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    set_test_name("RotateAboutZ (3x3 matrix)");

    a3f[0] = 2.0f; a3f[3] = 5.0f; a3f[6] =  8.0f;
    a3f[1] = 3.0f; a3f[4] = 6.0f; a3f[7] =  9.0f;
    a3f[2] = 4.0f; a3f[5] = 7.0f; a3f[8] = 10.0f;
    
    degrees = 123.4f;
    radians = toRadians(degrees);
    c       = std::cos(radians);
    s       = std::sin(radians);

    jship::Hazmat::RotateAboutZ(a3f, radians, b3f);
    
    DOUBLES_EQUAL(a3f[ 0],  2.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 1],  3.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 2],  4.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 3],  5.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 4],  6.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 5],  7.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 6],  8.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 7],  9.0, 1e-5);
    DOUBLES_EQUAL(a3f[ 8], 10.0, 1e-5);
   
    DOUBLES_EQUAL(b3f[ 0],  2.0f * c -  3.0f * s, 1e-5);
    DOUBLES_EQUAL(b3f[ 1],  3.0f * c +  2.0f * s, 1e-5);
    DOUBLES_EQUAL(b3f[ 2],                  4.0f, 1e-5);
    DOUBLES_EQUAL(b3f[ 3],  5.0f * c -  6.0f * s, 1e-5);
    DOUBLES_EQUAL(b3f[ 4],  6.0f * c +  5.0f * s, 1e-5);
    DOUBLES_EQUAL(b3f[ 5],                  7.0f, 1e-5);
    DOUBLES_EQUAL(b3f[ 6],  8.0f * c -  9.0f * s, 1e-5);
    DOUBLES_EQUAL(b3f[ 7],  9.0f * c +  8.0f * s, 1e-5);
    DOUBLES_EQUAL(b3f[ 8],                 10.0f, 1e-5);
    
    jship::Hazmat::RotateAboutZ(a3f, radians, a3f);
    
    DOUBLES_EQUAL(a3f[ 0],  2.0f * c -  3.0f * s, 1e-5);
    DOUBLES_EQUAL(a3f[ 1],  3.0f * c +  2.0f * s, 1e-5);
    DOUBLES_EQUAL(a3f[ 2],                  4.0f, 1e-5);
    DOUBLES_EQUAL(a3f[ 3],  5.0f * c -  6.0f * s, 1e-5);
    DOUBLES_EQUAL(a3f[ 4],  6.0f * c +  5.0f * s, 1e-5);
    DOUBLES_EQUAL(a3f[ 5],                  7.0f, 1e-5);
    DOUBLES_EQUAL(a3f[ 6],  8.0f * c -  9.0f * s, 1e-5);
    DOUBLES_EQUAL(a3f[ 7],  9.0f * c +  8.0f * s, 1e-5);
    DOUBLES_EQUAL(a3f[ 8],                 10.0f, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    set_test_name("RotateAboutZ (4x4 matrix)");

    a4f[ 0] = 2.0f; a4f[ 4] = 6.0f; a4f[ 8] = 10.0f; a4f[12] = 14.0f;
    a4f[ 1] = 3.0f; a4f[ 5] = 7.0f; a4f[ 9] = 11.0f; a4f[13] = 15.0f;
    a4f[ 2] = 4.0f; a4f[ 6] = 8.0f; a4f[10] = 12.0f; a4f[14] = 16.0f;
    a4f[ 3] = 5.0f; a4f[ 7] = 9.0f; a4f[11] = 13.0f; a4f[15] = 17.0f;

    degrees = 123.4f;
    radians = toRadians(degrees);
    c       = std::cos(radians);
    s       = std::sin(radians);

    jship::Hazmat::RotateAboutZ(a4f, radians, b4f);
    
    DOUBLES_EQUAL(a4f[ 0],  2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  3.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2],  4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],  5.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4],  6.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  7.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],  8.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7],  9.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8], 10.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 11.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 12.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 13.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 14.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 15.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 16.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 17.0, 1e-5);
   
    DOUBLES_EQUAL(b4f[ 0],  2.0f * c -  3.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[ 1],  3.0f * c +  2.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[ 2],                  4.0f, 1e-5);
    DOUBLES_EQUAL(b4f[ 3],                  5.0f, 1e-5);
    DOUBLES_EQUAL(b4f[ 4],  6.0f * c -  7.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[ 5],  7.0f * c +  6.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[ 6],                  8.0f, 1e-5);
    DOUBLES_EQUAL(b4f[ 7],                  9.0f, 1e-5);
    DOUBLES_EQUAL(b4f[ 8], 10.0f * c - 11.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[ 9], 11.0f * c + 10.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[10],                 12.0f, 1e-5);
    DOUBLES_EQUAL(b4f[11],                 13.0f, 1e-5);
    DOUBLES_EQUAL(b4f[12], 14.0f * c - 15.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[13], 15.0f * c + 14.0f * s, 1e-5);
    DOUBLES_EQUAL(b4f[14],                 16.0f, 1e-5);
    DOUBLES_EQUAL(b4f[15],                 17.0f, 1e-5);
    
    jship::Hazmat::RotateAboutZ(a4f, radians, a4f);
    
    DOUBLES_EQUAL(a4f[ 0],  2.0f * c -  3.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  3.0f * c +  2.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[ 2],                  4.0f, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],                  5.0f, 1e-5);
    DOUBLES_EQUAL(a4f[ 4],  6.0f * c -  7.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[ 5],  7.0f * c +  6.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[ 6],                  8.0f, 1e-5);
    DOUBLES_EQUAL(a4f[ 7],                  9.0f, 1e-5);
    DOUBLES_EQUAL(a4f[ 8], 10.0f * c - 11.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 11.0f * c + 10.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[10],                 12.0f, 1e-5);
    DOUBLES_EQUAL(a4f[11],                 13.0f, 1e-5);
    DOUBLES_EQUAL(a4f[12], 14.0f * c - 15.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[13], 15.0f * c + 14.0f * s, 1e-5);
    DOUBLES_EQUAL(a4f[14],                 16.0f, 1e-5);
    DOUBLES_EQUAL(a4f[15],                 17.0f, 1e-5);
}

}
