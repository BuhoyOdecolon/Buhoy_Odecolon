/*Климат контроль теплицы*/

//подключение библиотек 
#include <LiquidCrystal.h> //подключаем библиотеку LCD экрана
#include <stDHT.h> //подключаем библиотеку датчика DHT11

//Инициализация 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7 );
DHT sens(DHT11);

//переменные для пинов датчиков
byte DHT11_first_sens = 0; // подключаем датчик DHT11 к 2му цифровому пину
byte DHT11_second_sens = 1; // подключаем датчик DHT11 к 13му цифровому пину
byte DHT11_third_sens = 2; // подключаем датчик DHT11 к 2му цифровому пину
byte DHT11_four_sens = 3; // подключаем датчик DHT11 к 13му цифровому пину
byte Photo_sens = 11; // подключаем фотосенсор к 12му цифровому пину
byte CO2_sens = A1; // подключаем газоанализатор к первому аналоговому пину
byte Relay_1 = 12;
byte Relay_2 = 13;
byte Ground_Hum_first = A2;
byte Ground_Hum_second = A3;
byte Water_sens = A4;

//переменные для работы
boolean Test = false;
int Crit_CO2 = 600;

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

void setup() {
  if (Test == true) {
  Serial.begin(9600); }
  pinMode(DHT11_first_sens, INPUT);
  digitalWrite(DHT11_first_sens, HIGH);
  pinMode(DHT11_second_sens, INPUT);
  digitalWrite(DHT11_second_sens, HIGH);
  pinMode(DHT11_second_sens, INPUT);
  digitalWrite(DHT11_second_sens, HIGH);
  pinMode(DHT11_second_sens, INPUT);
  digitalWrite(DHT11_second_sens, HIGH);
  pinMode(Water_sens, INPUT);
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  lcd.begin(16,2); //инициализация дисплея
  lcd.setCursor(5,1); //курсор на 2ю строку
  lcd.print("v0.3.0");
  delay(3000);
  lcd.begin(16,2);
}

void loop() {
  lcd.begin(16,2);
  int Gas = CO2();
  if (Gas > Crit_CO2) //если значение больше критического 
   { lcd.begin(16,2);
    lcd.setCursor(2,0);
    lcd.print("Critical CO2");
    lcd.setCursor(7,1);
    lcd.print(Gas);
    delay(10000); }
  int Light();
  Serial.println(Light());
  if (Light() == 1) {
    digitalWrite(Relay_2, HIGH);   // реле включено
    delay(2000);                
  }
  if (Light() == 0) {               
    digitalWrite(Relay_2, LOW);  // реле выключено
    delay(2000);  
  }
  int buttonValue = analogRead(0); //считываем значение с кнопок 
  button = getPressedButton();
  switch (button) {
    case 1:
      menu_right1();
    break;
    case 2:
      menu_up();
    break;
    case 3:
      menu_down();
    break;
  }
  while (Test == true) {
    Test_UNO();
  }
}

int Test_UNO () {
    int buttonValue = analogRead(0);
    button = getPressedButton(); 
    Serial.print("button ");
    Serial.println(button);
    Serial.print("buttonValue ");
    Serial.println(buttonValue);
    delay(2000);
    int CO2_sens_Value = analogRead(CO2_sens);
    Serial.print("CO2 ");
    Serial.println(CO2_sens_Value);
    delay(2000);
    int photo_sens_value = digitalRead(Photo_sens);
    Serial.print("Light ");
    Serial.println(photo_sens_value);
    delay(2000);
    int Grnd_Hum1 = analogRead(Ground_Hum_first);
    int Grnd_Hum2 = analogRead(Ground_Hum_second);
    long Grnd_Hum = (Grnd_Hum1 + Grnd_Hum2)/2;
     Serial.print("Ground Humidity ");
     Serial.println(Grnd_Hum);
    delay(2000);
    int wtr = analogRead(Water_sens);
    Serial.print("Water ");
     Serial.println(wtr);
    
}

int CO2() {
  int CO2_sens_Value = analogRead(CO2_sens);
  return CO2_sens_Value;
}

int Light () {
  int photo_sens_value = digitalRead(Photo_sens);
  Serial.println(photo_sens_value);
  return photo_sens_value;
}

int Ground_Humidity1() {
    int Grnd_Hum1 = analogRead(Ground_Hum_first);
    return Grnd_Hum1;
}

int Ground_Humidity2() {
    int Grnd_Hum2 = analogRead(Ground_Hum_second);
    return Grnd_Hum2;
}

int Water() {
  int wtr = analogRead(Water_sens);
  return wtr;
}

int Sens_Dht_temp1() {
  int t1 = sens.readTemperature(DHT11_first_sens); // считывание показания температуры
 return t1;
}

int Sens_Dht_hum1() {
   int h1 = sens.readHumidity(DHT11_first_sens); // считывание показания температуры
 return h1;
}

int Sens_Dht_temp2() {
  int t2 = sens.readTemperature(DHT11_second_sens); // считывание показания температуры
 return t2;
}

int Sens_Dht_hum2() {
   int h2 = sens.readHumidity(DHT11_second_sens); // считывание показания температуры
 return h2;
}

int Sens_Dht_temp3() {
  int t3 = sens.readTemperature(DHT11_third_sens); // считывание показания температуры
 return t3;
}

int Sens_Dht_hum3() {
   int h3 = sens.readHumidity(DHT11_third_sens); // считывание показания температуры
 return h3;
}

int Sens_Dht_temp4() {
  int t4 = sens.readTemperature(DHT11_four_sens); // считывание показания температуры
 return t4;
}

int Sens_Dht_hum4() {
   int h4 = sens.readHumidity(DHT11_four_sens); // считывание показания температуры
 return h4;
}

int menu_right1 () {
  lcd.begin(16, 2);
  while (button == 1) // если нажата кнопка вправо
 {
     delay(500);
     int buttonValue = analogRead(0);
     Serial.println(buttonValue);
     if (buttonValue == 479 || buttonValue == 131 || buttonValue == 307 || buttonValue == 719) break; //если нажаты другие кнопки 
     if (buttonValue == 0) menu_right2(); // если снова нажата кпопка вправо
     int Temperature1 = Sens_Dht_temp1();
     int Humidity1 = Sens_Dht_hum1();
     int Temperature2 = Sens_Dht_temp2();
     int Humidity2 = Sens_Dht_hum2();
     int Temp_ground = (Temperature1 + Temperature2)/2;
     int Hum_ground = (Humidity1 + Humidity2)/2;
     lcd.setCursor(0,0);
     lcd.print("Ground");
     lcd.setCursor(11,0);
     lcd.print("T ");
     lcd.print(Temp_ground);
     lcd.print("C");
     lcd.setCursor(11,1);
     lcd.print("F ");
     lcd.print(Hum_ground);
     lcd.print("%");
   }
}
  
int menu_right2 () {
  lcd.begin(16, 2);
  while (button == 1) // если нажата кнопка вправо
 {
     delay(500);
     int buttonValue = analogRead(0);
     Serial.println(buttonValue);
     if (buttonValue == 0 || buttonValue == 131 || buttonValue == 307 || buttonValue == 719) loop(); //если нажаты другие кнопки 
     if (buttonValue == 479) menu_right1(); // если снова нажата кпопка вправо
     int Temperature3 = Sens_Dht_temp3();
     int Humidity3 = Sens_Dht_hum3();
     int Temperature4 = Sens_Dht_temp4();
     int Humidity4 = Sens_Dht_hum4();
     int Temp_ground = (Temperature3 + Temperature4)/2;
     int Hum_ground = (Humidity3 + Humidity4)/2;
     lcd.setCursor(0,0);
     lcd.print("Air");
     lcd.setCursor(11,0);
     lcd.print("T ");
     lcd.print(Temp_ground);
     lcd.print("C");
     lcd.setCursor(11,1);
     lcd.print("F ");
     lcd.print(Hum_ground);
     lcd.print("%");
   } 
}

int menu_down() {
  lcd.begin(16, 2);
  while (button == 3) // если нажата кнопка вправо
 {
     delay(500);
     int buttonValue = analogRead(0);
     Serial.println(buttonValue);
     if (buttonValue == 0 || buttonValue == 131 || buttonValue == 307 || buttonValue == 719) loop(); //если нажаты другие кнопки 
     if (buttonValue == 479) loop(); // если снова нажата кпопка вправо
     int Gas = CO2();
     lcd.setCursor(0,1);
     lcd.print("CO2 ");
     lcd.print(Gas);
   } 
}

int menu_up() {
  lcd.begin(16, 2);
  while (button == 2) // если нажата кнопка вверх
 {
     delay(500);
     int buttonValue = analogRead(0);
     Serial.println(buttonValue);
     if (buttonValue == 0 || buttonValue == 131 || buttonValue == 307 || buttonValue == 719) loop(); //если нажаты другие кнопки 
     if (buttonValue == 479) loop(); // если снова нажата кпопка вправо
     int sun = Light();
     lcd.setCursor(0,1);
     lcd.print("Light ");
     lcd.print(sun);
   }    
}