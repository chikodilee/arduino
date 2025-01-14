#include <Servo.h>
Servo myServo;
int servoPosition;
int servoPin = 6;
int photoPin = A3;
int resVolt;
int dt = 500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(servoPin);
pinMode(photoPin, INPUT);
pinMode(servoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
resVolt = analogRead(photoPin);
Serial.print("Read Voltage = ");
Serial.println(resVolt);
servoPosition = (-145./879.) * (resVolt - 925.);
Serial.println(servoPosition); 
myServo.write(servoPosition);
delay(dt);

if(servoPosition > 0 && servoPosition <= 45){
  Serial.println("Summer babes: ");
  Serial.println(servoPosition);
  delay(dt);
 
}

if(servoPosition > 45 && servoPosition <= 85){
  Serial.println("Condusive Weather: ");
  Serial.println(servoPosition);
  delay(dt);
}

if(servoPosition > 85 && servoPosition < 145){
  Serial.print("Very Cold Weather: ");
  delay(dt);
}

}
