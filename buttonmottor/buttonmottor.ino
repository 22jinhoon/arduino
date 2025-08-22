#include <Stepper.h>

// 스테퍼 모터의 회전당 스텝 수 (28BYJ-48 모터 기준)
const int stepsPerRevolution = 2048;

// 버튼이 연결된 핀
const int BUTTON_PIN = 2;

// Stepper 객체 생성 (핀 번호는 연결 상태에 따라 변경)
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // 모터 속도 설정 (RPM 단위)
  myStepper.setSpeed(10);
  
  // 버튼 핀을 INPUT_PULLUP 모드로 설정
  // 버튼을 누르지 않았을 때는 HIGH, 눌렀을 때는 LOW
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("스테퍼 모터 제어 시작.");
}

void loop() {
  // loop() 함수가 반복될 때마다 버튼 상태를 읽음
  int buttonState = digitalRead(BUTTON_PIN);

  // 버튼이 눌리지 않았을 때 (INPUT_PULLUP 모드에서는 HIGH)
  if (buttonState == HIGH) {
Serial.println("버튼 누름: 정방향으로 회전합니다.");
    // 모터를 정방향으로 한 바퀴 회전
    myStepper.step(stepsPerRevolution);
    delay(500);




    
  } 
  // 버튼이 눌렸을 때 (LOW)
  else {
   Serial.println("버튼 안 누름: 역방향으로 회전합니다.");
    // 모터를 역방향으로 한 바퀴 회전
    myStepper.step(-stepsPerRevolution);
    delay(500);
  }
}