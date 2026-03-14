int ledPins[8]={2,3,4,5,9,10,11,12};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<8;i++)pinMode(ledPins[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=8;i>=0;i--){
digitalWrite(ledPins[i],HIGH);
delay(150);
digitalWrite(ledPins[i],LOW);
}
  
  for(int i=0;i<=8;i++){
    digitalWrite(ledPins[i],HIGH);
    delay(150);
    digitalWrite(ledPins[i],LOW);
  }
}
