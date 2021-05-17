const int MotorApin4 = 3;
const int MotorApin3 = 2;

const int MotorBpin2 = 5;
const int MotorBpin1 = 4;


void setup() {
  Serial.begin(9600);
  
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop() {
  
    Serial.print("Estado motor 1: ");
    digitalWrite(2, HIGH); 
  digitalWrite(3, LOW);
  Serial.print("//Girando en las agujas del reloj//\n");
  
    Serial.print("Estado motor 2: ");
    digitalWrite(4, HIGH); 
  digitalWrite(5, LOW);
  Serial.print("//Girando en las agujas del reloj//\n");
    
  delay (500);
  
    Serial.print("Estado motor 1: ");
    digitalWrite(2, LOW); 
  digitalWrite(3, HIGH);
  Serial.print("//Girando en conta de las agujas del reloj//\n");
    
    Serial.print("Estado motor 2: ");
    digitalWrite(4, LOW); 
  digitalWrite(5, HIGH);
  Serial.print("//Girando en conta de las agujas del reloj//\n");
  
  delay (500);
  
}
