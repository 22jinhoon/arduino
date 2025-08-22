int ctrl_pin = 7;			// 릴레이모듈 IN(제어핀)을 7번에 연결

void setup() {
  pinMode(ctrl_pin, OUTPUT);	// 제어 핀을 출력으로 사용
}

void loop() {
  digitalWrite(ctrl_pin, HIGH);		// 제어핀을 HIGH로(LED 켬)
  delay(1000);			// 1초간 기다림
  digitalWrite(ctrl_pin, LOW);		// 제어핀을 LOW로(LED 끔)
  delay(1000);			// 1초간 기다림
}