#include "MyLCD.h"


uint16_t identifier;
RECT top;
Point center;

uint16_t dDefBGColor;

Adafruit_GFX_Button btn;

MyLCD::MyLCD(void) : Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET)
{
  vInit();
}

void MyLCD::vInit(void)
{
  // ===TFT init ===
  center.x= PIXEL_X*2; center.y=PIXEL_Y*2; 
  top.x=0; top.y=0; top.sizex=PIXEL_X; top.sizey=PIXEL_Y;  // draw area

}

void MyLCD::vLCDInit(uint16_t defBGcolor,uint8_t dRotation)
{
  Point pt;

  dDefBGColor = defBGcolor;
  reset();
  identifier = readID();
  if((identifier==0x0101) || (identifier==0))
      identifier=0x9341;
  /*
  if(identifier == 0x9325) {
   // Serial.println(F("Found ILI9325 LCD driver"));
  } else if(identifier == 0x4535) {
   // Serial.println(F("Found LGDP4535 LCD driver"));
  }else if(identifier == 0x9328) {
   // Serial.println(F("Found ILI9328 LCD driver"));
  } else if(identifier == 0x7575) {
   // Serial.println(F("Found HX8347G LCD driver"));
  } else if(identifier == 0x9341) {
   // Serial.println(F("Found ILI9341 LCD driver"));
  } else if(identifier == 0x8357) {
   // Serial.println(F("Found HX8357D LCD driver"));
  } else {
   // Serial.print(F("Found LCD ID: "));
   // Serial.println(identifier,HEX);
    //return;
  }
  */
  begin(identifier);
  setRotation(dRotation);
  vClean();
  pt.x = 0; pt.y = 100;
  vDrawText(pt,2,"LCTD ID: 0x"+String(identifier,HEX)+"\r\nInit Completed!", WHITE);
  
  //drawCircle(100,100,50,BLUE);
}

void MyLCD::vDrawText(Point pt, int textsize, String sText, uint16_t txtcolor, uint16_t bgcolor, bool bFillBG)
{
  RECT area;
  int strLen = 0;
  
  strLen = sText.length();
  area.x = pt.x;
  area.y = pt.y;
  area.sizex = FONT_X*strLen*textsize;
  area.sizey = FONT_Y*textsize;
  vDrawText(area, textsize, sText, txtcolor, bgcolor, bFillBG);
}
void MyLCD::vDrawText(RECT area, int textsize, String sText, uint16_t txtcolor, uint16_t bgcolor, bool bFillBG)
{
  
  setTextColor(txtcolor);
  setCursor(area.x,area.y);
  setTextSize(textsize);
  if (bFillBG)
    fillRect(area.x,area.y, area.sizex, area.sizey, bgcolor);
  setCursor(area.x+1,area.y+1); 
  print(sText);
  
}

 void MyLCD::vDrawButton(RECT area, String sText, uint16_t bndcolor, uint16_t txtcolor, uint16_t bgcolor)
 {
  char  text[10];
  int textsize = (area.sizey/FONT_Y)-1;  // auto cala font size
  
  sText.toCharArray(text,10);
  btn.initButton((Adafruit_GFX *)this,area.x,area.y,area.sizex,area.sizey,bndcolor,bgcolor,txtcolor,text,textsize);
  btn.drawButton();
 }

 void MyLCD::vPress(boolean p)
 {
  btn.drawButton(p);
  btn.press(p);
  
 }

 void MyLCD::vClean(void)
 {
  fillScreen(dDefBGColor);
 }

