int lectura_sensores[8] = {0,0,0,0,0,0,0,0};
int puertos_sensores[8] = {sensor_IR1,sensor_IR2,sensor_IR3,
                           sensor_IR4,sensor_IR5,sensor_IR6,
                           sensor_IR7,sensor_IR8};

void actualizar_lecturas_IR(){

  for(int i=0;i<8;i+=1){
    lectura_sensores[i] = digitalRead(puertos_sensores[i]);
  }  
  return;
}

void imprimir_lecturas_IR(){
  
  actualizar_lecturas_IR();
  
  for (int i=0;i<8;i=i+1){
    if(i==0){
      Serial.print("IR");
    }else{
      Serial.print(" | IR");
    }
    Serial.print(i+1);
    Serial.print(": ");
    if(i==7){
      Serial.println(lectura_sensores[i]);
    }else{
      Serial.print(lectura_sensores[i]);
    }  
        
  }
    
  return;
}

float kp = 20.0, ki = 0.001, kd = 0.0;
float lp = 0.0, li = 0.0, ld = 0.0;
float vel_obj = 20.0; 
float error = 0.0, integral = 0.0, derivada = 0.0, last_error = 0.0;

void pid(){
  //Tomar Lecturas
  
  int suma = 0;
  
  for(int i=0;i<8;i++){
    int coeficiente = i-4;
    if(coeficiente >=0){
      coeficiente++;
    }
    suma  = suma + (lectura_sensores[i] * coeficiente);
  }
  
  
  //Decidir Accion
  error = 0 + suma;
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
    digitalWrite(motor_izqatr_pos,LOW);
    digitalWrite(motor_izqatr_neg,HIGH);
  }else{
    digitalWrite(motor_izqdel_pos,HIGH);
    digitalWrite(motor_izqdel_neg,LOW);
    digitalWrite(motor_izqatr_pos,HIGH);
    digitalWrite(motor_izqatr_neg,LOW);    
  }
  int vel_motor_izq = fabs(vel_izq);
  vel_motor_izq = map(vel_motor_izq,0,100,155,255);
  
  if(vel_der < 0){
    digitalWrite(motor_derdel_pos,LOW);
    digitalWrite(motor_derdel_neg,HIGH);
    digitalWrite(motor_deratr_pos,LOW);
    digitalWrite(motor_deratr_neg,HIGH);
  }else{
    digitalWrite(motor_derdel_pos,HIGH);
    digitalWrite(motor_derdel_neg,LOW);
    digitalWrite(motor_deratr_pos,HIGH);
    digitalWrite(motor_deratr_neg,LOW); 
  }
  int vel_motor_der = fabs(vel_der);
  vel_motor_der = map(vel_motor_der,0,100,155,255);

  analogWrite(motor_izqdel_vel,vel_motor_izq);
  analogWrite(motor_izqatr_vel,vel_motor_izq);
  analogWrite(motor_derdel_vel,vel_motor_der);
  analogWrite(motor_deratr_vel,vel_motor_der);   

  Serial.print("vel_izq =");
  Serial.print(vel_motor_izq);
  Serial.print(" vel_der =");
  Serial.println(vel_motor_der);
  
  return; 
}

void seguidor_linea(){
  actualizar_lecturas_IR();

  // TO-DO: RECUADROS VERDES
  int variables[8] = {0,0,0,0,0,0,0,0};

  for (int i=0; i<8; i= i+1){  
    variables[i] = (lectura_sensores[i]);
  }
  
  
  if  (variables[0] == 0 && variables[1] == 0 && variables[2] == 0 && variables[3] == 0 && variables[4] == 0 && variables[5] == 0 && variables[6] == 0 && variables[7] == 0){
    detener(0);
  }
  if (variables[0] == 0 && variables[1] == 0 && variables[2] == 0 && variables[3] == 0 && variables[4] == 0){
    detener(0);
  }
  if (variables[3] == 0 && variables[4] == 0 && variables[5] == 0 && variables[6] == 0 && variables[7] == 0){
    detener(0);
  }
  if (variables[0] == 0 && variables[1] == 0 && variables[2] == 0 && variables[3] == 0){
    detener(0);
  }
  if (variables[4] == 0 && variables[5] == 0 && variables[6] == 0 && variables[7] == 0){
    detener(0);
  }
  else{ 
   pid();   
  }
  
  return;
}
