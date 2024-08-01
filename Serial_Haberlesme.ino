int num = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Number = ");
  Serial.println(num);
  num++;
  delay(1000);
  if(num > 100) {
    num = 0;
  }
}