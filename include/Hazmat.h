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

#ifndef HAZMAT_H
#define HAZMAT_H

#include <Hazmat/Common.h>

#include <Hazmat/Types/Array.h>
#include <Hazmat/Types/Matrix.h>
#include <Hazmat/Types/Quaternion.h>
#include <Hazmat/Types/Vector.h>

#include <Hazmat/Math/Matrix/Adjugate.h>
#include <Hazmat/Math/Matrix/Cofactor.h>
#include <Hazmat/Math/Matrix/Determinant.h>
#include <Hazmat/Math/Matrix/Identity.h>
#include <Hazmat/Math/Matrix/Invert.h>
#include <Hazmat/Math/Matrix/Multiply.h>
#include <Hazmat/Math/Matrix/Rotate.h>
#include <Hazmat/Math/Matrix/RotateAboutX.h>
#include <Hazmat/Math/Matrix/RotateAboutY.h>
#include <Hazmat/Math/Matrix/RotateAboutZ.h>
#include <Hazmat/Math/Matrix/Scale.h>
#include <Hazmat/Math/Matrix/Translate.h>
#include <Hazmat/Math/Matrix/Transpose.h>

#include <Hazmat/Math/Quaternion/Conjugate.h>
#include <Hazmat/Math/Quaternion/Dot.h>
#include <Hazmat/Math/Quaternion/Identity.h>
#include <Hazmat/Math/Quaternion/Invert.h>
#include <Hazmat/Math/Quaternion/Length.h>
#include <Hazmat/Math/Quaternion/Lerp.h>
#include <Hazmat/Math/Quaternion/Multiply.h>
#include <Hazmat/Math/Quaternion/Norm.h>
#include <Hazmat/Math/Quaternion/Rotate.h>
#include <Hazmat/Math/Quaternion/RotateAboutX.h>
#include <Hazmat/Math/Quaternion/RotateAboutY.h>
#include <Hazmat/Math/Quaternion/RotateAboutZ.h>
#include <Hazmat/Math/Quaternion/RotateFromAxes.h>
#include <Hazmat/Math/Quaternion/RotateFromAxisAngle.h>
#include <Hazmat/Math/Quaternion/RotateFromDirections.h>
#include <Hazmat/Math/Quaternion/RotateFromMatrix.h>
#include <Hazmat/Math/Quaternion/Set.h>
#include <Hazmat/Math/Quaternion/Slerp.h>
#include <Hazmat/Math/Quaternion/SquaredLength.h>

#include <Hazmat/Math/Vector/Add.h>
#include <Hazmat/Math/Vector/Cross.h>
#include <Hazmat/Math/Vector/Dot.h>
#include <Hazmat/Math/Vector/Length.h>
#include <Hazmat/Math/Vector/Lerp.h>
#include <Hazmat/Math/Vector/Negate.h>
#include <Hazmat/Math/Vector/Norm.h>
#include <Hazmat/Math/Vector/Scale.h>
#include <Hazmat/Math/Vector/Set.h>
#include <Hazmat/Math/Vector/SquaredLength.h>
#include <Hazmat/Math/Vector/Sub.h>
#include <Hazmat/Math/Vector/Transform.h>

#endif
