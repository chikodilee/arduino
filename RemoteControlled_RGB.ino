#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRRemoteControl.h>
#include <IRRemoteControlInt.h>
#include <LiquidCrystal.h>

int rs = 12;
int d4 = 11;
int d5 = 10;
int d6 = 9;
int d7 = 8;
int en = 13;
LiquidCrystal lcd(rs, en, d4,d5,d6,d7);

#include <IRremote.h>
int IRpin = 5;             //Infrared control pin on the microcontroller
IRrecv IR(IRpin);          // Created infrared receiver object IR that takes in the control pin as an argument
decode_results cmd;       // decode results is a library command that is used to create an object to receive the signal/information from the infrared sensor when transmitted

byte receiver;
String transmits;

int redPin = 4;
int greenPin =3;
int bluePin = 2;
int dtime = 500;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  IR.enableIRIn();      //Beginning the Infrared Sensor Module
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  lcd.begin(16,2);

}


void loop() {
  // put your main code here, to run repeatedly:

  
  while(IR.decode(&cmd) == 0){      //using the ampersand signifies whatever data is stored in the address of CMD
                                    // The IR.decode command is a fucntion that accepts an address as its argument. Its a pass by address function
    
  }

  Serial.println(cmd.value, HEX);    //printing out the sent info/data/value stored in the CMD address

  delay(500);
  IR.resume();


if(cmd.value == 0xFFA25D){
  transmits = "White Light ON. ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  delay(dtime);
  delay(dtime);
}

  lcd.clear();
  
if(cmd.value == 0xFFE21D){
  transmits = "Lights Off         ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(dtime);
  delay(dtime); 
}

 lcd.clear();
 
if(cmd.value == 0xFF22DD){
  transmits = "Red Light ON         ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits); 
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(dtime);
  delay(dtime);
}

 lcd.clear();
 
if(cmd.value == 0xFF02FD){
  transmits = "Green Light ON         ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits); 
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin, LOW);
  delay(dtime);
  delay(dtime);
}

 lcd.clear();
 
if(cmd.value == 0xFFC23D){
  transmits = "Blue Light ON          ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits); 
  digitalWrite(bluePin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(dtime);
  delay(dtime);
}

 lcd.clear();

if(cmd.value == 0xFFE01F){
  transmits = "Mustard Light ON         ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits);
    analogWrite(redPin, 255);
  analogWrite(greenPin, 165);
  analogWrite(bluePin, 0); 
  delay(dtime);
  delay(dtime);
}

 lcd.clear();
 
if(cmd.value == 0xFFA857){
  transmits = "Yellow Light ON          ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits);
   analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  digitalWrite(bluePin, LOW); 
  delay(dtime);
  delay(dtime);
}

if(cmd.value == 0xFF906F){
  transmits = "Lime Green Light ON        ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits); 
   analogWrite(redPin, 124);
  analogWrite(greenPin, 252);
  analogWrite(bluePin, 0);
  delay(dtime);
  delay(dtime);
}

 lcd.clear();
 
if(cmd.value == 0xFF6897){
  transmits = "Black Light ON              ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits); 
   analogWrite(redPin, 192);
  analogWrite(greenPin, 192);
  analogWrite(bluePin, 192);
  delay(dtime);
  delay(dtime);
}
 lcd.clear();

 
if(cmd.value == 0xFF9867){
  transmits = "Corn flower blue Light ON       ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits);
   analogWrite(redPin, 100);
  analogWrite(greenPin, 149);
  analogWrite(bluePin, 237); 
  delay(dtime);
  delay(dtime);
}

 lcd.clear();

if(cmd.value == 0xFFB04F){
  transmits = "Royal blue Light ON          ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits);
   analogWrite(redPin, 65);
  analogWrite(greenPin, 105);
  digitalWrite(bluePin, HIGH);
  delay(dtime);
  delay(dtime); 
}

 lcd.clear();
 
if(cmd.value == 0xFF30CF){
  transmits = "Indigo Light ON              ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits); 
   analogWrite(redPin, 75);
  analogWrite(bluePin, 130);
  digitalWrite(greenPin, LOW);
  delay(dtime);
  delay(dtime);
}

 lcd.clear();

if(cmd.value == 0xFF18E7){
  transmits = "Purple Light ON              ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits);
   analogWrite(redPin, 128);
  analogWrite(bluePin, 168);
  digitalWrite(greenPin, LOW);
  delay(dtime);
  delay(dtime); 
}

 lcd.clear();


if(cmd.value == 0xFF7A85){
  transmits = "Magenta Light ON             ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits); 
  analogWrite(redPin, 158);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 127);
  delay(dtime);
  delay(dtime);
}

 lcd.clear();
 
if(cmd.value == 0xFF38C7){
  transmits = "Fade Colors                ";
  lcd.setCursor(0,0);
  lcd.println(transmits);
  Serial.println(transmits);
  digitalWrite(redPin, HIGH);
  delay(dtime);
  digitalWrite(redPin, LOW);
  delay(dtime);
  digitalWrite(greenPin, HIGH);
  delay(dtime);
  digitalWrite(greenPin, LOW);
  delay(dtime);
  digitalWrite(bluePin, HIGH);
  delay(dtime);
  digitalWrite(bluePin,LOW);
  delay(dtime);

   analogWrite(redPin, 158);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 127);

 delay(dtime);
 digitalWrite(redPin,LOW);
 digitalWrite(bluePin,LOW);
 digitalWrite(greenPin,LOW);
 delay(dtime);
  delay(dtime);
 

}



 lcd.clear();
























  

}
