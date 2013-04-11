/* 
    Title --- iface/shiftin.cpp

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


#ifndef _RPI_HW_IFACE_SHIFTIN_CPP_
#define _RPI_HW_IFACE_SHIFTIN_CPP_

#include <rpi-hw/iface/shiftin.hpp>

#include <rpi-hw/utils.hpp>
#include <rpi-hw/utils-inl.hpp>

#include <rpi-hw/mutex.hpp>
#include <rpi-hw/mutex-inl.hpp>

#include <rpi-hw/thread.hpp>
#include <rpi-hw/thread-inl.hpp>

#include <rpi-hw/gpio.hpp>
#include <rpi-hw/gpio-inl.hpp>

#include <rpi-hw/iface/base.hpp>
#include <rpi-hw/iface/base-inl.hpp>

#include <rpi-hw/iface/shift-base.hpp>
#include <rpi-hw/iface/shift-base-inl.hpp>

#include <rpi-hw/iface/shiftin-inl.hpp>

namespace rpihw { // Begin main namespace

namespace iface { // Begin interfaces namespace

shiftIn::shiftIn( uint8_t data_pin, uint8_t clock_pin, BitOrder order, size_t delay ) : shiftBase( data_pin, clock_pin, order, delay ) {

	// Initialize the interface pins
	m_gpio->setup( m_pins[ DATA_PIN ], gpio::INPUT );
	m_gpio->setPullUpDown( m_pins[ DATA_PIN ], gpio::PULL_DOWN );

	m_gpio->write( m_pins[ CLOCK_PIN ], gpio::LOW );
	m_gpio->setup( m_pins[ CLOCK_PIN ], gpio::OUTPUT );
}

shiftIn::~shiftIn() {

}

uint8_t
shiftIn::read() {

	int8_t i;
	uint8_t data = 0;

	if ( m_order == MSBFIRST ) {

		for ( i = 7; i >= 0 ; i-- ) {

			// Read the data to the input pin
			data |= ( (uint8_t) m_gpio->read( m_pins[ DATA_PIN ] ) ) << i;

			// Toggle the clock
			strobe();
		}

	} else {

		for ( i = 0; i < 8; i++ ) {

			// Read the data to the input pin
			data |= ( (uint8_t) m_gpio->read( m_pins[ DATA_PIN ] ) ) << i;

			// Toggle the clock
			strobe();
		}
	}

	return data;
}

} // End of interfaces namespace

} // End of main namespace

#endif
