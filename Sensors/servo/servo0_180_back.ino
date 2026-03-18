
#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);  // servo connected to pin 9
  
}

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
  for(int i=0;i<=180;i++){
    myServo.write(i); 
    delay(15);   
  }
  for(int i=180;i>=0;i--){
    myServo.write(i);
    delay(15);
  }
}