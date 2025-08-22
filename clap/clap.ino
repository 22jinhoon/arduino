int LM_pin = 4;     // 아두이노의 4핀을 소리감지센서 핀으로 사용
int LED_pin = 6;    // 아두이노의 6번핀을 LED 핀으로 사용
int clap = 0;       // 박수 횟수를 기록하는 변수 선언

void setup() {
  pinMode(LED_pin, OUTPUT); // LED_pin을 출력으로 사용
  pinMode(LM_pin, INPUT);   // LM_pin은 입력으로 사용
}

void loop() {
  if(digitalRead(LM_pin) == HIGH)
  {     // 소리가 감지되면
    clap++;           // 박수 횟수를 1 증가
    delay(100);       // 0.1초간 기다림(연속입력 방지)
  } 
  if(clap == 2)     // 박수 횟수가 2가 되면
  {        
    clap = 0;         // 박수 횟수를 0으로 초기화
  }
  if(clap == 1){      // 박수를 한번 치면
    digitalWrite(LED_pin, HIGH);  // LED 점등
  } else{             // 박수를 한번 더 치면
    digitalWrite(LED_pin, LOW);  // LED 소등
  }  
}