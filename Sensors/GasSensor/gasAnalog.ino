// analog output
int gas=A2;
int led=9; // since uw ant analog oputput connect to pwm pin

void setup() {
  // put your setup code here, to run once:
pinMode(gas,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int value=analogRead(gas);
int gasAmount=map(value,0,1023,0,255);
analogWrite(led,gasAmount);
Serial.println(gasAmount);
delay(200);
}

//// digital output
// int gas=A0;
// int led=8;  

// void setup() {
//   // put your setup code here, to run once:
// pinMode(gas,INPUT);
// pinMode(led,OUTPUT);
// Serial.begin(9600);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// int value=digitalRead(gas);
// digitalWrite(led,gasAmount); // prints 0 with no gas present.
// Serial.println(gasAmount);
// delay(200);
// }
