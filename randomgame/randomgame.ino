// C++ code

// 핀 설정
int sw_pins[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, A1, A2, A3, A4, A5};
int green = 2;
int red = 4;
int piezo = 3;

// 멜로디 주파수 (Hz)
int safe_melody[] = {262, 330, 391}; // 도미솔
int die_melody[] = {262, 131, 131}; // 도(낮음) - 쿵! 쿵!

int die_sw = 0; // 함정 스위치
bool isGameOver = false; // 게임 오버 상태를 추적하는 변수
bool pressed[14] = {false,}; // 각 버튼의 눌림 상태를 저장하는 배열

void setup() {
  for (int i = 0; i < 14; i++) {
    pinMode(sw_pins[i], INPUT_PULLUP);
  }
  
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600); // 디버깅을 위해 시리얼 통신 시작
  
  startGame(); // 게임 시작 함수 호출
}

void loop() {
  if (isGameOver) {
    // 게임 오버 상태일 때 재시작을 기다림
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    
    // 아무 버튼이나 누르면 게임 재시작
    for (int i = 0; i < 14; i++) {
      if (digitalRead(sw_pins[i]) == LOW) {
        Serial.println("게임 재시작!");
        startGame();
        return; // loop를 즉시 재시작
      }
    }
  } else {
    // 게임 중인 경우
    for (int i = 0; i < 14; i++) {
      // 버튼이 눌렸고(LOW), 이전에 눌리지 않았을 때
      if (digitalRead(sw_pins[i]) == LOW && !pressed[i]) {
        pressed[i] = true; // 눌림 상태로 변경
        
        // 함정 스위치와 일치하는지 확인
        if (i == die_sw) {
          Serial.print("함정 발견! 스위치 번호: ");
          Serial.println(i);
          playMelody(die_melody, true); // 위험 멜로디 재생
          isGameOver = true; // 게임 오버
          break; // 현재 for 루프 종료
        } else {
          Serial.print("안전! 스위치 번호: ");
          Serial.println(i);
          playMelody(safe_melody, false); // 안전 멜로디 재생
        }
      }
      // 버튼이 떼어졌을 때
      if (digitalRead(sw_pins[i]) == HIGH && pressed[i]) {
          pressed[i] = false;
      }
    }
  }
}

// 멜로디 재생 함수
void playMelody(int melody[], bool isGameOverMelody) {
  for (int i = 0; i < 3; i++) {
    tone(piezo, melody[i], 500); // 0.5초 동안 멜로디 재생
    delay(500); // 0.5초 대기
    noTone(piezo); // 부저 끄기
  }
  if (isGameOverMelody) {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
}

// 게임 시작 함수
void startGame() {
  randomSeed(analogRead(A0));
  die_sw = random(0, 14); // 0부터 13까지의 무작위 함정 설정
  
  isGameOver = false;
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  
  Serial.println("--- 게임 시작! ---");
  Serial.print("함정 스위치 번호: ");
  Serial.println(die_sw);
}