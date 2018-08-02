#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x25,20,4); 

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");

}

void loop() {
  // put your main code here, to run repeatedly:

lcd.setCursor(0,0);
  lcd.print("- TEST i2c@0x25");
  lcd.setCursor(5,1);
  lcd.print("PANTALLAS -");

}
