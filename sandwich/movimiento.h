#include "puertos.h"

void avanzar(int velocidad,int tiempo){
  digitalWrite(motor_izqdel_pos,HIGH);
  digitalWrite(motor_izqdel_neg,LOW);
  analogWrite(motor_izqdel_vel,velocidad);
  
  digitalWrite(motor_derdel_pos,HIGH);
  digitalWrite(motor_derdel_neg,LOW);
  analogWrite(motor_derdel_vel,velocidad);

  
  digitalWrite(motor_izqatr_pos,HIGH);
  digitalWrite(motor_izqatr_neg,LOW);
  analogWrite(motor_izqatr_vel,velocidad);
  
  digitalWrite(motor_deratr_pos,HIGH);
  digitalWrite(motor_deratr_neg,LOW);
  analogWrite(motor_deratr_vel,velocidad);
  
  delay(tiempo);

  return;
}

void retroceder(int velocidad,int tiempo){
  digitalWrite(motor_izqdel_pos,LOW);
  digitalWrite(motor_izqdel_neg,HIGH);
  analogWrite(motor_izqdel_vel,velocidad);
  
  digitalWrite(motor_derdel_pos,LOW);
  digitalWrite(motor_derdel_neg,HIGH);
  analogWrite(motor_derdel_vel,velocidad);

  
  digitalWrite(motor_izqatr_pos,LOW);
  digitalWrite(motor_izqatr_neg,HIGH);
  analogWrite(motor_izqatr_vel,velocidad);
  
  digitalWrite(motor_deratr_pos,LOW);
  digitalWrite(motor_deratr_neg,HIGH);
  analogWrite(motor_deratr_vel,velocidad);
  
  delay(tiempo);
  return;
}

void giro_izq(int velocidad,int tiempo){
  digitalWrite(motor_izqdel_pos,LOW);
  digitalWrite(motor_izqdel_neg,HIGH);
  analogWrite(motor_izqdel_vel,velocidad);
  
  digitalWrite(motor_derdel_pos,HIGH);
  digitalWrite(motor_derdel_neg,LOW);
  analogWrite(motor_derdel_vel,velocidad);

  
  digitalWrite(motor_izqatr_pos,HIGH);
  digitalWrite(motor_izqatr_neg,LOW);
  analogWrite(motor_izqatr_vel,velocidad);
  
  digitalWrite(motor_deratr_pos,LOW);
  digitalWrite(motor_deratr_neg,HIGH);
  analogWrite(motor_deratr_vel,velocidad);
  
  delay(tiempo);

  return;
}

void giro_der(int velocidad,int tiempo){
  digitalWrite(motor_izqdel_pos,HIGH);
  digitalWrite(motor_izqdel_neg,LOW);
  analogWrite(motor_izqdel_vel,velocidad);
  
  digitalWrite(motor_derdel_pos,LOW);
  digitalWrite(motor_derdel_neg,HIGH);
  analogWrite(motor_derdel_vel,velocidad);

  
  digitalWrite(motor_izqatr_pos,LOW);
  digitalWrite(motor_izqatr_neg,HIGH);
  analogWrite(motor_izqatr_vel,velocidad);
  
  digitalWrite(motor_deratr_pos,HIGH);
  digitalWrite(motor_deratr_neg,LOW);
  analogWrite(motor_deratr_vel,velocidad);
  
  delay(tiempo);
  return;
}

void detener(int tiempo){
  digitalWrite(motor_izqdel_pos,LOW);
  digitalWrite(motor_izqdel_neg,LOW);
  analogWrite(motor_izqdel_vel,0);
  
  digitalWrite(motor_derdel_pos,LOW);
  digitalWrite(motor_derdel_neg,LOW);
  analogWrite(motor_derdel_vel,0);

  
  digitalWrite(motor_izqatr_pos,LOW);
  digitalWrite(motor_izqatr_neg,LOW);
  analogWrite(motor_izqatr_vel,0);
  
  digitalWrite(motor_deratr_pos,LOW);
  digitalWrite(motor_deratr_neg,LOW);
  analogWrite(motor_deratr_vel,0);
 
  delay(tiempo);

  return;
}



void test_motores(){
  avanzar(255,1000);
  giro_izq(255,1000);
  giro_der(255,1000);
  retroceder(255,1000);  
  detener(1000);
  return;
}
