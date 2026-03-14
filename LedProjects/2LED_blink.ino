int led1=2;  // 2 separate output pins for each LED.
int led2=3;
void setup() {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
}

void loop() {
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
delay(500); // both above statements get the same delay
digitalWrite(led2, HIGH);
digitalWrite(led1,LOW);
delay(500);

}
