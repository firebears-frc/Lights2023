#include <FastLED.h>

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 60;  //the value is a number of milliseconds

#define NUM_LEDS 30
#define NUM_LEDS2 30

#define DATA_PIN1 3  //change latter
#define DATA_PIN2 4  //change latter

#define BRIGHTNESS 100

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];

int Pixel1 = 0;   // Red
int Pixel4 = 5;   //Black
int Pixel2 = 10;  //OrangeRed
int Pixel5 = 15;  //Black
int Pixel3 = 20;  //DarkOrange
int Pixel6 = 25;  //Black

int inPin1 = 7;  //change latter
int val1 = 0;

int inPin2 = 8;  //change latter
int val2 = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds2, NUM_LEDS2);

  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);

  Serial.begin(115200);
  startMillis = millis();

  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  val1 = digitalRead(inPin1);  // read the input pin
  val2 = digitalRead(inPin2);  // read the input pin

  if (val1 == HIGH && val2 == LOW) {  //1 on 2 off Cube
    //Cube(leds1);
    //Cube(leds2);
  } else if (val1 == LOW && val2 == HIGH) {  //1 off 2 on Cone
    //Cone(leds1);
    //Cone(leds2);
  } else if (val1 == HIGH && val2 == HIGH) {  //1 on 2 on Rainbow celebration?

  } else if (val1 == LOW && val2 == LOW) {  //1 off 2 off Fire
    //Fire(leds1);
    //Fire(leds2);
  }
  Cone(leds1);
  Cone(leds2);
}

void Fire(CRGB *leds) {  //Start of Fire
  currentMillis = millis();           //Millis to avoid dellay
  if (currentMillis - startMillis >= period) {

    if (Pixel1 == NUM_LEDS) {
      Pixel1 = 0;
    }
    Pixel1 = Pixel1 + 1;
    leds[Pixel1] = CRGB::Red;
    FastLED.show();

    if (Pixel4 == NUM_LEDS) {
      Pixel4 = 0;
    }
    Pixel4 = Pixel4 + 1;
    leds[Pixel4] = CRGB::Black;
    FastLED.show();

    if (Pixel2 == NUM_LEDS) {
      Pixel2 = 0;
    }
    Pixel2 = Pixel2 + 1;
    leds[Pixel2] = CRGB::OrangeRed;
    FastLED.show();

    if (Pixel5 == NUM_LEDS) {
      Pixel5 = 0;
    }
    Pixel5 = Pixel5 + 1;
    leds[Pixel5] = CRGB::Black;
    FastLED.show();

    if (Pixel3 == NUM_LEDS) {
      Pixel3 = 0;
    }
    Pixel3 = Pixel3 + 1;
    leds[Pixel3] = CRGB::DarkOrange;
    FastLED.show();

    if (Pixel6 == NUM_LEDS) {
      Pixel6 = 0;
    }
    Pixel6 = Pixel6 + 1;
    leds[Pixel6] = CRGB::Black;
    FastLED.show();

    startMillis = currentMillis;
  }
}

void Cube(CRGB *leds) {  //start of Cube
  currentMillis = millis();           //Millis to avoid dellay
  if (currentMillis - startMillis >= period) {

    if (Pixel1 == NUM_LEDS) {
      Pixel1 = 0;
    }
    Pixel1 = Pixel1 + 1;
    leds[Pixel1] = CRGB::MediumVioletRed;
    FastLED.show();

    if (Pixel4 == NUM_LEDS) {
      Pixel4 = 0;
    }
    Pixel4 = Pixel4 + 1;
    leds[Pixel4] = CRGB::Black;
    FastLED.show();

    if (Pixel2 == NUM_LEDS) {
      Pixel2 = 0;
    }
    Pixel2 = Pixel2 + 1;
    leds[Pixel2] = CRGB::BlueViolet;
    FastLED.show();

    if (Pixel5 == NUM_LEDS) {
      Pixel5 = 0;
    }
    Pixel5 = Pixel5 + 1;
    leds[Pixel5] = CRGB::Black;
    FastLED.show();

    if (Pixel3 == NUM_LEDS) {
      Pixel3 = 0;
    }
    Pixel3 = Pixel3 + 1;
    leds[Pixel3] = CRGB::Purple;
    FastLED.show();

    if (Pixel6 == NUM_LEDS) {
      Pixel6 = 0;
    }
    Pixel6 = Pixel6 + 1;
    leds[Pixel6] = CRGB::Black;
    FastLED.show();

    startMillis = currentMillis;
  }
}

void Cone(CRGB *leds) {  //start of Cone
  currentMillis = millis();           //Millis to avoid dellay
  if (currentMillis - startMillis >= period) {

    if (Pixel1 == NUM_LEDS) {
      Pixel1 = 0;
    }
    Pixel1 = Pixel1 + 1;
    leds[Pixel1] = CRGB::DarkOrange;
    FastLED.show();

    if (Pixel4 == NUM_LEDS) {
      Pixel4 = 0;
    }
    Pixel4 = Pixel4 + 1;
    leds[Pixel4] = CRGB::Black;
    FastLED.show();

    if (Pixel2 == NUM_LEDS) {
      Pixel2 = 0;
    }
    Pixel2 = Pixel2 + 1;
    leds[Pixel2] = CRGB::Yellow;
    FastLED.show();

    if (Pixel5 == NUM_LEDS) {
      Pixel5 = 0;
    }
    Pixel5 = Pixel5 + 1;
    leds[Pixel5] = CRGB::Black;
    FastLED.show();

    if (Pixel3 == NUM_LEDS) {
      Pixel3 = 0;
    }
    Pixel3 = Pixel3 + 1;
    leds[Pixel3] = CRGB::DarkOrange;
    FastLED.show();

    if (Pixel6 == NUM_LEDS) {
      Pixel6 = 0;
    }
    Pixel6 = Pixel6 + 1;
    leds[Pixel6] = CRGB::Black;
    FastLED.show();

    startMillis = currentMillis;
  }
}
