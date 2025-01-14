int greenLed =3;
int yellowLed =7;
int redLed =11;
int voltPin = A2;
int readVolt;
float volt;
int lag = 500;

void setup() {
  
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(greenLed, OUTPUT);
pinMode(yellowLed, OUTPUT);
pinMode(redLed, OUTPUT);
pinMode(voltPin, INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
readVolt = analogRead(voltPin);
volt = readVolt * (5./1023.);
Serial.print("The read voltage equals ");
Serial.println(volt);

if(volt < 3){
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(lag);
}

if(volt>=3 && volt <= 4){
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(greenLed, LOW);
  delay(lag);
}

if( volt > 4){
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  delay(lag);
}


}
