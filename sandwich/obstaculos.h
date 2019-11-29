#include "puertos.h"

float leerUltrasonidoFrente(){
  float resultado = 0.0;
  long tiempo = 0; //tiempo que demora la senal en regresal al sensor

  //MANDAR LA SENAL ULTRASONICA
  digitalWrite(sensor_USFrenteTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor_USFrenteTrig,LOW);

  //RECIBIR SENAL
  tiempo = pulseIn(sensor_USFrenteEcho,HIGH);

  //CONVERTIR DE TIEMPO A DISTANCIA
  resultado = tiempo/59.0;

  return resultado;  
}

void evasion_obstaculos(){
  return;  
}
