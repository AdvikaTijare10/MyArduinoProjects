#include <Wire.h>
#include <uRTCLib.h>

// Create RTC object
uRTCLib rtc(0x68);  // DS3231 I2C address

 int ledPin = 2;  // LED connected to pin 8

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(ledPin, OUTPUT);

  // Set time once, then comment out
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // rtc.set(0, 0, 7, 5, 26, 7, 24); // 7:00:00 on Friday, 26 July 2024
}

void loop() {
  rtc.refresh();  // Refresh RTC time

  int hour = rtc.hour();
  int minute = rtc.minute();
  int second = rtc.second();

  // Print current time for debugging
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);

  // Turn LED ON at exactly 7:00:00
  if (hour == 20 && minute == 9 && second == 10) {
    digitalWrite(ledPin, HIGH);
  
  }

  // Turn LED OFF at exactly 7:01:00
  if (hour == 20 && minute == 9 && second == 20) {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);  // Wait 1 second
}