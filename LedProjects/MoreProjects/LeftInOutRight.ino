int ledPins[8]={2,3,4,5,9,10,11,12};

void setup() {
  for(int i=0;i<8;i++)
    pinMode(ledPins[i],OUTPUT);
}

void loop() {

  // Right to left
  for(int i=7;i>=0;i--){
    digitalWrite(ledPins[i],HIGH);
    delay(150);
    digitalWrite(ledPins[i],LOW);
  }

  // Turn OFF inward
  int left=0;
  int right=7;
  while(left<=3 && right>=4){
    digitalWrite(ledPins[left],HIGH);
    digitalWrite(ledPins[right],HIGH);
    delay(150);
    left++;
    right--;
  }
for(int i=0;i<8;i++){
  digitalWrite(ledPins[i],LOW);
}
  // Expand outward
  left=3;
  right=4;
  while(left>=0 && right<=7){
    digitalWrite(ledPins[left],HIGH);
    digitalWrite(ledPins[right],HIGH);
    delay(150);
    left--;
    right++;
  }
for(int i=0;i<8;i++){
  digitalWrite(ledPins[i],LOW);
}
  // Left to right
  for(int i=0;i<8;i++){
    digitalWrite(ledPins[i],HIGH);
    delay(150);
    digitalWrite(ledPins[i],LOW);
  }
}