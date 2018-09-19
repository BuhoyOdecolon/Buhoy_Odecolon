#include  <LiquidCrystal.h> //подключаем библиотеку

LiquidCrystal lcd(8, 9, 4, 5, 6, 7 );
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
  lcd.begin(16, 2); //Инициализируем дисплей: 2 строки по 16 символов            
  lcd.print("Helo world!");  //Выводи надпись www.helpduino.ru      
}

void loop()
{
  button = getPressedButton();
  //Присваиваем занчение переменной getPressedButton к переменной button 
  switch (button) //перебираем значения в цикле
  {
  case BUTTON_RIGHT: // при нажатии кнопки со значением BUTTON_RIGHT 
    lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("                 "); //стираем текст дисплея
    lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("BUTTON: RIGHT");//выводим надпись BUTTON: RIGHT на экран
    break; //переходим к следующему значению цикла
  case BUTTON_LEFT: // при нажатии кнопки со значением BUTTON_LEFT
     lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("                 "); //стираем текст дисплея
    lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("BUTTON: LEFT"); //выводим надпись BUTTON: LEFT на экран
    break; //переходим к следующему значению цикла
  case BUTTON_UP: // при нажатии кнопки со значением BUTTON_UP
     lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("                 "); //стираем текст дисплея
    lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("BUTTON: UP"); //выводим надпись BUTTON: UP на экран
    break; //переходим к следующему значению цикла
  case BUTTON_DOWN: // при нажатии кнопки со значением BUTTON_DOWN
     lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("                 "); //стираем текст дисплея
    lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("BUTTON: DOWN"); //выводим надпись BUTTON: DOWN на экран
    break; //переходим к следующему значению цикла
  case BUTTON_SELECT: // при нажатии кнопки со значением BUTTON_SELECT
     lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("                 "); //стираем текст дисплея
    lcd.setCursor(0, 0); //устанавливаем курсор на 1 строку 1 столба
    lcd.print("BUTTON: SELECT"); //выводим надпись BUTTON: SELECT на экран
    break; //переходим к следующему значению цикла
  }
}
