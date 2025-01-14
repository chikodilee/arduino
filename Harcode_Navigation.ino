/*
 * This sketch hardcodes the motion of the robot from the big block to small block to big block...
 */

#include <Servo.h>  // Used to control the gripper

//motor controls
//to control left motor direction and speed
const int IN1 = 6;  
const int IN2 = 7;
const int ENA = 3;
//to control right motor direction and speed
const int IN3 = 4;
const int IN4 = 5;
const int ENB = 2;
int bluePin = 12;
volatile double rpm = 0.0;  // the revolution per minute of the motors when the pin is set to HIGH
volatile double motorSpeed = 20.16129032; // the speed of the motors in centimeters 
volatile double timeElapsed = 0.0;  // stores the time elapsed using the millisecond counter
volatile double distTravel = 0.0; // stores the distance travelled by the robot

int counter = 0.0;  // Used to store how many times the robot makes a 90 degree turn
double temp = 0.0; // Used to store the offsets before switching

Servo myServo;  // object of the servo library to control the gripper
double pos = 0.0; // used to store the position of the gripper

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open the serial monitor at a rate of 9600bit/s
  Serial.println("Code starts");
 

  myServo.attach(9);  // the servo's signal wire (white) is connected to Pin 9 on the arduino
  pos = 0.0;
  myServo.write(pos);
  
  pinMode(ENA,OUTPUT);  // the pin that controls the A channel
  pinMode(ENB,OUTPUT);  // the pin that controls the A channel
  pinMode(IN1,OUTPUT);  // the pin that controls motor 1 is set to output 
  pinMode(IN2,OUTPUT);  // the pin that controls motor 2 is set to output
  pinMode(IN3,OUTPUT);  // the pin that controls motor 3 is set to output
  pinMode(IN4,OUTPUT);  // the pin that controls motor 4 is set to output
}

void loop() {
  // put your main code here, to run repeatedly:
  // Clear the y and x offset from start to first large block (block 1)
  forward(5330);
  stopp();
  turn90Right(697);
  stopp();
  forward(1330);
  stopp();
  turn90Left(697);
  stopp();

  // Clear the y and x offset from the first large block (block 1) to the red drop off
  forward(1490);
  stopp();
  turn90Right(697);
  stopp();
  forward(3090);
  stopp();
  turn90Left(697);
  stopp();

  // Clear the y and x offset from the red drop off to first small block (block 3)
  backward(1490);
  stopp();
  turn90Left(697);
  stopp();
  forward(430);
  stopp();
  turn90Right(697);
  stopp();

  // Clear the y and x offset from the first small block (block 3) to the green drop off
  backward(5330);
  stopp();
  turn90Right(697);
  stopp();
  forward(430);
  stopp();
  turn90Left(697);
  stopp();

  // Clear the y and x offset from the green drop off to second large block (block 2)
  forward(1780);
  stopp();
  turn90Left(697);
  stopp();
  forward(430);
  stopp();
  turn90Right(697);
  stopp();

  // Clear the y and x offset from the second large block (block 2) to the red drop off
  forward(5050);
  stopp();
  turn90Right(697);
  stopp();
  forward(430);
  stopp();
  turn90Left(697);
  stopp();

  // Clear the y and x offset from the red drop off to the second small block (block 4)
  backward(5050);
  stopp();
  turn90Left(697);
  stopp();
  forward(3090);
  stopp();
  turn90Right(697);
  stopp();

  // Clear the y and x offset from the second small block (block 4) to the green dropp off
  backward(1780);
  stopp();
  turn90Right(697);
  stopp();
  forward(3090);
  stopp();
  turn90Left(697);
  stopp();

  // Clear the y and x offset from the green drop off to the origin
  // No y offset as they are on the same x axis
  turn90Left(697);
  stopp();
  forward(4420);
  stopp();
  turn90Right(697);
  stopp();

  // The robot is at the origin so it should stop and not move anymore
  stopp();
  stopp();
  stopp();
  stopp();
  stopp(); 
  stopp();    
  stopp();
  stopp();
  stopp();
  stopp();
  stopp();
  stopp();
  stopp();            
}

void forward(int dt){ 
  analogWrite(ENA,195); //enable L298n A channel
  analogWrite(ENB,200); //enable L298n B channel
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH);  
  digitalWrite(IN3,HIGH); 
  digitalWrite(IN4,LOW); 
  Serial.println("Forward");//send message to serial monitor
  delay(dt);
}

void backward(int dt){
  analogWrite(ENA,195); //enable L298n A channel
  analogWrite(ENB,200); //enable L298n B channel
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("Back");
  delay(dt);
}

void turn90Right(int dt){
  analogWrite(ENA, 195);
  analogWrite(ENB, 200);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(dt); 
 }

 void turn90Left(int dt){
  analogWrite(ENA, 195);
  analogWrite(ENB, 200);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(dt); 
 }

void turn180(int dt){
  analogWrite(ENA, 195);
  analogWrite(ENB, 200);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(dt);
 }

void stopp(){
  analogWrite(ENA,0); //disable L298n A channel
  analogWrite(ENB,0); //disable L298n B channel
  delay(2000);
}
