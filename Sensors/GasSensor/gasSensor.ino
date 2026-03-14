int gasSensor=2;
int buzzer=8;
void setup() {
  // put your setup code here, to run once:
pinMode(gasSensor,INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val;
val=digitalRead(gasSensor);
if(val==LOW){ //meaning gas is present
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
}
else{
  digitalWrite(buzzer,LOW);
}
}
