#include <SPI.h>
#include <RF24.h>

RF24 radio(7,8); //Conexiones pin CNS, CE
const byte acceso[] = "10000"; //Pin de acceso

void setup() {
  //Inicia monitor en serie
  Serial.begin(9600);
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
    char texto[32] = "";
    //Recibimos la informacion por Radio Frecuencia
    radio.read(&texto,sizeof(texto));
    //Eviamos lo que hemos recibido al monitor
    Serial.println(texto);
  }
}
