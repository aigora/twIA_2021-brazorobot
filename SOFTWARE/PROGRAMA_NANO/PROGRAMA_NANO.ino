#include <SPI.h>
#include <RF24.h>

const int Sflexible = A5; 
int Estadoflexible = 0;

const int Sflexible2 = A4; 
int Estadoflexible2 = 0;

RF24 radio(9,10); //Conexiones pin CE|CSN
const uint64_t acceso = 0xE8E8F0F0E1LL; //Codigo de acceso

int dato;

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
  Estadoflexible = map(Estadoflexible,268,110,0,180);

   Estadoflexible2 = analogRead(A4);
  //Ajusta el valor de el estado a sus grados(0-180)
  Estadoflexible2 = map(Estadoflexible2,268,110,0,180);

  //Si el sensor sencuentra entre 70 y 110 grados
  if (Estadoflexible >= 70 && Estadoflexible <= 110){
    dato = 01;
    //Envia 01
    radio.write(dato,sizeof dato);
    delay(1000);
  }
   //Si el sensor sencuentra entre 160 y 180 grados
  else if (Estadoflexible >= 160 && Estadoflexible <= 180){
     dato = 10;
    //Envia 10
    radio.write(dato,sizeof dato);
    delay(1000);
  }else{
    dato = 00;
    radio.write(dato,sizeof dato);
    delay(1000);
  }

//Si el sensor 2 sencuentra entre 70 y 110 grados
  if (Estadoflexible2 >= 70 && Estadoflexible2 <= 110){
    dato = 02;
    //Envia 02
    radio.write(dato,sizeof dato);
    delay(1000);
  }
   //Si el sensor 2 sencuentra entre 160 y 180 grados
  else if (Estadoflexible2 >= 160 && Estadoflexible2 <= 180){
    dato = 20;
    //Envia 20
    radio.write(dato,sizeof dato);
    delay(1000);
  }else{
    dato = 00;
    radio.write(dato,sizeof dato);
    delay(1000);
  }
  
}
