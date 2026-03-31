#include <SPI.h>
#include <SD.h>
#include <DHT.h>
#include <Wire.h>
#include <uRTCLib.h>

#define DHTPIN 2
#define DHTTYPE DHT11
int chipSelect = 8;

DHT dht(DHTPIN, DHTTYPE);
uRTCLib rtc(0x68);
File dataFile;

int IRpin=4;
int gasPin=7;
int flamePin=6;
int ldrPin=5;
int uvPin=3;

void setup() {
  Serial.begin(9600);
  pinMode(IRpin,INPUT);
  pinMode(gasPin,INPUT);
  pinMode(flamePin,INPUT);
  pinMode(ldrPin,INPUT);

  Wire.begin();
  dht.begin();

  // rtc.set(0, 7, 18, 6, 20, 3, 26);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD fail");
    return;
  }

  Serial.println("SD OK");

  if (!SD.exists("data.csv")) {
    Serial.println("Creating file...");

    dataFile = SD.open("data.csv", FILE_WRITE);

    if (dataFile) {
      dataFile.println("Date,Time,Temperature,Humidity,IRsensor,GASsensor,LDRsensor,FLAMEsensor");
      dataFile.close();
      Serial.println("Header written");
    } else {
      Serial.println("File open FAILED");
    }
  } 
}

void loop() {

  rtc.refresh();

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor error");
    delay(2000);
    return;
  }

  // Read sensors first
  int IRval = digitalRead(IRpin);
  int GASval = digitalRead(gasPin);
  int LDRval = digitalRead(ldrPin);
  int Flameval = digitalRead(flamePin);

  // Convert to YES/NO
  String IRs = (IRval == LOW) ? "yes" : "no";
  String GASs = (GASval == LOW) ? "yes" : "no";
  String LDRs = (LDRval == LOW) ? "yes" : "no";
  String FLAMEs = (Flameval == LOW) ? "yes" : "no";

  // ---------------- SERIAL PRINT ----------------
  Serial.print(rtc.day()); Serial.print("/");
  Serial.print(rtc.month()); Serial.print("/20");
  Serial.print(rtc.year()); Serial.print(",");

  Serial.print(rtc.hour()); Serial.print(":");
  Serial.print(rtc.minute()); Serial.print(":");
  Serial.print(rtc.second()); Serial.print(",");

  Serial.print(t); Serial.print(",");
  Serial.print(h); Serial.print(",");

  Serial.print(IRs); Serial.print(",");
  Serial.print(GASs); Serial.print(",");
  Serial.print(LDRs); Serial.print(",");
  Serial.println(FLAMEs);
  // ------------------------------------------------

  dataFile = SD.open("data.csv", FILE_WRITE);

  if (dataFile) {

    dataFile.print(rtc.day());
    dataFile.print("/");
    dataFile.print(rtc.month());
    dataFile.print("/20");
    dataFile.print(rtc.year());
    dataFile.print(",");

    dataFile.print(rtc.hour());
    dataFile.print(":");
    dataFile.print(rtc.minute());
    dataFile.print(":");
    dataFile.print(rtc.second());
    dataFile.print(",");

    dataFile.print(t);
    dataFile.print(",");
    dataFile.print(h);
    dataFile.print(",");

    dataFile.print(IRs); dataFile.print(",");
    dataFile.print(GASs); dataFile.print(",");
    dataFile.print(LDRs); dataFile.print(",");
    dataFile.println(FLAMEs);

    dataFile.close();

    Serial.println("Data logged");
  } 
  else {
    Serial.println("Error opening file");
  }

  delay(2000);
}