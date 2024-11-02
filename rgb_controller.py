import serial
import time

from PIL import ImageGrab


# Connect to Arduino (update the port as needed)
try:
    arduino = serial.Serial('/dev/tty.usbserial-14120', 115200, timeout=1)
except serial.SerialException as e:
    print("Could not open serial port:", e)
    exit()

def get_screen_color():
    """Capture the screen and get the average color."""
    try:
        screenshot = ImageGrab.grab().resize((1, 1))
        color = screenshot.getpixel((0, 0))
        return color[:3]
    except Exception as e:
        print("Error capturing screen color:", e)
        return (0, 0, 0)

def send_color_to_arduino(color):
    """Send the color to the Arduino."""
    try:
        r, g, b = color
        print(f"Sending color: R={r}, G={g}, B={b}")
        arduino.write(b'Ada')
        arduino.write(bytes([r, g, b]))
    except serial.SerialException as e:
        print("Error sending data to Arduino:", e)

try:
    while True:
        color = get_screen_color()
        send_color_to_arduino(color)
        time.sleep(0.1)

except KeyboardInterrupt:
    print("Program interrupted by user.")

finally:
    arduino.close()
    print("Serial connection closed.")
