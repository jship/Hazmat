#include "Common.h"

#include <Hazmat/Math/Vector/Set.h>

struct SetTestData
{
    Vector2f u2f;
    Vector3f u3f;
    Vector4f u4f;
};

DEFINE_TEST_TYPES(SetTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Set (2D vector)");
    
    jship::Hazmat::Set(1.0f, -2.0f, u2f);

    DOUBLES_EQUAL(u2f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], -2.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Set (3D vector)");
    
    jship::Hazmat::Set(1.0f, -2.0f, 3.0f, u3f);

    DOUBLES_EQUAL(u3f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], -2.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  3.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Set (4D vector)");
    
    jship::Hazmat::Set(1.0f, -2.0f, 3.0f, -4.0f, u4f);

    DOUBLES_EQUAL(u4f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], -2.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  3.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], -4.0, 1e-5);
}

}
