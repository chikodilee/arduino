int pushPin = 9;
int redPin = 3;
int buttonVal;
int dt = 500;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pushPin, INPUT);
  pinMode(redPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(pushPin);
  Serial.print("Voltage is: ");
  Serial.println(buttonVal);

 if(buttonVal == 1){
  digitalWrite(redPin, LOW);
 }
delay(dt);
 if(buttonVal == 0){
  digitalWrite(redPin, HIGH);
 }
}
