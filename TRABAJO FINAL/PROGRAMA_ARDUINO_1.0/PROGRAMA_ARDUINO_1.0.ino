
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

//Direccion del giroscopio
const int mpuAddress = 0x68;  // Puede ser 0x68 o 0x69
MPU6050 mpu(mpuAddress);

//Posiciones de espacio
int ax, ay, az;
int gx, gy, gz;

//Declaracion de variables tiempo y giro
long tiempo_prev, dt;
float girosc_ang_x, girosc_ang_y,girosc_ang_z;
float girosc_ang_x_prev, girosc_ang_y_prev, girosc_ang_z_prev;

//Funcion de giro
void updateGiro()
{
   dt = millis() - tiempo_prev;
   tiempo_prev = millis();
   girosc_ang_x = (gx / 131)*dt / 1000.0 + girosc_ang_x_prev;
   girosc_ang_y = (gy / 131)*dt / 1000.0 + girosc_ang_y_prev;
   girosc_ang_z = (gy / 131)*dt / 1000.0 + girosc_ang_z_prev;
   girosc_ang_x_prev = girosc_ang_x;
   girosc_ang_y_prev = girosc_ang_y;
   girosc_ang_z_prev = girosc_ang_z;
}

//Motor A
const int MotorApin4 = 2;
const int MotorApin3 = 3;
//Motor B
const int MotorBpin2 = 5;
const int MotorBpin1 = 4;
//Motor C
const int MotorCpin2 = 7;
const int MotorCpin1 = 6;
//Motor D
const int MotorDpin4 = 9;
const int MotorDpin3 = 8;
//Motor E
const int MotorEpin2 = 11;
const int MotorEpin1 = 10;


//S.flexible 1
const int Sflexible = A0;
int Estadoflexible = 0;

//S.flexible 2
const int Sflexible2 = A1;
int Estadoflexible2 = 0;

void setup()
{
  //Inicia el monitor serie
  Serial.begin(9600);
  
  //Inicia el giroscopio
  Wire.begin();
  mpu.initialize();
  Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));

  //Estado de los pines digitales
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    
}

void loop()
{ 
  // Leer las velocidades angulares 
   mpu.getRotation(&gx, &gy, &gz);
   updateGiro();
   
   // Mostrar resultados
   Serial.print(F("\tRotacion en y: "));
   Serial.println(girosc_ang_y);
   Serial.print(F("\tRotacion en x: "));
   Serial.println(girosc_ang_x);
   Serial.print(F("\tRotacion en z: "));
   Serial.println(girosc_ang_z);
  
  //Lee los estados
  Estadoflexible2 = analogRead(A1);
  //Ajusta el valor de el estado a sus grados(0-180)
  Estadoflexible2 = map(Estadoflexible2,624,229,0,180);
  
  //Lee los estados
  Estadoflexible = analogRead(A0);
  
  //Instrucciones giroscopio
  if(girosc_ang_y > 35){
   digitalWrite(3, HIGH); 
   digitalWrite(2, LOW);
    }
    else if(girosc_ang_y < -35){
    digitalWrite(3, LOW); 
    digitalWrite(2, HIGH);
    }
     else{
    digitalWrite(3, LOW); 
    digitalWrite(2, LOW);
    }
    
    if(girosc_ang_x > 35){
   digitalWrite(4, HIGH); 
   digitalWrite(5, LOW);
    }
    else if(girosc_ang_x <- 35){
    digitalWrite(4, LOW); 
    digitalWrite(5, HIGH);
    }
     else{
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW);
    } 
    
  //Instrucciones sensores flexibles
  if (Estadoflexible >= 160 && Estadoflexible <= 190){
    digitalWrite(8, HIGH); 
    digitalWrite(9, LOW);
    Serial.print("La muñeca esta bajando\n");
    delay(1000);
  }else if (Estadoflexible >= 210 && Estadoflexible <= 240){
    digitalWrite(9, HIGH); 
    digitalWrite(8, LOW);
    Serial.print("La muñeca esta subiendo\n");
    delay(1000); 
  } else{
    digitalWrite(8, LOW); 
    digitalWrite(9, LOW);
    delay(1000);
  }
   delay (100);
  
   if (Estadoflexible2 >= 190 && Estadoflexible2 <= 220){
    digitalWrite(10, HIGH); 
    digitalWrite(11, LOW);
    Serial.print("Las pinzas se estan abriendo\n");
    delay(1000);
  }else if (Estadoflexible2 >= 221 && Estadoflexible2 <= 260){
    digitalWrite(11, HIGH); 
    digitalWrite(10, LOW);
    Serial.print("Las pinzas se estan cerrando\n");
    delay(1000);
  } else{
    digitalWrite(10, LOW); 
    digitalWrite(11, LOW);
    delay(1000);
  }
  delay (100);
}
