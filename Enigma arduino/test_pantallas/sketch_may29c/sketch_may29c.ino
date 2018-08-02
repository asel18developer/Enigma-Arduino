// Codigo para usar un LCD 16x2 con Arduino
// David Ortega Cuadrado - dorcu.com
// 27 de Abril de 2014
// dorcu.com
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
 
//Pines en el PCF8574(dir, en,rw,rs,d4,d5,d6,d7,bl, blpol)
LiquidCrystal_I2C lcd16(0x25, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd20(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
void setup(){
  lcd16.begin(16,2);
  lcd20.begin(20,4);
 
  lcd16.setCursor(0,0);
  lcd16.print("- TEST i2c@0x25");
  lcd16.setCursor(5,1);
  lcd16.print("PANTALLAS -");
  
  lcd20.setCursor(0,0);
  lcd20.print("- TEST");
  lcd20.setCursor(6,1);
  lcd20.print("(I2C address:");
  lcd20.setCursor(6,2);
  lcd20.print("  0x27)");
  lcd20.setCursor(9,3);
  lcd20.print("PANTALLAS -");
}
 
void loop(){}
