
int resPin = A4;
int redLed = 11;
int greenLed = 2;
int readVolt;
int dt = 500;
String msg = "The output voltage is: ";


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(resPin, INPUT);
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

readVolt = analogRead(resPin);
Serial.print(msg);
Serial.println(readVolt);
delay(dt);

if (readVolt <= 375){
  Serial.println("The light is off");
  digitalWrite(greenLed, HIGH);
  delay(dt);
  digitalWrite(redLed, LOW);
  readVolt = analogRead(resPin);
}
delay(dt);

if(readVolt > 375 && readVolt < 800){
  Serial.println("Condusive weather");
  readVolt = analogRead(resPin);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  readVolt = analogRead(resPin);
}

delay(dt);

if (readVolt >= 800){
  Serial.println("The light is ON");
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  readVolt = analogRead(resPin);
}
delay(dt);

}
