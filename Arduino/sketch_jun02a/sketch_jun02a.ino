#include <Wire.h>

#include <LiquidCrystal.h> // Подключаем библиотеку для LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Настройка пинов LCD shields 


byte sec = 0;
byte minut = 0;
byte hor = 0;
int timer = 0;
int currentSec = 0;

void setup() {
  lcd.clear();
  lcd.begin(16, 2);
  //  lcd.print(WC.GS("Ардуино"));
  lcd.print("Timer 1");
  //  lcd.setCursor(8,1);
  //  lcd.print("LCD 1602");

}

void loop() {

  ///////////////////////// обработка таймера

  lcd.setCursor(0, 0);
  lcd.print("Timer 1");

  if ((millis() / 1000) - currentSec >= 1) {
    currentSec = millis() / 1000;
    sec ++;
  }

  if (sec == 60) {
    sec = 0;
    //  lcd.clear();
    minut ++;
  }

  if (minut == 60) {
    minut = 0;
    hor ++;
  }

  if (hor > 99) {
    hor = 0;
  }
  //////////////////////// вывод времяни

  if (sec == 0) {
    lcd.setCursor(6, 1);
    lcd.print("00");
  }
  else {
    lcd.setCursor(6, 1);
    if (sec < 10) lcd.print("0");
    lcd.print(sec);
  }
  lcd.setCursor(2, 1);
  lcd.print(":");
  lcd.setCursor(5, 1);
  lcd.print(":");

  if (minut == 0) {
    lcd.setCursor(3, 1);
    lcd.print("00");
  }
  else {
    lcd.setCursor(3, 1);
    if (minut < 10) lcd.print("0");
    lcd.print(minut);
  }

  if (hor == 0) {
    lcd.setCursor(0, 1);
    lcd.print("00");
  }
  else {
    lcd.setCursor(0, 1);
    if (hor < 10) lcd.print("0");
    lcd.print(hor);
  }
}
