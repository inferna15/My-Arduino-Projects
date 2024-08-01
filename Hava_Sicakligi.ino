int number_pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int digit_pins[4] = {11, 10, 9, 8};
int val;
byte number_list[] = {
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110,  // 9
  B10011100   // C
};

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(digit_pins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(number_pins[i], OUTPUT);
  }
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
}

void loop() {
  val = analogRead(A0);
  float degree = (val * 5.0 / 1024.0) * 50.0;
  String value = String(degree, 1);
  value.replace(".", "");
  Serial.println(value);
  
  for(int i = 0; i < 100; i++){
    display(value);
  }
}

void display(String value) {
  for(int i = 0; i < 3; i++) {
    int number = value.charAt(i) - '0';
    digitalWrite(digit_pins[i], HIGH);
    for(int j = 0; j < 8; j++) {
      int isSegmentOn = bitRead(number_list[number], j);
      if (isSegmentOn) {
        digitalWrite(number_pins[j], LOW);
      }
      else {
        digitalWrite(number_pins[j], HIGH);
      }
      if (i == 1){
        digitalWrite(number_pins[0], HIGH);
      }
    }
    delay(3);
    digitalWrite(digit_pins[i], LOW);
  }
  digitalWrite(digit_pins[3], HIGH);
  for(int j = 0; j < 8; j++) {
      int isSegmentOn = bitRead(number_list[10], j);
      if (isSegmentOn) {
        digitalWrite(number_pins[j], LOW);
      }
      else {
        digitalWrite(number_pins[j], HIGH);
      }
    }
  delay(3);
  digitalWrite(digit_pins[3], LOW);
  
}