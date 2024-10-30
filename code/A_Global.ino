bool lowPower = false;
/*
screen setup
-nice!view 160x68 sharp memory display
similar github:
https://github.com/karnadii/sharp_memory_display_breakout
parts from:
https://nicekeyboards.com/nice-view/

uses Adafruit_GFX and Adafruit_SharpMem librarys
*/
//libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <Fonts/FreeSerif24pt7b.h>
//pin defs
const int SHARP_SCK = 0;
const int SHARP_MOSI = 2;
const int SHARP_SS = 1;

//defining screen object
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 160, 68);

//color definitions
#define BLACK 0
#define WHITE 1

/*
3 way navigation switch setup
-3 way navigation switch
parts from:
https://www.amazon.com/dp/B0147XLUVS?psc=1&ref=ppx_yo2ov_dt_b_product_details
LFDZ 32

uses ezButton library
*/
//libraries
#include <ezButton.h>
//HELP! FIX PIN DEFS!!!
#define up_pin 4
#define down_pin 3
#define ok_pin 13

//defining objects
ezButton up(up_pin);
ezButton down(down_pin);
ezButton ok(ok_pin);

/*
Trinket M0 adafruit dotstar
-the main board
parts from:
https://www.adafruit.com/product/3500
referance:
https://learn.adafruit.com/adafruit-dotstar-leds/arduino-library-use
uses Adafruit_DotStar library for led control
*/
//library
#include <Adafruit_DotStar.h>

//defining object
Adafruit_DotStar strip(DOTSTAR_NUM, PIN_DOTSTAR_DATA, PIN_DOTSTAR_CLK, DOTSTAR_BRG);


//low power
#include "ArduinoLowPower.h"

volatile unsigned long sleeep=0;
