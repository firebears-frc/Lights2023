#include<tinyNeoPixel.h>

#define NUM_LEDS_STRIP 31 // 30 leds in a 0.5m strip w/ 60 leds/m + 1 led on driver board
#define NUM_LEDS_RING 25 // 24 leds in a ring + 1 led on driver board

#define DATA_A PIN_PC0 // DIO Pins for Strip Output
#define DATA_B PIN_PC1
#define DATA_C PIN_PC2
#define DATA_D PIN_PC3

#define STRIP_a 0 // marks wich strip
#define STRIP_b 1
#define RING_a 2
#define RING_b 3

tinyNeoPixel strip_A = tinyNeoPixel(NUM_LEDS_STRIP, DATA_A, NEO_GRB + NEO_KHZ800);
tinyNeoPixel strip_B = tinyNeoPixel(NUM_LEDS_STRIP, DATA_B, NEO_GRB + NEO_KHZ800);
tinyNeoPixel ring_A = tinyNeoPixel(NUM_LEDS_RING, DATA_C, NEO_GRB + NEO_KHZ800);
tinyNeoPixel ring_B = tinyNeoPixel(NUM_LEDS_RING, DATA_D, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
