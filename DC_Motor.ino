
int speedPin =7;
int turnI= 5;
int turnII= 3;
int motSpeed = 255;
int dt = 275;
void setup() {
  // put your setup code here, to run once:
  
pinMode(speedPin, OUTPUT);
pinMode(turnI, OUTPUT);
pinMode(turnII, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(turnI, HIGH);
  digitalWrite(turnII, LOW);
  analogWrite(speedPin, motSpeed);
  delay(dt);

  Serial.println(motSpeed);
  delay(dt);

 

}
