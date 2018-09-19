#include "DHT.h"

#define DHTPIN 2 // Тот самый номер пина, о котором упоминалось выше
// Одна из следующих строк закомментирована. Снимите комментарий, если подключаете датчик DHT11 к arduino
//DHT dht(DHTPIN, DHT22); //Инициация датчика
DHT dht(DHTPIN, DHT11);
int DHTSens[2];
void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  delay(2000); // 2 секунды задержки
  tiri();
  float t=DHTSens[1];
  float h=DHTSens[0];
  if (isnan(h) || isnan(t)) {  // Проверка. Если не удается считать показания, выводится «Ошибка считывания», и программа завершает работу
    Serial.println("Ошибка считывания");
    return;
  }
  if (t == 0 || h == 0) {
    Serial.println("Ошибка считывания");
    return;
  }
  Serial.println(DHTSens[0]);
  Serial.println(DHTSens[1]);
  Serial.print("Влажность: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println(" *C "); //Вывод показателей на экран
}
int tiri() {
  float h = dht.readHumidity(); //Измеряем влажность
  float t = dht.readTemperature(); //Измеряем температуру
  DHTSens[0]=h;
  DHTSens[1]=t;
  return DHTSens;
}

