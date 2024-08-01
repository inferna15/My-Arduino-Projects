const int dataPin = 11;
const int latchPin = 10;
const int clockPin = 13;

const int cols[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], HIGH);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      setRow(i);
      setCol(j);
      delay(500);
    }
  }
}

void setRow(int row) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 1 << row);
  digitalWrite(latchPin, HIGH);
}

void setCol(int col) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(cols[i], HIGH);
  }
  digitalWrite(cols[col], LOW);
}