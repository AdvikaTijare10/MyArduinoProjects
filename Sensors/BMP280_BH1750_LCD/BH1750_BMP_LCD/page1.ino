void Lightlevel(){
  lcd.setCursor(0,0);
  lcd.print("Light intensity");
  lcd.setCursor(0,1);
  lcd.print(lux);
  lcd.print(" lux");
  delay(1000);
  lcd.clear();
}