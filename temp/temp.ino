#include <TMP36.h>

TMP36 myTemp;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{
  int value = analogRead(A0);
  myTemp.printTemp(value);
  delay(1000);
}
