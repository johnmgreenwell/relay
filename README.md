# Generic Relay Driver

Generic, portable, multi-instance relay driver.

## Overview

This HAL-mediated custom relay driver permits ease of use that is designed to be platform-independent. Though simple GPIO behavior, this driver brings it up into a portable and highly-readable object-oriented programming space.

## Usage

The relay header and source rely on an external user-defined hardware abstraction layer (HAL) called `hal.h` which defines the necessary calls in the `HAL` namespace. This includes a GPIO pin object with `pinMode()`, `digitalRead()`, and `digitalWrite()` methods, as well as an enumerated value `GPIO_OUTPUT` which, when supplied to the `pinMode()` function, will set the selected GPIO pin to output mode.

At instantiation, the logic level corresponding to the relay's on-state may be set. By default, a high logic level will be applied for on, and a low level for off.

It is assumed that the relay incorporates a protective flyback diode and is otherwise reliable electrically.

### Example

```cpp
#include "relay.h"

...

// Instantiate relay
PeripheralIO::Relay relay(PIN_A0);

...

int main()
{
    // Set relay in reaction to some condition
    if (someCondition)
    {
        relay.on();
    }
    else
    {
        relay.off();
    }

...

    // Check if relay is on
    if (relay.read())
    {
        // Do something
    }

    // Toggle the relay
    relay.toggle()
}

...
```

## License

MIT © 2024 John Greenwell