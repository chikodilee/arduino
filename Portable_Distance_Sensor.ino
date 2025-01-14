#include <LiquidCrystal.h> 

int buttonPin = A3;
int buttonVal;

int echoPin = 4;
int trigPin = 7;
int dt = 50;
int pulseDistTime;
float soundSpeed = 0.013515;
float totDist;
float distToTarget;


int rs  = 13;
int en  = 12;
int d4 = 11;
int d5 = 10;      
int d6 = 9;
int d7 = 8;

int dtime = 1000;
// Created LCD object to access the functions on the IDE
LiquidCrystal lcd (rs,en,d4,d5,d6,d7);



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(echoPin, OUTPUT);
  pinMode(trigPin, INPUT);
  pinMode(buttonPin, INPUT);
  lcd.begin(16,2);

digitalWrite(buttonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:


buttonVal = digitalRead(buttonPin);


  digitalWrite(echoPin, LOW);
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(dt);
  digitalWrite(echoPin, LOW);
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(dt);

  pulseDistTime = pulseIn(trigPin, HIGH);
  //Serial.println(pulseDistTime);
  totDist = 0.013515 * pulseDistTime;
  distToTarget = totDist/2.;
//Serial.print("The measured distance to target is: ");
//Serial.print(distToTarget);
//Serial.println(" in.");    
//  delay(dt);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Place the Target ");
lcd.setCursor(0,1);
lcd.print("Press to Measure");
 
while(buttonVal == 1){
  buttonVal = digitalRead(buttonPin);
}

while(buttonVal == 0){
  lcd.clear();
 lcd.setCursor(0,0); 
 lcd.print("Target Dist: ");
 lcd.setCursor(0,1);
 lcd.print(distToTarget);
 lcd.print(" in.");
 delay(dtime);
 

}

delay(dtime);
}
