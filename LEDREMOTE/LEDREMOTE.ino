#include <IRremote.h>

// IR 수신 모듈의 데이터 핀을 아두이노의 8번 핀에 연결합니다.
#define IR_RECEIVE_PIN 8

void setup() {
  // IR 수신을 시작하고, 피드백 LED(내장 13번 핀)를 활성화합니다.
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  
  // LED를 제어할 9번 핀을 출력 모드로 설정합니다.
  pinMode(9, OUTPUT);
  
  // 시리얼 통신을 시작하여 리모컨 신호값을 확인합니다.
  Serial.begin(9600);
  Serial.println("IR Receiver is ready.");
}

void loop() {
  // 적외선 신호가 성공적으로 수신되면
  if (IrReceiver.decode()) {
    // 수신된 16진수 값을 변수에 저장
    unsigned long data = IrReceiver.decodedIRData.decodedRawData;
    
    // 시리얼 모니터에 값을 출력
    Serial.println(data, HEX);
    
    // 리모컨 신호가 특정 값과 일치하면
    // 이전에 작성했던 코드처럼, 수신된 데이터와 이 값을 비교합니다.
if (data == 0xF30CBF00) {
  // 0번 버튼이 눌렸 // 숫자 0 버튼의 값 (예시)
      digitalWrite(9, HIGH); // 9번 핀 LED를 켭니다.
    } else {
      digitalWrite(9, LOW);  // 다른 신호가 들어오면 LED를 끕니다.
    }
    
    // 다음 신호를 받기 위해 IR 수신기를 재개합니다.
    IrReceiver.resume();
  }
}