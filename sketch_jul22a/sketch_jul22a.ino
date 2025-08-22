int datapin = 2;
int clockpin = 3;
int latchpin = 4;
byte data =0;

 void setup()
  {
  pinMode(datapin,OUTPUT);
  pinMode(clockpin ,OUTPUT);
  pinMode(latchpin, OUTPUT);
}

void loop() 
{
  for(int i =0; i<=7;i++)
  {
    shiftWrite(i,HIGH);
    delay(100);
  }
  for(int i =0; i>=0;i--)
  {
    shiftWrite(i,LOW);
    delay(100);
  }
}
void shiftWrite(int desiredPin,boolean desiredState)
{
  bitWrite(data,desiredPin,desiredState);
  shiftOut(datapin,clockpin,MSBFIRST,data);
  digitalWrite(latchpin,HIGH);
  digitalWrite(latchpin,LOW);
}
