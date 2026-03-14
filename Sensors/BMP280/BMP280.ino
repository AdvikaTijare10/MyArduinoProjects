#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include<LiquidCrystal_I2C.h>
#define SEALEVELPRESSURE_HPA (1013.25)    //hPa = Hecto Pascal

Adafruit_BMP280 bmp;    // Class & Object
LiquidCrystal_I2C lcd(0x3F,16,2);
float t,p,a;
void setup() 
{
  Serial.begin(9600);
  if (!bmp.begin(0x76))   //SDA & SCL lines tries to detect address 0x76 for Sensor
  {
    Serial.println("Could not find a valid bmp280 sensor, check wiring!");
    while (1);
  }
  lcd.init();
  lcd.backlight();
}

void loop() 
{ 
  t = bmp.readTemperature();
  p = bmp.readPressure() / 100.0F;  // To get reading in hPa
  a = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C");
  Serial.print("\t");

  Serial.print("Pressure = ");
  Serial.print(p);
  Serial.print(" hPa");
  Serial.print("\t");

  Serial.print("Approx. Altitude = ");
  Serial.print(a);
  Serial.println("m");
  temp();
  delay(1000);
  pressure();
  delay(1000);
  altitude();
  delay(1000);
  delay(2000);
}