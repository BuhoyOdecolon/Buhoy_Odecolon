// контакт подключения аналогового вывода MQ4
const int analogInPin = A0;
int sensorValue = 0; // переменная для хранения значения датчика
void setup()
{
Serial.begin(9600);
}
void loop()
{
sensorValue = analogRead(analogInPin); // получить значение
if (sensorValue >= 180) // превышение уровня
Serial.println("Critical" ); // зажечь светодиод превышения
else
Serial.println("Normal" ); // потушить светодиод превышения
// вывести значение в последовательный порт
Serial.print("sensor = " );
Serial.println(sensorValue); // пауза перед следующим измерением
delay(1000);
}
