int pot = A1;
int led1 = 9;
int led2 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int val = analogRead(pot);
  int val1 = map(val,0,1023,0,255);

  if(val1 > 127){
    analogWrite(led1,val1);
    analogWrite(led2,255-val1);
  }
  else{
    analogWrite(led1,val1);
    analogWrite(led2,255-val1);
  }

  Serial.println(val1);
  delay(200);
}

