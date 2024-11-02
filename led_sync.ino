#include <FastLED.h>

#define NUM_LEDS 60        // Set this to the actual number of LEDs on your strip
#define DI_PIN 12          // Pin to which the LED strip is connected
#define serialRate 115200  // Serial communication speed

CRGB leds[NUM_LEDS];       // Create an array to hold LED colors

void setup() {
  FastLED.addLeds<WS2812, DI_PIN, GRB>(leds, NUM_LEDS);  // Initialize LED strip
  FastLED.setBrightness(255);                            // Set max brightness
  Serial.begin(serialRate);                              // Begin Serial communication
}

void loop() {
  // Wait for the prefix "Ada" to be received
  if (Serial.available() >= 3) {
    if (Serial.read() == 'A' && Serial.read() == 'd' && Serial.read() == 'a') {

      // Check if we have received three more bytes for RGB values
      while (Serial.available() < 3);  // Wait until we have 3 bytes available
      byte r = Serial.read();
      byte g = Serial.read();
      byte b = Serial.read();

      // Set all LEDs to the received color
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(r, g, b);
      }
      FastLED.show();  // Update the LED strip with the new color
    }
  }
}
