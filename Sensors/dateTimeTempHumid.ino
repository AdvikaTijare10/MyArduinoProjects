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

void setup() {
  Serial.begin(9600);

  Wire.begin();
  dht.begin();

  // Set time ONCE (uncomment and upload once, then comment again)
  // rtc.set(0, 7, 18, 6, 20, 3, 26);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD fail");
    return;
  }

  Serial.println("SD OK");

  // Create file if not exists
  if (!SD.exists("weather.csv")) {
    Serial.println("Creating file...");

    dataFile = SD.open("weather.csv", FILE_WRITE);

    if (dataFile) {
      dataFile.println("Date,Time,Temperature,Humidity");
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

  dataFile = SD.open("weather.csv", FILE_WRITE);

  if (dataFile) {

    // Date
    dataFile.print(rtc.day());
    dataFile.print("/");
    dataFile.print(rtc.month());
    dataFile.print("/20");
    dataFile.print(rtc.year());
    dataFile.print(",");

    // Time
    dataFile.print(rtc.hour());
    dataFile.print(":");
    dataFile.print(rtc.minute());
    dataFile.print(":");
    dataFile.print(rtc.second());
    dataFile.print(",");

    // Sensor data
    dataFile.print(t);
    dataFile.print(",");
    dataFile.println(h);

    dataFile.close();

    Serial.println("Data logged");
  } else {
    Serial.println("Error opening file");
  }

  delay(2000);
}