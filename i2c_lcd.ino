//designed_by_ARMALLICK
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("A R MALLICK");
  lcd.setCursor(0,1);
  lcd.print("8981338027");
//   lcd.setCursor(3,2);
//  lcd.print("INCUBATION CELL");
//   lcd.setCursor(5,3);
//  lcd.print("S R I S T");
}


void loop()
{
}
