//out pin of the sensor goes to any digital pin on arduino 
// both bulbs same height
int IRpin=2;
int buzzer=8; //built-in led , (13)
void setup() {
  // put your setup code here, to run once:
pinMode(IRpin,INPUT); // ir sensor so input
pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val; 
val=digitalRead(IRpin); //stores the value high or low
if(val==LOW){
  digitalWrite(buzzer,HIGH);
  delay(200);  // tweaking this keeps the buzzing sound for longer or smaller time 
  digitalWrite(buzzer,LOW);
  delay(200);
}
else{
  digitalWrite(buzzer,LOW);
}
}   
// works for the buzzer as well