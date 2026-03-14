int ldr=A0;
int led=8;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=analogRead(ldr);
Serial.println(val);
delay(500);
if(val>850){
  digitalWrite(led,HIGH);
}
else digitalWrite(led,LOW);

}
