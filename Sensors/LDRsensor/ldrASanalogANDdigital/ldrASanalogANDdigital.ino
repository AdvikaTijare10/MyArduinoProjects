//treating as analog
int ldr=A1;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(ldr)); // more values prints , adc converts 
delay(200);
}


// treating as digital
int ldr=8;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(digitalRead(ldr));  //this prints only 0 or 1
delay(200);
}
