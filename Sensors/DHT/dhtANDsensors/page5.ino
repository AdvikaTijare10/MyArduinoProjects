void LDRsensor(){
  lcd.setCursor(0,0);
  lcd.print("Light present? ");
int val1;
  val1=digitalRead(LDRpin);
  lcd.setCursor(0,1);
  if(val1==LOW)lcd.print("Yes");
  else lcd.print("No");
}