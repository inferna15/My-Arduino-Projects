int out_a = 3;
int out_b = 2;
volatile int value = 0;
volatile int lastVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(out_a, INPUT);
  pinMode(out_b, INPUT);
  attachInterrupt(digitalPinToInterrupt(out_a), changeOutA, RISING);
  attachInterrupt(digitalPinToInterrupt(out_b), changeOutB, RISING);
}

void loop() {
  if(value != lastVal) {
    Serial.println(value);
    lastVal = value;
  }
  delay(10);
}

void changeOutA() {
  if(digitalRead(out_b) == LOW) {
    value--;
  }
  else {
    value++;
  }
}

void changeOutB() {
  if(digitalRead(out_a) == HIGH) {
    value--;
  }
  else {
    value++;
  }
}