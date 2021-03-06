#include  <LiquidCrystal.h> //подключаем библиотеку 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7 );
int x; //шина кнопок                
unsigned long currentTime; //текущее время
unsigned long loopTime; //время окончания
unsigned long LimitTime = 0; //добавочное время таймера
boolean running = false; //Флаг Запуска отсчета

 
void setup()
{
   lcd.begin(16, 2); //Инициализируем дисплей: 2 строки по 16 символов
   lcd.print("Timer"); //заставка 
   delay(500); //ждем половину секунды
   lcd.begin(16, 2); //очистить экран
   lcd.print("www.Helpduino.ru"); //заставка 
   delay(500); //ждем половину секунды
   lcd.begin(16, 2); //очистить экран
   currentTime = millis(); 
   // считываем время, прошедшее с момента запуска программы 
}
void loop()
{                           
   if (running == true) {    //Выбран РЕЖИМ ОТСЧЕТА 
   currentTime = millis();
  
  loopTime = currentTime + LimitTime; 
  //Указываем время окончания (текущее время + добавочное время таймера)
  while(currentTime < loopTime){
  // сравниваем текущее время с вр окончания
  //Пока текущее время меньше времени окончания
  //Проверяем кнопку "Прервать"
  x = analogRead (0); //считываем шину кнопок
  delay(200); //защита от дребезга
  if (x < 100) { // Если нажата кнопка "Right "
  //"прервать" кнопка "Right " 
  lcd.begin(16, 2); //очистить экран
  lcd.print("Interrupted"); //выводим прервано
  //устанавливаем начальные значения
  running = false; //останавливаем таймер
  LimitTime = 0; //устанавливаем начальные значения
  delay(3000); //пауза 3 секунды
  lcd.begin(16, 2); //очистить экран
  goto bailout; //переход на опрос клавиатуры
   } 
  lcd.begin(16, 2); //очистить экран
  lcd.setCursor(0, 0); //курсор в 0
  lcd.print("Time to off: "); //время до окончания
  lcd.setCursor(13, 0); //Устанавливаем курсор
  lcd.print(LimitTime/1000);
  //Указываем добавочное время, переводя миллисекунды в секунды 
  delay(800); //ждем 0.8 секунды
  LimitTime = LimitTime - (millis() - currentTime);
  //уменьшаем таймер для вывода на экран 
  currentTime = millis(); //получаем новое время 
   } 
  //окончание работы таймера
  lcd.print("             "); //стираем экран
  lcd.setCursor(0, 0); // установка курсора на нулевую строку
  lcd.print("Timer: OFF"); //Выводим надпись "Timer: OFF"
  running = false; //останавливаем таймер
  delay (3000); //ждем 3 секунды
  lcd.begin(16, 2); //очистить экран
   }
  else { //иначе, выбираем режим отсчета
  bailout:
  keypad ();
  }  
 } 
  void keypad () { //функция опроса клавиш: вверх, вниз и выбор
  x = analogRead (0); //считываем шину кнопок 
  delay(200); //ожидаем 0.2 секунды
  lcd.setCursor(0,1); //устанавливаем курсор
  lcd.print ("                "); //стираем экран
  lcd.setCursor(0,0);  //устанавливаем курсор
  lcd.print ("Time:");  //выводим слово "Time:"
   
  if (x < 200) { // если нажата клавиша вверх
    
    if ((LimitTime + 60000) <= 300005)
    //если мы указываем время меньше или равно 5 минутам минут 
    {
    LimitTime += 60000; // прибавляем 1 минуту
    lcd.setCursor(7,0); //устанавливаем курсор
    lcd.print (LimitTime/60000); //выводим значение таймера в секундах 
    }
    else {
    //иначе, при попытке прибавить больше 5 минут
    lcd.setCursor(0,1); //устанавливаем курсор
    lcd.print ("maximum 5 min"); //выводим надпись "maximum 5 min"
    delay (1000); //ждем 1 секунду
    lcd.setCursor(0,1); //устанавливаем курсор
    lcd.print ("               "); //стираем экран
    }
  } 
  else if (x < 400){  //иначе, если нажимаем кнопку вниз
    if (LimitTime  > 60000) // если мы указываем время больше 1 минуты
    {
    LimitTime -= 60000; //отнимаем 1 минуту
    lcd.setCursor(7,0); //устанавливаем курсор
    lcd.print (LimitTime/60000); //выводим значение таймера в секундах
    }
    else { // иначе, при выборе значения меньше 1 минуты
    lcd.setCursor(0,1); //устанавливаем курсор
    lcd.print ("minimum 1 min"); //выводим надпись "minimum 1 min"
    delay (1000); //ждем 1 секунду
    lcd.setCursor(0,1); //устанавливаем курсор
    lcd.print ("               "); //стираем экран
    }
    
  } 
  
  else if (x < 600){ //иначе, если нажимаем на кнопку left
    if (LimitTime !=0 ) //если добавочное время равно 0
    {running = true;                //Устанавливаем запуск отсчета
    lcd.begin(16, 2);
    lcd.setCursor(0,0); //устанавливаем курсор
    lcd.print ("Start"); //выводим надпись "Start"
   delay(1000); } //ждем 1 секунду
   else { //иначе, если не выбрали время
   lcd.setCursor(0,1); //устанавливаем курсор
   lcd.print ("Warning"); //выводим надпись "Warning"
   delay(700);//ждем 0.7 секунды
   }
  }
  } // Конец
