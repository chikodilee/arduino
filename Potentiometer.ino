int meterPin = A2;
int ReadV;
float volt;
int lag = 500;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ReadV = analogRead(meterPin);
volt = (5./1023.)*ReadV;
Serial.print("The voltage across the center pin = ");
Serial.println(volt);
delay(lag);
}
