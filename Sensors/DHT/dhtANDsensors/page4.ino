void IRsensor(){
  lcd.setCursor(0,0);
  lcd.print("Object detected?");
int val2;
  val2=digitalRead(IRpin);
  lcd.setCursor(0,1);
  if(val2==LOW)lcd.print("Yes");
  else lcd.print("No");
}