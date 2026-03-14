// int ldr=A0;
// int led=9;
// void setup() {
//   // put your setup code here, to run once:
// pinMode(ldr,INPUT);
// pinMode(led,OUTPUT);
// Serial.begin(9600);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// int value=analogRead(ldr);
// int brightness=map(value,0,1023,0,255); // pwm is 8 bit resolution
// analogWrite(led,brightness);
// Serial.println(brightness);
// delay(200);
// }


int ldr=A0;
int led=8;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int value=digitalRead(ldr);
 // pwm is 8 bit resolution
digitalWrite(led,value);
Serial.println(value);
delay(200);
}
