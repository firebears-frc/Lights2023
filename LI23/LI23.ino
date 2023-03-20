#include <FastLED.h>

constexpr uint8_t NUM_LEDS_STRIP = 30; // 30 leds in a 0.5m strip w/ 60 leds/m
constexpr uint8_t NUM_LEDS_RING = 24;  // 24 leds in a ring

constexpr uint8_t DATA_A = 3; // DIO Pins for Strip Output
constexpr uint8_t DATA_B = 4;
constexpr uint8_t DATA_C = 5;
constexpr uint8_t DATA_D = 6;

typedef enum {
    CONE,
    CUBE
} GamePiece;

#define GLOBAL_BRIGHTNESS 63 // Global Brightness

CRGB STRIP_A[NUM_LEDS_STRIP]; // define arays for two strips & two rings
CRGB STRIP_B[NUM_LEDS_STRIP];
CRGB RING_A[NUM_LEDS_RING];
CRGB RING_B[NUM_LEDS_RING];

void setup()
{
    FastLED.addLeds<NEOPIXEL, DATA_A>(STRIP_A, NUM_LEDS_STRIP);
    FastLED.addLeds<NEOPIXEL, DATA_B>(STRIP_B, NUM_LEDS_STRIP);
    FastLED.addLeds<NEOPIXEL, DATA_C>(RING_A, NUM_LEDS_RING);
    FastLED.addLeds<NEOPIXEL, DATA_D>(RING_B, NUM_LEDS_RING);

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
    static uint8_t a = 0; 
    static uint8_t b = 1;
    static uint8_t c = 2;
    static uint8_t d = 3;
    static uint8_t e = 4;
    static uint8_t f = 5;
    static uint8_t g = 6;
    static uint8_t h = 7;
    static uint8_t i = 8;
    static uint8_t j = 9;
    static uint8_t k = 10;

    if (a == (NUM_LEDS_STRIP))
    {
        a = 0;
    }
    else if (b == (NUM_LEDS_STRIP))
    {
        b = 0;
    }
    else if (c == (NUM_LEDS_STRIP))
    {
        c = 0;
    }
    else if (d == (NUM_LEDS_STRIP))
    {
        d = 0;
    }
    else if (e == (NUM_LEDS_STRIP))
    {
        e = 0;
    }
    else if (f == (NUM_LEDS_STRIP))
    {
        f = 0;
    }
    else if (g == (NUM_LEDS_STRIP))
    {
        g = 0;
    }
    else if (h == (NUM_LEDS_STRIP))
    {
        h = 0;
    }
    else if (i == (NUM_LEDS_STRIP))
    {
        i = 0;
    }
    else if (j == (NUM_LEDS_STRIP))
    {
        j = 0;
    }
    else if (k == (NUM_LEDS_STRIP))
    {
        k = 0;
    }

    switch (piece) {
        case CONE:
            // animation for cone, should be yellow ish. makes it appear as if the strips are linked on back end of robot
            output[a++] = CRGB::Black;
            output[b++] = CRGB::DarkOrange;
            output[c++] = CRGB::Yellow;
            output[d++] = CRGB::DarkOrange;
            output[e++] = CRGB::Yellow;
            output[f++] = CRGB::DarkOrange;
            output[g++] = CRGB::Yellow;
            output[h++] = CRGB::DarkOrange;
            output[i++] = CRGB::Yellow;
            output[j++] = CRGB::DarkOrange;
            output[k++] = CRGB::Yellow;
            break;
        case CUBE:
            // animation for cone, should be purple ish. makes it appear as if the strips are linked on back end of robot
            output[NUM_LEDS_STRIP - a++] = CRGB::Black;
            output[NUM_LEDS_STRIP - b++] = CRGB::DarkViolet;
            output[NUM_LEDS_STRIP - c++] = CRGB::Purple;
            output[NUM_LEDS_STRIP - d++] = CRGB::DarkViolet;
            output[NUM_LEDS_STRIP - e++] = CRGB::Purple;
            output[NUM_LEDS_STRIP - f++] = CRGB::DarkViolet;
            output[NUM_LEDS_STRIP - g++] = CRGB::Purple;
            output[NUM_LEDS_STRIP - h++] = CRGB::DarkViolet;
            output[NUM_LEDS_STRIP - i++] = CRGB::Purple;
            output[NUM_LEDS_STRIP - j++] = CRGB::DarkViolet;
            output[NUM_LEDS_STRIP - k++] = CRGB::Purple;
            break;
    }
}

void fire(CRGB *output)
{
    static uint8_t a = 0;
    static uint8_t b = 1;
    static uint8_t c = 2;
    static uint8_t d = 3;
    static uint8_t e = 4;
    static uint8_t f = 5;
    static uint8_t g = 6;
    static uint8_t h = 7;
    static uint8_t i = 8;
    static uint8_t j = 9;
    static uint8_t k = 10;

    if (a == (NUM_LEDS_STRIP))
    {
        a = 0;
    }
    else if (b == (NUM_LEDS_STRIP))
    {
        b = 0;
    }
    else if (c == (NUM_LEDS_STRIP))
    {
        c = 0;
    }
    else if (d == (NUM_LEDS_STRIP))
    {
        d = 0;
    }
    else if (e == (NUM_LEDS_STRIP))
    {
        e = 0;
    }
    else if (f == (NUM_LEDS_STRIP))
    {
        f = 0;
    }
    else if (g == (NUM_LEDS_STRIP))
    {
        g = 0;
    }
    else if (h == (NUM_LEDS_STRIP))
    {
        h = 0;
    }
    else if (i == (NUM_LEDS_STRIP))
    {
        i = 0;
    }
    else if (j == (NUM_LEDS_STRIP))
    {
        j = 0;
    }
    else if (k == (NUM_LEDS_STRIP))
    {
        k = 0;
    }

    output[a++] = CRGB::DarkOrange;
    output[b++] = CRGB::Maroon;
    output[c++] = CRGB::Orange;
    output[d++] = CRGB::DarkOrange;
    output[e++] = CRGB::Orange;
    output[f++] = CRGB::DarkOrange;
    output[g++] = CRGB::Orange;
    output[h++] = CRGB::DarkOrange;
    output[i++] = CRGB::Orange;
    output[j++] = CRGB::DarkOrange;
    output[k++] = CRGB::Orange;
}
