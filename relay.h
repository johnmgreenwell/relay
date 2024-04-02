//--------------------------------------------------------------------------------------------------------------------
// Name        : relay.h
// Purpose     : Relay Driver Class
// Description : 
//               This driver class intended for simply control of a relay.
//
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2024, John Greenwell
// Requires    : External : N/A
//               Custom   : hal.h - Custom implementation-defined Hardware Abstraction Layer
//--------------------------------------------------------------------------------------------------------------------
#ifndef _RELAY_H
#define _RELAY_H

#include "hal.h"

namespace PeripheralIO
{

class Relay 
{
    public:

        /**
         * @brief Constructor for Relay object; relay initializes off
         * @param relay_pin Identifying pin number of the relay
         * @param on_logic_level Logic level for which the relay is on
        */
        Relay(uint8_t relay_pin, bool on_logic_level=true);

        /**
         * @brief Turn on the relay
        */
        void on() const;

        /**
         * @brief Turn off the relay
        */
        void off() const;

        /**
         * @brief Toggle the current state of the relay
        */
        void toggle() const;

        /**
         * @brief Check whether the relay is currently on
         * @return True for relay on, false otherwise
        */
        bool is_on() const;

        /**
         * @brief Write a logic value to the relay
         * @param val The state to write to the relay; zero for off, nonzero for on
        */
        void write(uint8_t val) const;

        /**
         * @brief Read the state of the relay
         * @return State read from relay; zero for off, one for on
        */
        uint8_t read() const;

    private:
        HAL::GPIO _relay;
        bool      _on_logic_level;

};

}

#endif // _RELAY_H

// EOF
