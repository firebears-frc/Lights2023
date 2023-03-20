#include <FastLED.h>

constexpr uint8_t NUM_LEDS_STRIP = 30;
constexpr uint8_t NUM_LEDS_RING = 24;
constexpr uint8_t GLOBAL_BRIGHTNESS = 63;
constexpr uint8_t DATA_A_PIN = 3; // DIO Pins for Strip Output
constexpr uint8_t DATA_B_PIN = 4;
constexpr uint8_t DATA_C_PIN = 5;
constexpr uint8_t DATA_D_PIN = 6;

typedef enum
{
    CONE,
    CUBE
} GamePiece;

CRGB STRIP_A[NUM_LEDS_STRIP]; // define arays for two strips & two rings
CRGB STRIP_B[NUM_LEDS_STRIP];
CRGB RING_A[NUM_LEDS_RING];
CRGB RING_B[NUM_LEDS_RING];

void setup()
{
    FastLED.addLeds<NEOPIXEL, DATA_A_PIN>(STRIP_A, NUM_LEDS_STRIP);
    FastLED.addLeds<NEOPIXEL, DATA_B_PIN>(STRIP_B, NUM_LEDS_STRIP);
    FastLED.addLeds<NEOPIXEL, DATA_C_PIN>(RING_A, NUM_LEDS_RING);
    FastLED.addLeds<NEOPIXEL, DATA_D_PIN>(RING_B, NUM_LEDS_RING);

    FastLED.setBrightness(GLOBAL_BRIGHTNESS);

    DDRB = 0b00000000; // set all of port B to input
}

void loop()
{
    // check state of PB4-PB7 (on MEGA 2560 Digial 10-13)
    if (PINB == 0b00000000)
    { // state 0 Clear
        solid(CRGB::Black, STRIP_A);
        solid(CRGB::Black, STRIP_B);
    }
    else if (PINB == 0b00010000)
    { // state 1 Red
        solid(CRGB::Red, STRIP_A);
        solid(CRGB::Red, STRIP_B);
    }
    else if (PINB == 0b00100000)
    { // state 2 Blue
        solid(CRGB::Blue, STRIP_A);
        solid(CRGB::Blue, STRIP_B);
    }
    else if (PINB == 0b00110000)
    { // state 3 Yellow
        solid(CRGB::Yellow, STRIP_A);
        solid(CRGB::Yellow, STRIP_B);
    }
    else if (PINB == 0b01000000)
    { // state 4 Purple
        solid(CRGB::Purple, STRIP_A);
        solid(CRGB::Purple, STRIP_B);
    }
    else if (PINB == 0b01010000)
    { // state 5 Cone
        gamePiece(CONE, STRIP_A);
        gamePiece(CONE, STRIP_B);
        delay(20);
    }
    else if (PINB == 0b01100000)
    { // state 6 Cube
        gamePiece(CUBE, STRIP_A);
        gamePiece(CUBE, STRIP_B);
        delay(20);
    }
    else if (PINB == 0b01110000)
    { // state 7 Fire
        fire(STRIP_A);
        fire(STRIP_B);
        delay(20);
    } /*
     else if( PINB == 0b10000000){ //state 8

     }
     else if( PINB == 0b10010000){ //state 9

     }
     else if( PINB == 0b10100000){ //state 10

     }
     else if( PINB == 0b10110000){ //state 11

     }
     else if( PINB == 0b11000000){ //state 12

     }
     else if( PINB == 0b11010000){ //state 13

     }
     else if( PINB == 0b11100000){ //state 14

     }
     else if( PINB == 0b11110000){ //state 15

     }*/
    FastLED.show();
}

void solid(CRGB color, CRGB *output)
{
    for (uint8_t i = 0; i < NUM_LEDS_STRIP; i++)
    {
        output[i] = color;
    }
}

void gamePiece(GamePiece piece, CRGB *output)
{ // animation for game pieces
    static uint8_t i = 0;

    switch (piece)
    {
    case CONE:
        // animation for cone, should be yellow ish. makes it appear as if the strips are linked on back end of robot
        output[(i + 0) % NUM_LEDS_STRIP] = CRGB::Black;
        output[(i + 1) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
        output[(i + 2) % NUM_LEDS_STRIP] = CRGB::Yellow;
        output[(i + 3) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
        output[(i + 4) % NUM_LEDS_STRIP] = CRGB::Yellow;
        output[(i + 5) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
        output[(i + 6) % NUM_LEDS_STRIP] = CRGB::Yellow;
        output[(i + 7) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
        output[(i + 8) % NUM_LEDS_STRIP] = CRGB::Yellow;
        output[(i + 9) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
        output[(i + 10) % NUM_LEDS_STRIP] = CRGB::Yellow;
        break;
    case CUBE:
        // animation for cone, should be purple ish. makes it appear as if the strips are linked on back end of robot
        output[(i + 0) % NUM_LEDS_STRIP] = CRGB::Black;
        output[(i + 1) % NUM_LEDS_STRIP] = CRGB::DarkViolet;
        output[(i + 2) % NUM_LEDS_STRIP] = CRGB::Purple;
        output[(i + 3) % NUM_LEDS_STRIP] = CRGB::DarkViolet;
        output[(i + 4) % NUM_LEDS_STRIP] = CRGB::Purple;
        output[(i + 5) % NUM_LEDS_STRIP] = CRGB::DarkViolet;
        output[(i + 6) % NUM_LEDS_STRIP] = CRGB::Purple;
        output[(i + 7) % NUM_LEDS_STRIP] = CRGB::DarkViolet;
        output[(i + 8) % NUM_LEDS_STRIP] = CRGB::Purple;
        output[(i + 9) % NUM_LEDS_STRIP] = CRGB::DarkViolet;
        output[(i + 10) % NUM_LEDS_STRIP] = CRGB::Purple;
        break;
    }

    i++;
    i %= NUM_LEDS_STRIP;
}

void fire(CRGB *output)
{
    static uint8_t i = 0;

    output[(i + 0) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
    output[(i + 1) % NUM_LEDS_STRIP] = CRGB::Maroon;
    output[(i + 2) % NUM_LEDS_STRIP] = CRGB::Orange;
    output[(i + 3) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
    output[(i + 4) % NUM_LEDS_STRIP] = CRGB::Orange;
    output[(i + 5) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
    output[(i + 6) % NUM_LEDS_STRIP] = CRGB::Orange;
    output[(i + 7) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
    output[(i + 8) % NUM_LEDS_STRIP] = CRGB::Orange;
    output[(i + 9) % NUM_LEDS_STRIP] = CRGB::DarkOrange;
    output[(i + 10) % NUM_LEDS_STRIP] = CRGB::Orange;

    i++;
    i %= NUM_LEDS_STRIP;
}
