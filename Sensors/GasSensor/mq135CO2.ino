#define MQ135_PIN A0

float R0 = 10.0;   // 🔧 Replace after calibration
float CO2_ppm = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("MQ-135 CO2 Monitor Starting...");
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN);

  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Prevent division by zero
  if (voltage <= 0) {
    Serial.println("Sensor Error");
    return;
  }

  // Calculate sensor resistance (RS)
  float RS = (5.0 - voltage) / voltage;

  // Ratio RS/R0
  float ratio = RS / R0;

  // CO2 estimation formula (approx from datasheet curve)
  CO2_ppm = 116.6020682 * pow(ratio, -2.769034857);

  // Print values
  Serial.println("------ CO2 Data ------");
  Serial.print("Raw Value: ");
  Serial.println(sensorValue);

  Serial.print("Voltage: ");
  Serial.println(voltage);

  Serial.print("CO2 (ppm): ");
  Serial.println(CO2_ppm);

  // Air quality hint
  if (CO2_ppm < 400) {
    Serial.println("Fresh Air 🌿");
  }
  else if (CO2_ppm < 1000) {
    Serial.println("Normal Indoor 👍");
  }
  else if (CO2_ppm < 2000) {
    Serial.println("Poor Air ⚠️");
  }
  else {
    Serial.println("Dangerous 🚨");
  }

  Serial.println("----------------------\n");

  delay(2000);
}