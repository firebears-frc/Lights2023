#include <FastLED.h>

#define NUM_LEDS 64
#define DATA_PIN 3
#define BRIGHTNESS 10
#define WIDTH 8
#define HIGHT 8
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {


}

void setcolor(int row , int col, long color) {
  int n = 0;
  if (row % 2 == 0) {
    n = row * WIDTH + col;
  } else {
    n = row * WIDTH + (WIDTH - col - 1);
  }
  leds[n] = color;
}
