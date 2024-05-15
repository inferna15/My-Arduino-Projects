#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define ses 6
bool flag;
bool find = false;
byte daragaci[] = {
  B11111,
  B10001,
  B10000,
  B10000,
  B10000,
  B10000,
  B11000,
  B00000
};
byte kafa[] = {
  B00100,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte govde[] = {
  B00100,
  B01010,
  B00100,
  B00100,
  B00100,
  B00000,
  B00000,
  B00000
};
byte sagkol[] = {
  B00100,
  B01010,
  B00100,
  B00111,
  B00100,
  B00000,
  B00000,
  B00000
};
byte solkol[] = {
  B00100,
  B01010,
  B00100,
  B11111,
  B00100,
  B00000,
  B00000,
  B00000
};
byte sagayak[] = {
  B00100,
  B01010,
  B00100,
  B11111,
  B00100,
  B00010,
  B00001,
  B00000
};
byte solayak[] = {
  B00100,
  B01010,
  B00100,
  B11111,
  B00100,
  B01010,
  B10001,
  B00000
};
byte death[] = {
  B00100,
  B01010,
  B00100,
  B01110,
  B10101,
  B01010,
  B01010,
  B00000
};
int space;
int a;
char kelime[5];
bool check[5];
short bilinen;
short counter;
String count;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("BASLAMAK ICIN -SPACE- BASIN");
  lcd.createChar(0, daragaci);
  lcd.createChar(1, kafa);
  lcd.createChar(2, govde);
  lcd.createChar(3, sagkol);
  lcd.createChar(4, solkol);
  lcd.createChar(5, sagayak);
  lcd.createChar(6, solayak);
  lcd.createChar(7, death);
  pinMode(ses, OUTPUT);
}

void loop() {
  while(Serial.read() != 32);
  a = 0;
  flag = false;
  bilinen = 0;
  counter = 0;
  lcd.clear();
  Serial.println("SORAN OYUNCU 5 KARAKTERLI KELIME GIRSIN");
  tone(ses, 5000, 200);
  while(a < 5){
    if(Serial.available() > 0){
      kelime[a] = Serial.read();
      check[a] = false;
      Serial.print("*");
      a++;
      tone(ses, 4000, 200);
    }
  }
  Serial.println("");
  Serial.println("KELIME GIRILDI. BULAN OYUNCU TAHMINE BASLASIN");
  tone(ses, 4500, 200);
  lcd.setCursor(7, 0);
  lcd.write(byte(0));
  while(!flag){
    while(Serial.available() <= 0);
    char tahmin = Serial.read();
    for(int i = 0; i < 5; i++){
      if(tahmin == kelime[i]){
        if(check[i] == false){
          lcd.setCursor(i, 0);
          lcd.print(kelime[i]);
          find = true;
          bilinen++;
          check[i] = true;
          tone(ses, 6000, 200);
        }
        else{
          Serial.println("AYNI HARFI YAZMA");
        }
      }
    }
    if(find == false){
      counter++;
      lcd.setCursor(8,0);
      lcd.write(byte(counter));
      lcd.setCursor(0,1);
      lcd.print("KALAN HAK : ");
      lcd.setCursor(12,1);
      count = String(6 - counter);
      lcd.print(count);
      tone(ses, 5500, 200);
    }
    if(counter == 6){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("KAYBETTIN");
      for(int i = 5000; i > 4000; i -= 100){
        tone(ses, i, 50);
        delay(50);
      }
      delay(250);
      lcd.setCursor(8,0);
      lcd.write(byte(7));
      flag = true;
    }
    if(bilinen == 5){
      delay(500);
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("KAZANDINIZ");
      for(int i = 4000; i < 5000; i += 100){
        tone(ses, i, 50);
        delay(50);
      }
      flag = true;
    }
    find = false;
  }
  Serial.println("TEKRAR OYNAMAK ICIN -SPACE- BASIN");
}