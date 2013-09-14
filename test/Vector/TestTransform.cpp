#include "Common.h"

#include <Hazmat/Math/Vector/Transform.h>

struct TransformTestData
{
    Vector2f u2f, v2f;
    Vector3f u3f, v3f;
    Vector4f u4f, v4f;

    Matrix2f m2f;
    Matrix3f m3f;
    Matrix4f m4f;
};

DEFINE_TEST_TYPES(TransformTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Transform (2D vector and 2x2 matrix)");

    jship::Hazmat::Transform(m2f, u2f, v2f);

    DOUBLES_EQUAL(m2f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m2f[ 0] = 1.0f; m2f[ 2] = 3.0f;
    m2f[ 1] = 2.0f; m2f[ 3] = 4.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    jship::Hazmat::Transform(m2f, u2f, v2f);

    DOUBLES_EQUAL(m2f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3],  4.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 13.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 20.0, 1e-5);
    
    jship::Hazmat::Transform(m2f, u2f, u2f);
    
    DOUBLES_EQUAL(m2f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3],  4.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 13.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 20.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator*= (2D vector and 2x2 matrix)");
    
    u2f *= m2f;

    DOUBLES_EQUAL(m2f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);

    m2f[ 0] = 1.0f; m2f[ 2] = 3.0f;
    m2f[ 1] = 2.0f; m2f[ 3] = 4.0f;

    u2f[X] = 4.0f;
    u2f[Y] = 3.0f;
    
    u2f *= m2f;

    DOUBLES_EQUAL(m2f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3],  4.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 13.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 20.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator* (2x2 matrix and 2D vector)");

    v2f = m2f * u2f;

    DOUBLES_EQUAL(m2f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m2f[ 0] = 1.0f; m2f[ 2] = 3.0f;
    m2f[ 1] = 2.0f; m2f[ 3] = 4.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    v2f = m2f * u2f;

    DOUBLES_EQUAL(m2f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3],  4.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 13.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 20.0, 1e-5);
    
    u2f = m2f * u2f;
    
    DOUBLES_EQUAL(m2f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3],  4.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 13.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 20.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<4>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator* (2D vector and 2x2 matrix)");

    v2f = u2f * m2f;

    DOUBLES_EQUAL(m2f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m2f[ 0] = 1.0f; m2f[ 2] = 3.0f;
    m2f[ 1] = 2.0f; m2f[ 3] = 4.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    v2f = u2f * m2f;

    DOUBLES_EQUAL(m2f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3],  4.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 13.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 20.0, 1e-5);
    
    u2f = u2f * m2f;
    
    DOUBLES_EQUAL(m2f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m2f[ 3],  4.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 13.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 20.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<5>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Transform (2D vector and 3x3 matrix)");

    jship::Hazmat::Transform(m3f, u2f, v2f);

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    jship::Hazmat::Transform(m3f, u2f, v2f);

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 23.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 31.0, 1e-5);
    
    jship::Hazmat::Transform(m3f, u2f, u2f);
    
    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 23.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 31.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<6>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator*= (2D vector and 3x3 matrix)");
    
    u2f *= m3f;

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u2f[X] = 4.0f;
    u2f[Y] = 3.0f;
    
    u2f *= m3f;

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 23.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 31.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<7>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator* (3x3 matrix and 2D vector)");

    v2f = m3f * u2f;

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    v2f = m3f * u2f;

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 23.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 31.0, 1e-5);
    
    u2f = m3f * u2f;
    
    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 23.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 31.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<8>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator* (2D vector and 3x3 matrix)");

    v2f = u2f * m3f;

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    v2f = u2f * m3f;

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 23.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 31.0, 1e-5);
    
    u2f = u2f * m3f;
    
    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 23.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 31.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<9>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Transform (3D vector and 3x3 matrix)");

    jship::Hazmat::Transform(m3f, u3f, v3f);

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u3f[X] = 4.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 2.0f; v3f[Z] = -19.6f;
    
    jship::Hazmat::Transform(m3f, u3f, v3f);

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u3f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 30.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 39.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 48.0, 1e-5);
    
    jship::Hazmat::Transform(m3f, u3f, u3f);
    
    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 30.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 39.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 48.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<10>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator*= (3D vector and 3x3 matrix)");
    
    u3f *= m3f;

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u3f[X] = 4.0f;
    u3f[Y] = 3.0f;
    u3f[Z] = 2.0f;
    
    u3f *= m3f;

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 30.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 39.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 48.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<11>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator* (3x3 matrix and 3D vector)");

    v3f = m3f * u3f;

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u3f[X] = 4.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 2.0f; v3f[Z] = -19.6f;
    
    v3f = m3f * u3f;

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u3f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 30.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 39.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 48.0, 1e-5);
    
    u3f = m3f * u3f;
    
    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 30.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 39.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 48.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<12>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator* (3D vector and 3x3 matrix)");

    v3f = u3f * m3f;

    DOUBLES_EQUAL(m3f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    m3f[ 0] = 1.0f; m3f[ 3] = 4.0f; m3f[6] = 7.0f;
    m3f[ 1] = 2.0f; m3f[ 4] = 5.0f; m3f[7] = 8.0f;
    m3f[ 2] = 3.0f; m3f[ 5] = 6.0f; m3f[8] = 9.0f;

    u3f[X] = 4.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 2.0f; v3f[Z] = -19.6f;
    
    v3f = u3f * m3f;

    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u3f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 30.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 39.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 48.0, 1e-5);
    
    u3f = u3f * m3f;
    
    DOUBLES_EQUAL(m3f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m3f[ 8],  9.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 30.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 39.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 48.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<13>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Transform (2D vector and 4x4 matrix)");

    jship::Hazmat::Transform(m4f, u2f, v2f);

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    jship::Hazmat::Transform(m4f, u2f, v2f);

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 32.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 40.0, 1e-5);
    
    jship::Hazmat::Transform(m4f, u2f, u2f);
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 32.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 40.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<14>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator*= (2D vector and 4x4 matrix)");

    u2f *= m4f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u2f[X] = 4.0f;
    u2f[Y] = 3.0f;
    
    u2f *= m4f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 32.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 40.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<15>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator* (4x4 matrix and 2D vector)");

    v2f = m4f * u2f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    v2f = m4f * u2f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 32.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 40.0, 1e-5);
    
    u2f = m4f * u2f;
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 32.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 40.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<16>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator* (2D vector and 4x4 matrix)");

    v2f = u2f * m4f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u2f[X] = 4.0f; v2f[X] =  10.2f;
    u2f[Y] = 3.0f; v2f[Y] =  33.7f;
    
    v2f = u2f * m4f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u2f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 32.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 40.0, 1e-5);
    
    u2f = u2f * m4f;
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u2f[X], 32.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 40.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<17>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Transform (3D vector and 4x4 matrix)");

    jship::Hazmat::Transform(m4f, u3f, v3f);

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u3f[X] = 4.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 2.0f; v3f[Z] = -19.6f;
    
    jship::Hazmat::Transform(m4f, u3f, v3f);

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u3f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 70.0, 1e-5);
    
    jship::Hazmat::Transform(m4f, u3f, u3f);
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 70.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<18>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator*= (3D vector and 4x4 matrix)");

    u3f *= m4f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u3f[X] = 4.0f;
    u3f[Y] = 3.0f;
    u3f[Z] = 2.0f;
    
    u3f *= m4f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 70.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<19>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator* (4x4 matrix and 3D vector)");

    v3f = m4f * u3f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u3f[X] = 4.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 2.0f; v3f[Z] = -19.6f;
    
    v3f = m4f * u3f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u3f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 70.0, 1e-5);
    
    u3f = m4f * u3f;
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 70.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<20>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator* (3D vector and 4x4 matrix)");

    v3f = u3f * m4f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u3f[X] = 4.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 2.0f; v3f[Z] = -19.6f;
    
    v3f = u3f * m4f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u3f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 70.0, 1e-5);
    
    u3f = u3f * m4f;
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u3f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 70.0, 1e-5);
}

// wolfram: {{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16}} . {4,3,2,1}
template <>
template <>
void TestRegistry::test<21>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Transform (4D vector and 4x4 matrix)");

    jship::Hazmat::Transform(m4f, u4f, v4f);

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u4f[X] = 4.0f; v4f[X] =  10.2f;
    u4f[Y] = 3.0f; v4f[Y] =  33.7f;
    u4f[Z] = 2.0f; v4f[Z] = -19.6f;
    u4f[W] = 1.0f; v4f[W] =  99.0f;
    
    jship::Hazmat::Transform(m4f, u4f, v4f);

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u4f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(u4f[W],  1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 70.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 80.0, 1e-5);
    
    jship::Hazmat::Transform(m4f, u4f, u4f);
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 70.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 80.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<22>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("operator*= (4D vector and 4x4 matrix)");

    u4f *= m4f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u4f[X] = 4.0f;
    u4f[Y] = 3.0f;
    u4f[Z] = 2.0f;
    u4f[W] = 1.0f;
    
    u4f *= m4f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 70.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 80.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<23>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("operator* (4x4 matrix and 4D vector)");

    v4f = m4f * u4f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u4f[X] = 4.0f; v4f[X] =  10.2f;
    u4f[Y] = 3.0f; v4f[Y] =  33.7f;
    u4f[Z] = 2.0f; v4f[Z] = -19.6f;
    u4f[W] = 1.0f; v4f[W] =  99.0f;
    
    v4f = m4f * u4f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u4f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(u4f[W],  1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 70.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 80.0, 1e-5);
    
    u4f = m4f * u4f;
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 70.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 80.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<24>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("operator* (4D vector and 4x4 matrix)");

    v4f = u4f * m4f;

    DOUBLES_EQUAL(m4f[ 0], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 0.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 0.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);

    m4f[ 0] = 1.0f; m4f[ 4] = 5.0f; m4f[ 8] =  9.0f; m4f[12] = 13.0f;
    m4f[ 1] = 2.0f; m4f[ 5] = 6.0f; m4f[ 9] = 10.0f; m4f[13] = 14.0f;
    m4f[ 2] = 3.0f; m4f[ 6] = 7.0f; m4f[10] = 11.0f; m4f[14] = 15.0f;
    m4f[ 3] = 4.0f; m4f[ 7] = 8.0f; m4f[11] = 12.0f; m4f[15] = 16.0f;

    u4f[X] = 4.0f; v4f[X] =  10.2f;
    u4f[Y] = 3.0f; v4f[Y] =  33.7f;
    u4f[Z] = 2.0f; v4f[Z] = -19.6f;
    u4f[W] = 1.0f; v4f[W] =  99.0f;
    
    v4f = u4f * m4f;

    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u4f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  2.0, 1e-5);
    DOUBLES_EQUAL(u4f[W],  1.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 70.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 80.0, 1e-5);
    
    u4f = u4f * m4f;
    
    DOUBLES_EQUAL(m4f[ 0],  1.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 1],  2.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 2],  3.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 3],  4.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 4],  5.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 5],  6.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 6],  7.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 7],  8.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 8],  9.0, 1e-5);
    DOUBLES_EQUAL(m4f[ 9], 10.0, 1e-5);
    DOUBLES_EQUAL(m4f[10], 11.0, 1e-5);
    DOUBLES_EQUAL(m4f[11], 12.0, 1e-5);
    DOUBLES_EQUAL(m4f[12], 13.0, 1e-5);
    DOUBLES_EQUAL(m4f[13], 14.0, 1e-5);
    DOUBLES_EQUAL(m4f[14], 15.0, 1e-5);
    DOUBLES_EQUAL(m4f[15], 16.0, 1e-5);

    DOUBLES_EQUAL(u4f[X], 50.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 60.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 70.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 80.0, 1e-5);
}

}
