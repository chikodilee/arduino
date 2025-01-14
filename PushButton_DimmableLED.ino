int buttonPinI = 12;
int buttonPinII = 3;
int buttonI;
int buttonII;
int dt = 500;
int ledPin = 9;
int brightNess;
int buzzPin = 5;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(buttonPinI, INPUT);
pinMode(buttonPinII, INPUT);
pinMode(ledPin, OUTPUT);
pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

buttonI = digitalRead(buttonPinI);
buttonII = digitalRead(buttonPinII);

Serial.print("button I = ");
Serial.print(buttonI);
Serial.print(" and buttonII = ");
Serial.println(buttonII);
delay(dt);

while (buttonI == 0){
  analogWrite(ledPin, brightNess);
  brightNess = brightNess + 5;
  delay(dt);
  Serial.println(brightNess);
  buttonI = digitalRead(buttonPinI);
  if(brightNess > 255){
    brightNess = 255;
    digitalWrite(buzzPin, HIGH);
    Serial.println("Maximum brightness achieved");
    delay(dt);}
    
    else{
      digitalWrite(buzzPin, LOW);
    }
}


while(buttonII == 0){
  analogWrite(ledPin, brightNess); 
  brightNess = brightNess - 5;
  delay(dt);
  Serial.println(brightNess);
  buttonII = digitalRead(buttonPinII);
  if(brightNess < 0){
    brightNess = 0;
    digitalWrite(buzzPin, HIGH);
    Serial.println("Minimum dimminess achieved");
    delay(dt);
  }
    else{
      digitalWrite(buzzPin, LOW);
  }
}


}
