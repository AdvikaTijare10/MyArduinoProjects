#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x3F,16,2); // address,size

void setup() {
  // put your setup code here, to run once:
lcd.init(); // starts the comm with lcd
lcd.backlight(); // turns ont he backlight;; lcd.nobacklight()
}

void loop() {
  // put your main code here, to run repeatedly:
page1();
page2();
page3();
page4();
//paging in lcd
}



