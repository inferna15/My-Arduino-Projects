String message;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    message = Serial.readString();
    Serial.println(message.length() - 1); // "-1 newline için"
  }
}