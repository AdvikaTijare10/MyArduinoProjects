int led1=2;
int led2=3;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  digitalWrite(2,HIGH);
  delay(200);
  digitalWrite(2,LOW);
  delay(200);
  digitalWrite(2,HIGH);
  delay(200);
  digitalWrite(2,LOW);
  delay(200);

  digitalWrite(3,HIGH);
  delay(200);
  digitalWrite(3,LOW);
  delay(200);
  digitalWrite(3,HIGH);
  delay(200);
  digitalWrite(3,LOW);
  delay(200);   // this makes smooth transition


  
}