
/*
  District P
  아두이노 코딩#18-2
  조이스틱 모듈 다루기
*/

int push_pin = 12;	// 조이스틱 버튼은 아두이노 12번 핀에 연결
int pos_X = A0;	// 조이스틱 X축은 아두이노 A0에 연결
int pos_Y = A1;	// 조이스틱 Y축은 아두이노 A1에 연결
int LED_X1 = 11;	// 좌측 LED는 11번에 연결
int LED_X2 = 10;	// 우측 LED는 10번에 연결
int LED_Y1 = 6;	// 상측 LED는 6번에 연결
int LED_Y2 = 5;	// 하측 LED는 5번에 연결
int LED_push = 2;	// 버튼 LED는 2번에 연결

void setup() {
  pinMode(push_pin, INPUT_PULLUP);	// 조이스틱 버튼은 INPUT_PULLUP
  pinMode(LED_X1, OUTPUT);	// LED들은 모두 OUTPUT으로 설정
  pinMode(LED_X2, OUTPUT);
  pinMode(LED_Y1, OUTPUT);
  pinMode(LED_Y2, OUTPUT);
  pinMode(LED_push, OUTPUT);
  Serial.begin(9600);
}

void loop() {int X = analogRead(pos_X);		// 조이스틱 X축 움직임을 X 변수에 저장
  int Y = analogRead(pos_Y);

  Serial.print("Push: ");		// 시리얼모니터에 "PUSH: " 출력
  Serial.print(digitalRead(push_pin));	// 시리얼모니터에 버튼 누름 유무 표시
  Serial.print("\t");			// 시리얼모니터에 tab(일정거리 띄움) 표시
  Serial.print("X: ");			// 시리얼모니터에 "X: " 출력
  Serial.println(X);			// 시리얼모니터에 X방향 움직임 표시
  Serial.print("\t");			// 시리얼모니터에 tab(일정거리 띄움) 표시
  Serial.print("Y: ");			// 시리얼모니터에 "Y: " 출력
  Serial.println(Y);			// 시리얼모니터에 Y방향 움직임 표시
  delay(100); 			// 1초간 기다림
  
  		// 조이스틱 Y축 움직임을 Y 변수에 저장
  if(digitalRead(push_pin) == LOW)
  {	// 조이스틱 버튼을 누를 경우
    digitalWrite(LED_push, HIGH);	// 버튼 LED 켬
  }
  else
  {				// 조이스틱 버튼을 누르지 않을 경우
    digitalWrite(LED_push, LOW);	// 버튼 LED 끔
  }
  if(X<506)
  {			// 조이스틱을 좌측으로 움직인 경우
    analogWrite(LED_X1, map(X, 480, 0, 0, 255));	// 움직임 정도에 따라 좌측 LED 밝기 조절
    analogWrite(LED_X2, 0);		// 우측 LED는 끔
  }
  else if(X>520)
  {			// 조이스틱을 우측으로 움직인 경우
    analogWrite(LED_X1, 0);		// 좌측 LED는 끔
    analogWrite(LED_X2, map(X, 520, 1023, 0, 255)); // 우측 LED는 움직임 정도에 따라 밝기 조절
  }
  else
  {				// 조이스틱을 X축방향으로 움직이지 않은 경우
    analogWrite(LED_X1, 0);		// 좌, 우 LED 둘다 끔
    analogWrite(LED_X2, 0);
  }
  if(Y<500){			// 조이스틱을 상측으로 움직인 경우
    analogWrite(LED_Y1, map(Y, 480, 0, 0, 255)); // 움직임 정도에 따라 상측 LED 밝기 조절
    analogWrite(LED_Y2, 0);		// 하측 LED는 끔
  }else if(Y>520){			// 조이스틱을 하측으로 움직인 경우
    analogWrite(LED_Y1, 0);		// 상측 LED는 끔
    analogWrite(LED_Y2, map(Y, 520, 1023, 0, 255)); // 움직임 정도에 따라 하측 LED 밝기 조절
  }else{				// 조이스틱을 Y축방향으로 움직이지 않은 경우
    analogWrite(LED_Y1, 0);		// 상, 하 LED 둘다 끔
    analogWrite(LED_Y2, 0);
  }
}
