
#include <Servo.h>

int servoPin =9;
int servoPos = 10;

//creating serve object
Servo gripServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gripServo.attach(servoPin);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  gripServo.write(servoPin);

}
