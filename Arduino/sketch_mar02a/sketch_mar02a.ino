int Relay = 13;

void setup() 
{                
  pinMode(Relay, OUTPUT);     
}

void loop() 
{
  digitalWrite(Relay, LOW);   // реле включено
  delay(2000);               
  digitalWrite(Relay, HIGH);  // реле выключено
  delay(2000);               
}
