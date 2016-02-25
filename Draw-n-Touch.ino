#include "MyLCD.h"

MyLCD lcd;
void setup() {
  RECT btn0;
  btn0.x = 50; btn0.y=100; btn0.sizex=100; btn0.sizey=30;
  
  lcd.vLCDInit(GREEN);
  lcd.vClean();
  lcd.vDrawButton(btn0,"1234",WHITE,BLACK,GREEN);


}

void loop() {

  lcd.vPress(true);
  delay(1000);
  lcd.vPress(false);
  delay(1000);

}
