#include "Common.h"

struct TestData
{
    Float2 float2;
    Float3 float3;
    Float4 float4;
    
    Float3 float3Array[10];
    
    Vec3f vec3f;
    Vec3f vec3fArray[10];
};

DEFINE_TEST_TYPES(TestData);

namespace tut
{

template <>
template <>
void TestRegistry::test<1>()
{
    set_test_name("Sizing");
    
    ensure(float3.byteCount == 3 * sizeof(float));
    ensure(sizeof(float3Array) == float3.byteCount * 10);
    ensure("hellow", sizeof(vec3f) == float3.byteCount);
    ensure("blah", sizeof(vec3fArray) == vec3f.byteCount * 10);
    
    vec3fArray[0][0] = 0.12345f;
    
    vec3fArray[1][0] = 1.0f;
    vec3fArray[1][1] = 1.0f;
    vec3fArray[1][2] = 1.0f;
    
    vec3fArray[2][0] = 2.0f;
    vec3fArray[2][1] = 2.0f;
    vec3fArray[2][2] = 2.0f;
    
//    Vec3f::ValueType* floatPtr = &vec3fArray[0][0];
    Vec3f::ValueType* floatPtr = vec3fArray[0].bytes();

    ENSURE(*floatPtr == 0.12345f); floatPtr++;
    ENSURE(*floatPtr == 0.0f); floatPtr++;
    ENSURE(*floatPtr == 0.0f); floatPtr++;
    ensure("4", *floatPtr == 1.0f); floatPtr++;
    ensure("5", *floatPtr == 1.0f); floatPtr++;
    ensure("6", *floatPtr == 1.0f); floatPtr++;
    
//    ensure_not("7", floatPtr != vec3fArray[0].bytes());
    ENSURE_NOT(floatPtr == vec3fArray[0].bytes());
    
    floatPtr = vec3fArray[0].bytes();
    
    VALUES_EQUAL(floatPtr, floatPtr);
    VALUES_EQUAL(23, 23);
//    ensure_equals("abcdefg", floatPtr[0], floatPtr[3], 0.0001);
    
    DOUBLES_EQUAL(23.5, 23.5000001, 0.000001);
    DOUBLES_EQUAL(23.5, 23.4999999, 0.000001);
    
    DOUBLES_EQUAL(15.3f, 15.300001f, 0.000001f);

    float dot = jship::Hazmat::Dot(vec3fArray[1], vec3fArray[2]);
    DOUBLES_EQUAL(dot, 6.0f, 0.00001f);

    Vec4f u, v, w;
    u[0] = 1.0f;  v[0] = 0.0f;
    u[1] = 0.0f;  v[1] = 1.0f;
    u[2] = 0.0f;  v[2] = 0.0f;

    w[3] = 5.0f;
    DOUBLES_EQUAL(w[3], 5.0f, 0.000001f);

    jship::Hazmat::Cross(u, v, w);
    DOUBLES_EQUAL(w[0], 0.0f, 0.000001f);
    DOUBLES_EQUAL(w[1], 0.0f, 0.000001f);
    DOUBLES_EQUAL(w[2], 1.0f, 0.000001f);
    DOUBLES_EQUAL(w[3], 0.0f, 0.000001f);
    

    jship::Hazmat::Cross(u, v, w);
    DOUBLES_EQUAL(jship::Hazmat::Cross(u, v, w)[0], 0.0f, 0.000001f);
    DOUBLES_EQUAL(jship::Hazmat::Cross(u, v, w)[1], 0.0f, 0.000001f);
    DOUBLES_EQUAL(jship::Hazmat::Cross(u, v, w)[2], 1.0f, 0.000001f);

    Vec2f a;
    a[0] = 3.0f;
    a[1] = 4.0f;
    DOUBLES_EQUAL(jship::Hazmat::SquaredLength(a), 25.0f, 0.000001f);
    DOUBLES_EQUAL(jship::Hazmat::Length(a), 5.0f, 0.000001f);
}

template <>
template <>
void TestRegistry::test<2>()
{
    return;
}

}
