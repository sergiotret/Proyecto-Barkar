//quite los switch para trabajar con if, ire modificando para optimizarlo, pero ya funciona con este codigo
#include <Servo.h>
int foco=13; //usaremos el led de arduino
Servo servoMotor, servoMotor2;
const int sensorMin = 0;
const int sensorMax = 1024;
const int sensormin2 = 0;
const int sensormax2 = 1024;
int sensorpin = A1;
int ledpin2 = 3; 
int sensorValue = 0;

//dato auxiliar para el bluetooh
char dato = '0';

//datos auxiliares para el servo
int dato1=0;
int dato2=0;

//datos auxiliares para los leds
int dato3=0;
int dato4=0;

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
  //SERVOMOTOR COMEDOR
  servoMotor2.attach(11);
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
    Serial.println("Foco encendido del cuarto");
    digitalWrite(foco,HIGH);
    //digitalWrite(ledpin2,HIGH);
    dato3=3;
    }
  if(dato == '2')
    {
      Serial.println("foco apagado del cuarto");
      digitalWrite(foco,LOW);
      //digitalWrite(ledpin2,LOW);
      dato3=4;
     }
  if(dato == '3')
  {
    Serial.println("Foco encendido del comedor");
    //digitalWrite(foco,HIGH);
    digitalWrite(ledpin2,HIGH);
    dato4=3;
    }
  if(dato == '4')
    {
      Serial.println("foco apagado del comedor");
      //digitalWrite(foco,LOW);
      digitalWrite(ledpin2,LOW);
      dato4=4;
     }
if(dato == '5')
    {
      Serial.println("ventana abierta cuarto");
      servoMotor.write(170);
      dato1=3;
     }
if(dato == '6')
    {
      Serial.println("ventana cerrada cuarto");
      servoMotor.write(80);
      dato1=4;
     }
if(dato == '7')
    {
      Serial.println("ventana abierta comedor");
      servoMotor2.write(0);
      dato2=3;
     }
     if(dato == '8')
    {
      Serial.println("ventana cerrada comedor");
      servoMotor2.write(80);
      dato2=4;
     }
       if(dato == '9')
    {
      Serial.println("modo automatico");
      dato3=0;
      dato4=0;
      dato1=0;
      dato2=0;
     }
     /*if(dato == '14')
    {
      Serial.println("ventanas abiertas");
      servoMotor.write(0);
      servoMotor2.write(0);
      dato2=4;
     }
      if(dato == '10')
    {
      Serial.println("sensor de lluvia activado");
      dato1=0;
      dato2=0;
     }
     if(dato == '11')
     {
      Serial.println("sensor de luz activado");
      dato3=0;
      dato4=0;
     }
     if(dato == '12')
     {
      Serial.println("luces apagadas");
      digitalWrite(foco,LOW);
      digitalWrite(ledpin2,LOW);
     }
     if(dato == '13')
     {
      Serial.println("luces encendidas");
      digitalWrite(foco,HIGH);
      digitalWrite(ledpin2,HIGH);
     }*/
    int sensorReading= analogRead(A0);
    //el sensor al no detectar agua regresa a su posicion original
    if(sensorReading>=1014 && dato1!=3 && dato2!=3)
    {
      servoMotor.write(170);
      servoMotor2.write(80);
    }
    //si detecta agyua 
    if (sensorReading<=670 && dato1!=4 && dato2!=4)
    {
      servoMotor.write(80);
      servoMotor2.write(0);
    }
    Serial.println(sensorReading);
    delay(5000);
      //PARA EL FOTORESISTOR
      //CODIGO SENCILLO, DEPENDIENDO LA CANTIDAD DE LUZ DETERMINA SI ENCIENDE UN LED, O ENCIENDE AMBOS LEDS
      sensorValue = analogRead(sensorpin);
     // si el sensor no detecta luz, automaticamente se encienden
     if(sensorValue>=1000 && dato3!=4 && dato4!=4)
    {
      digitalWrite(foco,HIGH);
      digitalWrite(ledpin2,HIGH);
    }
    //si detecta luz, se apaga
    if (sensorValue<=600 && dato3!=3 && dato4!=4)
    {
      digitalWrite(foco,LOW);
      digitalWrite(ledpin2,LOW);
    }
    Serial.println(dato);
}
