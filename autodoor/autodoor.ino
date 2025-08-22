#include <Servo.h>

Servo myServo; // 서보 모터 객체 생성

void setup() 
{
  Serial.begin(9600); // 시리얼 통신 시작 (가장 중요한 수정)
  
  myServo.attach(9); // 서보 모터를 9번 핀에 연결
  
  // 7번 핀을 입력 모드로 설정 (내장 풀업 저항 사용)
  pinMode(7, INPUT_PULLUP);
  
  // 시작 시 서보 모터를 0도로 초기화
  myServo.write(0);
}

void loop()
{
  // 7번 핀의 디지털 값을 읽음
  // INPUT_PULLUP을 사용하면 버튼이 눌리지 않았을 때 HIGH, 눌렀을 때 LOW가 됨
  int detect = digitalRead(7);

  // 시리얼 모니터에 현재 상태를 출력하여 디버깅에 도움
  Serial.print("Detect value: ");
  Serial.println(detect);

  if (detect == LOW) // 버튼을 눌렀을 때 (LOW 상태)
  {
    myServo.write(90); // 서보 모터를 90도로 움직임
  }
  else // 버튼을 누르지 않았을 때 (HIGH 상태)
  {
    myServo.write(0); // 서보 모터를 0도로 움직임
  }
  
  // 지연 시간을 제거하여 센서 반응 속도를 높임
}