#include<DHT.h>
#include <LiquidCrystal_I2C.h>
int pin=2;
#define DHTTYPE DHT11
DHT dht(pin,DHTTYPE);
LiquidCrystal_I2C lcd(0x3F,16,2);
float t,h;
void setup() {
dht.begin();
lcd.init();
lcd.backlight();
}
void loop() {
t=dht.readTemperature();
h=dht.readHumidity();
page1();
delay(1000);
lcd.clear();
page2();
delay(1000);
lcd.clear();
page3();
delay(1000);
lcd.clear();
}

