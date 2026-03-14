int gasSensor=2;
int relay=8;

void setup() {
  // put your setup code here, to run once:
pinMode(gasSensor,INPUT);
pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val;
val=digitalRead(gasSensor);
if(val==LOW){//gas is present
digitalWrite(relay,LOW); // turn off the led becoz gas reacts with electricity
}
else
digitalWrite(relay,HIGH);// on the led when no gas
}
