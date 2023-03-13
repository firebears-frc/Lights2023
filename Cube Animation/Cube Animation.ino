#include <FastLED.h>
unsigned long startMillis; 
unsigned long currentMillis;
const unsigned long period = 10; 
const byte ledPin = 13;

#define NUM_LEDS 120
#define DATA_PIN 3
#define CLOCK_PIN 13
#define BRIGHTNESS 50

#define Color1 MediumVioletRed
#define Color2 BlueViolet
#define Color3 Purple

CRGB leds[NUM_LEDS];
int Pixel = 27; //MediumVioletRed 2
int Pixel2 = 54; //BlueViolet 4
int Pixel3 = 81; //Purple 6
int Pixel4 = 5; //Black 1
int Pixel5 = 32; //Black 3
int Pixel6 = 59; //Black 5

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   Serial.begin(115200);
   pinMode(ledPin, OUTPUT);
   startMillis = millis();
   FastLED.setBrightness(BRIGHTNESS);
  

}

void loop() {
 currentMillis = millis();
 if (currentMillis - startMillis >= period)
{ if(Pixel == NUM_LEDS) {
  Pixel = 0;
}
 Pixel = Pixel + 1;
 leds[Pixel] = CRGB::Color1;
 FastLED.show();

  if(Pixel4 == NUM_LEDS) {
  Pixel4 = 0;
}
 Pixel4 = Pixel4 + 1;
 leds[Pixel4] = CRGB::Black;
 FastLED.show();

 if(Pixel2 == NUM_LEDS) {
  Pixel2 = 0;
}
 Pixel2 = Pixel2 + 1;
 leds[Pixel2] = CRGB::Color2;
 FastLED.show();

 if(Pixel5 == NUM_LEDS) {
  Pixel5 = 0;
}
 Pixel5 = Pixel5 + 1;
 leds[Pixel5] = CRGB::Black;
 FastLED.show();

 if(Pixel3 == NUM_LEDS) {
  Pixel3 = 0;
}
 Pixel3 = Pixel3 + 1;
 leds[Pixel3] = CRGB::Color3;
 FastLED.show();

 if(Pixel6 == NUM_LEDS) {
  Pixel6 = 0;
}
 Pixel6 = Pixel6 + 1;
 leds[Pixel6] = CRGB::Black;
 FastLED.show();

 



  digitalWrite(ledPin, !digitalRead(ledPin));
  startMillis = currentMillis; 

}

}

