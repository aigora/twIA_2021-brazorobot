//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
const int mpuAddress = 0x68;  // Puede ser 0x68 o 0x69
MPU6050 mpu(mpuAddress);
int ax, ay, az;
int gx, gy, gz;
long tiempo_prev, dt;
float girosc_ang_x, girosc_ang_y,girosc_ang_z;
float girosc_ang_x_prev, girosc_ang_y_prev, girosc_ang_z_prev;
const int MotorApin4 = 2;
const int MotorApin3 = 3;
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
void setup()
{
   Serial.begin(9600);
   Wire.begin();
   mpu.initialize();
   Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, INPUT);
   pinMode(13, INPUT);
}
void loop()
{
   // Leer las velocidades angulares 
   mpu.getRotation(&gx, &gy, &gz);
   updateGiro();
   // Mostrar resultados
   /*Serial.print(F("\tRotacion en y: "));
   Serial.println(girosc_ang_y);
   Serial.print(F("\tRotacion en x: "));
   Serial.println(girosc_ang_x);*/
   Serial.print(F("\tRotacion en z: "));
   Serial.println(girosc_ang_z);
   
   if(girosc_ang_y>35){
   digitalWrite(3, HIGH); 
   digitalWrite(2, LOW);
    }
    else if(girosc_ang_y<-35){
    digitalWrite(3, LOW); 
    digitalWrite(2, HIGH);
    }
     else{
    digitalWrite(3, LOW); 
    digitalWrite(2, LOW);
    }
    if(girosc_ang_x>35){
   digitalWrite(4, HIGH); 
   digitalWrite(5, LOW);
    }
    else if(girosc_ang_x<-35){
    digitalWrite(4, LOW); 
    digitalWrite(5, HIGH);
    }
     else{
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW);
    } 
    if(digitalRead(12)==HIGH){
    digitalWrite(10, HIGH); 
    digitalWrite(11, LOW);
      }else{
      digitalWrite(10, LOW); 
      digitalWrite(11, LOW);
        }
    if(digitalRead(13)==HIGH){
    digitalWrite(10,LOW); 
    digitalWrite(11,HIGH);
    }else{
      digitalWrite(10, LOW); 
      digitalWrite(11, LOW);
    } 
    /*Serial.print(girosc_ang_x);
   Serial.print(F("\tRotacion en Y: "));
   Serial.println(girosc_ang_y);
   Serial.print(F("\tRotacion en z: "));
   Serial.println(girosc_ang_z);*/
   delay(100);
}
