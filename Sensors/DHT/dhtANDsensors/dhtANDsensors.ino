#include<DHT.h>
#include <LiquidCrystal_I2C.h>
int DHTpin=2;
int IRpin=8;
int LDRpin=10;
#define DHTTYPE DHT11
DHT dht(DHTpin,DHTTYPE);
LiquidCrystal_I2C lcd(0x3F,16,2);
float t,h;
void setup() {
  // put your setup code here, to run once:
dht.begin();
lcd.init();
lcd.backlight();
pinMode(IRpin,INPUT);
pinMode(LDRpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
t=dht.readTemperature();
h=dht.readHumidity();
Welcome();
delay(1000);
lcd.clear();
Temp();
delay(1000);
lcd.clear();
Humidity();
delay(1000);
lcd.clear();
IRsensor();
delay(1000);
lcd.clear();
LDRsensor();
delay(1000);
lcd.clear();
Thankyou();
delay(1000);
lcd.clear();
}
