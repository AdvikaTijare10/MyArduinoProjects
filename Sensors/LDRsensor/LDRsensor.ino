int LDRsensor=2;
int led=12;
void setup() {
  // put your setup code here, to run once:
pinMode(LDRsensor,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val;
val=digitalRead(LDRsensor);
if(val==HIGH){ // means no light
digitalWrite(led,HIGH); // no need of blinking
}
else{
  digitalWrite(led,LOW);
}
}
