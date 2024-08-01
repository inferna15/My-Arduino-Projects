#include <Servo.h>

Servo servo;
int potPin = A0;
int value;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  value = analogRead(potPin);
  value = map(value, 0, 1023, 0, 180);
  Serial.println(value);
  servo.write(value);
  delay(15);
}