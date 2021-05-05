const int Sflexible = A5;
int Estado = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Estado = analogRead(A5);
  Serial.print("Valor del sensor flexible: ");
  Serial.println(Estado);
  
  delay(1000);
}
