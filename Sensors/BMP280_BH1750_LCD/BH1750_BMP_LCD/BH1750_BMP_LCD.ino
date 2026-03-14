#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include<LiquidCrystal_I2C.h>
#include<BH1750.h>
#define SEALEVELPRESSURE_HPA (1013.25)
LiquidCrystal_I2C lcd(0x3F,16,2);
BH1750 lightmeter;
Adafruit_BMP280 bmp;  
float a,t,p,lux;
void setup() {
  // put your setup code here, to run once:
Wire.begin();
lightmeter.begin();
if (!bmp.begin(0x76)) {
  Serial.println("BMP280 not found!");
  while (1);
}
lcd.init();
lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
lux=lightmeter.readLightLevel();
t=bmp.readTemperature();
a=bmp.readAltitude(SEALEVELPRESSURE_HPA);
p=bmp.readPressure()/ 100.0F;
welcome();
Lightlevel();
temp();
pressure();
altitude();
}
