#include<DHT.h>
int pin =2;
int relay=9;
#define DHTTYPE DHT11
DHT dht (pin,DHTTYPE);//DHT is class And dht is the object
float t;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//baudrate of communication
dht.begin();
pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
t= dht.readTemperature();
if(t>30.0)digitalWrite(relay,HIGH);//turn on the fan
else digitalWrite(relay,LOW);
Serial.print("Temp=");
Serial.println(t);
delay(500);
}