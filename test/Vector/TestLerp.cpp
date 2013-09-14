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

#include <Hazmat/Math/Vector/Lerp.h>

struct LerpTestData
{
    Vector2f u2f, v2f, w2f;
    Vector3f u3f, v3f, w3f;
    Vector4f u4f, v4f, w4f;
};

DEFINE_TEST_TYPES(LerpTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Lerp (2D vectors)");
    
    jship::Hazmat::Lerp(u2f, v2f, 0.5f, w2f);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 0.0, 1e-5);

    u2f[X] = 1.0f; v2f[X] = 2.0f;
    u2f[Y] = 1.0f; v2f[Y] = 2.0f;
    
    jship::Hazmat::Lerp(u2f, v2f, 0.0f, w2f);

    DOUBLES_EQUAL(u2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 1.0, 1e-5);
    
    jship::Hazmat::Lerp(u2f, v2f, 0.25f, w2f);

    DOUBLES_EQUAL(u2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 1.25, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 1.25, 1e-5);
    
    jship::Hazmat::Lerp(u2f, v2f, 0.5f, w2f);

    DOUBLES_EQUAL(u2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 1.5, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 1.5, 1e-5);
    
    jship::Hazmat::Lerp(u2f, v2f, 0.75f, w2f);

    DOUBLES_EQUAL(u2f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  1.0, 1e-5);
    DOUBLES_EQUAL(v2f[X],  2.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y],  2.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 1.75, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 1.75, 1e-5);
    
    jship::Hazmat::Lerp(u2f, v2f, 1.0f, w2f);

    DOUBLES_EQUAL(u2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 2.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Lerp (3D vectors)");
    
    jship::Hazmat::Lerp(u3f, v3f, 0.5f, w3f);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 0.0, 1e-5);

    u3f[X] = 1.0f; v3f[X] = 2.0f;
    u3f[Y] = 1.0f; v3f[Y] = 2.0f;
    u3f[Z] = 1.0f; v3f[Z] = 2.0f;
    
    jship::Hazmat::Lerp(u3f, v3f, 0.0f, w3f);

    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 1.0, 1e-5);
    
    jship::Hazmat::Lerp(u3f, v3f, 0.25f, w3f);

    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 1.25, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 1.25, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 1.25, 1e-5);
    
    jship::Hazmat::Lerp(u3f, v3f, 0.5f, w3f);

    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 1.5, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 1.5, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 1.5, 1e-5);
    
    jship::Hazmat::Lerp(u3f, v3f, 0.75f, w3f);

    DOUBLES_EQUAL(u3f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  1.0, 1e-5);
    DOUBLES_EQUAL(v3f[X],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 1.75, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 1.75, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 1.75, 1e-5);
    
    jship::Hazmat::Lerp(u3f, v3f, 1.0f, w3f);

    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 2.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Lerp (4D vectors)");
    
    jship::Hazmat::Lerp(u4f, v4f, 0.5f, w4f);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(w4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(w4f[W], 0.0, 1e-5);

    u4f[X] = 1.0f; v4f[X] = 2.0f;
    u4f[Y] = 1.0f; v4f[Y] = 2.0f;
    u4f[Z] = 1.0f; v4f[Z] = 2.0f;
    u4f[W] = 1.0f; v4f[W] = 2.0f;
    
    jship::Hazmat::Lerp(u4f, v4f, 0.0f, w4f);

    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 2.0, 1e-5);
    DOUBLES_EQUAL(w4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(w4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(w4f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(w4f[W], 1.0, 1e-5);
    
    jship::Hazmat::Lerp(u4f, v4f, 0.25f, w4f);

    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 2.0, 1e-5);
    DOUBLES_EQUAL(w4f[X], 1.25, 1e-5);
    DOUBLES_EQUAL(w4f[Y], 1.25, 1e-5);
    DOUBLES_EQUAL(w4f[Z], 1.25, 1e-5);
    DOUBLES_EQUAL(w4f[W], 1.25, 1e-5);
    
    jship::Hazmat::Lerp(u4f, v4f, 0.5f, w4f);

    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 2.0, 1e-5);
    DOUBLES_EQUAL(w4f[X], 1.5, 1e-5);
    DOUBLES_EQUAL(w4f[Y], 1.5, 1e-5);
    DOUBLES_EQUAL(w4f[Z], 1.5, 1e-5);
    DOUBLES_EQUAL(w4f[W], 1.5, 1e-5);
    
    jship::Hazmat::Lerp(u4f, v4f, 0.75f, w4f);

    DOUBLES_EQUAL(u4f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],  1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  1.0, 1e-5);
    DOUBLES_EQUAL(u4f[W],  1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X],  2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y],  2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(v4f[W],  2.0, 1e-5);
    DOUBLES_EQUAL(w4f[X], 1.75, 1e-5);
    DOUBLES_EQUAL(w4f[Y], 1.75, 1e-5);
    DOUBLES_EQUAL(w4f[Z], 1.75, 1e-5);
    DOUBLES_EQUAL(w4f[W], 1.75, 1e-5);
    
    jship::Hazmat::Lerp(u4f, v4f, 1.0f, w4f);

    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 2.0, 1e-5);
    DOUBLES_EQUAL(w4f[X], 2.0, 1e-5);
    DOUBLES_EQUAL(w4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(w4f[Z], 2.0, 1e-5);
    DOUBLES_EQUAL(w4f[W], 2.0, 1e-5);
}

}
