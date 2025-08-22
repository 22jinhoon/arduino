#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);



void setup()
 {
  lcd.begin(16,2);
  lcd.print("hello, arduino!");

  
}

void loop() 
{
  for(int i =0 ; i<16;i++)
  {
    lcd.scrollDisplayLeft();
  delay(150);
  }
  for(int i =0 ; i<32;i++)
  {
    lcd.scrollDisplayRight();
  delay(150);
  }
   for(int i =0 ; i<16;i++)
  {
    lcd.scrollDisplayLeft();
  delay(150);
  }

}
