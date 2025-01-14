String Blink;
int redPin = 12;
int greenPin = 10;
int bluePin = 6;
String msg = "What color do you want the RGB huh..  ";
String msg2 = " Thank you, for your unique choice";
String msg3 = " LED blink";
int dt = 500;


void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(msg);

  while(Serial.available() == 0 ){ 
  }
  
Blink = Serial.readString();


if(Blink == "red"){
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

delay(dt);


if(Blink == "green"){
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
}
delay(dt);



if(Blink == "blue"){
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);
}
delay(dt);


if(Blink == "cyan"){
  analogWrite(greenPin, 250);
  analogWrite(bluePin, 155);
  analogWrite(redPin, 0);
  
}

if(Blink == "magenta"){
  analogWrite(redPin, 128);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 127);
}



if(Blink == "yellow"){
  analogWrite(redPin, 255);
  analogWrite(greenPin, 145);
  digitalWrite(bluePin, LOW);
}
delay(dt);


if(Blink == "off"){
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}


if(Blink == "orange"){
  analogWrite(redPin, 230);
  analogWrite(greenPin, 35);
  digitalWrite(bluePin, LOW);
}
delay(dt);


if(Blink == "fuschia"){
  analogWrite(redPin, 250);
  analogWrite(greenPin, 10);
  analogWrite(bluePin, 225);
}
delay(dt);
}
