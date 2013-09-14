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

#include <Hazmat/Math/Vector/Dot.h>

struct DotTestData
{
    Vector2f u2f, v2f;
    Vector3f u3f, v3f;
    Vector4f u4f, v4f;
};

DEFINE_TEST_TYPES(DotTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Dot (2D vectors)");
    
    float result = jship::Hazmat::Dot(u2f, v2f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    u2f[X] = 1.0f; v2f[X] = 0.0f;
    u2f[Y] = 0.0f; v2f[Y] = 1.0f;
    
    result = jship::Hazmat::Dot(u2f, v2f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 1.0, 1e-5);
    
    u2f[X] = 1.0f; v2f[X] = 3.0f;
    u2f[Y] = 2.0f; v2f[Y] = 4.0f;
    
    result = jship::Hazmat::Dot(u2f, v2f);
    DOUBLES_EQUAL(result, 11.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 3.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 4.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Dot (3D vectors)");
    
    float result = jship::Hazmat::Dot(u3f, v3f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    u3f[X] = 1.0f; v3f[X] = 0.0f;
    u3f[Y] = 0.0f; v3f[Y] = 1.0f;
    u3f[Z] = 0.0f; v3f[Z] = 0.0f;
    
    result = jship::Hazmat::Dot(u3f, v3f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);
    
    u3f[X] = 1.0f; v3f[X] = 4.0f;
    u3f[Y] = 2.0f; v3f[Y] = 5.0f;
    u3f[Z] = 3.0f; v3f[Z] = 6.0f;
    
    result = jship::Hazmat::Dot(u3f, v3f);
    DOUBLES_EQUAL(result, 32.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 3.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 4.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 5.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 6.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Dot (4D vectors)");
    
    float result = jship::Hazmat::Dot(u4f, v4f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);

    u4f[X] = 1.0f; v4f[X] = 0.0f;
    u4f[Y] = 0.0f; v4f[Y] = 1.0f;
    u4f[Z] = 0.0f; v4f[Z] = 0.0f;
    u4f[W] = 0.0f; v4f[W] = 0.0f;
    
    result = jship::Hazmat::Dot(u4f, v4f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);
    
    u4f[X] = 1.0f; v4f[X] = 5.0f;
    u4f[Y] = 2.0f; v4f[Y] = 6.0f;
    u4f[Z] = 3.0f; v4f[Z] = 7.0f;
    u4f[W] = 4.0f; v4f[W] = 8.0f;
    
    result = jship::Hazmat::Dot(u4f, v4f);
    DOUBLES_EQUAL(result, 70.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 3.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 4.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 5.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 6.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 7.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 8.0, 1e-5);
}

}
