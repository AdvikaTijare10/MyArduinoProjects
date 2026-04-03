#include <TinyGPS++.h>        //GPS Library
#include <SoftwareSerial.h>   //To use Virtual Serial port for GPS. 
#include <LiquidCrystal_I2C.h> //Library for I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); //Object of LCD with its address & column(16) & row(2) count

SoftwareSerial mySerial(2, 3); //Creating object for Software Serial Port. D2 = Rx & D3 = Tx
TinyGPSPlus gps;      //Creating object for GPS

double latitude, longitude;   //Global variables to store latitude & longitude

void setup()
{
  lcd.init();   //Initialize LCD
  lcd.backlight();    //Turn on the LCD backlight

  mySerial.begin(9600);  //Setting baudrate of GPS
  Serial.begin(9600);    //Setting baud rate of arduino

}

void loop()
{
  while (mySerial.available())  //Check for data coming from GPS
  {
    int data = mySerial.read();  //Local variable to Store the raw data(NMEA) received from GPS device
    if (gps.encode(data))       //Decoding the NMEA data to retrieve latitude & Longitude
    {
      latitude = (gps.location.lat());  //get value of latitude
      longitude = (gps.location.lng()); //get value of longitude

      Serial.print ("latitude: ");   //Print on serial monitor
      Serial.print (latitude, 6);   //Print value upto 6 places

      Serial.print ("   longitude: ");
      Serial.println (longitude, 6);

      lcd.setCursor(1, 0);  //Set LCD cursor (row & column position)
      lcd.print("LAT : ");  //Print value on LCD upto 6 Places
      lcd.print(latitude, 6);

      lcd.setCursor(1, 1);
      lcd.print("LNG : ");
      lcd.print(longitude, 6);

      delay (1000);        //Print after every 500 milliseconds
    }
  }
}
