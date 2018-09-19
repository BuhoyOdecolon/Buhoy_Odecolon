 
#include <Wire.h>                           // Подключаем библиотеку Wire                           
#include <TimeLib.h>                        // Подключаем библиотеку TimeLib
#include <DS1307RTC.h>                      // Подключаем библиотеку DS1307RTC
 
void setup() {
  Serial.begin(9600);                       // Устанавливаем скорость передачи данных 
  while (!Serial) ;                         // Ожидаем подключение последовательного порта. Нужно только для Leonardo
  delay(200);                               // Ждем 200 мкс
  Serial.println("DS1307RTC Read Test");    // Выводим данные на последовательный порт
  Serial.println("-------------------");    // Выводим данные на последовательный порт
}
 
void loop() {
  tmElements_t tm;                          
 
  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
}
 
void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
