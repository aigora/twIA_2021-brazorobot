int Tilt1 = 3;
int Tilt2 =9;
int Estado1;
int Estado2;
const int MotorApin4 = 6;
const int MotorApin3 = 7;
const int MotorBpin2 = 5;
const int MotorBpin1 = 4;

void setup()
{
  pinMode(Tilt1, INPUT);
  pinMode(Tilt2,INPUT);
  Serial.begin(9600);
   pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
  Estado1 = digitalRead(Tilt1);
  Estado2 = digitalRead(Tilt2);
  if(Estado1 == HIGH){
    digitalWrite(4, HIGH); 
	digitalWrite(5, LOW);
  }  
    else{
    digitalWrite(4, LOW); 
	digitalWrite(5, LOW);
    }  
  if(Estado2 == HIGH){
    digitalWrite(4, LOW); 
	digitalWrite(5, HIGH);
  }
      else{
    digitalWrite(4, LOW); 
	digitalWrite(5, LOW);
      }
}