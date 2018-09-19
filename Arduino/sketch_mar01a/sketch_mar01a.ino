#include <stDHT.h>
DHT sens(DHT11);

void setup() {
  Serial.begin(9600); 
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
    pinMode(13, INPUT);
  digitalWrite(13, HIGH);

}

void loop() {
 int T1 = Sens_t1();
 int H1 = Sens_h1();
 delay(2000);
 int T2 = Sens_t2();
 int H2 = Sens_h2();
  delay(2000);
  Serial.print("T1 ");
  Serial.print(T1);
  Serial.print("  H1 ");
  Serial.println(H1);
  Serial.print("T2 ");
  Serial.print(T2);
  Serial.print("  H2 ");
  Serial.println(H2);
  }
int Sens_t1() {
  int t1 = sens.readTemperature(2); // считывание показания температуры
 //delay(1000);
 return t1;
 
}
int Sens_h1() {
   int h1 = sens.readHumidity(2); // считывание показания температуры
 //delay(1000);
 return h1;

}
int Sens_t2() {
  int t2 = sens.readTemperature(13); // считывание показания температуры
//delay(1000);
 return t2;

}
int Sens_h2() {
   int h2 = sens.readHumidity(13); // считывание показания температуры
//delay(1000);
 return h2;
}
