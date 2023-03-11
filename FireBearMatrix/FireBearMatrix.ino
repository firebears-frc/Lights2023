#include <MatrixHardware_Teensy4_ShieldV5.h>        // SmartLED Shield for Teensy 4 (V5)


int Pix1 = 17;//Col
int Pix2 = 0; //Row

//Fire Color
int Col1 = 255;  //red  
int Col2 = 0;    //green
int Col3 = 0;    //blue

//Bear Color
int Col21 = 255;   //red
int Col22 = 255;   //green
int Col23 = 255;   //Blue

//Eye Color
int Col31 = 255;   //red
int Col32 = 0;   //green
int Col33 = 0;   //Blue

//background color
int Col41 = 0;   //red
int Col42 = 0;   //green
int Col43 = 0;   //Blue


const int X = 124;
//x
//y
//red
//green
//blue

uint8_t thing[5][X] = {   

  {Pix1,Pix1+1,Pix1+2,Pix1+3,Pix1+4,Pix1+5,Pix1+6,Pix1+7,Pix1+8,Pix1+8,Pix1+8,Pix1+8,Pix1+8,Pix1+8,Pix1+8,Pix1+8 ,Pix1+8 ,Pix1+7 ,Pix1+7,Pix1+6,Pix1+7,Pix1+6,Pix1+5,Pix1+5,Pix1+5  ,Pix1+5 ,Pix1+5 ,Pix1+4 ,Pix1+4 ,Pix1+3,Pix1+2,Pix1+2 ,Pix1+2 ,Pix1+2 ,Pix1+2 ,Pix1+2 ,Pix1+2 ,Pix1+1 ,Pix1+1 ,Pix1   ,Pix1-1 ,Pix1-1,Pix1-2 ,Pix1-2 ,Pix1-2 ,Pix1-3 ,Pix1-3 ,Pix1-4 ,Pix1-4 ,Pix1-5 ,Pix1-5 ,Pix1-6 ,Pix1-6 ,Pix1-6 ,Pix1-7 ,Pix1-7,Pix1-7,Pix1-7,Pix1-7,Pix1-7,Pix1-7,Pix1-7,Pix1-6,Pix1-5,Pix1-4,Pix1-3,Pix1-2,Pix1-1, Pix1  ,Pix1+1,Pix1+2,Pix1-1,Pix1-2, Pix1  ,Pix1+1,Pix1+2,Pix1+3,Pix1-1,Pix1-2,Pix1-3, Pix1  ,Pix1+1,Pix1+2,Pix1+3,Pix1+4,Pix1-1,Pix1-2,Pix1-3, Pix1  ,Pix1+1,Pix1+2,Pix1+3,Pix1+4,Pix1-1,Pix1-2,Pix1-3, Pix1  ,Pix1+1,Pix1+2,Pix1+3,Pix1+4,Pix1-1,Pix1-2,Pix1-3, Pix1  ,Pix1+1,Pix1+2,Pix1+3,Pix1+4,Pix1-1,Pix1-2,Pix1-3, Pix1  ,Pix1+1,Pix1+2,Pix1+3,Pix1+4,Pix1+5,Pix1-1,Pix1-2,Pix1-3,Pix1-4, Pix1+4,Pix1-3},
  {Pix2,Pix2  ,Pix2  ,Pix2  ,Pix2  ,Pix2  ,Pix2+1,Pix2+2,Pix2+3,Pix2+4,Pix2+5,Pix2+6,Pix2+7,Pix2+8,Pix2+9,Pix2+10,Pix2+11,Pix2+10,Pix2+9,Pix2+8,Pix2+9,Pix2+8,Pix2+9,Pix2+10,Pix2+11,Pix2+12,Pix2+13,Pix2+11,Pix2+10,Pix2+9,Pix2+9,Pix2+10,Pix2+11,Pix2+12,Pix2+13,Pix2+14,Pix2+15,Pix2+13,Pix2+12,Pix2+11,Pix2+10,Pix2+9,Pix2+11,Pix2+12,Pix2+13,Pix2+12,Pix2+11,Pix2+11,Pix2+10,Pix2+11,Pix2+12,Pix2+11,Pix2+12,Pix2+13,Pix2+10,Pix2+9,Pix2+8,Pix2+7,Pix2+6,Pix2+5,Pix2+4,Pix2+3,Pix2+2,Pix2+1,Pix2  ,Pix2  ,Pix2  ,Pix2  , Pix2+1,Pix2+1,Pix2+1,Pix2+1,Pix2+1, Pix2+2,Pix2+2,Pix2+2,Pix2+2,Pix2+2,Pix2+2,Pix2+2, Pix2+3,Pix2+3,Pix2+3,Pix2+3,Pix2+3,Pix2+3,Pix2+3,Pix2+3, Pix2+4,Pix2+4,Pix2+4,Pix2+4,Pix2+4,Pix2+4,Pix2+4,Pix2+4, Pix2+5,Pix2+5,Pix2+5,Pix2+5,Pix2+5,Pix2+5,Pix2+5,Pix2+5, Pix2+6,Pix2+6,Pix2+6,Pix2+6,Pix2+6,Pix2+6,Pix2+6,Pix2+6, Pix2+7,Pix2+7,Pix2+7,Pix2+7,Pix2+7,Pix2+7,Pix2+7,Pix2+7,Pix2+7,Pix2+7, Pix2+8,Pix2+8},
  {Col1,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1   ,Col1   ,Col1   ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1  ,Col1  ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1  ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1   ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  ,Col1  , Col21 ,Col21 ,Col21 ,Col21 ,Col21 , Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 , Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 , Col21 ,Col21 ,Col31  ,Col21 ,Col21 ,Col31  ,Col21 ,Col21 , Col21 ,Col21 ,Col21 ,Col31  ,Col21 ,Col21 ,Col31  ,Col21 , Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 , Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 ,Col21 , Col21 ,Col21 },
  {Col2,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2   ,Col2   ,Col2   ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2  ,Col2  ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2  ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2   ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  ,Col2  , Col22 ,Col22 ,Col22 ,Col22 ,Col22 , Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 , Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 , Col22 ,Col22 ,Col32  ,Col22 ,Col22 ,Col32  ,Col22 ,Col22 , Col22 ,Col22 ,Col22 ,Col32  ,Col22 ,Col22 ,Col32  ,Col22 , Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 , Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 ,Col22 , Col22 ,Col22 },
  {Col3,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3   ,Col3   ,Col3   ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3  ,Col3  ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3  ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3   ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  ,Col3  , Col23 ,Col23 ,Col23 ,Col23 ,Col23 , Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 , Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 , Col23 ,Col23 ,Col33  ,Col23 ,Col23 ,Col33  ,Col23 ,Col23 , Col23 ,Col23 ,Col23 ,Col33  ,Col23 ,Col23 ,Col33  ,Col23 , Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 , Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 ,Col23 , Col23 ,Col23 },

};

#include <SmartMatrix.h>
#include <FastLED.h>

#define COLOR_DEPTH 24
const uint16_t kMatrixWidth = 64;       // Set to the width of your display, must be a multiple of 8
const uint16_t kMatrixHeight = 16;      // Set to the height of your display
const uint8_t kRefreshDepth = 36;       // Tradeoff of color quality vs refresh rate, max brightness, and RAM usage.  36 is typically good, drop down to 24 if you need to.  On Teensy, multiples of 3, up to 48: 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48.  On ESP32: 24, 36, 48 
const uint8_t kDmaBufferRows = 4;       // known working: 2-4, use 2 to save RAM, more to keep from dropping frames and automatically lowering refresh rate.  (This isn't used on ESP32, leave as default)
const uint8_t kPanelType = SM_PANELTYPE_HUB75_16ROW_MOD8SCAN;   // Choose the configuration that matches your panels.  See more details in MatrixCommonHub75.h and the docs: https://github.com/pixelmatix/SmartMatrix/wiki
const uint32_t kMatrixOptions = (SM_HUB75_OPTIONS_NONE);        // see docs for options: https://github.com/pixelmatix/SmartMatrix/wiki
const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);
const uint8_t kScrollingLayerOptions = (SM_SCROLLING_OPTIONS_NONE);

SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions);
SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);
SMARTMATRIX_ALLOCATE_SCROLLING_LAYER(scrollingLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kScrollingLayerOptions);

static uint16_t x;
static uint16_t y;
static uint16_t z;

#define WIDTH 64
#define HIGHT 16



void setup() {
  Serial.begin(115200);

  matrix.addLayer(&backgroundLayer); 
  matrix.begin();

 for(uint8_t p = 0; p < 64; p++){ 
    setcolor(0,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(1,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(2,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(3,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(4,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(5,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(6,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(7,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(8,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(9,p,  (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(10,p, (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(11,p, (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(12,p, (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(13,p, (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(14,p, (rgb24)CRGB(Col41,Col42,Col43));
    setcolor(15,p, (rgb24)CRGB(Col41,Col42,Col43));
}
 backgroundLayer.swapBuffers(false);
 
}

void loop() {
rgb24 *buffer = backgroundLayer.backBuffer();

  


for(uint8_t i = 0; i < X; i++){
  setcolor(thing[1][i],thing[0][i], (rgb24)CRGB(thing[2][i],thing[3][i],thing[4][i]));
}

  backgroundLayer.swapBuffers(false);

}

void setcolor(int row , int col, rgb24 color) { //setcolor(2, 2, (rgb24)CRGB(0,255,0));
  rgb24 *buffer = backgroundLayer.backBuffer(); //setcolor(2, 2, (rgb24)CRGB::Color);
  int n = 0;
  n = row * WIDTH + col;
  buffer[n] = color;
}
