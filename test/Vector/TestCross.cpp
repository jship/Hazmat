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

#include <Hazmat/Math/Vector/Cross.h>

struct CrossTestData
{
    Vector3f u3f, v3f, w3f;
    Vector4f u4f, v4f, w4f;
};

DEFINE_TEST_TYPES(CrossTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Cross (3D vectors)");

    jship::Hazmat::Cross(u3f, v3f, w3f);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 0.0, 1e-5);

    u3f[X] = 1.0f; v3f[X] = 0.0f;
    u3f[Y] = 0.0f; v3f[Y] = 1.0f;
    u3f[Z] = 0.0f; v3f[Z] = 0.0f;
    
    jship::Hazmat::Cross(u3f, v3f, w3f);

    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 1.0, 1e-5);

    u3f[X] =    18.7f; v3f[X] = -41.5f;
    u3f[Y] = -103.25f; v3f[Y] = -14.4f;
    u3f[Z] =    9.63f; v3f[Z] = 42.42f;
    
    jship::Hazmat::Cross(u3f, v3f, w3f);

    DOUBLES_EQUAL(u3f[X],    18.7  , 1e-1);
    DOUBLES_EQUAL(u3f[Y],  -103.25 , 1e-1);
    DOUBLES_EQUAL(u3f[Z],     9.63 , 1e-1);
    DOUBLES_EQUAL(v3f[X],   -41.5  , 1e-1);
    DOUBLES_EQUAL(v3f[Y],   -14.4  , 1e-1);
    DOUBLES_EQUAL(v3f[Z],    42.42 , 1e-1);
    DOUBLES_EQUAL(w3f[X], -4241.19 , 1e-1);
    DOUBLES_EQUAL(w3f[Y], -1192.9  , 1e-1);
    DOUBLES_EQUAL(w3f[Z], -4554.16 , 1e-1);
    
    jship::Hazmat::Cross(u3f, u3f, u3f);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Cross (4D vectors)");
    
    jship::Hazmat::Cross(u4f, v4f, w4f);
    
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

    u4f[X] = 1.0f; v4f[X] = 0.0f;
    u4f[Y] = 0.0f; v4f[Y] = 1.0f;
    u4f[Z] = 0.0f; v4f[Z] = 0.0f;
    u4f[W] = 0.0f; v4f[W] = 0.0f;
    
    jship::Hazmat::Cross(u4f, v4f, w4f);

    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(w4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w4f[Z], 1.0, 1e-5);
    DOUBLES_EQUAL(w4f[W], 0.0, 1e-5);

    u4f[X] =    18.7f; v4f[X] = -41.5f;
    u4f[Y] = -103.25f; v4f[Y] = -14.4f;
    u4f[Z] =    9.63f; v4f[Z] = 42.42f;
    u4f[W] =    1.23f; v4f[W] =  4.56f;
    
    jship::Hazmat::Cross(u4f, v4f, w4f);

    DOUBLES_EQUAL(u4f[X],    18.7  , 1e-1);
    DOUBLES_EQUAL(u4f[Y],  -103.25 , 1e-1);
    DOUBLES_EQUAL(u4f[Z],     9.63 , 1e-1);
    DOUBLES_EQUAL(u4f[W],     1.23 , 1e-1);
    DOUBLES_EQUAL(v4f[X],   -41.5  , 1e-1);
    DOUBLES_EQUAL(v4f[Y],   -14.4  , 1e-1);
    DOUBLES_EQUAL(v4f[Z],    42.42 , 1e-1);
    DOUBLES_EQUAL(v4f[W],     4.56 , 1e-1);
    DOUBLES_EQUAL(w4f[X], -4241.19 , 1e-1);
    DOUBLES_EQUAL(w4f[Y], -1192.9  , 1e-1);
    DOUBLES_EQUAL(w4f[Z], -4554.16 , 1e-1);
    DOUBLES_EQUAL(w4f[W],      0.0 , 1e-5);
    
    jship::Hazmat::Cross(u4f, u4f, u4f);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
}

}
