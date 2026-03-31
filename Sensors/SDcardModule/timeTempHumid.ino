// #include <SPI.h>        // Library for SPI communication (used by SD card)
// #include <SD.h>         // Library to control SD card
// #include <DHT.h>        // Library for DHT temperature & humidity sensor

// // -------- Pin Definitions --------
// #define DHTPIN 2        // Define the pin where DHT sensor is connected
// #define DHTTYPE DHT11   // Define the type of DHT sensor (DHT11)
// int chipSelect =8;    // SD card module CS (Chip Select) pin

// // -------- Create Objects --------
// DHT dht(DHTPIN, DHTTYPE); // Create DHT sensor object
// File dataFile;            // File object for SD card

// void setup() {
//   Serial.begin(9600);    // Start serial communication
//   dht.begin();           // Initialize DHT sensor

//   Serial.println("Initializing SD card...");

//   if (!SD.begin(chipSelect)) {   // Initialize SD card
//     Serial.println("SD initialization failed!");
//     return;                      // Stop if SD fails
//   }
//   Serial.println("SD initialization done.");

//   // Create file and write header if not exists
//   if (!SD.exists("datalog.csv")) {   // Check if file exists
//     dataFile = SD.open("datalog.csv", FILE_WRITE); // Open file
//     if (dataFile) {
//       dataFile.println("Temperature(C),Humidity(%)"); // Header without time
//       dataFile.close();   // Close file
//       Serial.println("CSV header written.");
//     }
//   }
// }

// void loop() {
//   float humidity = dht.readHumidity();       // Read humidity
//   float temperature = dht.readTemperature(); // Read temperature

//   // Check if sensor reading failed
//   if (isnan(humidity) || isnan(temperature)) {
//     Serial.println("Failed to read from DHT sensor!");
//     delay(2000);   // Wait before retry
//     return;        // Skip rest of loop
//   }

//   // Open file to write data
//   dataFile = SD.open("datalog.csv", FILE_WRITE);

//   if (dataFile) {
   
//     dataFile.print(temperature);  // Write temperature
//     dataFile.print(",");          // Separator
//     dataFile.println(humidity);   // Write humidity

//     dataFile.close();             // Close file after writing

//     // Print data on Serial Monitor
//     Serial.print("Logged: ");
//     Serial.print(temperature);
//     Serial.print("C, ");
//     Serial.print(humidity);
//     Serial.println("%");
//   } else {
//     Serial.println("Error opening datalog.csv");
//   }

//   delay(2000);  // Log data every 2 seconds
// }


#include <SPI.h>        // Library for SPI communication (used by SD card)
#include <SD.h>         // Library to control SD card
#include <DHT.h>        // Library for DHT temperature & humidity sensor

// -------- Pin Definitions --------
#define DHTPIN 2        // Define the pin where DHT sensor is connected
#define DHTTYPE DHT11   // Define the type of DHT sensor (DHT11)
int chipSelect =8;    // SD card module CS (Chip Select) pin

// -------- Create Objects --------
DHT dht(DHTPIN, DHTTYPE); // Create DHT sensor object with pin and type
File dataFile;            // Create file object to handle SD file

void setup() {
  Serial.begin(9600);    // Start serial communication at 9600 baud rate
  dht.begin();           // Initialize the DHT sensor

  Serial.println("Initializing SD card..."); // Print message to serial monitor

  if (!SD.begin(chipSelect)) {   // Try to initialize SD card
    Serial.println("SD initialization failed!"); // If failed, print error
    return;                      // Stop setup execution
  }
  Serial.println("SD initialization done."); // If successful, print message

  // Create file and write header if not exists
  if (!SD.exists("datalog.csv")) {   // Check if file already exists
    dataFile = SD.open("datalog.csv", FILE_WRITE); // Open file in write mode
    if (dataFile) {                  // Check if file opened successfully
      dataFile.println("Time(s),Temperature(C),Humidity(%)"); // Write CSV header
      dataFile.close();              // Close file after writing
      Serial.println("CSV header written."); // Confirm on serial monitor
    }
  }
}

void loop() {
  float humidity = dht.readHumidity();      // Read humidity from DHT sensor
  float temperature = dht.readTemperature(); // Read temperature from DHT sensor

 

  // Open file
  dataFile = SD.open("datalog.csv", FILE_WRITE); // Open file to write data

  if (dataFile) {   // If file opened successfully
    unsigned long timeStamp = millis() / 1000; // Get time in seconds since start ---- if delay used, we will not get realtime data, instead 2 sec delay

    // Write data in CSV format (comma separated)
    dataFile.print(timeStamp);     // Write time
    dataFile.print(",");           // Add comma
    dataFile.print(temperature);   // Write temperature
    dataFile.print(",");           // Add comma
    dataFile.println(humidity);    // Write humidity and move to next line

    dataFile.close();              // Close file after writing (important!)

    // Print same data on Serial Monitor
    Serial.print("Logged: ");
    Serial.print(timeStamp);
    Serial.print("s, ");
    Serial.print(temperature);
    Serial.print("C, ");
    Serial.print(humidity);
    Serial.println("%");
  } else {
    Serial.println("Error opening datalog.csv"); // If file failed to open
  }

  delay(2000);  // Wait 2 seconds before next reading (logging interval)
}