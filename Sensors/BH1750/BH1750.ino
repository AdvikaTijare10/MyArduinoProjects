#include<Wire.h>//dependant lib for all i2c sensors
#include<BH1750.h>//main lib
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
BH1750 lightMeter;

float lux;
void setup() {
  Serial.begin(9600);
  Wire.begin();
lightMeter.begin();
// Serial.println(F("BH1750 Test begin"));
lcd.init();
lcd.backlight();
}

void loop() {
lux = lightMeter.readLightLevel();
  Serial.print("The value of light =");
  Serial.print(lux);
  Serial.println("lx ");
  lcd.setCursor(0,0);
  lcd.print("Light Intensity");
  lcd.setCursor(0,1);
  lcd.print(lux );
  lcd.print(" lux");
  
  delay(1000);

}