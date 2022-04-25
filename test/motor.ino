/*
int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;
void setup()
{
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT);
}

void loop()
{
  { 
  int value;
  for(value = 0 ; value <= 255; value+=5)
    {
     digitalWrite(M1,HIGH);
     digitalWrite(M2, HIGH);
     analogWrite(E1, value);
     analogWrite(E2, value);
     delay(30);
    }
    delay(1000);
 }
 {
  int value;
  for(value = 0 ; value <= 255; value+=5)
   {
    digitalWrite(M1,LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, value);
    analogWrite(E2, value);
    delay(30);
   }
   delay(1000);
  }
}
*/
#include "Servo.h"

//int MOTOR1_DIRECTION_PIN = 12;
int MOTOR2_DIRECTION_PIN = 13;

//int MOTOR1_SPEED_PIN = 10;
int MOTOR2_SPEED_PIN = 11;

int SERVO_PIN = 10;

Servo _servo;

void setup() {
//  pinMode(MOTOR1_DIRECTION_PIN, OUTPUT);
  pinMode(MOTOR2_DIRECTION_PIN, OUTPUT);
//  pinMode(MOTOR1_SPEED_PIN, OUTPUT);
  pinMode(MOTOR2_SPEED_PIN, OUTPUT);
  
  _servo.attach(SERVO_PIN);
}

void loop() {
  int motorValue = 0;
  
//  digitalWrite(MOTOR1_DIRECTION_PIN,HIGH);
//  analogWrite(MOTOR1_SPEED_PIN,motorValue);
  
  digitalWrite(MOTOR2_DIRECTION_PIN,HIGH);
  analogWrite(MOTOR2_SPEED_PIN,motorValue);

  int servoValue = 0;

  _servo.write(servoValue);  

  delay(2000);

  motorValue = 50000;
  servoValue = 180;
  
//  analogWrite(MOTOR1_SPEED_PIN,motorValue);
//  analogWrite(MOTOR2_SPEED_PIN,motorValue);
  _servo.write(servoValue);  

  delay(10000);

  motorValue = 100000;
  servoValue = 90;

  digitalWrite(MOTOR2_DIRECTION_PIN,LOW);
//  digitalWrite(MOTOR1_DIRECTION_PIN,LOW);
  
//  analogWrite(MOTOR1_SPEED_PIN,motorValue);
  analogWrite(MOTOR2_SPEED_PIN,motorValue);
  _servo.write(servoValue);  

  delay(2000);
  
}
