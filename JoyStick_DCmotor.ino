int xPin = A3;
int yPin = A4;
int swPin = 2;
int xVal;
int yVal;
int swVal;
int dt = 500;
int speedPin = 7;
int dir1 = 5;
int dir2 = 3;
int motSpeed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  digitalWrite(swPin, HIGH);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  xVal= analogRead(xPin);
  yVal= analogRead(yPin);
  swVal = digitalRead(swPin);
  Serial.print("Xvalue = ");
  Serial.print(xVal);
  Serial.print(" and Yvalue = ");
  Serial.print(yVal);
  Serial.print("; Switch value = ");
  Serial.println(swVal);
  delay(dt);


  if(yVal < 443 && yVal >=0){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    motSpeed = (-255./443.)*yVal + 255.;
     analogWrite(speedPin, motSpeed);
    Serial.print("Speed is: ");
      Serial.println(motSpeed);
     
    }
 delay(dt);


 
  if(yVal == 443 || yVal == 444){
    motSpeed = 0;
     analogWrite(speedPin, motSpeed);
  }
delay(dt);


    if(yVal > 443){
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
      motSpeed = (255./443.)*(yVal - 886.) + 255.; 
       analogWrite(speedPin, motSpeed);
      Serial.print("Speed is: ");
      Serial.println(motSpeed);
  }

  delay(dt);

}
