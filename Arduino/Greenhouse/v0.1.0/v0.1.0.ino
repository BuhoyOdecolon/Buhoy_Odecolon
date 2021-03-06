/*
Скетч для управления теплицы. Созданно Васильченко Иваном.
*/

//Подключение необходимых библиотек
#include <LiquidCrystal.h> //подключаем библиотеку LCD экрана
#include <stDHT.h> //подключаем библиотеку датчика DHT11


//Инициализации
LiquidCrystal lcd(8, 9, 4, 5, 6, 7 );
DHT sens(DHT11);
byte DHT11_first_sens = 2;
byte DHT11_second_sens = 13;
int button;  //вводим числовые значения для кнопок
const int BUTTON_NONE   = 0; //присваиваем постоянное значение для BUTTON_NONE 
const int BUTTON_RIGHT  = 1; //присваиваем постоянное значение для BUTTON_RIGHT
const int BUTTON_UP     = 2; //присваиваем постоянное значение для BUTTON_UP
const int BUTTON_DOWN   = 3; //присваиваем постоянное значение для BUTTON_DOWN 
const int BUTTON_LEFT   = 4; //присваиваем постоянное значение для BUTTON_LEFT
const int BUTTON_SELECT = 5; //присваиваем постоянное значение для BUTTON_SELECT

int getPressedButton() //инициализация переменной
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
void setup() 
{
  Serial.begin(9600);
  pinMode(DHT11_first_sens, INPUT);
  digitalWrite(DHT11_first_sens, HIGH);
  pinMode(DHT11_second_sens, INPUT);
  digitalWrite(DHT11_second_sens, HIGH);
  lcd.begin(16,2); //инициализация дисплея
  /*
  //Бегущая строка
  
  char string[50] = "Control of Greenhouse "; //Выводимый текст
  int razmer = strlen(string);

    for (int i = 15; i > 0; i--)
      { 
      lcd.setCursor(i,0); //устанавливаем курсор на 1 строку (она нулевая)
      lcd.print(string); //пишем вводимый текст
      delay(500); // задержка в выводе текста
      }
   
    for (int in = 0; in <= razmer; in++)
     {
       lcd.setCursor(0,0);
       lcd.print(string);
   
         for(int j = 0; j < razmer; j++)
          {
         if (string[j+1] == '\0')
          {
           string[j] = ' ';  
          }
         else
          string[j] = string[j+1];
          }

    delay(1000);
     }
   */  
  lcd.setCursor(0,1); //курсор на 2ю строку
  lcd.print("  Version 0.1.0");
  delay(3000);
  lcd.begin(16,2);
}

void loop() 
{ 
 pause:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("initialization");
  delay(1000);
 
 int buttonValue = analogRead(0);
 Serial.println(buttonValue);
 button = getPressedButton();
 Serial.println(button);
 first:
 while (button == 1){
     delay(500);
     int buttonValue = analogRead(0);
     Serial.println(buttonValue);
     if (buttonValue > 100 && buttonValue < 1000) break;
     if (buttonValue < 100) goto second;
     delay(1000);
     int t1 = sens.readTemperature(DHT11_first_sens);
     int h1 = sens.readHumidity(DHT11_first_sens);
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("First DHT");
     lcd.setCursor(11,0);
     lcd.print("T ");
     lcd.print(t1);
     lcd.print("C");
     lcd.setCursor(11,1);
     lcd.print("F ");
     lcd.print(h1);
     lcd.print("%");
   }

 second:
  while (button == 1){
     delay(500);
     int buttonValue = analogRead(0);
     Serial.println(buttonValue);
     if (buttonValue > 100 && buttonValue < 470 && buttonValue > 490 && buttonValue < 1000) break;
     if (buttonValue == 480) goto first;
     int t1 = sens.readTemperature(DHT11_second_sens);
     int h1 = sens.readHumidity(DHT11_second_sens);
     delay(1000);
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("Gogo ");
     lcd.setCursor(13,0);
     lcd.print(t1);
     lcd.setCursor(15,0);
     lcd.print("C");
     lcd.setCursor(0,1);
     lcd.print("Jojo ");
     lcd.setCursor(13,1);
     lcd.print(h1);
     lcd.setCursor(15,1);
     lcd.print("%");
     delay(100);
  }
}
