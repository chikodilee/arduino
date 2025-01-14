 int latchPin = 10;
int clockPin = 8;
int dataPin = 9;

byte LEDs = 0xff;



void setup() {
  // put your setup code here, to run once: 

         pinMode(latchPin, OUTPUT);
         pinMode(clockPin, OUTPUT);
         pinMode(dataPin, OUTPUT);
Serial.begin(9600);
} 

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
  digitalWrite(latchPin, HIGH);

}
