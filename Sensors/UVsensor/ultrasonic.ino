int trigPin = 8;
 int echoPin = 13;
long duration;
int distance_cm;
int distance_inch;

void setup() {
  Serial.begin(9600);           // Initialize Serial Monitor
  pinMode(trigPin, OUTPUT);     // Set trigPin as output
  pinMode(echoPin, INPUT);      // Set echoPin as input
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
  delay(50);
}