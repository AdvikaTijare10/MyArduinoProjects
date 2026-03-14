int LDRsensor=2;
int relay=8;
void setup() {
  // put your setup code here, to run once:
pinMode(relay,OUTPUT);
pinMode(LDRsensor,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int val;
val=digitalRead(LDRsensor);
if(val==HIGH)//no light 
  {digitalWrite(relay,LOW); // smtg connected to relay will turn on i.e the led.
  }
else // light is there
  digitalWrite(relay,HIGH);
}

// default state in gas project, connect com and nc. by default shoulld be on and when leakage is dtecetd it should turn off

