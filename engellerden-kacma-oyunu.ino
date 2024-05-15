#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define button 8
boolean start = false;
short state = 0;
short running = 0;
short engel1 = 16;
short engel2 = 24;
int counter = -3;
byte man1[] = {
	B01110,
  B01110,
  B01110,
  B11111,
  B11111,
  B00110,
  B00110,
  B00000
};
byte man2[] = {
	B01110,
  B01110,
  B01110,
  B11111,
  B11111,
  B01100,
  B01100,
  B00000
};
byte engel[] = {
	B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
  
void setup(){
  lcd.begin(16, 2); 
  lcd.createChar(0, man1);
  lcd.createChar(1, man2);
  lcd.createChar(2, engel);
}

void start_screen(){
  lcd.setCursor(2, 0);
  lcd.print("PRESS START");
  if(digitalRead(button) == HIGH){
    start = true;
  }
}

void engel_gel(short e1, short e2){
  lcd.setCursor(e1, 0);
  lcd.write(byte(2));
  if(e1 != 16){
    lcd.setCursor(e1 + 1, 0);
    lcd.write(byte(2));
  }
  lcd.setCursor(e2, 1);
  lcd.write(byte(2));
  if(e2 != 16){
    lcd.setCursor(e2 + 1, 1);
    lcd.write(byte(2));
  }
}

void gameover_screen(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(3, 1);
  lcd.print("SCORE :");
  lcd.setCursor(11, 1);
  lcd.print((counter / 8) - 1);
  counter = -3;
  delay(1000);
}

void game(){
	lcd.clear();
  if(digitalRead(button) == HIGH){
    state = (state == 1) ? 0 : 1;
  }
  lcd.setCursor(3, state);
  lcd.write(byte(running));
  running = (running == 1) ? 0 : 1;
  if(engel1 == 0){
    engel1 = 16;
  }
  if(engel2 == 0){
    engel2 = 16;
  }
  engel_gel(engel1, engel2);
  if( ((engel1 == 3) && (state == 0)) || ((engel2 == 3) && (state == 1))){
    gameover_screen();
    start = false;
  }
  engel1--;
  engel2--;
  counter++;
}

void loop()
{
  	
  	if(start == true){
      game();
    }
    else{
      start_screen();
    }
    delay(125);
}

