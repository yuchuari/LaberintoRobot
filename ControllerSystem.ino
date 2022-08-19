/**
 ECUAPLUS S.A. @Copy&Write
 Date: 18/08/2022
 Last Editión: 18/08/2022
 Autor: Yandri J. Uchuari -@yuchuari

 Este código permite el desarrollo y conrol de un robot bidireccional de los ruedas, que funciona
 con un ayuda de 3 sensores infrarojos en alguno de 35 grados.
 
**/
//Sensores Infrarojos
const int sensorPin1 = 6; //Izquierda
const int sensorPin2 = 5; //Frente
const int sensorPin3 = 4; //Derecha

//Variables Motores
/*
const int motorA1 = 8;
const int motorA2 = 9;
const int motorB1 = 10;
const int motorB2 = 11;
*/
const int MotorDE = 9;
const int MotorIZ = 10;
const int MotorDE_r = 8;
const int MotorIZ_r = 11;

//Estado de Sensores
int eS1F = 1;
int eS2D = 1;
int eS3I = 1;

//Velocidad de Motores
const int velNormalDe = 80;
const int velNormalIz = 77;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);   //iniciar puerto serie
  
  pinMode(sensorPin1 , INPUT);  //definir pin como entrada
  pinMode(sensorPin2 , INPUT);  //definir pin como entrada
  pinMode(sensorPin3 , INPUT);  //definir pin como entrada
  
  /*
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  */

   pinMode(MotorDE, OUTPUT);
   pinMode(MotorIZ, OUTPUT);
   pinMode(MotorDE_r, OUTPUT);
   pinMode(MotorIZ_r, OUTPUT);
   

}

void loop() {
  // put your main code here, to run repeatedly:

  eS1F = digitalRead(sensorPin2);
  eS2D = digitalRead(sensorPin3);
  eS3I = digitalRead(sensorPin1);

  

  //Giro Adelante
  if(eS1F == HIGH && eS2D == LOW && eS3I == LOW)
  {
    analogWrite(MotorDE, velNormalDe);
    analogWrite(MotorIZ, velNormalIz);
  }
  
  //Giro Derecha
  if(eS1F == LOW && eS2D == LOW && eS3I == HIGH)
  {
    analogWrite(MotorDE, 150);
    analogWrite(MotorDE_r, 0);
    analogWrite(MotorIZ_r, 0);
    analogWrite(MotorIZ, 0);
  }

  //Giro Izquierda
  if(eS1F == LOW && eS2D == HIGH && eS3I == LOW)
  {
    analogWrite(MotorDE, 0);
    analogWrite(MotorIZ, 150);
    analogWrite(MotorDE_r, 0);
    analogWrite(MotorIZ_r, 0);
  }

  //Sin Obstaculo
  if(eS1F == LOW && eS2D == HIGH && eS3I == HIGH)
  {
    analogWrite(MotorDE, 150);
    analogWrite(MotorIZ, 0);
    analogWrite(MotorDE_r, 0);
    analogWrite(MotorIZ_r, 0);
  }

  //Obstaculo Derecha
  if(eS1F == HIGH && eS2D == LOW && eS3I == HIGH)
  {
    analogWrite(MotorDE, 150);
    analogWrite(MotorIZ, 0);
    analogWrite(MotorDE_r, 0);
    analogWrite(MotorIZ_r, 0);
  }

  //Obstaculo Izquierda
  if(eS1F == HIGH && eS2D == HIGH && eS3I == LOW)
  {
    analogWrite(MotorDE, 0);
    analogWrite(MotorIZ, 150);
    analogWrite(MotorDE_r, 0);
    analogWrite(MotorIZ_r, 0);
  }

  //NADA
  if(eS1F == HIGH && eS2D == HIGH && eS3I == HIGH)
  {
    analogWrite(MotorDE, velNormalDe);
    analogWrite(MotorIZ, velNormalIz);
    analogWrite(MotorDE_r, 0);
    analogWrite(MotorIZ_r, 0);
  }

  //Sin Salida
  if(eS1F == LOW && eS2D == LOW && eS3I == LOW)
  {
    analogWrite(MotorDE_r, 200);
    analogWrite(MotorIZ, 200);
    analogWrite(MotorDE, 0);
    analogWrite(MotorIZ_r, 0);
  }

}
