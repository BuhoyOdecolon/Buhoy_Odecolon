//подключение библиотек 
#include <LiquidCrystal.h> //подключаем библиотеку LCD экрана
#include <stDHT.h> //подключаем библиотеку датчика DHT11

//кнопки LCD модуля
int button;  //вводим числовые значения для кнопок
const int BUTTON_NONE   = 0; //присваиваем постоянное значение для BUTTON_NONE 
const int BUTTON_RIGHT  = 1; //присваиваем постоянное значение для BUTTON_RIGHT
const int BUTTON_UP     = 2; //присваиваем постоянное значение для BUTTON_UP
const int BUTTON_DOWN   = 3; //присваиваем постоянное значение для BUTTON_DOWN 
const int BUTTON_LEFT   = 4; //присваиваем постоянное значение для BUTTON_LEFT
const int BUTTON_SELECT = 5; //присваиваем постоянное значение для BUTTON_SELECT

int getPressedButton() //функция инициализации переменной
{
  int buttonValue = analogRead(0); // считываем значения с аналогового входа
  if (buttonValue < 100) { //если при нажатии кнопки значение меньше 100
    return BUTTON_RIGHT;   // выводим значение BUTTON_RIGHT
  }
  else if (buttonValue < 200) { //если при нажатии кнопки значение меньше 200
    return BUTTON_UP; // выводим значение BUTTON_UP
  }
  else if (buttonValue < 400){ //если при нажатии кнопки значение меньше 400
    return BUTTON_DOWN; // выводим значение BUTTON_DOWN
  }
  else if (buttonValue < 600){ //если при нажатии кнопки значение меньше 600
    return BUTTON_LEFT; // выводим значение BUTTON_LEFT
  }
  else if (buttonValue < 800){ //если при нажатии кнопки значение меньше 800
    return BUTTON_SELECT; // выводим значение BUTTON_SELECT
  }
  return BUTTON_NONE; //иначе, выводим значение BUTTON_NONE
}
byte load100[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
void setup() {

  lcd.begin(16,2); //инициализация дисплея
  lcd.print("    Loading.    ");
  lcd.setCursor(0, 1);
  lcd.print("\1");
  delay(200);
  lcd.print("\1");
  delay(250);
  lcd.print("\1");
  delay(100);
  lcd.print("\1");
  delay(210);
  lcd.print("\1");
  delay(250);
  lcd.print("\1");
  delay(200);
  lcd.print("\1");
  delay(200);
  lcd.print("\1");
  delay(200);
  lcd.print("\1");
  delay(250);
  lcd.print("\1");
  delay(280);
  lcd.print("\1");
  delay(300);
  lcd.print("\1");
  delay(300);
  lcd.print("\1");
  delay(200);
  lcd.print("\1");
  delay(200);
  lcd.print("\1");
  delay(200);
  lcd.print("\1");
  
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    Welcome!    ");
  delay(3500);
  lcd.clear();
}

}

void loop() {
  // put your main code here, to run repeatedly:

}
