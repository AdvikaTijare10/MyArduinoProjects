#include <Wire.h>
#include <uRTCLib.h>
#include<LiquidCrystal_I2C.h>
uRTCLib rtc(0x68);  // DS3231 I2C address
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Set RTC time ONCE, then comment out this line and re-upload
  // Format: rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // Example: 12:34:00 on Friday, July 26, 2024
  // Days of weeek("Sunday"=1, "Monday"=2, "Tuesday"=3, "Wednesday"=4, "Thursday"=5, "Friday"=6, "Saturday"=7)
   //rtc.set(0, 46, 19, 4, 18, 3, 26);  // (second, minute, hour, dayOfWeek, dayOfMonth, month, year)
   lcd.init();
   lcd.backlight();
}

void loop() {
rtc.refresh();  // Update RTC time
lcd.setCursor(0,0);
lcd.print("Time: ");
lcd.print(rtc.hour());
lcd.print(":");
lcd.print(rtc.minute());
lcd.print(":");
lcd.print(rtc.second());

lcd.setCursor(0,1);
lcd.print("Date:");
lcd.print(rtc.day());
lcd.print("/");
lcd.print(rtc.month());
lcd.print("/");
lcd.print(2000 + rtc.year());
delay(1000);
lcd.clear();

  // Refresh every second
}