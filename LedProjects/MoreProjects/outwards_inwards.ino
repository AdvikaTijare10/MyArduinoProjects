int ledPins[8]={2,3,4,5,9,10,11,12};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<8;i++)pinMode(ledPins[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// int left=3;
// int right=4;
// while(left>=0&&right<=7){
//   digitalWrite(ledPins[left],HIGH);
//   digitalWrite(ledPins[right],HIGH);
//   delay(50);
//   left--;
//   right++;
// }
//  left=0;
//  right=7;
// while(left<=3&&right>=4){
//   digitalWrite(ledPins[left],LOW);
//   digitalWrite(ledPins[right],LOW);
//   delay(50);
//   left++;
//   right--;
// }

//--------------------------------------------------------
//0 1 2 3 4 5 6 7
digitalwrite(3,HIGH);
digitalWrite(4,HIGH);
delay(200);
digitalWrite(2,HIGH);
digitalWrite(5,HIGH);
delay(200);
digitalWrite(1,HIGH);
digitalWrite(6,HIGH);
delay(200);
digitalWrite(0,HIGH);
digitalWrite(7,HIGH);
delay(200);
digitalWrite(0,HIGH);
digitalWrite(7,HIGH);
delay(200);
digitalWrite(0,LOW);
digitalWrite(7,LOW);
delay(200);
digitalWrite(1,LOW);
digitalWrite(6,LOW);
delay(200);
digitalWrite(2,LOW);
digitalWrite(5,LOW);
delay(200);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
delay(200);
}
