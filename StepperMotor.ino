/*
 * Stepper motors cannot be powered by the arduino and needs an external power supply or power supply module
 * Each stepper motor has its own driver that is used to connect the stepper motor to the arduion or microcontroller
 * Every steppermotor is different and its parameters differ from one motor to another
 * Different motors have different step size and steps per revolution
 */

#include <Stepper.h>  //include stepper motor library to use motor
int stepsPerRev = 2048; //the steps per revolution of the 
int motSpeed = 3;  //revs per min
int dt = 500;

Stepper myStepper(stepsPerRev, 2,3,4,5);
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);  //sets the speed of the stepper motor

}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(stepsPerRev); //tells the stepperMotor the number of steps to move
  delay(dt);
  myStepper.step(-stepsPerRev);
  delay(dt);

}
