#include <Arduino.h>
#include <FastLED.h>
#define NUM_LEDS 8
#define DATA_PIN 21
void loading_visualization(int param);
CRGB leds[NUM_LEDS];
uint8_t count = 0;
int red = 0;
int green = 0;
int blue = 0;
int brightness_f = 0;

void setup() {
  delay(5000);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.setBrightness(255);
  
}

void random_color() {

  red = random(0, 255);
  green = random(0, 255);
  blue = random(0, 255);

}

void loading_visualization_2(int brightness_f, int delay_f, int red, int green, int blue) {
  FastLED.setBrightness(brightness_f);

  for(int i = 0; i < NUM_LEDS; i++) {
    // set our current dot to red
    leds[i].setRGB( red, green, blue);
    delay(delay_f);
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(delay_f);
  };
  for(int i = NUM_LEDS-1; i >= 0; i--) {
    // set our current dot to red
    leds[i].setRGB( red, green, blue);
    delay(delay_f);
    FastLED.show();
    // clear our current dot before we move on
    leds[i] = CRGB::Black;
    delay(delay_f);
  };

}

void loop() {
  random_color();
  loading_visualization_2(25, 25, red, green, blue);
};
