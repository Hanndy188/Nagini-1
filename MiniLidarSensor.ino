//
//
//  MiniLidarSensor.ino
//
//  Created by Sameed Ahmed on 27/03/2020.
//  Copyright © 2020 Sameed Ahmed. All rights reserved.
//

#include <Servo.h>  //servo library
Servo myservo;

//MiniLidar sensor variables
int Echo = A4;
int Trig = A5;

//motor controller pins
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define SnakeRobotSpeed 150  //  maximum analog value
#define SnakeRobotSpeed2 150  // make the Robot turn faster or slower
int rightDistance = 0, leftDistance = 0;

void forward(){
  analogWrite(ENA, SnakeRobotSpeed);
  analogWrite(ENB, SnakeRobotSpeed);
  digitalWrite(IN1, HIGH);  //left
  digitalWrite(IN2, LOW);   //Right
  digitalWrite(IN3, LOW);    //right
  digitalWrite(IN4, HIGH);   //left
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA, SnakeRobotSpeed);
  analogWrite(ENB, SnakeRobotSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}
void left() {
  analogWrite(ENA, SnakeRobotSpeed2);
  analogWrite(ENB, SnakeRobotSpeed2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Left");
}
void right() {
  analogWrite(ENA, SnakeRobotSpeed2);
  analogWrite(ENB, SnakeRobotSpeed2);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}
void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}



void setup() {
  myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
}

void loop() {
  
    myservo.write(60);  //setservo position to right side
    delay(200);
    rightDistance = Distance_Object();

    myservo.write(120);  //setservo position to left side
    delay(200);
    leftDistance = Distance_Object();

}
