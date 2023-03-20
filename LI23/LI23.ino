#include <FastLED.h>

#define NUM_LEDS_STRIP 30 // 30 leds in a 0.5m strip w/ 60 leds/m
#define NUM_LEDS_RING 24 // 24 leds in a ring

#define DATA_A 3 // DIO Pins for Strip Output
#define DATA_B 4
#define DATA_C 5
#define DATA_D 6

#define STRIP_a 0 // marks wich strip
#define STRIP_b 1
#define RING_a 2
#define RING_b 3

#define cBLANK 0 // output solid colors
#define cRED 1
#define cBLUE 2
#define cYELLOW 3
#define cPURPLE 4

#define CONE 0 // game pices
#define CUBE 1


#define GLOBAL_BRIGHTNESS 63 // Global Brightness

CRGB STRIP_A[NUM_LEDS_STRIP]; // define arays for two strips & two rings
CRGB STRIP_B[NUM_LEDS_STRIP];
CRGB RING_A[NUM_LEDS_RING];
CRGB RING_B[NUM_LEDS_RING];

uint8_t a = 0; // vars for scrolling animations (strips)
uint8_t b = 1;
uint8_t c = 2;
uint8_t d = 3;
uint8_t e = 4;
uint8_t f = 5;
uint8_t g = 6;
uint8_t h = 7;
uint8_t i = 8;
uint8_t j = 9;
uint8_t k = 10;

uint8_t A = 0; //vars for scoling animations (rings)
uint8_t B = 1;
uint8_t C = 2;
uint8_t D = 3;
uint8_t E = 4;
uint8_t F = 5;
uint8_t G = 6;
uint8_t H = 7;
uint8_t I = 8;

uint16_t randomNum = 0; // random number for the fire
byte fireStarter;
#define delayTime 0

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_A>(STRIP_A, NUM_LEDS_STRIP);
  FastLED.addLeds<NEOPIXEL, DATA_B>(STRIP_B, NUM_LEDS_STRIP);
  FastLED.addLeds<NEOPIXEL, DATA_C>(RING_A, NUM_LEDS_RING);
  FastLED.addLeds<NEOPIXEL, DATA_D>(RING_B, NUM_LEDS_RING);

  Serial.begin(115200);

  FastLED.setBrightness(GLOBAL_BRIGHTNESS);

  DDRB = 0b00000000; // set all of port B to input

}

void loop() {
  // check state of PB4-PB7 (on MEGA 2560 Digial 10-13)
  if ( PINB == 0b00000000 ){     //state 0 Clear
    solid(cBLANK, STRIP_a);
    solid(cBLANK, STRIP_b);
  }
  else if( PINB == 0b00010000 ){ //state 1 Red
    solid(cRED, STRIP_a);
    solid(cRED, STRIP_b);  
  }
  else if( PINB == 0b00100000){ //state 2 Blue
    solid(cBLUE, STRIP_a);
    solid(cBLUE, STRIP_b);
  }
  else if( PINB == 0b00110000){ //state 3 Yellow
    solid(cYELLOW, STRIP_a);
    solid(cYELLOW, STRIP_b);
  }
  else if( PINB == 0b01000000){ //state 4 Purple
    solid(cPURPLE, STRIP_a);
    solid(cPURPLE, STRIP_b);
  }
  else if( PINB == 0b01010000){ //state 5 Cone
    gamePiece(CONE, STRIP_a);
    gamePiece(CONE, STRIP_b);
    delay(20);
  }
  else if( PINB == 0b01100000){ //state 6 Cube
    gamePiece(CUBE, STRIP_a);
    gamePiece(CUBE, STRIP_b);
    delay(20);
  }
  else if( PINB == 0b01110000){ //state 7 Fire
    fire(STRIP_a);
    fire(STRIP_b);
    delay(20);
  }/*
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
  fireStarter = PINB;
}

 void solid(uint8_t color, uint8_t output){ // puts whole strip or ring to a solid color, curently blank, red, and blue
  if(color == cBLANK){ // make strip blank
      if(output == STRIP_a){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip a
        STRIP_A[i] = CRGB::Black;
        }
    }
    if(output == STRIP_b){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip b
        STRIP_B[i] = CRGB::Black;
      }
    }
    if(output == RING_a){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring a
        RING_A[i] = CRGB::Black;
      }
    }
    if(output == RING_b){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring b
        RING_B[i] = CRGB::Black;
      }
    }
  }
  if(color == cRED){ // make strip red
      if(output == STRIP_a){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip a
        STRIP_A[i] = CRGB::Red;
        }
    }
    if(output == STRIP_b){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip b
        STRIP_B[i] = CRGB::Red;
      }
    }
    if(output == RING_a){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring a
        RING_A[i] = CRGB::Red;
      }
    }
    if(output == RING_b){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring b
        RING_B[i] = CRGB::Red;
      }
    }
  } 
  if(color == cBLUE){ // make strip blue
      if(output == STRIP_a){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip a
        STRIP_A[i] = CRGB::Blue;
        }
    }
    if(output == STRIP_b){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip b
        STRIP_B[i] = CRGB::Blue;
      }
    }
    if(output == RING_a){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring a
        RING_A[i] = CRGB::Blue;
      }
    }
    if(output == RING_b){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring b
        RING_B[i] = CRGB::Blue;
      }
    }
  }
  if(color == cYELLOW){ // make strip blank
      if(output == STRIP_a){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip a
        STRIP_A[i] = CRGB::Yellow;
        }
    }
    if(output == STRIP_b){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip b
        STRIP_B[i] = CRGB::Yellow;
      }
    }
    if(output == RING_a){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring a
        RING_A[i] = CRGB::Yellow;
      }
    }
    if(output == RING_b){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring b
        RING_B[i] = CRGB::Yellow;
      }
    }
  }
  if(color == cPURPLE){ // make strip blank
      if(output == STRIP_a){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip a
        STRIP_A[i] = CRGB::Purple;
        }
    }
    if(output == STRIP_b){
      for(uint8_t i = 0; i < NUM_LEDS_STRIP; i++){ // strip b
        STRIP_B[i] = CRGB::Purple;
      }
    }
    if(output == RING_a){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring a
        RING_A[i] = CRGB::Purple;
      }
    }
    if(output == RING_b){
      for(uint8_t i = 0; i < NUM_LEDS_RING; i++){ // ring b
        RING_B[i] = CRGB::Purple;
      }
    }
  }
}

void gamePiece( uint8_t piece, uint8_t output){ // animation for game pices
  
  if(piece == CONE){ // animation for cone, should be yellow ish. makes it apear as if the strips are linked on back end of robot
    if(a == (NUM_LEDS_STRIP)){
        a = 0;
    }
    else if(b == (NUM_LEDS_STRIP)){
        b = 0;
    }
    else if(c == (NUM_LEDS_STRIP)){
      c = 0;
    }
    else if(d == (NUM_LEDS_STRIP)){
        d = 0;
    }
    else if(e == (NUM_LEDS_STRIP)){
        e = 0;
    }
    else if(f == (NUM_LEDS_STRIP)){
      f = 0;
    }
    else if(g == (NUM_LEDS_STRIP)){
        g = 0;
    }
    else if(h == (NUM_LEDS_STRIP)){
        h = 0;
    }
    else if(i == (NUM_LEDS_STRIP)){
      i = 0;
    }
    else if(j == (NUM_LEDS_STRIP)){
        j = 0;
    }
    else if(k == (NUM_LEDS_STRIP)){
        k = 0;
    }
    if(output == STRIP_a){
      STRIP_A[a] = CRGB::Black;
      STRIP_A[b] = CRGB::DarkOrange;
      STRIP_A[c] = CRGB::Yellow;
      STRIP_A[d] = CRGB::DarkOrange;
      STRIP_A[e] = CRGB::Yellow;
      STRIP_A[f] = CRGB::DarkOrange;
      STRIP_A[g] = CRGB::Yellow;
      STRIP_A[h] = CRGB::DarkOrange;
      STRIP_A[i] = CRGB::Yellow;
      STRIP_A[j] = CRGB::DarkOrange;
      STRIP_A[k] = CRGB::Yellow;
    }
    if(output == STRIP_b){
      STRIP_B[NUM_LEDS_STRIP - a] = CRGB::Black;
      STRIP_B[NUM_LEDS_STRIP - b] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - c] = CRGB::Yellow;
      STRIP_B[NUM_LEDS_STRIP - d] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - e] = CRGB::Yellow;
      STRIP_B[NUM_LEDS_STRIP - f] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - g] = CRGB::Yellow;
      STRIP_B[NUM_LEDS_STRIP - h] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - i] = CRGB::Yellow;
      STRIP_B[NUM_LEDS_STRIP - j] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - k] = CRGB::Yellow;
    }
    a++;
    b++;
    c++;
    d++;
    e++;
    f++;
    g++;
    h++;
    i++;
    j++;
    k++;
    if(A == (NUM_LEDS_STRIP)){
        A = 0;
    }
    else if(B == (NUM_LEDS_STRIP)){
        B = 0;
    }
    else if(C == (NUM_LEDS_STRIP)){
      C = 0;
    }
    else if(D == (NUM_LEDS_STRIP)){
        D = 0;
    }
    else if(E == (NUM_LEDS_STRIP)){
        E = 0;
    }
    else if(F == (NUM_LEDS_STRIP)){
      F = 0;
    }
    else if(G == (NUM_LEDS_STRIP)){
        G = 0;
    }
    else if(H == (NUM_LEDS_STRIP)){
        H = 0;
    }
    else if(I == (NUM_LEDS_STRIP)){
      I = 0;
    }
    if(output == STRIP_a){
      RING_A[A] = CRGB::Black;
      RING_A[B] = CRGB::DarkOrange;
      RING_A[C] = CRGB::Yellow;
      RING_A[D] = CRGB::DarkOrange;
      RING_A[E] = CRGB::Yellow;
      RING_A[F] = CRGB::DarkOrange;
      RING_A[G] = CRGB::Yellow;
      RING_A[H] = CRGB::DarkOrange;
      RING_A[I] = CRGB::Yellow;
    }
    if(output == STRIP_b){
      RING_B[NUM_LEDS_STRIP - A] = CRGB::Black;
      RING_B[NUM_LEDS_STRIP - B] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - C] = CRGB::Yellow;
      RING_B[NUM_LEDS_STRIP - D] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - E] = CRGB::Yellow;
      RING_B[NUM_LEDS_STRIP - F] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - G] = CRGB::Yellow;
      RING_B[NUM_LEDS_STRIP - H] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - I] = CRGB::Yellow;
    }
    A++;
    B++;
    C++;
    D++;
    E++;
    F++;
    G++;
    H++;
    I++;
  }
  if(piece == CUBE){ // animation for cone, should be purple ish. makes it apear as if the strips are linked on back end of robot
    if(a == (NUM_LEDS_STRIP)){
        a = 0;
    }
    else if(b == (NUM_LEDS_STRIP)){
        b = 0;
    }
    else if(c == (NUM_LEDS_STRIP)){
      c = 0;
    }
    else if(d == (NUM_LEDS_STRIP)){
       d = 0;
    }
    else if(e == (NUM_LEDS_STRIP)){
        e = 0;
    }
    else if(f == (NUM_LEDS_STRIP)){
      f = 0;
    }
    else if(g == (NUM_LEDS_STRIP)){
        g = 0;
    }
    else if(h == (NUM_LEDS_STRIP)){
        h = 0;
    }
    else if(i == (NUM_LEDS_STRIP)){
      i = 0;
    }
    else if(j == (NUM_LEDS_STRIP)){
        j = 0;
    }
    else if(k == (NUM_LEDS_STRIP)){
        k = 0;
    }
    if(output == STRIP_a){
      STRIP_A[a] = CRGB::Black;
      STRIP_A[b] = CRGB::DarkViolet;
      STRIP_A[c] = CRGB::Purple;
      STRIP_A[d] = CRGB::DarkViolet;
      STRIP_A[e] = CRGB::Purple;
      STRIP_A[f] = CRGB::DarkViolet;
      STRIP_A[g] = CRGB::Purple;
      STRIP_A[h] = CRGB::DarkViolet;
      STRIP_A[i] = CRGB::Purple;
      STRIP_A[j] = CRGB::DarkViolet;
      STRIP_A[k] = CRGB::Purple;
    }
    if(output == STRIP_b){
      STRIP_B[NUM_LEDS_STRIP - a] = CRGB::Black;
      STRIP_B[NUM_LEDS_STRIP - b] = CRGB::DarkViolet;
      STRIP_B[NUM_LEDS_STRIP - c] = CRGB::Purple;
      STRIP_B[NUM_LEDS_STRIP - d] = CRGB::DarkViolet;
      STRIP_B[NUM_LEDS_STRIP - e] = CRGB::Purple;
      STRIP_B[NUM_LEDS_STRIP - f] = CRGB::DarkViolet;
      STRIP_B[NUM_LEDS_STRIP - g] = CRGB::Purple;
      STRIP_B[NUM_LEDS_STRIP - h] = CRGB::DarkViolet;
      STRIP_B[NUM_LEDS_STRIP - i] = CRGB::Purple;
      STRIP_B[NUM_LEDS_STRIP - j] = CRGB::DarkViolet;
      STRIP_B[NUM_LEDS_STRIP - k] = CRGB::Purple;
    }
    a++;
    b++;
    c++;
    d++;
    e++;
    f++;
    g++;
    h++;
    i++;
    j++;
    k++;
    if(A == (NUM_LEDS_STRIP)){
        A = 0;
    }
    else if(B == (NUM_LEDS_STRIP)){
        B = 0;
    }
    else if(C == (NUM_LEDS_STRIP)){
      C = 0;
    }
    else if(D == (NUM_LEDS_STRIP)){
        D = 0;
    }
    else if(E == (NUM_LEDS_STRIP)){
        E = 0;
    }
    else if(F == (NUM_LEDS_STRIP)){
      F = 0;
    }
    else if(G == (NUM_LEDS_STRIP)){
        G = 0;
    }
    else if(H == (NUM_LEDS_STRIP)){
        H = 0;
    }
    else if(I == (NUM_LEDS_STRIP)){
      I = 0;
    }
    if(output == STRIP_a){
      RING_A[A] = CRGB::Black;
      RING_A[B] = CRGB::DarkViolet;
      RING_A[C] = CRGB::Purple;
      RING_A[D] = CRGB::DarkViolet;
      RING_A[E] = CRGB::Purple;
      RING_A[F] = CRGB::DarkViolet;
      RING_A[G] = CRGB::Purple;
      RING_A[H] = CRGB::DarkViolet;
      RING_A[I] = CRGB::Purple;
    }
    if(output == STRIP_b){
      RING_B[NUM_LEDS_RING - A] = CRGB::Black;
      RING_B[NUM_LEDS_RING - B] = CRGB::DarkViolet;
      RING_B[NUM_LEDS_RING - C] = CRGB::Purple;
      RING_B[NUM_LEDS_RING - D] = CRGB::DarkViolet;
      RING_B[NUM_LEDS_RING - E] = CRGB::Purple;
      RING_B[NUM_LEDS_RING - F] = CRGB::DarkViolet;
      RING_B[NUM_LEDS_RING - G] = CRGB::Purple;
      RING_B[NUM_LEDS_RING - H] = CRGB::DarkViolet;
      RING_B[NUM_LEDS_RING - I] = CRGB::Purple;
    }
    A++;
    B++;
    C++;
    D++;
    E++;
    F++;
    G++;
    H++;
    I++;
  }
}

void fire(uint8_t output){
  if(a == (NUM_LEDS_STRIP)){
        a = 0;
    }
    else if(b == (NUM_LEDS_STRIP)){
        b = 0;
    }
    else if(c == (NUM_LEDS_STRIP)){
      c = 0;
    }
    else if(d == (NUM_LEDS_STRIP)){
        d = 0;
    }
    else if(e == (NUM_LEDS_STRIP)){
        e = 0;
    }
    else if(f == (NUM_LEDS_STRIP)){
      f = 0;
    }
    else if(g == (NUM_LEDS_STRIP)){
        g = 0;
    }
    else if(h == (NUM_LEDS_STRIP)){
        h = 0;
    }
    else if(i == (NUM_LEDS_STRIP)){
      i = 0;
    }
    else if(j == (NUM_LEDS_STRIP)){
        j = 0;
    }
    else if(k == (NUM_LEDS_STRIP)){
        k = 0;
    }
    if(output == STRIP_a){
      STRIP_A[a] = CRGB::DarkOrange;
      STRIP_A[b] = CRGB::Maroon;
      STRIP_A[c] = CRGB::Orange;
      STRIP_A[d] = CRGB::DarkOrange;
      STRIP_A[e] = CRGB::Orange;
      STRIP_A[f] = CRGB::DarkOrange;
      STRIP_A[g] = CRGB::Orange;
      STRIP_A[h] = CRGB::DarkOrange;
      STRIP_A[i] = CRGB::Orange;
      STRIP_A[j] = CRGB::DarkOrange;
      STRIP_A[k] = CRGB::Orange;
    }
    if(output == STRIP_b){
      STRIP_B[NUM_LEDS_STRIP - a] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - b] = CRGB::Maroon;
      STRIP_B[NUM_LEDS_STRIP - c] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - d] = CRGB::Maroon;
      STRIP_B[NUM_LEDS_STRIP - e] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - f] = CRGB::Maroon;
      STRIP_B[NUM_LEDS_STRIP - g] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - h] = CRGB::Maroon;
      STRIP_B[NUM_LEDS_STRIP - i] = CRGB::DarkOrange;
      STRIP_B[NUM_LEDS_STRIP - j] = CRGB::Maroon;
      STRIP_B[NUM_LEDS_STRIP - k] = CRGB::DarkOrange;
    }
    a++;
    b++;
    c++;
    d++;
    e++;
    f++;
    g++;
    h++;
    i++;
    j++;
    k++;
    if(A == (NUM_LEDS_STRIP)){
        A = 0;
    }
    else if(B == (NUM_LEDS_STRIP)){
        B = 0;
    }
    else if(C == (NUM_LEDS_STRIP)){
      C = 0;
    }
    else if(D == (NUM_LEDS_STRIP)){
        D = 0;
    }
    else if(E == (NUM_LEDS_STRIP)){
        E = 0;
    }
    else if(F == (NUM_LEDS_STRIP)){
      F = 0;
    }
    else if(G == (NUM_LEDS_STRIP)){
        G = 0;
    }
    else if(H == (NUM_LEDS_STRIP)){
        H = 0;
    }
    else if(I == (NUM_LEDS_STRIP)){
      I = 0;
    }
    if(output == STRIP_a){
      RING_A[A] = CRGB::DarkOrange;
      RING_A[B] = CRGB::Maroon;
      RING_A[C] = CRGB::DarkOrange;
      RING_A[D] = CRGB::Maroon;
      RING_A[E] = CRGB::DarkOrange;
      RING_A[F] = CRGB::Maroon;
      RING_A[G] = CRGB::DarkOrange;
      RING_A[H] = CRGB::Maroon;
      RING_A[I] = CRGB::DarkOrange;
    }
    if(output == STRIP_b){
      RING_B[NUM_LEDS_STRIP - A] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - B] = CRGB::Maroon;
      RING_B[NUM_LEDS_STRIP - C] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - D] = CRGB::Maroon;
      RING_B[NUM_LEDS_STRIP - E] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - F] = CRGB::Maroon;
      RING_B[NUM_LEDS_STRIP - G] = CRGB::DarkOrange;
      RING_B[NUM_LEDS_STRIP - H] = CRGB::Maroon;
      RING_B[NUM_LEDS_STRIP - I] = CRGB::DarkOrange;
    }
    A++;
    B++;
    C++;
    D++;
    E++;
    F++;
    G++;
    H++;
    I++;
  }
