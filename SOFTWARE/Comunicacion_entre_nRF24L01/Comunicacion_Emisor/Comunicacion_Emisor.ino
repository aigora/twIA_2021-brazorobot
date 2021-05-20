#include <SPI.h>
#include <RF24.h>

RF24 radio(9,10); //Conexiones pin CE|CSN
const uint64_t acceso = 0xE8E8F0F0E1LL; //Codigo de acceso

int dato;

void setup() {
  //Inicia la señal
  radio.begin();
  radio.openWritingPipe(acceso);
  //Establece un nivel bajo de potencia
  radio.setPALevel(RF24_PA_MIN);
  //Declarar trasmisor
  radio.stopListening();

}

void loop() {
  //Asigna un valo a dato
  dato = 01;
  //Envia los siguientes digitos
  radio.write(dato, sizeof dato);
  delay(1000);
}
