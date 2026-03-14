void pressure(){
  lcd.setCursor(0,0);
  lcd.print("Pressure: ");
  lcd.print(p);
  delay(1000);
  lcd.clear();
}