# starov-post-ore
Repostorio de código para el robot de práctica del equipo STAR OV LARVIC, alias "Sandwich de Ventana". 

### Actualizaciones

- 30/Noviembre: Proyecto Base. 
- 07/Diciembre: -/-
- 14/Diciembre: -/-

### Uso
Para este código, se considera un robot que tiene los siguientes componentes: 
- 1 Arduino Mega 2560 R3
- 2 Doble Puente H Driver L298
- 4 Motores DC 
- 8 Sensores Infrarojos TCRT5000
- 2 Sensores de Color TCS3200
- 1 Sensor de Ultrasonido HC-SR04

### Archivos Presentes

- `sandwich`:
  - `sandwich.ino`: Base del Proyecto. Contiene las funciones setup y loop. 
  - `puertos.h`: Archivo que contiene los puertos utilizados para el proyecto. 
  - `movimiento.h`: Archivo con funciones básicas para el movimiento del robot. 
  - `seguidor_linea`: Archivo con las funciones necesarias para que el robot realice el seguidor de linea.
  - `obstaculos.h`: Archivo con las funciones necesarias para que el robot pueda evadir obstaculos. 
- `README.md`: Este archivo de ayuda. 