/* 
    Title --- rpi-hw.hpp

    Copyright (C) 2013 Giacomo Trudu - wicker25[at]gmail[dot]com

    This file is part of Rpi-hw.

    Rpi-hw is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation version 3 of the License.

    Rpi-hw is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Rpi-hw. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _RPI_HW_TYPES_HPP_
#define _RPI_HW_TYPES_HPP_

#include <cstddef>
#include <stdint.h>

namespace rpihw { // Begin main namespace

//! Structure of a two-dimensional vector.
template < typename T >
struct vec2 {

	//! First dimension.
	union { T i, x, w; };

	//! Second dimension.
	union { T j, y, h; };
};

//! Structure of a three-dimensional vector.
template < typename T >
struct vec3 {

	//! First dimension.
	union { T i, x, w; };

	//! Second dimension.
	union { T j, y, h; };

	//! Third dimension.
	union { T k, z, d; };
};

} // End of main namespace

#endif
