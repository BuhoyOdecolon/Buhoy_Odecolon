#include <stDHT.h>

DHT sens(DHT11);

void setup() {
  Serial.begin(57600);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);
  

}

void loop() {
 int t1 = sens.readTemperature(2);
 int h1 = sens.readHumidity(2);
 delay(2000);
 int t2 = sens.readTemperature(3);
 int h2 = sens.readHumidity(3);
 delay(2000);

 Serial.print("Humidity 1: ");
 Serial.print(h1);
 Serial.print(" % ");
 Serial.print("Temperature 1: ");
 Serial.print(t1);
 Serial.println(" C ");
 Serial.print("Humidity 2: ");
 Serial.print(h2);
 Serial.print(" % ");
 Serial.print("Temperature 2: ");
 Serial.print(t2);
 Serial.println(" C ");
}
