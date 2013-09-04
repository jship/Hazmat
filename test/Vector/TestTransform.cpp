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

// wolfram: {{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16}} . {4,3,2,1}
template <>
template <>
void TestRegistry::test<1>()
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

}
