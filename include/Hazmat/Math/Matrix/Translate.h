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

#ifndef HAZMAT_MATH_MATRIX_TRANSLATE_H
#define HAZMAT_MATH_MATRIX_TRANSLATE_H

#include <Hazmat/Types/Matrix.h>
#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

template <int MDIM, int VDIM, typename T>
void Translate(const Matrix<MDIM, T>& a,
               const Vector<VDIM, T>& u,
                     Matrix<MDIM, T>& b);

END_HAZMAT_NAMESPACE

#include <Hazmat/Math/Matrix/Priv/Translate.inl>

#endif
