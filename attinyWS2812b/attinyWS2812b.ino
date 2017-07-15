#include "FastLED.h"
#define DATA_PIN 3

// Define the array of leds
CRGB led;

void setup() { 
	LEDS.addLeds<WS2812B,DATA_PIN,GRB>(&led,1);
	LEDS.setBrightness(255);
}

void loop() { 
	  static uint8_t hue = 0;
		led = CHSV(hue++, 255, 255);
		// Show the leds
		FastLED.show(); 
		// Wait a little bit before we loop around and do it again
		delay(50);
}

