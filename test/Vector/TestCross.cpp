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

    Cross(u3f, v3f, w3f);

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
    
    Cross(u3f, v3f, w3f);

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
    
    Cross(u3f, v3f, w3f);

    DOUBLES_EQUAL(u3f[X],    18.7  , 1e-1);
    DOUBLES_EQUAL(u3f[Y],  -103.25 , 1e-1);
    DOUBLES_EQUAL(u3f[Z],     9.63 , 1e-1);
    DOUBLES_EQUAL(v3f[X],   -41.5  , 1e-1);
    DOUBLES_EQUAL(v3f[Y],   -14.4  , 1e-1);
    DOUBLES_EQUAL(v3f[Z],    42.42 , 1e-1);
    DOUBLES_EQUAL(w3f[X], -4241.19 , 1e-1);
    DOUBLES_EQUAL(w3f[Y], -1192.9  , 1e-1);
    DOUBLES_EQUAL(w3f[Z], -4554.16 , 1e-1);
    
    Cross(u3f, u3f, u3f);

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
    
    Cross(u4f, v4f, w4f);
    
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
    
    Cross(u4f, v4f, w4f);

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
    
    Cross(u4f, v4f, w4f);

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
    
    Cross(u4f, u4f, u4f);

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
}

}
