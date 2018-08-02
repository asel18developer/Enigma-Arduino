#include <KeyboardController.h>
#include <MouseController.h>
#include <parsetools.h>
#include <Usb.h>
#include <usb_ch9.h>

#include <KeyboardController.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <LiquidCrystal.h>

// Initialize USB Controller
USBHost usb;

// Attach Keyboard controller to USB
KeyboardController keyboard(usb);

/*
 * PANTALLAS.
 *
 * (dir, en,rw,rs,d4,d5,d6,d7,bl, blpol)
 */
LiquidCrystal_I2C lcd_16x2(0x25, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd_20x4(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin(9600);
  lcd_16x2.begin(16, 2);
  lcd_20x4.begin(20, 4);
}

void loop() {
  usb.Task();
  delay(1);
}

void keyPressed() {
  char c = (char)keyboard.getKey();
  lcd_20x4.print(c);
}
