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

#ifndef HAZMAT_MATH_VECTOR_SET_H
#define HAZMAT_MATH_VECTOR_SET_H

#include <Hazmat/Types/Vector.h>

BEGIN_HAZMAT_NAMESPACE

template <int DIM, typename T, typename TX, typename TY>
void Set(TX x, TY y, Vector<DIM, T>& u);

template <int DIM, typename T, typename TX, typename TY, typename TZ>
void Set(TX x, TY y, TZ z, Vector<DIM, T>& u);

template <int DIM, typename T, typename TX, typename TY, typename TZ, typename TW>
void Set(TX x, TY y, TZ z, TW w, Vector<DIM, T>& u);

END_HAZMAT_NAMESPACE

#include <Hazmat/Math/Vector/Priv/Set.inl>

#endif
