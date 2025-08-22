void setup()
 {
  pinMode(8, OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
 }

void loop() 
{ 
  int value = digitalRead(2);
  Serial.println(value);

  if(value==HIGH)
  digitalWrite(8,HIGH);
else
digitalWrite(8,LOW);

  // put your main code here, to run repeatedly:

}
 