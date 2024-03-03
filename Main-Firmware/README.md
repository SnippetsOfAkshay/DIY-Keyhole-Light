# DIY Keyhole Light Main Firmware 💻

## Overview
This firmware is designed to test all the peripherals connected to the ESP32 of the SMART KEY ILLUMINATION board REV1, FEB 2024. It includes functionalities to control LEDs, read sensors, and manage the system's behavior based on the proximity of objects.

## Disclaimer
This work is provided "as is" with no warranties, expressed or implied. The user agrees to hold harmless and indemnify Mission Critical, its agents, and employees from any claims or liabilities arising from the use of this work.

## Version Details
- ESP32 Version: v2.0.13

## Libraries Used
- FastLED

## Private Defines
- NUM_LEDS: Number of LEDs connected
- DATA_PIN: Pin number for data connection to LEDs
- MAX_FRAMES: Maximum number of animation frames
- uS_TO_S_FACTOR: Conversion factor for microseconds to seconds
- TIME_TO_SLEEP: Time ESP32 will go to sleep (in seconds)

## Pin Definitions
- Buttons:
  - WIFI_RST: GPIO_NUM_12
- Sensors:
  - TRIG: GPIO_NUM_5
  - ECHO: GPIO_NUM_18
- LEDs:
  - WIFI_LED: GPIO_NUM_2

## Variables
- leds[NUM_LEDS]: Array to store LED colors
- frameIndex: Index of current animation frame
- duration, cm: Variables to store sensor readings

## Functions
- nextFrameIndex(): Returns the index of the next animation frame
- setup(): Initializes pin modes and sets up serial communication and LED configuration
- loop(): Main loop function that controls the behavior based on sensor readings
- setColors(): Function to set LED colors based on the current animation frame
- Dist_Test(): Function to read distance from the ultrasonic sensor

## Usage
1. Upload the firmware to the ESP32.
2. Connect the peripherals according to the pin definitions.
3. Power on the device and observe the behavior based on proximity to objects.

## Disclaimer of Warranty
Please refer to the disclaimer section at the beginning of this document for details on the warranty disclaimer.

Enjoy testing your DIY Keyhole Light firmware!
