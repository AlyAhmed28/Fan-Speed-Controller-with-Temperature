# Temperature-Controlled Fan System

An embedded C project for an AVR microcontroller that reads the ambient temperature from an **LM35** sensor and automatically controls the speed of a **DC motor (fan)** using **PWM**. The current fan state and temperature are shown on a **16x2 LCD**.

## Features

- Real-time temperature sensing with the LM35 through the ADC
- Automatic fan speed control based on temperature ranges
- PWM-based DC motor speed control
- Live status display on a 16x2 LCD (fan ON/OFF and temperature in °C)
- Modular, layered driver design (GPIO, ADC, PWM, LCD, sensor, motor)

## How It Works

1. The LM35 outputs an analog voltage proportional to temperature (10 mV/°C).
2. The ADC driver converts this voltage to a digital value.
3. The LM35 driver converts the digital value to a temperature in °C.
4. The main application decides the fan speed and updates the LCD.

### Fan Speed Logic

| Temperature (°C) | Fan State | Motor Speed (PWM duty) |
|------------------|-----------|------------------------|
| Below 30         | OFF       | 0%                     |
| 30 to < 60       | ON        | 25%                    |
| 60 to < 90       | ON        | 50%                    |
| 90 to < 120      | ON        | 75%                    |
| 120 and above    | ON        | 100%                   |

### LCD Output

```
FAN is ON
Temp = 45 C
```

## Project Structure

```
.
├── Source.c          # Main application (application logic)
├── adc.c / adc.h     # ADC driver (configurable prescaler and reference voltage)
├── gpio.c / gpio.h   # GPIO driver (pin/port direction, read, write)
├── lcd.c / lcd.h     # 16x2 LCD driver
├── lm35.c / lm35.h   # LM35 temperature sensor driver
├── dcmotor.c / .h    # DC motor driver (direction and speed)
├── pwm.c / pwm.h     # PWM driver (used for motor speed control)
├── common_macros.h   # Common bit-manipulation macros
└── std_types.h       # Standard data type definitions
```

## Drivers Overview

| Module     | Description |
|------------|-------------|
| **GPIO**   | Generic digital I/O: set pin/port direction, read and write pins and ports. |
| **ADC**    | Initializes the ADC using a configuration struct (prescaler and reference voltage) and reads analog channels. |
| **LM35**   | Reads the ADC value and converts it to temperature in °C. |
| **LCD**    | Initializes the LCD and provides functions to display characters, strings, integers, and move the cursor. |
| **DC Motor** | Controls motor direction (`CW`, `STOP`) and speed via PWM. |
| **PWM**    | Generates a PWM signal to control motor speed. |

## Hardware Requirements

- AVR microcontroller (e.g., ATmega32)
- LM35 temperature sensor
- 16x2 character LCD
- DC motor (fan) with a motor driver (e.g., L293D H-bridge)
- Power supply, breadboard, and jumper wires

## Pin Connections

> Update this table to match your wiring.

| Component        | Microcontroller Pin |
|------------------|---------------------|
| LM35 output      | ADC channel (e.g., PA2) |
| LCD data/control | Configured in `lcd.h` |
| Motor driver     | Configured in `dcmotor.h` |
| PWM output       | OC0 (e.g., PB3) |

## ADC Configuration

The ADC is initialized in `Source.c` with:

```c
ADC_ConfigType config = {F_CPU_8, INTERNAL};
```

- **Prescaler:** `F_CPU / 8`
- **Reference voltage:** Internal (2.56 V)

## Build and Run

1. Open the project in your IDE (e.g., Eclipse with AVR plugin, Atmel Studio, or VS Code with `avr-gcc`).
2. Set the target MCU and the CPU frequency (`F_CPU`) to match your hardware.
3. Build the project.
4. Flash the generated `.hex` file to the microcontroller.
5. Power the circuit. The LCD will show the fan status and temperature.

Example with `avr-gcc` (adjust the MCU and frequency):

```bash
avr-gcc -mmcu=atmega32 -DF_CPU=8000000UL -Os *.c -o fan.elf
avr-objcopy -O ihex fan.elf fan.hex
```

## Author

**Aly Ahmed**
GitHub: [AlyAhmed28](https://github.com/AlyAhmed28)

Created: March 2024
