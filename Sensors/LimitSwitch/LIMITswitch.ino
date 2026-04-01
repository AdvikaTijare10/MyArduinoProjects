int Lswitch=8;
int buzzer=4;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzer,OUTPUT);
pinMode(Lswitch,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(Lswitch);
if(val==LOW)  digitalWrite(buzzer,HIGH);
else digitalWrite(buzzer,LOW);
}
