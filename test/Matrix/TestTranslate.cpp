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

#include <Hazmat/Math/Matrix/Translate.h>

struct TranslateTestData
{
    Matrix3f a3f, b3f;
    Matrix4f a4f, b4f;
    
    Vector2f u2f;
    Vector3f u3f;
};

DEFINE_TEST_TYPES(TranslateTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    
    set_test_name("Translate (3x3 matrix)");

    a3f[0] = 1.0f; a3f[3] = 0.0f; a3f[6] = 0.0f;
    a3f[1] = 0.0f; a3f[4] = 1.0f; a3f[7] = 0.0f;
    a3f[2] = 0.0f; a3f[5] = 0.0f; a3f[8] = 1.0f;
    
    u2f[X] = 1.0f;
    u2f[Y] = 2.0f;
    
    jship::Hazmat::Translate(a3f, u2f, b3f);
    
    DOUBLES_EQUAL(a3f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[2], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[3], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[8], 1.0, 1e-5);
    
    DOUBLES_EQUAL(b3f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(b3f[1], 0.0, 1e-5);
    DOUBLES_EQUAL(b3f[2], 0.0, 1e-5);
    DOUBLES_EQUAL(b3f[3], 0.0, 1e-5);
    DOUBLES_EQUAL(b3f[4], 1.0, 1e-5);
    DOUBLES_EQUAL(b3f[5], 0.0, 1e-5);
    DOUBLES_EQUAL(b3f[6], 1.0, 1e-5);
    DOUBLES_EQUAL(b3f[7], 2.0, 1e-5);
    DOUBLES_EQUAL(b3f[8], 1.0, 1e-5);
    
    jship::Hazmat::Translate(a3f, u2f, a3f);
    
    DOUBLES_EQUAL(a3f[0], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[1], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[2], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[3], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[4], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[5], 0.0, 1e-5);
    DOUBLES_EQUAL(a3f[6], 1.0, 1e-5);
    DOUBLES_EQUAL(a3f[7], 2.0, 1e-5);
    DOUBLES_EQUAL(a3f[8], 1.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    
    set_test_name("Translate (4x4 matrix)");

    a4f[ 0] = 1.0f; a4f[ 4] = 0.0f; a4f[ 8] = 0.0f; a4f[12] = 0.0f;
    a4f[ 1] = 0.0f; a4f[ 5] = 1.0f; a4f[ 9] = 0.0f; a4f[13] = 0.0f;
    a4f[ 2] = 0.0f; a4f[ 6] = 0.0f; a4f[10] = 1.0f; a4f[14] = 0.0f;
    a4f[ 3] = 0.0f; a4f[ 7] = 0.0f; a4f[11] = 0.0f; a4f[15] = 1.0f;

    u3f[X] = 1.0f;
    u3f[Y] = 2.0f;
    u3f[Z] = 3.0f;

    jship::Hazmat::Translate(a4f, u3f, b4f);
    
    DOUBLES_EQUAL(a4f[ 0], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 1.0, 1e-5);
    
    DOUBLES_EQUAL(b4f[ 0], 1.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 5], 1.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[10], 1.0, 1e-5);
    DOUBLES_EQUAL(b4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(b4f[12], 1.0, 1e-5);
    DOUBLES_EQUAL(b4f[13], 2.0, 1e-5);
    DOUBLES_EQUAL(b4f[14], 3.0, 1e-5);
    DOUBLES_EQUAL(b4f[15], 1.0, 1e-5);
    
    jship::Hazmat::Translate(a4f, u3f, a4f);
    
    DOUBLES_EQUAL(a4f[ 0], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 5], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[10], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(a4f[12], 1.0, 1e-5);
    DOUBLES_EQUAL(a4f[13], 2.0, 1e-5);
    DOUBLES_EQUAL(a4f[14], 3.0, 1e-5);
    DOUBLES_EQUAL(a4f[15], 1.0, 1e-5);
}

}
