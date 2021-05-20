#include <SPI.h>
#include <RF24.h>

RF24 radio(7,8); //Conexiones pin CE|CSN
const uint64_t acceso = 0xE8E8F0F0E1LL; //Codigo de acceso

int dato;

void setup() {
  //Inicia monitor en serie
  Serial.begin(9600);
  //Inicia la señal
  radio.begin();
  //Misma direccion el el trasmisor
  radio.openReadingPipe(1, acceso);
  //Establece un nivel bajo de potencia
  radio.setPALevel(RF24_PA_MIN);
  //Declarar receptor
  radio.startListening();

}

void loop() {
   //Si recibe algo
  if(radio.available()){
      radio.read(dato, sizeof dato); 
      //Imprimelo
      Serial.println(dato);
  }
  delay(1000);
}
