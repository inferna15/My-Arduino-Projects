#include <Stepper.h>
#include "Stepmotor.h"
// !! Simülasyonda motorlar +1 den başladığı için bende bu sapmayı ekledim.
int sapma = 1;
// !!
// Motorlar
Stepmotor motor1(10, 11, 12, 13); // Yatay Haraket Sağlayacak |x| <= 25 cm
Stepmotor motor2(6, 7, 8, 9); // Dikey Haraket Sağlayacak 0 <= x <= 15 cm
Stepmotor motor3(2, 3, 4, 5); // Dönme haraketi Sağlayacak |deg| <= 45°
// Konumlar
float dikeykonum = 0; // 0 <= x <= 15 cm
float yataykonum = 0; // |x| <= 25 cm
float donmeacisi = 0; // |deg| <= 45°
// Hız ayarıyla ilgili şeyler
int hiz = 3;
String strhiz[] = {"1", "2", "3", "4", "5"};
int inthiz[] = {10, 25, 50, 100, 200};

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(50); // 10    25    50    100     200
  motor2.setSpeed(50); // 1000  400   200   100     50
  motor3.setSpeed(50);
}

void loop() {
  Serial.println("Yatay Haraket Ayarlama (Y)");
  Serial.println("Dikey Haraket Ayarlama (D)");
  Serial.println("Donme Acisi   Ayarlama (A)");
  Serial.println("Hiz Ayarlama           (H)");
  while(!Serial.available());
  int durum = Serial.read();
  if(durum == 89 || durum == 121){
    yatayHareketAyarla();
  }
  else if(durum == 68 || durum == 100){
    dikeyHareketAyarla();
  }
  else if(durum == 65 || durum == 97){
    donmeAcisiAyarla();
  }
  else if(durum == 72 || durum == 104){
    hizAyarla();
  }
  else{
    Serial.println("Lutfen gecerli bir deger giriniz.");
  }
}

void yatayHareketAyarla(){
  Serial.println("(|x| <= 25 cm) Bu kurala gore bir cm degeri giriniz :");
  int number = sayial();
  int temp = number;
  bool isTurn = true;
  if(number <= 25 - sapma && number >= -25 - sapma){
    // Yön ayarlama
    if(yataykonum > number){
      motor1.setDirection(-1);
      number = yataykonum - number;
    }
    else if(yataykonum < number){
      motor1.setDirection(1);
      number = number - yataykonum;
    }
    else{
      Serial.println("Zaten bu konumda.");
      isTurn = false;
    }
    // Adım sayısı ayarlama
    if(isTurn){
      for(int i = 0; i < number; i++){
        motor1.run();
      }
    }
    yataykonum = temp;
  }
  else{
    Serial.println("Lutfen kurala uygun bir deger giriniz.");
  }
}

void dikeyHareketAyarla(){
  Serial.println("(0 <= x <= 15 cm) Bu kurala gore bir cm degeri giriniz :");
  int number = sayial();
  int temp = number;
  bool isTurn = true;
  if(number <= 15 - sapma && number >= 0 - sapma){
    // Yön ayarlama
    if(dikeykonum > number){
      motor2.setDirection(-1);
      number = dikeykonum - number;
    }
    else if(dikeykonum < number){
      motor2.setDirection(1);
      number = number - dikeykonum;
    }
    else{
      Serial.println("Zaten bu konumda.");
      isTurn = false;
    }
    // Adım sayısı ayarlama
    if(isTurn){
      for(int i = 0; i < number; i++){
        motor2.run();
      }
    }
    dikeykonum = temp;
  }
  else{
    Serial.println("Lutfen kurala uygun bir deger giriniz.");
  }
}

void donmeAcisiAyarla(){
  Serial.println("(|deg| <= 45°) Bu kurala gore bir cm degeri giriniz :");
  int number = sayial();
  int temp = number;
  bool isTurn = true;
  if(number <= 45 - sapma && number >= -45 - sapma){
    // Yön ayarlama
    if(donmeacisi > number){
      motor3.setDirection(-1);
      number = donmeacisi - number;
    }
    else if(donmeacisi < number){
      motor3.setDirection(1);
      number = number - donmeacisi;
    }
    else{
      Serial.println("Zaten bu konumda.");
      isTurn = false;
    }
    // Adım sayısı ayarlama
    if(isTurn){
      for(int i = 0; i < number; i++){
        motor3.run();
      }
    }
    donmeacisi = temp;
  }
  else{
    Serial.println("Lutfen kurala uygun bir deger giriniz.");
  }
}

int sayial(){
  int number = 0;
  bool isSum = true;
  while (1){
    if(Serial.available()){
      int rakam = Serial.read();
      if(rakam == 13){
        break;
      }
      if(rakam == 45){
        isSum = false;
        continue;
      }
      if(isSum){
        number = (number * 10) + (rakam - 48);
      }
      else{
        number = (number * 10) - (rakam - 48);
      }
    }
  }
  return number - sapma;
}

void hizAyarla(){
  Serial.println("5 hiz ayarindan birini seciniz.");
  Serial.println("Suanda mevcut hiz ayariniz : " + strhiz[hiz - 1]);
  Serial.println(" [1] - [2] - [3] - [4] - [5] ");
  while(!Serial.available());
  int a = Serial.read();
  if(a > 48 && a < 54){
    hiz = a - 48;
    Serial.println("Yeni hiz ayariniz : " + strhiz[hiz - 1]);
    motor1.setSpeed(inthiz[hiz - 1]);
    motor2.setSpeed(inthiz[hiz - 1]);
    motor3.setSpeed(inthiz[hiz - 1]);
  }
  else{
    Serial.println("Yanlis giris");
  }
}








