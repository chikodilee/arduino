//libraries for the A4988 stepper motor driver
//#include <A4988.H>
#include <BasicStepperDriver.h>
#include <DRV8834.h>
#include <DRV8880.h>
#include <MultiDriver.h>
#include <SyncDriver.h>

//Motor steps per revolution ******IF YOU'RE NOT USING FULL STEPS DO CHANGE THE VARIABLES TO MATCH THE MODE
const int MOTOR_STEPS = 200;       // steps to complete full revolution
const int RPM = 120;              //to set desired speed of the motor 
const int MICROSTEPS = 1;         //For full steps of the motor 

//Pins to control motor speed and direction
const int stepPin = 13;
const int dirPin = 12;

//Stepper motor object
BasicStepperDriver stepper(MOTOR_STEPS, dirPin, stepPin);  

//Pins for garage door functionality
const int contactPin = 3;     // button to detect when door has reached the ground
const int retractPin = 4;     // button to sense once door is fully open/retracted
const int openPin = 5;        // Toggle button to open/close the garage door
const int obsSensePin = 7;    // button that signals when an obstruction has been detected

//Variables for state of the sensors/switches/buttons ..... all are active low
volatile int obsPinState = 1;    //normal state of the obstruction sensor      
volatile int contactState = 1;   //normal state of the contact sensor
volatile int retractState = 1;   //normal state to detect when the door is fully retracted

//button states for the open/close pin
volatile int openPinOld = 1;       
volatile int openPinNew;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Motorpins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  //input pull up pins
  pinMode(contactPin, INPUT_PULLUP);
  pinMode(retractPin, INPUT_PULLUP);
  pinMode(openPin, INPUT_PULLUP);
  pinMode(obsSensePin, INPUT_PULLUP);

  //attaching interrupts to pins
  attachInterrupt(digitalPinToInterrupt(contactPin), contactFloor , FALLING);
  attachInterrupt(digitalPinToInterrupt(retractPin), retractLimit , FALLING);
//attachInterrupt(digitalPinToInterrupt(openPin), openClose, FALLING);  //openClose to be determined
   attachInterrupt(digitalPinToInterrupt(obsSensePin), obstruction, FALLING);

  //Stepper Motor set up
  stepper.begin(RPM, MICROSTEPS); //sets a target speed for the motor **can be changed**
  stepper.enable();

}

void loop() {
  // put your main code here, to run repeatedly:

  //reads all pins 
  contactState = digitalRead(contactPin);
  retractState = digitalRead(retractPin);
  obsPinState = digitalRead(obsSensePin);    // Continually reads the state of the obstruction sensor pin
  openPinNew = digitalRead(openPin);        //checks the current state of the openPin
  
  //checks if the open/close button has been pressed
  if(openPinOld == 0 && openPinNew == 1){
     stepper.move(MOTOR_STEPS * MICROSTEPS);    // motor rotates to open door
  }
  else{
    stepper.move(0*MOTOR_STEPS);    //no door movement
  }
  openPinOld = openPinNew;    //updates the garage door open/close button
}

void obstruction(){
  if(obsPinState == 0){
    do {       // to reverse motor movement
      stepper.move(MOTOR_STEPS * -MICROSTEPS);  
    }
     while(retractState != 0);     //reverse the motor direction until the door is fully retracted
  stepper.move(0);  //stops motor once fully retracted
  }
    Serial.println("Obstruction Detected");
}

void openDoor(){
   stepper.move(MOTOR_STEPS * MICROSTEPS);    //motor motion to lower the garage door
}

void closeDoor(){
   stepper.move(MOTOR_STEPS * -MICROSTEPS);    //reverses motor direction to raises the garage door 
}

void retractLimit(){  //Button gets automatically pressed once door is fully retracted
  if (retractState == 0){   //button state when button is pressed 
    stepper.move(0); //stops the motor
    Serial.println("Door is fully retracted"); 
  }
}

void contactFloor(){
  if(contactState == 0){  //button is pressed
    stepper.move(0);        //stops motor/further door movement
    Serial.println("Door has reached the ground");
  }
}
