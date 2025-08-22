int trig = 10;
int echo = 9;
int red = 7;
int yellow = 6;


void setup() 
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);


  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  double duration = pulseIn(9,HIGH);
  double cm = duration / 58.0;

  Serial.println(cm);

  if(cm>0)
  {if(cm < 5)
  {
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
  }
  else
  {  digitalWrite(yellow, HIGH);
     digitalWrite(red,LOW);}
}
delay(100);
}
  
