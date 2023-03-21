#include <FastLED.h>

constexpr uint8_t NUM_LEDS_STRIP    = 30;
constexpr uint8_t NUM_LEDS_RING     = 24;
constexpr uint8_t GLOBAL_BRIGHTNESS = 63;
constexpr uint8_t DATA_A_PIN        = 3;
constexpr uint8_t DATA_B_PIN        = 4;
constexpr uint8_t DATA_C_PIN        = 5;
constexpr uint8_t DATA_D_PIN        = 6;

typedef enum {
    CONE,
    CUBE
} GamePiece;

typedef enum {
    ZERO = 0,

    DISABLED,
    DISABLED_RED,
    DISABLED_BLUE,

    AUTO_NONE,
    AUTO_HAS_CUBE,
    AUTO_HAS_CONE,
    AUTO_DOCKED,
    AUTO_DOCKED_RED,
    AUTO_DOCKED_BLUE,
    AUTO_ENGAGED,
    AUTO_ENGAGED_RED,
    AUTO_ENGAGED_BLUE,

    TELEOP_NONE,
    TELEOP_HAS_CUBE,
    TELEOP_HAS_CONE,
    TELEOP_WANT_CUBE,
    TELEOP_WANT_CONE,
    TELEOP_DOCKED,
    TELEOP_DOCKED_RED,
    TELEOP_DOCKED_BLUE,
    TELEOP_ENGAGED,
    TELEOP_ENGAGED_RED,
    TELEOP_ENGAGED_BLUE,

    ONE
} State;

CRGB STRIP_A[NUM_LEDS_STRIP];
CRGB STRIP_B[NUM_LEDS_STRIP];
CRGB RING_A[NUM_LEDS_RING];
CRGB RING_B[NUM_LEDS_RING];

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_A_PIN>(STRIP_A, NUM_LEDS_STRIP);
    FastLED.addLeds<NEOPIXEL, DATA_B_PIN>(STRIP_B, NUM_LEDS_STRIP);
    FastLED.addLeds<NEOPIXEL, DATA_C_PIN>(RING_A, NUM_LEDS_RING);
    FastLED.addLeds<NEOPIXEL, DATA_D_PIN>(RING_B, NUM_LEDS_RING);

    FastLED.setBrightness(GLOBAL_BRIGHTNESS);

    // Set port B to output
    DDRB = 0b00000000;
}

State getState() {
    uint8_t state = PINB;
    state &= 0b11110000;
    state >>= 3;
    if (digitalRead(9) == HIGH) {
        state |= 0b00000001;
    }

    if (state >= ONE) {
        return ONE;
    }

    return (State) state;
}

void loop() {
    switch (getState()) {
        case ZERO:
        case ONE:
        default:
            solid(CRGB::Black, STRIP_A);
            solid(CRGB::Black, STRIP_B);
            break;
        case DISABLED:
        case AUTO_ENGAGED:
        case TELEOP_ENGAGED:
            solid(CRGB::Green, STRIP_A);
            solid(CRGB::Green, STRIP_B);
            break;
        case DISABLED_RED:
        case AUTO_ENGAGED_RED:
        case TELEOP_ENGAGED_RED:
            solid(CRGB::Red, STRIP_A);
            solid(CRGB::Red, STRIP_B);
            break;
        case DISABLED_BLUE:
        case AUTO_ENGAGED_BLUE:
        case TELEOP_ENGAGED_BLUE:
            solid(CRGB::Blue, STRIP_A);
            solid(CRGB::Blue, STRIP_B);
            break;
        case AUTO_HAS_CONE:
        case TELEOP_HAS_CONE:
        case TELEOP_WANT_CONE:
            gamePiece(CONE, STRIP_A);
            gamePiece(CONE, STRIP_B);
            break;
        case AUTO_HAS_CUBE:
        case TELEOP_HAS_CUBE:
        case TELEOP_WANT_CUBE:
            gamePiece(CUBE, STRIP_A);
            gamePiece(CUBE, STRIP_B);
            break;
        case AUTO_NONE:
        case AUTO_DOCKED:
        case AUTO_DOCKED_RED:
        case AUTO_DOCKED_BLUE:
        case TELEOP_NONE:
        case TELEOP_DOCKED:
        case TELEOP_DOCKED_RED:
        case TELEOP_DOCKED_BLUE:
            fire(STRIP_A);
            fire(STRIP_B);
            break;
    }

    delay(20);
    FastLED.show();
}

void solid(CRGB color, CRGB *output) {
    for (uint8_t i = 0; i < NUM_LEDS_STRIP; i++) {
        output[i] = color;
    }
}

void gamePiece(GamePiece piece, CRGB *output) {  // animation for game pieces
    static uint8_t i = 0;

    switch (piece) {
        case CONE:
            // animation for cone, should be yellow ish. makes it appear as if
            // the strips are linked on back end of robot
            output[i % NUM_LEDS_STRIP]        = CRGB::Black;
            output[(i + 1) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
            output[(i + 2) % NUM_LEDS_STRIP]  = CRGB::Yellow;
            output[(i + 3) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
            output[(i + 4) % NUM_LEDS_STRIP]  = CRGB::Yellow;
            output[(i + 5) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
            output[(i + 6) % NUM_LEDS_STRIP]  = CRGB::Yellow;
            output[(i + 7) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
            output[(i + 8) % NUM_LEDS_STRIP]  = CRGB::Yellow;
            output[(i + 9) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
            output[(i + 10) % NUM_LEDS_STRIP] = CRGB::Yellow;
            break;
        case CUBE:
            // animation for cone, should be purple ish. makes it appear as if
            // the strips are linked on back end of robot
            output[i % NUM_LEDS_STRIP]        = CRGB::Black;
            output[(i + 1) % NUM_LEDS_STRIP]  = CRGB::DarkViolet;
            output[(i + 2) % NUM_LEDS_STRIP]  = CRGB::Purple;
            output[(i + 3) % NUM_LEDS_STRIP]  = CRGB::DarkViolet;
            output[(i + 4) % NUM_LEDS_STRIP]  = CRGB::Purple;
            output[(i + 5) % NUM_LEDS_STRIP]  = CRGB::DarkViolet;
            output[(i + 6) % NUM_LEDS_STRIP]  = CRGB::Purple;
            output[(i + 7) % NUM_LEDS_STRIP]  = CRGB::DarkViolet;
            output[(i + 8) % NUM_LEDS_STRIP]  = CRGB::Purple;
            output[(i + 9) % NUM_LEDS_STRIP]  = CRGB::DarkViolet;
            output[(i + 10) % NUM_LEDS_STRIP] = CRGB::Purple;
            break;
    }

    i++;
    i %= NUM_LEDS_STRIP;
}

void fire(CRGB *output) {
    static uint8_t i = 0;

    output[i % NUM_LEDS_STRIP]        = CRGB::DarkOrange;
    output[(i + 1) % NUM_LEDS_STRIP]  = CRGB::Maroon;
    output[(i + 2) % NUM_LEDS_STRIP]  = CRGB::Orange;
    output[(i + 3) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
    output[(i + 4) % NUM_LEDS_STRIP]  = CRGB::Orange;
    output[(i + 5) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
    output[(i + 6) % NUM_LEDS_STRIP]  = CRGB::Orange;
    output[(i + 7) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
    output[(i + 8) % NUM_LEDS_STRIP]  = CRGB::Orange;
    output[(i + 9) % NUM_LEDS_STRIP]  = CRGB::DarkOrange;
    output[(i + 10) % NUM_LEDS_STRIP] = CRGB::Orange;

    i++;
    i %= NUM_LEDS_STRIP;
}
