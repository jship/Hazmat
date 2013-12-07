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

#include <Hazmat/Math/Quaternion/Dot.h>

struct QuatDotTestData
{
    Quaternion4f p4f, q4f;
};

DEFINE_TEST_TYPES(QuatDotTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Dot (Quaternions)");
    
    float result = jship::Hazmat::Dot(p4f, q4f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(p4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(p4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(p4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(p4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(q4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(q4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(q4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(q4f[W], 0.0, 1e-5);

    p4f[X] = 1.0f; q4f[X] = 0.0f;
    p4f[Y] = 0.0f; q4f[Y] = 1.0f;
    p4f[Z] = 0.0f; q4f[Z] = 0.0f;
    p4f[W] = 0.0f; q4f[W] = 0.0f;
    
    result = jship::Hazmat::Dot(p4f, q4f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(p4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(p4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(p4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(p4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(q4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(q4f[Y], 1.0, 1e-5);
    DOUBLES_EQUAL(q4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(q4f[W], 0.0, 1e-5);
    
    p4f[X] = 1.0f; q4f[X] = 5.0f;
    p4f[Y] = 2.0f; q4f[Y] = 6.0f;
    p4f[Z] = 3.0f; q4f[Z] = 7.0f;
    p4f[W] = 4.0f; q4f[W] = 8.0f;
    
    result = jship::Hazmat::Dot(p4f, q4f);
    DOUBLES_EQUAL(result, 70.0, 1e-5);

    DOUBLES_EQUAL(p4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(p4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(p4f[Z], 3.0, 1e-5);
    DOUBLES_EQUAL(p4f[W], 4.0, 1e-5);
    DOUBLES_EQUAL(q4f[X], 5.0, 1e-5);
    DOUBLES_EQUAL(q4f[Y], 6.0, 1e-5);
    DOUBLES_EQUAL(q4f[Z], 7.0, 1e-5);
    DOUBLES_EQUAL(q4f[W], 8.0, 1e-5);
}

}
