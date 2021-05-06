//Motor A
const int MotorApin4 = 2;
const int MotorApin3 = 3;
//Motor B
const int MotorBpin2 = 5;
const int MotorBpin1 = 4;
//S.flexible 1
const int Sflexible = A5;
int Estadoflexible = 0;

//S.flexible 2
const int Sflexible2 = A4;
int Estadoflexible2 = 0;

void setup()
{
  //Inicia el monitor serie
  Serial.begin(9600);
  
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop()
{ //Lee los estados
  Estadoflexible2 = analogRead(A4);
  //Ajusta el valor de el estado a sus grados(0-180)
  Estadoflexible2 = map(Estadoflexible2,624,229,0,180);
  //Lee los estados
  Estadoflexible = analogRead(A5);
  //Ajusta el valor de el estado a sus grados(0-180)
  Estadoflexible = map(Estadoflexible,624,229,0,180);
  
  if (Estadoflexible >= 70 && Estadoflexible <= 110){
    digitalWrite(3, HIGH); 
  digitalWrite(2, LOW);
  Serial.print("La muñeca esta bajando\n");
    delay(1000);
  }else if (Estadoflexible >= 160 && Estadoflexible <= 180){
    digitalWrite(2, HIGH); 
  digitalWrite(3, LOW);
    Serial.print("La muñeca esta subiendo\n");
    delay(1000);
  } else{
    digitalWrite(2, LOW); 
  digitalWrite(3, LOW);
    Serial.print("La muñeca esta quieta\n");
    delay(1000);
  }
  delay (100);
  
   if (Estadoflexible2 >= 70 && Estadoflexible2 <= 110){
    digitalWrite(4, HIGH); 
  digitalWrite(5, LOW);
  Serial.print("Las pinzas se estan abriendo\n");
     delay(1000);
  }else if (Estadoflexible2 >= 160 && Estadoflexible2 <= 180){
    digitalWrite(5, HIGH); 
  digitalWrite(4, LOW);
    Serial.print("Las pinzas se estan cerrando\n");
     delay(1000);
  } else{
    digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
     Serial.print("Las pinzas estan quietas\n");
     delay(1000);
  }
  delay (100);
}
