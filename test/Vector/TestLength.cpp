#include "Common.h"

#include <Hazmat/Math/Vector/Length.h>

struct LengthTestData
{
    Vector2f u2f;
    Vector3f u3f;
    Vector4f u4f;
};

DEFINE_TEST_TYPES(LengthTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Length (2D vector)");
    
    float result = jship::Hazmat::Length(u2f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);

    u2f[X] = 1.0f;
    u2f[Y] = 2.0f;
    
    result = jship::Hazmat::Length(u2f);
    DOUBLES_EQUAL(result, std::sqrt(5.0), 1e-5);
    
    DOUBLES_EQUAL(u2f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 2.0, 1e-5);
    
    u2f[X] = -1.0f;
    u2f[Y] = -2.0f;
    
    result = jship::Hazmat::Length(u2f);
    DOUBLES_EQUAL(result, std::sqrt(5.0), 1e-5);

    DOUBLES_EQUAL(u2f[X], -1.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], -2.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Length (3D vector)");
    
    float result = jship::Hazmat::Length(u3f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);

    u3f[X] = 1.0f;
    u3f[Y] = 2.0f;
    u3f[Z] = 3.0f;
    
    result = jship::Hazmat::Length(u3f);
    DOUBLES_EQUAL(result, std::sqrt(14.0), 1e-5);
    
    DOUBLES_EQUAL(u3f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 3.0, 1e-5);
    
    u3f[X] = -1.0f;
    u3f[Y] = -2.0f;
    u3f[Z] = -3.0f;
    
    result = jship::Hazmat::Length(u3f);
    DOUBLES_EQUAL(result, std::sqrt(14.0), 1e-5);

    DOUBLES_EQUAL(u3f[X], -1.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], -2.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], -3.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Length (4D vector)");
    
    float result = jship::Hazmat::Length(u4f);
    DOUBLES_EQUAL(result, 0.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);

    u4f[X] = 1.0f;
    u4f[Y] = 2.0f;
    u4f[Z] = 3.0f;
    u4f[W] = 4.0f;
    
    result = jship::Hazmat::Length(u4f);
    DOUBLES_EQUAL(result, std::sqrt(30.0), 1e-5);
    
    DOUBLES_EQUAL(u4f[X], 1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 2.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 3.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 4.0, 1e-5);
    
    u4f[X] = -1.0f;
    u4f[Y] = -2.0f;
    u4f[Z] = -3.0f;
    u4f[W] = -4.0f;
    
    result = jship::Hazmat::Length(u4f);
    DOUBLES_EQUAL(result, std::sqrt(30.0), 1e-5);

    DOUBLES_EQUAL(u4f[X], -1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], -2.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], -3.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], -4.0, 1e-5);
}

}
