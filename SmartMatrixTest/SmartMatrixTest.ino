#include <MatrixHardware_Teensy4_ShieldV5.h>        // SmartLED Shield for Teensy 4 (V5)


#include <SmartMatrix.h>
#include <FastLED.h>

#define COLOR_DEPTH 24
const uint16_t kMatrixWidth = 32;       // Set to the width of your display, must be a multiple of 8
const uint16_t kMatrixHeight = 16;      // Set to the height of your display
const uint8_t kRefreshDepth = 36;       // Tradeoff of color quality vs refresh rate, max brightness, and RAM usage.  36 is typically good, drop down to 24 if you need to.  On Teensy, multiples of 3, up to 48: 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48.  On ESP32: 24, 36, 48
const uint8_t kDmaBufferRows = 4;       // known working: 2-4, use 2 to save RAM, more to keep from dropping frames and automatically lowering refresh rate.  (This isn't used on ESP32, leave as default)
const uint8_t kPanelType = SM_PANELTYPE_HUB75_32ROW_MOD16SCAN;   // Choose the configuration that matches your panels.  See more details in MatrixCommonHub75.h and the docs: https://github.com/pixelmatix/SmartMatrix/wiki
const uint32_t kMatrixOptions = (SM_HUB75_OPTIONS_NONE);        // see docs for options: https://github.com/pixelmatix/SmartMatrix/wiki
const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);
const uint8_t kScrollingLayerOptions = (SM_SCROLLING_OPTIONS_NONE);

SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions);
SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);
SMARTMATRIX_ALLOCATE_SCROLLING_LAYER(scrollingLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kScrollingLayerOptions);

static uint16_t x;
static uint16_t y;
static uint16_t z;

#define NUM_LEDS 512
#define DATA_PIN 13
#define BRIGHTNESS 100
#define WIDTH 32
#define HIGHT 16

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);

  matrix.addLayer(&backgroundLayer); 
  matrix.begin();
  
  backgroundLayer.setBrightness(255); 
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

}

void loop() {
rgb24 *buffer = backgroundLayer.backBuffer();
  
setcolor(5, 2, (rgb24)CRGB::Black);
backgroundLayer.swapBuffers(false);
delay(1000);


setcolor(5, 2, (rgb24)CRGB::Red);
backgroundLayer.swapBuffers(false);
delay(1000);



}

void setcolor(int row , int col, rgb24 color) { //setcolor(2, 2, (rgb24)CRGB(0,255,0));
  rgb24 *buffer = backgroundLayer.backBuffer(); //setcolor(2, 2, (rgb24)CRGB::Color);
  int n = 0;
  n = row * WIDTH + col;
  buffer[n] = color;
}





