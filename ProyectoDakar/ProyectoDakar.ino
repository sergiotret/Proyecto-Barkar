#include <Servo.h>
// Declaramos la variable para controlar el servo
Servo servoMotor;
const int sensorMin = 0;
const int sensorMax = 1024;
const int sensormin2 = 0;
const int sensormax2 = 1024;
int sensorpin = A1;
int ledpin = 5;
int ledpin2 = 3;
int sensorValue = 0;
const int ledPIN = 3;
void setup() {
  Serial.begin(9600);    //iniciar puerto serie
  pinMode(ledPIN , OUTPUT);  //definir pin como salida
  
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(9, INPUT);  //definir pin como entrada
  
  servoMotor.attach(10);
  Serial.begin(9600);
  //para el fotoresistor
  pinMode(ledpin, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int sensorReading= analogRead(A0);
  int range=map(sensorReading, sensorMin, sensorMax,0,3);
  //Serial.println(sensorReading);
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

  
//PARA EL FOTORESISTOR, USE LA MISMA SINTAXIS QUE CON EL SENSOR DE LLUVIA
//CODIGO SENCILLO, DEPENDIENDO LA CANTIDAD DE LUZ DETERMINA SI ENCIENDE UN LED, O ENCIENDE AMBOS LEDS
sensorValue = analogRead(sensorpin);
  int range2=map(sensorValue, sensormin2, sensormax2,0,3);
  switch(range2){
 case 0:
    Serial.println("Encender Leds");
    digitalWrite(ledpin,HIGH);
    digitalWrite(ledpin2,HIGH);
    delay(5000);
    break;
 case 1:
    Serial.println("encender led");
      //Desplazamos a la posición 180º
  digitalWrite(ledpin,LOW);
  digitalWrite(ledpin2,HIGH);
  delay(5000);
    break;
 case 2:
    Serial.println("Apagar leds");
    digitalWrite(ledpin,LOW);
    digitalWrite(ledpin2,LOW);
    delay(2000);
    break;
  }
  Serial.println(sensorValue, DEC);
}
