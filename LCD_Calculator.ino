
#include <LiquidCrystal.h>

int rs  = 7;
int en  = 8;
int d4 = 9;
int d5 = 10;      
int d6 = 11;
int d7 = 12;
int dt = 1000;
LiquidCrystal lcd (rs,en,d4,d5,d6,d7);

String firstPrompt = "What is your first number of choice: ";
float firstNum;
String secondPrompt = "What is your second number: ";
float secNum;
String opPrompt = "Choose one of the operators: '+', '-', 'x' or '/' ";
String arithOp;
float result = 0;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);
     lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(firstPrompt);
while(Serial.available() == 0){
  
}
firstNum = Serial.parseFloat();

Serial.println(secondPrompt);
while(Serial.available() == 0 ){
  
}
secNum = Serial.parseFloat();

Serial.print("First Number: ");
Serial.print(firstNum);
Serial.print(" and Second Number: ");
Serial.println(secNum);
delay(dt);

Serial.println(opPrompt);
while(Serial.available() == 0){
  
}

arithOp = Serial.readString();

//if(arithOp != "+" || arithOp != "-" || arithOp != "*" || arithOp != "/"){
//  Serial.println("Error, invalid operation");
//  Serial.println(opPrompt);
//while(Serial.available() == 0){
//  
//}
//
//arithOp = Serial.readString();
//}

if (arithOp == "+"){
  result = firstNum + secNum;

}
else if(arithOp == "-"){
  result = firstNum - secNum;
}

else if(arithOp == "*"){
  result = firstNum * secNum;
}

else if(arithOp == "/"){
  result = firstNum / secNum;
}

else{
  Serial.println("Error: invalid operation");
  Serial.println(opPrompt);
while(Serial.available() == 0){
  
}

arithOp = Serial.readString();
}

Serial.print(firstNum);
Serial.print(" ");
Serial.print(arithOp);
Serial.print(" ");
Serial.print(secNum);
Serial.print(" = ");
Serial.println(result);

lcd.setCursor(0,0);
lcd.print(firstNum);
lcd.print(arithOp);
lcd.print(secNum);
lcd.print(" =");
lcd.setCursor(0,1);
lcd.print(result);
delay(dt);
delay(dt);
delay(dt);
lcd.clear();



delay(dt);


}
