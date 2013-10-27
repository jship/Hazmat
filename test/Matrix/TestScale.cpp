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

#include <Hazmat/Math/Matrix/Scale.h>

struct ScaleMatrixTestData
{
    Matrix2f a2f, b2f;
    Matrix3f a3f, b3f;
    Matrix4f a4f, b4f;
    
    Vector2f u2f;
    Vector3f u3f;
    Vector4f u4f;
};

DEFINE_TEST_TYPES(ScaleMatrixTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    
    set_test_name("Scale (2x2 matrix)");

    a2f[0] = 1.0f; a2f[2] = 3.0f;
    a2f[1] = 2.0f; a2f[3] = 4.0f;

    u2f[X] = 2.0f;
    u2f[Y] = 3.0f;

    jship::Hazmat::Scale(a2f, u2f, b2f);
    
    DOUBLES_EQUAL(a2f[0],  1.0, 1e-5);
    DOUBLES_EQUAL(a2f[1],  2.0, 1e-5);
    DOUBLES_EQUAL(a2f[2],  3.0, 1e-5);
    DOUBLES_EQUAL(a2f[3],  4.0, 1e-5);
    
    DOUBLES_EQUAL(b2f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(b2f[1],  6.0, 1e-5);
    DOUBLES_EQUAL(b2f[2],  6.0, 1e-5);
    DOUBLES_EQUAL(b2f[3], 12.0, 1e-5);
    
    jship::Hazmat::Scale(a2f, u2f, a2f);
    
    DOUBLES_EQUAL(a2f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(a2f[1],  6.0, 1e-5);
    DOUBLES_EQUAL(a2f[2],  6.0, 1e-5);
    DOUBLES_EQUAL(a2f[3], 12.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    
    set_test_name("Scale (3x3 matrix)");

    a3f[0] = 1.0f; a3f[3] = 4.0f; a3f[6] = 7.0f;
    a3f[1] = 2.0f; a3f[4] = 5.0f; a3f[7] = 8.0f;
    a3f[2] = 3.0f; a3f[5] = 6.0f; a3f[8] = 9.0f;

    u2f[X] = 2.0f;
    u2f[Y] = 3.0f;

    jship::Hazmat::Scale(a3f, u2f, b3f);
    
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
    DOUBLES_EQUAL(b3f[1],  6.0, 1e-5);
    DOUBLES_EQUAL(b3f[2],  3.0, 1e-5);
    DOUBLES_EQUAL(b3f[3],  8.0, 1e-5);
    DOUBLES_EQUAL(b3f[4], 15.0, 1e-5);
    DOUBLES_EQUAL(b3f[5],  6.0, 1e-5);
    DOUBLES_EQUAL(b3f[6], 14.0, 1e-5);
    DOUBLES_EQUAL(b3f[7], 24.0, 1e-5);
    DOUBLES_EQUAL(b3f[8],  9.0, 1e-5);
    
    jship::Hazmat::Scale(a3f, u2f, a3f);
    
    DOUBLES_EQUAL(a3f[0],  2.0, 1e-5);
    DOUBLES_EQUAL(a3f[1],  6.0, 1e-5);
    DOUBLES_EQUAL(a3f[2],  3.0, 1e-5);
    DOUBLES_EQUAL(a3f[3],  8.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 15.0, 1e-5);
    DOUBLES_EQUAL(a3f[5],  6.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 14.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 24.0, 1e-5);
    DOUBLES_EQUAL(a3f[8],  9.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    
    set_test_name("Scale (4x4 matrix)");

    a4f[ 0] = 1.0f; a4f[ 4] = 5.0f; a4f[ 8] =  9.0f; a4f[12] = 13.0f;
    a4f[ 1] = 2.0f; a4f[ 5] = 6.0f; a4f[ 9] = 10.0f; a4f[13] = 14.0f;
    a4f[ 2] = 3.0f; a4f[ 6] = 7.0f; a4f[10] = 11.0f; a4f[14] = 15.0f;
    a4f[ 3] = 4.0f; a4f[ 7] = 8.0f; a4f[11] = 12.0f; a4f[15] = 16.0f;

    u3f[X] = 2.0f;
    u3f[Y] = 3.0f;
    u3f[Z] = 4.0f;

    jship::Hazmat::Scale(a4f, u3f, b4f);
    
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
    DOUBLES_EQUAL(b4f[ 1],  6.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 2], 12.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 4], 10.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 5], 18.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 6], 28.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 8], 18.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 9], 30.0, 1e-5);
    DOUBLES_EQUAL(b4f[10], 44.0, 1e-5);
    DOUBLES_EQUAL(b4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(b4f[12], 26.0, 1e-5);
    DOUBLES_EQUAL(b4f[13], 42.0, 1e-5);
    DOUBLES_EQUAL(b4f[14], 60.0, 1e-5);
    DOUBLES_EQUAL(b4f[15], 16.0, 1e-5);
    
    jship::Hazmat::Scale(a4f, u3f, a4f);
    
    DOUBLES_EQUAL(a4f[ 0],  2.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1],  6.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2], 12.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4], 10.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5], 18.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6], 28.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8], 18.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 30.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 44.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 26.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 42.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 60.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 16.0, 1e-5);
}

}
