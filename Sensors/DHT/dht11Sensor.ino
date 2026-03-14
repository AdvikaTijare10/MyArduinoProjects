#include<DHT.h>
int pin =2;
#define DHTTYPE DHT11
DHT dht (pin,DHTTYPE);//DHT is class And dht is the object
float t,h;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);// 9600 is baudrate of communication . starts the communication
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
t= dht.readTemperature();
h=dht.readHumidity();

Serial.print("Temp="); // each char gets concverted into its ascii number-> binary-> bit by bit sent
Serial.println(t);
Serial.print("Humi=");
Serial.println(h);
delay(500);
}