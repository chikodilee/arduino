/*
 * Servo Motors are good for position control
 * They are low torque and have a restriction on the position range. Usually 0deg - 180deg
 */

#include <Servo.h>    //servo library for the servo motor
Servo myServo;   //servo object
int servoPin = 2;   // arduino pin to control the servo
int servoPos1;  // desired servo position
int servoPos2;  // another desired servo position
int Xpin = A2;  //Analog pin for reading voltage from the x direction on the joy stick's potentiometer
int Ypin = A3;  // Analog pin for reading voltage from the y direction on the joy stick's potentiometer
int Spin = 6;   // Digital pin to read in the up/down switch voltage value (will output 0 or 1) because its a digital read
int Xval;  //variable to store read in X value
int Yval;  //variable to store read in Y value
int Sval;  //variable to store read in switch value
int dt = 500;
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
myServo.attach(servoPin);  //attaches the servo to the arduino pin used for control
pinMode(Spin, INPUT);
pinMode(Xpin, INPUT);
pinMode(Ypin, INPUT);
pinMode(servoPin, OUTPUT);

digitalWrite(Spin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

 //myServo.write(servoPos1);

 
Sval = digitalRead(Spin);
Xval = analogRead(Xpin);
Yval = analogRead(Ypin);

delay(dt);

servoPos1 = (-165./1023.) * Xval + 165;  //always put your floating point value please... if not it'll round to zero or stay at a stagnant value.
myServo.write(servoPos1); //write() command used to send the desired position to the arduino pin to move the servo to that specified position
Serial.print("Coordinates (");
Serial.print(Xval);
Serial.print(" ' ");
Serial.print(Yval);
Serial.print(" ) with position: ");
Serial.print(servoPos1);
Serial.println(" degrees");

delay(dt);
Serial.println();

}
