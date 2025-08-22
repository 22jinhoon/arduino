#include "TMP36.h"

float TMP36::printTemp(int analogInput)
{
	float voltage = analogInput * 5.0 / 1023.0;
	float temperature = voltage * 100 - 50;
	
	Serial.print("temperature is ");
	Serial.println(temperature);

}
