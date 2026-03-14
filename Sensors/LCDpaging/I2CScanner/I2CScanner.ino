#include <Wire.h>

void setup() {
  Serial.begin(9600); // Start the serial communication at 9600 baud rate
  Wire.begin();       // Join the I2C bus
  Serial.println("I2C Scanner");
}

void loop() {
  byte error, address;
  int count = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    // The I2C address can be from 1 to 127
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");
      count++;
      delay(10);  // Wait a bit before the next scan
    }
  }

  if (count == 0) {
    Serial.println("No I2C devices found");
  } else {
    Serial.println("Scan completed.");
  }

  delay(5000); // Wait 5 seconds before scanning again
}