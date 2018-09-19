#define PIN_PHOTO_SENSOR 10
 
void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT);
}
 
void loop() {
  int val = digitalRead(10);
  delay(5000);
  if (val < 1) {
    Serial.println("Light ON");
  } else {
    Serial.println("Light OFF");
  }
  

}

