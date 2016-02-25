#ifndef _DEF_MYLCD_
#define _DEF_MYLCD_

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//======LCD & Font Size define(for 2.4")=======
#define PIXEL_X  320
#define PIXEL_Y  240
#define FONT_X  7
#define FONT_Y  9
//====================================

typedef struct 
{ 
   unsigned int x;   
   unsigned int y;   
   unsigned int sizex;
   unsigned int sizey;
} RECT;
 
typedef struct 
{ 
   unsigned int x;   
   unsigned int y;   
} Point;

class MyLCD : public Adafruit_TFTLCD {

  public:
    MyLCD(void);
    void vInit(void); 
    void vLCDInit(uint16_t defBGcolor=BLACK, uint8_t dRotation=1);
    void vDrawText(RECT area, int textsize, String sText, uint16_t txtcolor, uint16_t bgcolor=0, bool bFillBG=false);
    void vDrawText(Point pt, int textsize, String sText, uint16_t txtcolor, uint16_t bgcolor=0, bool bFillBG=false);
    void vDrawButton(RECT area, String sText, uint16_t bndcolor, uint16_t txtcolor, uint16_t bgcolor);
    void vPress(boolean p);
    void vClean(void);
};

#endif //_DEF_MYLCD_
