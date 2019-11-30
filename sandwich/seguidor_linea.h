#include "puertos.h"

int lectura_sensor_IR1 = 0;
int lectura_sensor_IR2 = 0;
int lectura_sensor_IR3 = 0;
int lectura_sensor_IR4 = 0;
int lectura_sensor_IR5 = 0;
int lectura_sensor_IR6 = 0;
int lectura_sensor_IR7 = 0;
int lectura_sensor_IR8 = 0;

void actualizar_lecturas_IR(){
  lectura_sensor_IR1 = digitalRead(sensor_IR1);
  lectura_sensor_IR2 = digitalRead(sensor_IR2);
  lectura_sensor_IR3 = digitalRead(sensor_IR3);
  lectura_sensor_IR4 = digitalRead(sensor_IR4);
  lectura_sensor_IR5 = digitalRead(sensor_IR5);
  lectura_sensor_IR6 = digitalRead(sensor_IR6);
  lectura_sensor_IR7 = digitalRead(sensor_IR7);
  lectura_sensor_IR8 = digitalRead(sensor_IR8);
  return;
}

void imprimir_lecturas_IR(){
  actualizar_lecturas_IR();
  Serial.print("IR1: ");
  Serial.print(lectura_sensor_IR1);
  Serial.print(" | IR2: "); 
  Serial.print(lectura_sensor_IR2);
  Serial.print(" | IR3: "); 
  Serial.print(lectura_sensor_IR3);
  Serial.print(" | IR4: "); 
  Serial.print(lectura_sensor_IR4);
  Serial.print(" | IR5: "); 
  Serial.print(lectura_sensor_IR5);
  Serial.print(" | IR6: "); 
  Serial.print(lectura_sensor_IR6);
  Serial.print(" | IR7: "); 
  Serial.print(lectura_sensor_IR7);
  Serial.print(" | IR8: "); 
  Serial.println(lectura_sensor_IR8);

  return;
}

float kp = 1.0, ki = 0.0, kd = 0.0;
float lp = 0.0, li = 0.0, ld = 0.0;
float vel_obj = 25.0; 
float error = 0.0, integral = 0.0, derivada = 0.0, last_error = 0.0;

void pid(){
  //Tomar Lecturas
  int l_1  = lectura_sensor_IR1 * -4;
  int l_2  = lectura_sensor_IR2 * -3;
  int l_3  = lectura_sensor_IR3 * -2;
  int l_4  = lectura_sensor_IR4 * -1;
  int l_5  = lectura_sensor_IR5 * 1;
  int l_6  = lectura_sensor_IR6 * 2;
  int l_7  = lectura_sensor_IR7 * 3;
  int l_8  = lectura_sensor_IR8 * 4;
  int suma = l_1+l_2+l_3+l_4+l_5+l_6+l_7+l_8; 

  //Decidir Accion
  error = 0 - suma;
  integral = integral + error;
  derivada = error-last_error; 
  float vel_lin = vel_obj - (lp*error + li*integral + ld*derivada);
  float vel_ang = kp*error + ki*integral + kd*derivada;

  float vel_izq = vel_lin - vel_ang;
  float vel_der = vel_lin + vel_ang; 

  if(vel_izq > 100.0){
    vel_izq = 100.0;  
  }
  else if(vel_izq < -100.0){
    vel_izq = -100.0; 
  }

  if(vel_der > 100.0){
    vel_der = 100.0;  
  }
  else if(vel_der < -100.0){
    vel_der = -100.0; 
  }

  //Ejecutar Accion
  if(vel_izq < 0){
    digitalWrite(motor_izqdel_pos,LOW);
    digitalWrite(motor_izqdel_neg,HIGH);
    digitalWrite(motor_izqatr_pos,HIGH);
    digitalWrite(motor_izqatr_neg,LOW);
  }else{
    digitalWrite(motor_izqdel_pos,HIGH);
    digitalWrite(motor_izqdel_neg,LOW);
    digitalWrite(motor_izqatr_pos,LOW);
    digitalWrite(motor_izqatr_neg,HIGH);    
  }
  int vel_motor_izq = fabs(vel_izq);
  vel_motor_izq = map(vel_motor_izq,0,100,155,255);
  
  if(vel_der < 0){
    digitalWrite(motor_derdel_pos,LOW);
    digitalWrite(motor_derdel_neg,HIGH);
    digitalWrite(motor_deratr_pos,HIGH);
    digitalWrite(motor_deratr_neg,LOW);
  }else{
    digitalWrite(motor_derdel_pos,HIGH);
    digitalWrite(motor_derdel_neg,LOW);
    digitalWrite(motor_deratr_pos,LOW);
    digitalWrite(motor_deratr_neg,HIGH); 
  }
  int vel_motor_der = fabs(vel_der);
  vel_motor_der = map(vel_motor_der,0,100,155,255);

  analogWrite(motor_izqdel_vel,vel_motor_izq);
  analogWrite(motor_izqatr_vel,vel_motor_izq);
  analogWrite(motor_derdel_vel,vel_motor_der);
  analogWrite(motor_deratr_vel,vel_motor_der);   
  return; 
}

void seguidor_linea(){
  actualizar_lecturas_IR();

  // TO-DO: RECUADROS VERDES
  pid(); 
}
