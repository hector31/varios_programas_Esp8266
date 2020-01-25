#define My_LED 14

void setup() 
{
  pinMode(My_LED, OUTPUT);
}

void loop() 
{
  digitalWrite(My_LED, HIGH); 
  delay(500);
  digitalWrite(My_LED, LOW); 
  delay(500);
}
