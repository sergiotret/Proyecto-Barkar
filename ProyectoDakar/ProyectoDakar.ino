//quite los switch para trabajar con if, ire modificando para optimizarlo, pero ya funciona con este codigo
#include <Servo.h>
int foco=13; //usaremos el led de arduino
Servo servoMotor;
const int sensorMin = 0;
const int sensorMax = 1024;
const int sensormin2 = 0;
const int sensormax2 = 1024;
int sensorpin = A1;
int ledpin2 = 3; 
int sensorValue = 0;
int dato=0;
int dato2=0;
int dato3=0;
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
  {
    Serial.println("Foco encendido");
    digitalWrite(foco,HIGH);
    digitalWrite(ledpin2,HIGH);
    dato3=3;
    }
  if(dato == '2')
    {
      Serial.println("foco apagado");
      digitalWrite(foco,LOW);
      digitalWrite(ledpin2,LOW);
      dato3=4;
     }
if(dato == '3')
    {
      Serial.println("Sistema encendido");
      servoMotor.write(180);
      dato2=3;
     }
     if(dato == '4')
    {
      Serial.println("Sistema Apagado");
      servoMotor.write(0);
      dato2=4;
     }
     if(dato == '5')
    {
      Serial.println("Sistema en modo automatico");
      dato2=0;
      dato3=0;
     }
    int sensorReading= analogRead(A0);
    //el sensor al no detectar agua regresa a su posicion original
    if(sensorReading>=1014 && dato2!=3)
    {
      servoMotor.write(0);
    }
    //si detecta agyua 
    if (sensorReading<=670 && dato2!=4)
    {
      servoMotor.write(180);
    }
    Serial.println(sensorReading);
    delay(5000);
      //PARA EL FOTORESISTOR
      //CODIGO SENCILLO, DEPENDIENDO LA CANTIDAD DE LUZ DETERMINA SI ENCIENDE UN LED, O ENCIENDE AMBOS LEDS
      sensorValue = analogRead(sensorpin);
     // si el sensor no detecta luz, automaticamente se encienden
     if(sensorValue>=1000 && dato3!=4)
    {
      digitalWrite(foco,HIGH);
      digitalWrite(ledpin2,HIGH);
    }
    //si detecta luz, se apaga
    if (sensorValue<=600 && dato3!=3)
    {
      digitalWrite(foco,LOW);
      digitalWrite(ledpin2,LOW);
    }
    Serial.println(dato);
}
