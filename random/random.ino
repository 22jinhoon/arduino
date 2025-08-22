
/*
  District P
  아두이노 코딩#14-1
  랜덤한 간격으로 점멸되는 LED 코드
*/
int LED_pin = 12;	// LED핀을 12로 지정
		
void setup() 
{
  pinMode(LED_pin, OUTPUT);	// LED핀을 출력으로 설정
  Serial.begin(9600);
  randomSeed(analogRead(A0)); 		// 시리얼 통신 시작
}

void loop()
 {
  int blink_time = random(1, 21);	// 점멸시간을 1-20사이의 임의의 값으로 설정
  Serial.println(blink_time);		// 점멸시간을 시리얼모니터에 출력
  digitalWrite(LED_pin, HIGH);	// LED를 켬
  delay(blink_time*100);		// 점멸시간*100, 즉 0.1-2초 기다림
  digitalWrite(LED_pin, LOW);		// LED를 끔
  delay(1000);			// 1초간 기다림(1초간 끄는 것을 유지
}
