/*
Скетч для управления теплицы. Созданно Васильченко Иваном.
*/

//Подключение необходимых библиотек
#include <LiquidCrystal.h> //подключаем библиотеку LCD экрана
#include <stDHT.h> //подключаем библиотеку датчика DHT11


//Инициализации
LiquidCrystal lcd(8, 9, 4, 5, 6, 7 );
DHT sens(DHT11);
byte DHT11_first_sens = 2; // подключаем датчик DHT11 к 2му цифровому пину
byte DHT11_second_sens = 13; // подключаем датчик DHT11 к 13му цифровому пину
byte CO2_sens = A1; // подключаем газоанализатор к первому аналоговому пину
byte Photo_sens = 12; // подключаем фотосенсор к 12му цифровому пину
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
  lcd.print("  Version 0.2.0");
  delay(3000);
  lcd.begin(16,2);
}

void loop() 
{ 
 //ПРОВЕРКА НА УГАРНЫЙ ГАЗ
 int CO2_sens_Value = analogRead(CO2_sens); //считываем значение с газоанализатора
 //Serial.print("CO2 ");
 //Serial.println(CO2_sens_Value);
 if (CO2_sens_Value > 190) //если значение больше критического 
   { lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Critical CO2");
    delay(10000); }
 int photo_sens_value = digitalRead(Photo_sens); //считываем значение с датчика освещённости
 /* Serial.print("Photo ");
  Serial.println(photo_sens_value);
 if (photo_sens_value == 1) {
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("Light ON");
     delay(5000);
  } else {
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("Light OFF");
     delay(5000);
  }*/
pause:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("initialization");
  delay(100);
 
 int buttonValue = analogRead(0); //считываем значение с кнопок 
 //Serial.println(buttonValue);
 button = getPressedButton();
 //Serial.println(button);
 first_sens: //метка
 while (button == 1) // если нажата кнопка вправо
 {
     delay(500);
     int buttonValue = analogRead(0);
     //Serial.println(buttonValue);
     if (buttonValue == 480 || buttonValue == 131 || buttonValue == 307 || buttonValue == 721) goto pause; //если нажаты другие кнопки 
     if (buttonValue == 0) goto second_sens; // если снова нажата кпопка вправо
     delay(100);
     int t1 = sens.readTemperature(DHT11_first_sens); // считывание показания температуры
     int h1 = sens.readHumidity(DHT11_first_sens); // считывание показания влажности
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("First");
     lcd.setCursor(0,1);
     lcd.print("DHT");
     lcd.setCursor(11,0);
     lcd.print("T ");
     lcd.print(t1);
     lcd.print("C");
     lcd.setCursor(11,1);
     lcd.print("F ");
     lcd.print(h1);
     lcd.print("%");
   }

 second_sens:
  while (button == 1){
     delay(500);
     int buttonValue = analogRead(0);
     Serial.println(buttonValue);
     if (buttonValue == 0 || buttonValue == 131 || buttonValue == 307 || buttonValue == 721) goto pause;
     if (buttonValue == 480) goto first_sens; // если нажата кпопка влево
     delay(100);
     int t1 = sens.readTemperature(DHT11_second_sens);
     int h1 = sens.readHumidity(DHT11_second_sens);
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("Second");
     lcd.setCursor(0,1);
     lcd.print("DHT");
     lcd.setCursor(11,0);
     lcd.print("T ");
     lcd.print(t1);
     lcd.print("C");
     lcd.setCursor(11,1);
     lcd.print("F ");
     lcd.print(h1);
     lcd.print("%");
  }
  
}
