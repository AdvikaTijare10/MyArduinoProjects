void temp(){
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print(t);
  delay(1000);
  lcd.clear();  
}