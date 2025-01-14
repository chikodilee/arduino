int redBlink;
int yellowBlink;
int greenBlink;
int redPin = 11;
int yellowPin = 7;
int greenPin = 3;
String msg = "The red, yellow, and green led's would blink:";
String msg2 = " respectively.";
int dt = 500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin, OUTPUT);
pinMode(yellowPin, OUTPUT);
pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Please input the blink value for the red Led: ");
while(Serial.available()==0){
  
}
redBlink = Serial.parseInt();
delay(dt);


Serial.println("Please input the blink value for the yellow Led: ");
while(Serial.available()==0){  
  
}
yellowBlink = Serial.parseInt();
delay(dt);


Serial.println("Please input the blink value for the Green Led: ");
while(Serial.available()==0){
  
}
greenBlink = Serial.parseInt();


Serial.print(msg);
Serial.print(" ");
Serial.print(redBlink);
Serial.print(", ");
Serial.print(yellowBlink);
Serial.print(", ");
Serial.print(greenBlink);
Serial.println(msg2);
Serial.println();

for(int i = 0; i<redBlink; i++){
  digitalWrite(redPin, HIGH);
  delay(dt);
  digitalWrite(redPin, LOW);
  delay(dt);
}

for(int i = 0; i<yellowBlink; i++){
  digitalWrite(yellowPin, HIGH);
  delay(dt);
  digitalWrite(yellowPin, LOW);
  delay(dt);
}

for(int i = 0; i<greenBlink; i++){
  digitalWrite(greenPin, HIGH);
  delay(dt);
  digitalWrite(greenPin, LOW);
  delay(dt);
}
}
