#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include "TutHelpers.h"

#include <Hazmat/Types/Matrix.h>
#include <Hazmat/Types/Quaternion.h>
#include <Hazmat/Types/Vector.h>

typedef jship::Hazmat::Array<2, float> Array2f;
typedef jship::Hazmat::Array<3, float> Array3f;
typedef jship::Hazmat::Array<4, float> Array4f;

typedef jship::Hazmat::Matrix< 4, float> Matrix2f;
typedef jship::Hazmat::Matrix< 9, float> Matrix3f;
typedef jship::Hazmat::Matrix<16, float> Matrix4f;

typedef jship::Hazmat::Quaternion<float> Quaternion4f;

typedef jship::Hazmat::Vector<2, float> Vector2f;
typedef jship::Hazmat::Vector<3, float> Vector3f;
typedef jship::Hazmat::Vector<4, float> Vector4f;

inline
float toRadians(float degrees)
{
    return (M_PI * degrees) / 180.0f;
}

inline
float toDegrees(float radians)
{
    return (180.0f * radians) / M_PI;
}

#endif
