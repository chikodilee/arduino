String Blink;
int redPin = 11;
int yellowPin = 7;
int greenPin = 3;
String msg = "Which LED do you want to blink red, yellow, or green: ";
String msg2 = " Thank you, now watch the ";
String msg3 = " LED blink";
int dt = 500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin, OUTPUT);
pinMode(yellowPin, OUTPUT);
pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(msg);
while(Serial.available() == 0){
  
}
Blink = Serial.readString();

Serial.print(msg2);
Serial.print(Blink);
Serial.println(msg3);

if ("Blink.toLowerCase()" == "red"){
  digitalWrite(redPin, HIGH);
  delay(dt);
  digitalWrite(redPin, LOW);
  delay(dt);

}
else if ("Blink.toLowerCase()" == "yellow"){
  digitalWrite(yellowPin, HIGH);
  delay(dt);
  digitalWrite(yellowPin, LOW);
  delay(dt);
  }
  else if ("Blink.toLowerCase()" == "green")
  {
    digitalWrite(greenPin, HIGH);
  delay(dt);
  digitalWrite(greenPin, LOW);
  delay(dt);
  }

  else{
    Serial.println("Invalid color choice hunnay, read the instruction... Thank you");
  }

Serial.println();

}
