# Fan-Controller

This project is a simple embedded fan controller based on the **ATmega328PB** microcontroller. It allows the user to control the fan speed using buttons and provides real-time feedback via a 7-segment display and LEDs.

## 🛠️Hardware Requirements

- ATmega328PB microcontroller
- 12V Fan (or suitable for your setup)
- 7-segment display
- 4 buttons (connected to PORTC: PC0–PC3)
- 3 LEDs (connected to PORTB: PB0–PB2)


## ✨Features

- **Speed Control via Buttons**  
  Four buttons are used to select different fan speed modes.
  
- **PWM Fan Control**  
  Fan speed is controlled using Pulse Width Modulation (PWM).

- **Visual Feedback**  
  - A 7-segment display shows the currently selected speed profile (0, 1, 2, or 3).
  - LEDs indicate which speed mode is active.


## Wiring Overview

- **Buttons**: Connected to `PORTC` (PC0–PC3)
- **LEDs**: Connected to `PORTB` (PB0–PB2)
- **Fan (PWM)**: Connected to `PORTB` pin PB3 (FAN_1)
- **7-Segment Display**: Connected to `PORTD`

## 🧑‍💻How It Works


### 1. Initialization Phase

Upon startup, the microcontroller performs the following setup:

- Configures the input pins for buttons with internal pull-up resistors.
- Sets output pins for LEDs and the 7-segment display.

### 2. User Interaction

- The user can press one of the four buttons connected to **PORTC** (PC0–PC3) to select a fan speed mode.
- Each button triggers a different mode:
  - `PC0` → MODE_1
  - `PC1` → MODE_2
  - `PC2` → MODE_3
  - `PC3` → MODE_0 (fan off)

### 3. Visual Feedback

- The current mode is displayed on a **7-segment display** via `DIS_PORT`.
- One of three **LEDs** connected to PORTB (PB0–PB2) lights up to indicate the active mode:
  - LED_1 (PB0) for MODE_1
  - LED_2 (PB1) for MODE_2
  - LED_3 (PB2) for MODE_3

### 4. Fan Control via PWM

The fan is connected to PB3 and controlled using a simple delay-based Pulse Width Modulation (PWM) approach:

- **MODE_1**: Fan blinks on and off every 100ms → medium speed.
- **MODE_2**: Fan blinks on and off every 10ms → high speed.
- **MODE_3**: Fan is fully on → maximum speed.
- **MODE_0**: Fan is turned off.

This simulates different levels of fan speed using software-generated PWM by toggling the output pin with delays.

### 5. Continuous Operation

The main program loop continuously:

- Polls the button states.
- Updates the current mode.
- Adjusts the 7-segment display, LED indicators, and fan speed based on the selected mode.

This loop ensures that the user can change the fan speed in real time, with immediate visual and functional feedback.
