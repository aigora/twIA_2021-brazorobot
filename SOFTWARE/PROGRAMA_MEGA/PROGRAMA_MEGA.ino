#include <SPI.h>
#include <RF24.h>

//Motor A
const int MotorApin4 = 2;
const int MotorApin3 = 3;
//Motor B
const int MotorBpin2 = 5;
const int MotorBpin1 = 4;

RF24 radio(7,8); //Conexiones pin CNS, CE
const byte acceso[] = "10000"; //Pin de acceso

void setup() {
  //Inicia monitor en serie
  Serial.begin(9600);

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
  
  //Inicia la señal
  radio.begin();
  //Misma direccion el el trasmisor
  radio.openReadingPipe(0, acceso);
  //Establece un nivel bajo de potencia
  radio.setPALevel(RF24_PA_MIN);
  //Declarar receptor
  radio.startListening();

}

void loop() {
  if(radio.available()){
    //Creamos una cadena donde recibir el mensaje
    char texto[3] = "";
    //Recibimos la informacion por Radio Frecuencia
    radio.read(&texto,sizeof(texto));

    if(texto == "01"){
      digitalWrite(3, HIGH); 
      digitalWrite(2, LOW);
      Serial.print("La muñeca esta bajando\n");
      delay(1000);
    }
    if(texto == "10"){
      digitalWrite(2, HIGH); 
      digitalWrite(3, LOW);
      Serial.print("La muñeca esta subiendo\n");
      delay(1000);
    }
    if(texto == "02"){
      digitalWrite(4, HIGH); 
      digitalWrite(5, LOW);
      Serial.print("Las pinzas se estan abriendo\n");
      delay(1000);
    }
    if(texto == "20"){
      digitalWrite(5, HIGH); 
      digitalWrite(4, LOW);
      Serial.print("Las pinzas se estan cerrando\n");
      delay(1000);
    }
    if(texto == "00"){
      digitalWrite(2, LOW); 
      digitalWrite(3, LOW);
      digitalWrite(4, LOW); 
      digitalWrite(5, LOW);
      delay(1000);
    }
  }
}
