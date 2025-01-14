int redLed = 11;
int potPin = A2;
int delaytime = 1000;
int PotValue;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redLed, OUTPUT);
pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
PotValue = analogRead(potPin);
Serial.println(PotValue);
delay(delaytime);

while(PotValue>1000){                       //loop sends a warning by turning on led when the read voltage is greater than 1000
  digitalWrite(redLed, HIGH);               // when read voltage is below the critical voltage value of a 1000, the warning signal is off
  Serial.println(PotValue);
  Serial.println();
  delay(delaytime);
  PotValue = analogRead(potPin);           //This is to continuously read the value of the potentiometer while its in the loop so its not stuck there and updates frequently as it changes
}
digitalWrite(redLed, LOW);   // When the read voltage is below the critical value, it escapes the loop as its false and carries out this command which keeps the warning signal off
}
