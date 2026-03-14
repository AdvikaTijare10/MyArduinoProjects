#include<LiquidCrystal_I2C.h>
int trigPin = 8;
int echoPin = 13;
long duration;
int distance_cm;
int distance_inch;
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  Serial.begin(9600);           // Initialize Serial Monitor
  pinMode(trigPin, OUTPUT);     // Set trigPin as output
  pinMode(echoPin, INPUT);// Set echoPin as input
  lcd.init();     
  lcd.backlight();
}
  

void loop() {
  // Send a 10 µs pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin and measure the duration of pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance using simplified formulas
  distance_cm = duration / 58;
  distance_inch = duration / 148;

  // Display the results
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.print(" cm  |  ");
  Serial.print(distance_inch);
  Serial.println(" inches");
  lcd.setCursor(0,0);
 lcd.print("Dist in cm:");
 lcd.print(distance_cm);
 lcd.setCursor(0,1);
 lcd.print("Dist in inch:");
 lcd.print(distance_inch);
delay(200);
lcd.clear();
}