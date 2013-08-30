#include "Common.h"

#include <Hazmat/Math/Vector/Add.h>

struct AddTestData
{
    Vector2f u2f, v2f, w2f;
    Vector3f u3f, v3f, w3f;
    Vector4f u4f, v4f, w4f;
};

DEFINE_TEST_TYPES(AddTestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("Add (2D vectors)");

    jship::Hazmat::Add(u2f, v2f, w2f);

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 0.0, 1e-5);

    u2f[X] = 2.0f; v2f[X] = 10.2f;
    u2f[Y] = 3.0f; v2f[Y] = 33.7f;
    
    jship::Hazmat::Add(u2f, v2f, w2f);

    DOUBLES_EQUAL(u2f[X],  2.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 10.2, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 33.7, 1e-5);
    DOUBLES_EQUAL(w2f[X], 12.2, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 36.7, 1e-5);
    
    jship::Hazmat::Add(u2f, u2f, u2f);
    
    DOUBLES_EQUAL(u2f[X], 4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 6.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<2>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator+= (2D vectors)");

    v2f += u2f;

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);

    u2f[X] = 2.0f; v2f[X] = 10.2f;
    u2f[Y] = 3.0f; v2f[Y] = 33.7f;
    
    v2f += u2f;

    DOUBLES_EQUAL(u2f[X],  2.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 12.2, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 36.7, 1e-5);
    
    u2f += v2f;
    
    DOUBLES_EQUAL(u2f[X], 14.2, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 39.7, 1e-5);
    DOUBLES_EQUAL(v2f[X], 12.2, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 36.7, 1e-5);
}

template <>
template <>
void TestRegistry::test<3>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;

    set_test_name("operator+ (2D vectors)");

    w2f = u2f + v2f;

    DOUBLES_EQUAL(u2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w2f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 0.0, 1e-5);

    u2f[X] = 2.0f; v2f[X] = 10.2f;
    u2f[Y] = 3.0f; v2f[Y] = 33.7f;
    
    w2f = u2f + v2f;

    DOUBLES_EQUAL(u2f[X],  2.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y],  3.0, 1e-5);
    DOUBLES_EQUAL(v2f[X], 10.2, 1e-5);
    DOUBLES_EQUAL(v2f[Y], 33.7, 1e-5);
    DOUBLES_EQUAL(w2f[X], 12.2, 1e-5);
    DOUBLES_EQUAL(w2f[Y], 36.7, 1e-5);

    u2f = u2f + u2f;

    DOUBLES_EQUAL(u2f[X], 4.0, 1e-5);
    DOUBLES_EQUAL(u2f[Y], 6.0, 1e-5);
}


template <>
template <>
void TestRegistry::test<4>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("Add (3D vectors)");

    jship::Hazmat::Add(u3f, v3f, w3f);

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 0.0, 1e-5);

    u3f[X] = 2.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 4.0f; v3f[Z] = -19.6f;
    
    jship::Hazmat::Add(u3f, v3f, w3f);

    DOUBLES_EQUAL(u3f[X],   2.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],   3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],   4.0, 1e-5);
    DOUBLES_EQUAL(v3f[X],  10.2, 1e-5);
    DOUBLES_EQUAL(v3f[Y],  33.7, 1e-5);
    DOUBLES_EQUAL(v3f[Z], -19.6, 1e-5);
    DOUBLES_EQUAL(w3f[X],  12.2, 1e-5);
    DOUBLES_EQUAL(w3f[Y],  36.7, 1e-5);
    DOUBLES_EQUAL(w3f[Z], -15.6, 1e-5);
    
    jship::Hazmat::Add(u3f, u3f, u3f);
    
    DOUBLES_EQUAL(u3f[X], 4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 6.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 8.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<5>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator+= (3D vectors)");

    v3f += u3f;

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 0.0, 1e-5);

    u3f[X] = 2.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 4.0f; v3f[Z] = -19.6f;

    v3f += u3f;

    DOUBLES_EQUAL(u3f[X],   2.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],   3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],   4.0, 1e-5);
    DOUBLES_EQUAL(v3f[X],  12.2, 1e-5);
    DOUBLES_EQUAL(v3f[Y],  36.7, 1e-5);
    DOUBLES_EQUAL(v3f[Z], -15.6, 1e-5);
   
    u3f += v3f;
    
    DOUBLES_EQUAL(u3f[X],  14.2, 1e-5);
    DOUBLES_EQUAL(u3f[Y],  39.7, 1e-5);
    DOUBLES_EQUAL(u3f[Z], -11.6, 1e-5);
}

template <>
template <>
void TestRegistry::test<6>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;

    set_test_name("operator+ (3D vectors)");

    w3f = u3f + v3f;

    DOUBLES_EQUAL(u3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v3f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(w3f[Z], 0.0, 1e-5);

    u3f[X] = 2.0f; v3f[X] =  10.2f;
    u3f[Y] = 3.0f; v3f[Y] =  33.7f;
    u3f[Z] = 4.0f; v3f[Z] = -19.6f;

    w3f = u3f + v3f;

    DOUBLES_EQUAL(u3f[X],   2.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y],   3.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z],   4.0, 1e-5);
    DOUBLES_EQUAL(v3f[X],  10.2, 1e-5);
    DOUBLES_EQUAL(v3f[Y],  33.7, 1e-5);
    DOUBLES_EQUAL(v3f[Z], -19.6, 1e-5);
    DOUBLES_EQUAL(w3f[X],  12.2, 1e-5);
    DOUBLES_EQUAL(w3f[Y],  36.7, 1e-5);
    DOUBLES_EQUAL(w3f[Z], -15.6, 1e-5);
   
    u3f = u3f + u3f;
    
    DOUBLES_EQUAL(u3f[X], 4.0, 1e-5);
    DOUBLES_EQUAL(u3f[Y], 6.0, 1e-5);
    DOUBLES_EQUAL(u3f[Z], 8.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<7>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("Add (4D vectors)");

    jship::Hazmat::Add(u4f, v4f, w4f);

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

    u4f[X] = 2.0f; v4f[X] =  10.2f;
    u4f[Y] = 3.0f; v4f[Y] =  33.7f;
    u4f[Z] = 4.0f; v4f[Z] = -19.6f;
    u4f[W] = 5.0f; v4f[W] =  99.0f;
    
    jship::Hazmat::Add(u4f, v4f, w4f);

    DOUBLES_EQUAL(u4f[X],   2.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],   3.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],   4.0, 1e-5);
    DOUBLES_EQUAL(u4f[W],   5.0, 1e-5);
    DOUBLES_EQUAL(v4f[X],  10.2, 1e-5);
    DOUBLES_EQUAL(v4f[Y],  33.7, 1e-5);
    DOUBLES_EQUAL(v4f[Z], -19.6, 1e-5);
    DOUBLES_EQUAL(v4f[W],  99.0, 1e-5);
    DOUBLES_EQUAL(w4f[X],  12.2, 1e-5);
    DOUBLES_EQUAL(w4f[Y],  36.7, 1e-5);
    DOUBLES_EQUAL(w4f[Z], -15.6, 1e-5);
    DOUBLES_EQUAL(w4f[W], 104.0, 1e-5);
    
    jship::Hazmat::Add(u4f, u4f, u4f);
    
    DOUBLES_EQUAL(u4f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],  6.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  8.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 10.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<8>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("operator+= (4D vectors)");

    v4f += u4f;

    DOUBLES_EQUAL(u4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[X], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Y], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[Z], 0.0, 1e-5);
    DOUBLES_EQUAL(v4f[W], 0.0, 1e-5);

    u4f[X] = 2.0f; v4f[X] =  10.2f;
    u4f[Y] = 3.0f; v4f[Y] =  33.7f;
    u4f[Z] = 4.0f; v4f[Z] = -19.6f;
    u4f[W] = 5.0f; v4f[W] =  99.0f;

    v4f += u4f;

    DOUBLES_EQUAL(u4f[X],   2.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],   3.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],   4.0, 1e-5);
    DOUBLES_EQUAL(u4f[W],   5.0, 1e-5);
    DOUBLES_EQUAL(v4f[X],  12.2, 1e-5);
    DOUBLES_EQUAL(v4f[Y],  36.7, 1e-5);
    DOUBLES_EQUAL(v4f[Z], -15.6, 1e-5);
    DOUBLES_EQUAL(v4f[W], 104.0, 1e-5);
   
    u4f += v4f;
    
    DOUBLES_EQUAL(u4f[X],  14.2, 1e-5);
    DOUBLES_EQUAL(u4f[Y],  39.7, 1e-5);
    DOUBLES_EQUAL(u4f[Z], -11.6, 1e-5);
    DOUBLES_EQUAL(u4f[W], 109.0, 1e-5);
}

template <>
template <>
void TestRegistry::test<9>()
{
    using jship::Hazmat::X;
    using jship::Hazmat::Y;
    using jship::Hazmat::Z;
    using jship::Hazmat::W;

    set_test_name("operator+ (4D vectors)");

    w4f = u4f + v4f;

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

    u4f[X] = 2.0f; v4f[X] =  10.2f;
    u4f[Y] = 3.0f; v4f[Y] =  33.7f;
    u4f[Z] = 4.0f; v4f[Z] = -19.6f;
    u4f[W] = 5.0f; v4f[W] =  99.0f;
    
    w4f = u4f + v4f;

    DOUBLES_EQUAL(u4f[X],   2.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],   3.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],   4.0, 1e-5);
    DOUBLES_EQUAL(u4f[W],   5.0, 1e-5);
    DOUBLES_EQUAL(v4f[X],  10.2, 1e-5);
    DOUBLES_EQUAL(v4f[Y],  33.7, 1e-5);
    DOUBLES_EQUAL(v4f[Z], -19.6, 1e-5);
    DOUBLES_EQUAL(v4f[W],  99.0, 1e-5);
    DOUBLES_EQUAL(w4f[X],  12.2, 1e-5);
    DOUBLES_EQUAL(w4f[Y],  36.7, 1e-5);
    DOUBLES_EQUAL(w4f[Z], -15.6, 1e-5);
    DOUBLES_EQUAL(w4f[W], 104.0, 1e-5);
   
    u4f = u4f + u4f;
    
    DOUBLES_EQUAL(u4f[X],  4.0, 1e-5);
    DOUBLES_EQUAL(u4f[Y],  6.0, 1e-5);
    DOUBLES_EQUAL(u4f[Z],  8.0, 1e-5);
    DOUBLES_EQUAL(u4f[W], 10.0, 1e-5);
}

}