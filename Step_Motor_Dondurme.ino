#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  turn();
}

void turn() {
  digitalWrite(IN4, LOW);
  digitalWrite(IN1, HIGH);
  delayMicroseconds(2100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delayMicroseconds(2100);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  delayMicroseconds(2100);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delayMicroseconds(2100);
}