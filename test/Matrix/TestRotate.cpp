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

#include <Hazmat/Math/Matrix/Rotate.h>

struct RotateMatrixTestData
{
    Matrix4f a4f, b4f;

    Vector3f axis;
    
    float degrees;
    float radians;
    float c;
    float s;
    float d; // 1 - c
    float x;
    float y;
    float z;
};

DEFINE_TEST_TYPES(RotateMatrixTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Rotate (4x4 matrix)");

    a4f[ 0] = 2.0f; a4f[ 4] = 6.0f; a4f[ 8] = 10.0f; a4f[12] = 14.0f;
    a4f[ 1] = 3.0f; a4f[ 5] = 7.0f; a4f[ 9] = 11.0f; a4f[13] = 15.0f;
    a4f[ 2] = 4.0f; a4f[ 6] = 8.0f; a4f[10] = 12.0f; a4f[14] = 16.0f;
    a4f[ 3] = 5.0f; a4f[ 7] = 9.0f; a4f[11] = 13.0f; a4f[15] = 17.0f;

    degrees = 123.4f;
    radians = toRadians(degrees);
    c       = std::cos(radians);
    s       = std::sin(radians);
    d       = 1 - c;

    // {1, 2, 3}, normalized.
    x       = 1.0f / std::sqrt(14.0f);
    y       = 2.0f / std::sqrt(14.0f);
    z       = 3.0f / std::sqrt(14.0f);

    axis[X] = x;
    axis[Y] = y;
    axis[Z] = z;

    jship::Hazmat::Rotate(a4f, radians, axis, b4f);
    
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

    // This is ugly as sin...
    DOUBLES_EQUAL(b4f[ 0], 2.0f*(d*x*x+c)+3.0f*(d*x*y-s*z)+4.0f*(s*y+d*x*z),1e-5);
    DOUBLES_EQUAL(b4f[ 1], 3.0f*(d*y*y+c)+2.0f*(d*x*y+s*z)+4.0f*(d*y*z-s*x),1e-5);
    DOUBLES_EQUAL(b4f[ 2], 2.0f*(d*x*z-s*y)+3.0f*(s*x+d*y*z)+4.0f*(d*z*z+c),1e-5);
    DOUBLES_EQUAL(b4f[ 3], 5.0f,1e-5);
    DOUBLES_EQUAL(b4f[ 4], 6.0f*(d*x*x+c)+7.0f*(d*x*y-s*z)+8.0f*(s*y+d*x*z),1e-5);
    DOUBLES_EQUAL(b4f[ 5], 7.0f*(d*y*y+c)+6.0f*(d*x*y+s*z)+8.0f*(d*y*z-s*x),1e-5);
    DOUBLES_EQUAL(b4f[ 6], 6.0f*(d*x*z-s*y)+7.0f*(s*x+d*y*z)+8.0f*(d*z*z+c),1e-5);
    DOUBLES_EQUAL(b4f[ 7], 9.0f,1e-5);
    DOUBLES_EQUAL(b4f[ 8], 10.0f*(d*x*x+c)+11.0f*(d*x*y-s*z)+12.0f*(s*y+d*x*z),1e-5);
    DOUBLES_EQUAL(b4f[ 9], 11.0f*(d*y*y+c)+10.0f*(d*x*y+s*z)+12.0f*(d*y*z-s*x),1e-5);
    DOUBLES_EQUAL(b4f[10], 10.0f*(d*x*z-s*y)+11.0f*(s*x+d*y*z)+12.0f*(d*z*z+c),1e-5);
    DOUBLES_EQUAL(b4f[11], 13.0f,1e-5);
    DOUBLES_EQUAL(b4f[12], 14.0f*(d*x*x+c)+15.0f*(d*x*y-s*z)+16.0f*(s*y+d*x*z),1e-5);
    DOUBLES_EQUAL(b4f[13], 15.0f*(d*y*y+c)+14.0f*(d*x*y+s*z)+16.0f*(d*y*z-s*x),1e-5);
    DOUBLES_EQUAL(b4f[14], 14.0f*(d*x*z-s*y)+15.0f*(s*x+d*y*z)+16.0f*(d*z*z+c),1e-5);
    DOUBLES_EQUAL(b4f[15], 17.0f,1e-5);

    jship::Hazmat::Rotate(a4f, radians, axis, a4f);
    
    DOUBLES_EQUAL(a4f[ 0], b4f[ 0], 1e-5);
    DOUBLES_EQUAL(a4f[ 1], b4f[ 1], 1e-5);
    DOUBLES_EQUAL(a4f[ 2], b4f[ 2], 1e-5);
    DOUBLES_EQUAL(a4f[ 3], b4f[ 3], 1e-5);
    DOUBLES_EQUAL(a4f[ 4], b4f[ 4], 1e-5);
    DOUBLES_EQUAL(a4f[ 5], b4f[ 5], 1e-5);
    DOUBLES_EQUAL(a4f[ 6], b4f[ 6], 1e-5);
    DOUBLES_EQUAL(a4f[ 7], b4f[ 7], 1e-5);
    DOUBLES_EQUAL(a4f[ 8], b4f[ 8], 1e-5);
    DOUBLES_EQUAL(a4f[ 9], b4f[ 9], 1e-5);
    DOUBLES_EQUAL(a4f[10], b4f[10], 1e-5);
    DOUBLES_EQUAL(a4f[11], b4f[11], 1e-5);
    DOUBLES_EQUAL(a4f[12], b4f[12], 1e-5);
    DOUBLES_EQUAL(a4f[13], b4f[13], 1e-5);
    DOUBLES_EQUAL(a4f[14], b4f[14], 1e-5);
    DOUBLES_EQUAL(a4f[15], b4f[15], 1e-5);
}

}
