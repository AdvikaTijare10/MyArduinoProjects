int gasSensor=2;
int flameSensor=8;
int led=13;
int buzzer=4;
void setup() {
  // put your setup code here, to run once:
pinMode(gasSensor,INPUT);
pinMode(flameSensor,INPUT);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int flame,gas;
flame=digitalRead(flameSensor);
gas=digitalRead(gasSensor);
//-----fire detection
if(flame==HIGH){ // flame is there
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
}
else{
  digitalWrite(buzzer,LOW);
}
//-----gas detection
if(gas==LOW){ //gas is present
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
}
else {
  digitalWrite(led,LOW);
}
}
