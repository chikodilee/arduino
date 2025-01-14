int BluePin = 3;
int GreenPin = 7;
int RedPin = 10;           //pin initializations
int bLink = 500;
void setup() {
  // put your setup code here, to run once:
pinMode(BluePin,OUTPUT);
pinMode(GreenPin, OUTPUT);  //initializing pinModes
pinMode(RedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  for(int i=0; i<5; i++){  //loop for redled to blink five times
digitalWrite(RedPin, HIGH);
delay(bLink);
digitalWrite(RedPin, LOW);
delay (bLink);
  }
for(int j=0; j<10; j++){   //loop for greenled to blink ten times
digitalWrite(GreenPin, HIGH);
delay(bLink);
digitalWrite(GreenPin, LOW);
delay (bLink);
}
for(int k=0; k<15; k++){    //loop for blueled to blink 15 times
digitalWrite(BluePin, HIGH);
delay(bLink);
digitalWrite (BluePin, LOW);
delay(bLink);
}
}
