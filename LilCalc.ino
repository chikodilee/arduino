#include <LiquidCrystal.h>

int rs  = 7;
int en  = 8;
int d4 = 9;
int d5 = 10;      
int d6 = 11;
int d7 = 12;
int dt = 500;
LiquidCrystal lcd (rs,en,d4,d5,d6,d7);


String firstPrompt = "What is your first number of choice: ";
float firstNum;
String secondPrompt = "What is your second number: ";
float secNum;
String opPrompt = "Choose one of the operators: '+', '-', 'x' or '/' ";
String arithOp;
float result;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Receiing the irst number from the user
Serial.println(firstPrompt);
while (Serial.available()== 0 ){
  
}
firstNum = Serial.parseFloat();


//receiving the secomd number from the user
Serial.println(secondPrompt);
while (Serial.available()== 0 ){
  
}
secNum = Serial.parseFloat();

 delay(dt);
 result = firstNum + secNum;
 Serial.println(result);
 
//requesting the arithmetic operation to be performed on the numbers from the user
/*Serial.println(opPrompt);
while (Serial.available()== 0 ){
  
}
arithOp = Serial.readString();

//checking that the user inputs the right arithmetic operator provided

while(arithOp != "+" || arithOp != "-" || arithOp != "x" || arithOp != "/"){
  Serial.println("Invalid arithmetic operation, Math don't allow that");
  Serial.println(opPrompt);
while (Serial.available()== 0 ){
  
}
arithOp = Serial.readString();
   
}

// carrying out the arithmetic operation
if(arithOp == '+'){
  result = firstNum + secNum;
}

if(arithOp == '-'){
  result = firstNum - secNum;
}

if(arithOp == 'x'){
  result = firstNum * secNum;
}

if(arithOp == '/'){
  if(secNum == 0){
    Serial.println("Math Error");
  }
  result = firstNum / secNum;
}

Serial.println(result);
delay(dt);
*/
}
