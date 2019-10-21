#include <Servo.h>
// Declaramos la variable para controlar el servo
Servo servoMotor;
const int sensorMin = 0;
const int sensorMax = 1024;
int sensorpin = A1;
int ledpin = 5;
int ledpin2 = 3;
int sensorValue = 0;
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(9, INPUT);  //definir pin como entrada
  servoMotor.attach(10);
  Serial.begin(9600);
  //para el fotoresistor
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
  int sensorReading= analogRead(A0);
  int range=map(sensorReading, sensorMin, sensorMax,0,3);
  switch(range){
 case 0:
    Serial.println("lloviendo");
    servoMotor.write(180);
    delay(5000);
    break;
 case 1:
    Serial.println("alerta de lluvia");
      //Desplazamos a la posición 180º
  servoMotor.write(180);
  delay(5000);
    break;
 case 2:
    Serial.println("sin lluvia");
    delay(2000);
    break;
  }
  delay(1000);
  Serial.println(sensorReading);
  if(sensorReading>=1014)
  {
    servoMotor.write(90);
  }
  //para el fotoresistor;
  sensorValue = analogRead(sensorpin);
  digitalWrite(ledpin, HIGH);
  delay(sensorValue);
  digitalWrite(ledpin,LOW);
  delay(sensorValue);
  Serial.println(sensorValue, DEC);
  /*int value = 0;
  value = digitalRead(9 );  //lectura digital de pin
 
    /*Serial.println("Detectada lluvia");
     // Desplazamos a la posición 0º
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
   Para el sentido positivo
/*  for (int i = 0; i=180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(1000);
  }
  }*/
}
/*void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 8
  servoMotor.attach(10);
}
 
void loop() {
  
  // Desplazamos a la posición 0º
  servoMotor.write(0);
  // Esperamos 1 segundo
  delay(1000);
  
  // Desplazamos a la posición 90º
  servoMotor.write(90);
  // Esperamos 1 segundo
  delay(1000);
  
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  // Esperamos 1 segundo
  delay(1000);
}
*/
