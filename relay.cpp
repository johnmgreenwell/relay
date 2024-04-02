//--------------------------------------------------------------------------------------------------------------------
// Name        : relay.cpp
// Purpose     : Relay Driver Class
// Description : This source file implements header file relay.h.
// Language    : C++
// Platform    : Portable
// Framework   : Portable
// Copyright   : MIT License 2024, John Greenwell
//--------------------------------------------------------------------------------------------------------------------

#include "relay.h"

namespace PeripheralIO
{

Relay::Relay(uint8_t relay_pin, bool on_logic_level)
: _relay(relay_pin)
, _on_logic_level(on_logic_level)
{
    _relay.pinMode(GPIO_OUTPUT);
}

void Relay::on() const
{
    _relay.digitalWrite(_on_logic_level);
}

void Relay::off() const
{
    _relay.digitalWrite(!_on_logic_level);
}

void Relay::toggle() const
{
    _relay.digitalWrite(!_relay.digitalRead());
}

void Relay::write(uint8_t val) const
{
    bool state = (val) ? _on_logic_level : !_on_logic_level;

    _relay.digitalWrite(state);
}

uint8_t Relay::read() const
{
    bool state = (_relay.digitalRead()) ? _on_logic_level : !_on_logic_level;

    return state;
}

}

// EOF
