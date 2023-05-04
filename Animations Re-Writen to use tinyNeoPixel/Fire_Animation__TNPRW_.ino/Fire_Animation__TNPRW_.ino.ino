/*

This is a re-write of "Fire Animation.ino" made to use tinyNeoPixel instead
of fastLED. None of the mechanics of the code have been changed, only the
library used to control the led strip's. In this case, the library did not 
properly handle the original shade of Orange so the best mimic was selected.


Original Sketch Writen by Ava Lambert

May 4 2023 - Thedore A. Albano

*/

#include<tinyNeoPixel.h>

#define NUM_LEDS 30

uint32_t startMillis;
uint32_t currentMillis;
const uint32_t period = 35;

uint8_t Pixel = 27;
uint8_t Pixel2 = 54;
uint8_t Pixel3 = 81;
uint8_t Pixel4 = 5;
uint8_t Pixel5 = 32;
uint8_t Pixel6 = 59;

// Custom Orange (255, 15, 0)

tinyNeoPixel pixels = tinyNeoPixel(NUM_LEDS, PIN_PC0, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  startMillis = millis();
}

void loop() {
currentMillis = millis();
  if (currentMillis - startMillis >= period){
    if(Pixel == NUM_LEDS) {
      Pixel = 0;
    }
    
    Pixel = Pixel + 1;
    pixels.setPixelColor(Pixel , pixels.Color(255, 15, 0));

    if(Pixel4 == NUM_LEDS) {
      Pixel4 = 0;
    }
    
    Pixel4 = Pixel4 + 1;
    pixels.setPixelColor(Pixel4 , pixels.Color(0, 0, 0));

    if(Pixel2 == NUM_LEDS) {
      Pixel2 = 0;
    }
    
    Pixel2 = Pixel2 + 1;
    pixels.setPixelColor(Pixel2 , pixels.Color(255, 15 , 0));

    if(Pixel5 == NUM_LEDS) {
      Pixel5 = 0;
    }
    
    Pixel5 = Pixel5 + 1;
    pixels.setPixelColor(Pixel5 , pixels.Color(0, 0, 0));

    if(Pixel3 == NUM_LEDS) {
      Pixel3 = 0;
    }
    
    Pixel3 = Pixel3 + 1;
    pixels.setPixelColor(Pixel3 , pixels.Color(255, 15, 0));

    if(Pixel6 == NUM_LEDS) {
      Pixel6 = 0;
    }
    
    Pixel6 = Pixel6 + 1;
    pixels.setPixelColor(Pixel6 , pixels.Color(0, 0, 0));

    pixels.show();
    startMillis = currentMillis; 

  }

}
