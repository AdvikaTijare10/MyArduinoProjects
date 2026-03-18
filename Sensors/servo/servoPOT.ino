
#include <Servo.h>

Servo myServo;
int pot=A2;
void setup() {
  Serial.begin(9600);
  myServo.attach(9);  // servo connected to pin 9
  pinMode(pot,INPUT);
}
int val;
void loop() {
  // myServo.write(0);
  // delay(2000);
  // myServo.write(45);   // move to 45°
  // delay(2000);

  // myServo.write(90);   // move to 90°
  // delay(2000);

  // myServo.write(127);  // move to 127°
  // delay(2000);

  // myServo.write(180);  // move to 180°
  // delay(2000);
  val=analogRead(pot);
  int angle=map(val,0,1023,0,180);
  myServo.write(angle);
  Serial.println(angle);
  delay(15);
}