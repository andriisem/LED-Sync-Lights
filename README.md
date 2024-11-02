# ScreenSyncLED

ScreenSyncLED is a project that synchronizes an LED strip with your computer screen’s colors, creating an immersive lighting experience. The project uses a Python script to capture screen colors and an Arduino to control the LED strip.

## Features
- **Real-Time Screen Synchronization**: Matches LED colors to your screen in real time.
- **Adaptive Brightness**: Adjusts brightness based on ambient lighting.

TODO:
- **Flexible Zones**: Divides the screen into zones for more accurate color mapping.

## Hardware Requirements
- **Arduino** (e.g., Nano, Uno)
- **WS2812 LED Strip** (or similar individually addressable LEDs)
- **Power Supply** (sufficient for the number of LEDs)
- **USB Cable** to connect Arduino to your computer

## Software Requirements
- **Python 3.x**
- **Pillow** for screen capturing
- **pyserial** for Serial communication with the Arduino

Install dependencies with:
```bash
pip install pillow pyserial
