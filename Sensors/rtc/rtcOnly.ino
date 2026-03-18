#include <Wire.h>
#include <uRTCLib.h>

uRTCLib rtc(0x68);  // DS3231 I2C address

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Set RTC time ONCE, then comment out this line and re-upload
  // Format: rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // Example: 12:34:00 on Friday, July 26, 2024
  // Days of weeek("Sunday"=1, "Monday"=2, "Tuesday"=3, "Wednesday"=4, "Thursday"=5, "Friday"=6, "Saturday"=7)
   //rtc.set(0, 46, 19, 4, 18, 3, 26);  // (second, minute, hour, dayOfWeek, dayOfMonth, month, year)
}

void loop() {
  rtc.refresh();  // Update RTC time

  Serial.print("Time: ");
  Serial.print(rtc.hour());
  Serial.print(":");
  Serial.print(rtc.minute());
  Serial.print(":");
  Serial.print(rtc.second());

  Serial.print(" | Date: ");
  Serial.print(rtc.day());
  Serial.print("/");
  Serial.print(rtc.month());
  Serial.print("/");
  Serial.print(2000 + rtc.year());

  Serial.println();

  delay(1000);  // Refresh every second
}