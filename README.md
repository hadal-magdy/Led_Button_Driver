# LED & Button Driver (GPIO-Based)

This repository contains a simple and modular GPIO-based LED and button driver implementation for embedded systems. It includes:

- **LED driver**: Abstraction to control LEDs connected to GPIO pins.
- **Button driver**: Debounced input handling for buttons.
- **GPIO driver**: Low-level GPIO abstraction layer.

## 🔧 Application Layer

The application demonstrates the use of these drivers through:

- **Magic Button**: Triggers a special behavior or sequence on the LED.
- **Function Button**: Cycles through different LED control programs such as:
  - Blinking patterns
  - On/Off control

This project can be used as a base for learning driver development or building more complex embedded applications.

## 🛠️ Technologies

- Language: C
- Platform: Pic18f4620

