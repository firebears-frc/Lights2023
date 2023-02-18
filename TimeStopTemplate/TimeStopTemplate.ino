#include <FastLED.h>

unsigned long startMillis;  
unsigned long currentMillis;
const unsigned long period = 150;  //the value is a number of milliseconds
const byte ledPin = 13;

#define NUM_LEDS 64
#define DATA_PIN 3
#define BRIGHTNESS 10

CRGB leds[NUM_LEDS];

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
  {  




    
    
    
    
    digitalWrite(ledPin, !digitalRead(ledPin));  
    startMillis = currentMillis;  
  }
}
    
    
