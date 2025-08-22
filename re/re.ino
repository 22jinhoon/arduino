
#include <IRremote.h>	// 리모컨 라이브러리를 불러옴
	
int remote_pin = 11;	// 리모컨 수신모듈을 아두이노 11번 핀에 연결

IRrecv irrecv(remote_pin);	// 리모컨 모듈을 사용하기 위한 준비코드 1
decode_results results;	// 리모컨 모듈을 사용하기 위한 준비코드 2
void setup() {
  Serial.begin(9600);	// 시리얼 통신 시작
  irrecv.enableIRIn();	// 리모컨 수신모듈 수신 시작
}
void loop() {
  if (irrecv.decode(&results)){		// 신호를 입력받으면
    int remote_signal = results.value;	// 신호를 remote_signal에 저장
    Serial.println(remote_signal, HEX);	// 받은 신호를 시리얼 모니터에 출력
    delay(100);			// 0.1초간 기다림
    irrecv.resume();			// 리모컨 수신모듈 수신 속행
  }
}
