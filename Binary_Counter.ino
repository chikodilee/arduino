// Four LEDs means using four switches


int yellowled = 10;
int whiteled = 7;
int blueled = 3;
int greenled = 2;
int lag =750;
void setup() {
  // put your setup code here, to run once:


pinMode(yellowled, OUTPUT);
pinMode(whiteled, OUTPUT);
pinMode(blueled, OUTPUT); //initializing Pin modes
pinMode(greenled, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//digitalWrite(greenled, HIGH);

//binary number 0 - 0000
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, LOW);
  delay(lag);

  //binary number 1 - 0001
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, HIGH);
  delay(lag);
  
  //binary number 2 - 0010
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, LOW);
  delay(lag);
  
  //binary number 3 - 0011
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, HIGH);
  delay(lag);
  
  //binary number 4 -0100
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, LOW);
  delay(lag);
  
  //binary number 5 - 0101
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, HIGH);
  delay(lag);
  
  //binary number 6 - 0110
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, LOW);
  delay(lag);
  
  //binary number 7 - 0111
  digitalWrite(yellowled, LOW);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, HIGH);
  delay(lag);
  
  //binary number 8 - 1000
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, LOW);
  delay(lag);
  
  //binary number 9 - 1001
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, HIGH);
  delay(lag);
  
  //binary number 10 - 1010
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, LOW);
  delay(lag);
  
  //binary number 11 - 1011
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, LOW);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, HIGH);
  delay(lag);
  
  //binary number 12 - 1100
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, LOW);
  delay(lag);
  
  //binary number 13 - 1101
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, HIGH);
  delay(lag);
  
  //binary number 14 - 1110
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, LOW);
  delay(lag);
  
  
  //binary number 15 - 1111
  digitalWrite(yellowled, HIGH);
  digitalWrite(whiteled, HIGH);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, HIGH);
  delay(lag);

//To indicate counter is done

 delay(lag);
  
  for(int i=0; i<3; i++){
  digitalWrite(yellowled, HIGH);
  delay(500);
  digitalWrite(yellowled ,LOW);
  delay(500);
  digitalWrite(blueled ,HIGH);
  delay(500);
  digitalWrite(blueled, LOW);
  delay(500);

  }
}
