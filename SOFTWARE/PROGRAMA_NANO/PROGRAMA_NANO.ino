#include <SPI.h>
#include <RF24.h>

const int Sflexible = A5; 
int Estadoflexible = 0;

const int Sflexible2 = A4; 
int Estadoflexible2 = 0;

RF24 radio(7,8); //Conexiones pin CNS, CE
const byte acceso[] = "10000"; //Pin de acceso

void setup() {
  //Inicia el monitor en serie
  Serial.begin(9600);
  
  //Inicia la señal
  radio.begin();
  radio.openWritingPipe(acceso);
  //Establece un nivel bajo de potencia
  radio.setPALevel(RF24_PA_MIN);
  //Declarar trasmisor
  radio.stopListening();

}

void loop() {
  
  Estadoflexible = analogRead(A5);
  //Ajusta el valor de el estado a sus grados(0-180)
  Estadoflexible = map(Estadoflexible,624,229,0,180);

   Estadoflexible2 = analogRead(A4);
  //Ajusta el valor de el estado a sus grados(0-180)
  Estadoflexible2 = map(Estadoflexible2,624,229,0,180);

  //Si el sensor sencuentra entre 70 y 110 grados
  if (Estadoflexible >= 70 && Estadoflexible <= 110){
    //Envia 01
    radio.write("01",sizeof("01"));
    delay(1000);
  }
   //Si el sensor sencuentra entre 160 y 180 grados
  else if (Estadoflexible >= 160 && Estadoflexible <= 180){
    //Envia 10
    radio.write("10",sizeof("10"));
    delay(1000);
  }else{
    radio.write("00",sizeof("00"));
    delay(1000);
  }

//Si el sensor 2 sencuentra entre 70 y 110 grados
  if (Estadoflexible2 >= 70 && Estadoflexible2 <= 110){
    //Envia 02
    radio.write("02",sizeof("02"));
    delay(1000);
  }
   //Si el sensor 2 sencuentra entre 160 y 180 grados
  else if (Estadoflexible2 >= 160 && Estadoflexible2 <= 180){
    //Envia 20
    radio.write("20",sizeof("20"));
    delay(1000);
  }else{
    radio.write("00",sizeof("00"));
    delay(1000);
  }
  
}
