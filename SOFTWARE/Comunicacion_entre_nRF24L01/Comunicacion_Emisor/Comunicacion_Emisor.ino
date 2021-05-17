#include <SPI.h>
#include <RF24.h>

RF24 radio(7,8); //Conexiones pin CNS, CE
const byte acceso[] = "10000"; //Pin de acceso

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
  Serial.begin(9600);
  const char texto[]= "Conectado";
  //Envia el siguiente texto
  radio.write(&texto, sizeof(texto));
  delay(1000);
}
