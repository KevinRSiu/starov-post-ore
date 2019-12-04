#include "puertos.h"
#include "movimiento.h"
#include "seguidor_linea.h"
#include "obstaculos.h"

void setup() {
  // CONSOLA
  Serial.begin(9600); 
  // MOTORES -> TODO SALIDA
  pinMode(motor_izqdel_pos,OUTPUT);
  pinMode(motor_izqdel_neg,OUTPUT);
  pinMode(motor_izqdel_vel,OUTPUT);
  pinMode(motor_derdel_pos,OUTPUT);
  pinMode(motor_derdel_neg,OUTPUT);
  pinMode(motor_derdel_vel,OUTPUT);
  pinMode(motor_izqatr_pos,OUTPUT);
  pinMode(motor_izqatr_neg,OUTPUT);
  pinMode(motor_izqatr_vel,OUTPUT);
  pinMode(motor_deratr_pos,OUTPUT);
  pinMode(motor_deratr_neg,OUTPUT);
  pinMode(motor_deratr_vel,OUTPUT);
  // SENSORES IR -> TODO ENTRADA
  // IZQ IR1 IR2 IR3 IR4 IR5 IR6 IR7 IR8 DER
  pinMode(sensor_IR1,INPUT);
  pinMode(sensor_IR2,INPUT);
  pinMode(sensor_IR3,INPUT);
  pinMode(sensor_IR4,INPUT);
  pinMode(sensor_IR5,INPUT);
  pinMode(sensor_IR6,INPUT);
  pinMode(sensor_IR7,INPUT); 
  pinMode(sensor_IR8,INPUT);
  // SENSOR ULTRASONIDO FRENTE -> TRIG SALIDA Y ECHO ENTRADA 
  pinMode(sensor_USFrenteTrig, OUTPUT);
  pinMode(sensor_USFrenteEcho, INPUT);
}


void loop() {
  //test_motores();  

 // imprimir_lecturas_IR();
  //delay(1000);

  /*
  if( leerUltrasonidoFrente() <= 10.0 ){ //HAY UN OBSTACULO
    detener(0);    
  }else{ //NO HAY OBSTACULO. PROCEDER CON LINEA
     seguidor_linea();
  } 

  delay(100);
  */
seguidor_linea();
delay(100);
}

