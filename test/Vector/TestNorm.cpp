#include "Common.h"

#include <Hazmat/Math/Vector/Norm.h>

struct NormTestData
{
    Vector2f u2f, v2f;
    Vector3f u3f, v3f;
    Vector4f u4f, v4f;
};

DEFINE_TEST_TYPES(NormTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Norm (2D vectors)");
    
    jship::Hazmat::Norm(u2f, v2f);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    u2f[X] = -5.0f;
    u2f[Y] = 12.0f;
    
    jship::Hazmat::Norm(u2f, v2f);
    
    DOUBLES_EQUAL(u2f[X], -5.0,        1e-5);
    DOUBLES_EQUAL(u2f[Y], 12.0,        1e-5);
    DOUBLES_EQUAL(v2f[X], -5.0 / 13.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 12.0 / 13.0, 1e-5);
    
    jship::Hazmat::Norm(u2f, u2f);
    
    DOUBLES_EQUAL(u2f[X], -5.0 / 13.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 12.0 / 13.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Norm (3D vectors)");
    
    jship::Hazmat::Norm(u3f, v3f);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    u3f[X] = -6.0f;
    u3f[Y] =  6.0f;
    u3f[Z] = -7.0f;
    
    jship::Hazmat::Norm(u3f, v3f);
    
    DOUBLES_EQUAL(u3f[X], -6.0,        1e-5);
    DOUBLES_EQUAL(u3f[Y],  6.0,        1e-5);
    DOUBLES_EQUAL(u3f[Z], -7.0,        1e-5);
    DOUBLES_EQUAL(v3f[X], -6.0 / 11.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y],  6.0 / 11.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], -7.0 / 11.0, 1e-5);
    
    jship::Hazmat::Norm(u3f, u3f);
    
    DOUBLES_EQUAL(u3f[X], -6.0 / 11.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  6.0 / 11.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], -7.0 / 11.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Norm (4D vectors)");
    
    jship::Hazmat::Norm(u4f, v4f);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);

    u4f[X] =  1.0f;
    u4f[Y] = -7.0f;
    u4f[Z] =  7.0f;
    u4f[W] = -1.0f;
    
    jship::Hazmat::Norm(u4f, v4f);
    
    DOUBLES_EQUAL(u4f[X],  1.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], -7.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  7.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], -1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X],  0.1, 1e-5);
    DOUBLES_EQUAL(v4f[Y], -0.7, 1e-5);
    DOUBLES_EQUAL(v4f[Z],  0.7, 1e-5);
    DOUBLES_EQUAL(v4f[W], -0.1, 1e-5);
    
    jship::Hazmat::Norm(u4f, u4f);
    
    DOUBLES_EQUAL(u4f[X],  0.1, 1e-5);
    DOUBLES_EQUAL(u4f[Y], -0.7, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  0.7, 1e-5);
    DOUBLES_EQUAL(u4f[W], -0.1, 1e-5);
}

}
