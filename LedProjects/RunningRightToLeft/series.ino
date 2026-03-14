int ledPins[8]={2,3,4,5,9,10,11,12};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<8;i++)
pinMode(ledPins[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<8;i++){
  for(int j=0;j<8;j++){
    if(j==i)digitalWrite(ledPins[j],HIGH);
    else digitalWrite(ledPins[j],LOW);
  }
  delay(100);
}
for(int i=7;i>=0;i--){
  for(int j=0;j<8;j++){
    if(j==i)digitalWrite(ledPins[j],HIGH);
    else digitalWrite(ledPins[j],LOW);
  }
  delay(100);
}
}
 