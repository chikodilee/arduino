int readPin = A4;
int buzzPin = 9;
int readVolt;
int dt = 500;
String msg = "The read potentiometer voltage is: ";

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(readPin, INPUT);
pinMode(buzzPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  readVolt = analogRead(readPin);
  Serial.print(msg);
  Serial.println(readVolt);
  delayMicroseconds(dt);


  if(readVolt > 1000){
    digitalWrite(buzzPin, HIGH);
    delayMicroseconds(dt);
    Serial.println("Warning, voltage is high");
    readVolt = analogRead(readPin);
  }

  digitalWrite(buzzPin, LOW);

}
