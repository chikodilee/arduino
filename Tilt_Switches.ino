/*
 * Tilt Switches are used mostly for orientation
 * It contains a ball in its circuitry
 * When upright, the switch is closed and when tilted or oriented otherwise, the switch is open
 * Cons: Vibrations should be taken into consideration because ball wont be stable and will have unpredictable motion
 */

int tiltPin =7;
int tiltVal;
int dt = 500;
int greenLed = 3;
int redLed = 11;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(tiltPin, INPUT);
digitalWrite(tiltPin, HIGH);
pinMode(greenLed, OUTPUT);
pinMode(redLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  tiltVal = digitalRead(tiltPin);
 // Serial.println(tiltVal);
  delay(dt);

  if(tiltVal == 0){
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    delay (dt);
  }

else{
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  delay(dt);
}
}
