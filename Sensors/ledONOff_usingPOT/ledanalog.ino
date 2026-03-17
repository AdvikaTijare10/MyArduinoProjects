int led=9;
int pot=A5;
int val;
int pwm;
void setup() {
  // put your setup code here, to run once:
 pinMode(pot,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(pot); // max value it can give is 1023 but dac wont understand becoz it is 8 bit so only till 255 max
pwm=map(val,1023,0,255,0);// (var,upperLimit(to convert),lowerLimit,upperLimit(convert into wht),lowerLimit)
Serial.print(val);
Serial.print(" ");
Serial.println(pwm);
delay(200);
analogWrite(led,pwm);
}
