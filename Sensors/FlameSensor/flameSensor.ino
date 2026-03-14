int flameSensor=2;
int led=8;
void setup() {
  // put your setup code here, to run once:
pinMode(flameSensor,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val;
val=digitalRead(flameSensor);
if(val==LOW){ // glow led when flame present
  digitalWrite(led,HIGH);
  delay(200);
digitalWrite(led,LOW);
delay(200);
}
else{
  digitalWrite(led,LOW);
}
}
