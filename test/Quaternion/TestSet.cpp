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

#include <Hazmat/Math/Quaternion/Set.h>

struct QuatSetTestData
{
    Quaternion4f p4f;
};

DEFINE_TEST_TYPES(QuatSetTestData);

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

    set_test_name("Set (Quaternion)");
    
    jship::Hazmat::Set(1.0f, -2.0f, 3.0f, -4.0f, p4f);

    DOUBLES_EQUAL(p4f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(p4f[Y], -2.0, 1e-5);
    DOUBLES_EQUAL(p4f[Z],  3.0, 1e-5);
    DOUBLES_EQUAL(p4f[W], -4.0, 1e-5);
}

}
