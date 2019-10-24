//quite los switch para trabajar con if, ire modificando para optimizarlo, pero ya funciona con este codigo
#include <Servo.h>
int foco=13; //usaremos el led de arduino
Servo servoMotor;
const int sensorMin = 0;
const int sensorMax = 1024;
const int sensormin2 = 0;
const int sensormax2 = 1024;
int sensorpin = A1;
int ledpin = 5;
int ledpin2 = 3; 
int sensorValue = 0;
int dato=0;
void setup() {
  Serial.begin(9600);
  pinMode(foco,OUTPUT); //->salida del foco
  //----------------------------------------------------------------
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(9, INPUT);  //definir pin como entrada
  //SERVOMOTOR------------------------------------------------------
  servoMotor.attach(10);
  Serial.begin(9600);
  //leds del FOTORESISTOR--------------------------------------------
  pinMode(ledpin, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = 0;
  if(Serial.available()>0){
  dato=Serial.read(); //lo que se lea del bluetooth, es decir lo mandará la app
  }
  if(dato == '1')
  {digitalWrite(foco,HIGH);
  Serial.println("Foco encendido");
    }
  if(dato == '2')
    {
      digitalWrite(foco,LOW);
      Serial.println("foco apagado");
     }
if(dato == '3')
    {
      digitalWrite(foco,LOW);
      Serial.println("foco ENCENDIDO");
      servoMotor.write(90);
     }
    int sensorReading= analogRead(A0);
    //el sensor al no detectar agua regresa a su posicion original
    if(sensorReading>=1014)
    {
      servoMotor.write(90);
    }
    //si detecta agyua 
    if (sensorReading<=670)
    {
      servoMotor.write(180);
    }
    delay(5000);
      //PARA EL FOTORESISTOR
      //CODIGO SENCILLO, DEPENDIENDO LA CANTIDAD DE LUZ DETERMINA SI ENCIENDE UN LED, O ENCIENDE AMBOS LEDS
      sensorValue = analogRead(sensorpin);
     // si el sensor no detecta luz, automaticamente se encienden
     if(sensorValue>=1000)
    {
      digitalWrite(ledpin,HIGH);
      digitalWrite(ledpin2,HIGH);
    }
    //si detecta luz, se enciende
    if (sensorValue<=600)
    {
      digitalWrite(ledpin,LOW);
      digitalWrite(ledpin2,LOW);
    }
}
