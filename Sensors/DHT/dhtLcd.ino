#include<DHT.h>
#include<LiquidCrystal_I2C.h>
int pin =2;
#define DHTTYPE DHT11
DHT dht (pin,DHTTYPE);//DHT is class And dht is the object
float t,h;
LiquidCrystal_I2C lcd (0x3F,16,2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);// 9600 is baudrate of communication . starts the communication
dht.begin();
lcd.init();
lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
t= dht.readTemperature();
h=dht.readHumidity();

lcd.setCursor(0,0);
lcd.print("Temperature ");
lcd.print(t);
lcd.setCursor(0,1);
lcd.print("Humidity ");
lcd.print(h);
delay(1000);
lcd.clear();
}