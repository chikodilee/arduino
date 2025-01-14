#include <LiquidCrystal.h>  //lcd library used to access the predeined lcd functions on the IDE

/*
 * //parameter pins for the pin connection of the LCD hardware/shield to the arduino
 * They are passed as arguments to the created LCD object for the serial information transmission
 */
int rs  = 7;
int en  = 8;
int d4 = 9;
int d5 = 10;      
int d6 = 11;
int d7 = 12;


int dt = 1000;

// Created LCD object to access the functions on the IDE
LiquidCrystal lcd (rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

   /*
    * Used to signal the lcd to start up and receive data
    * LCD can only print or show data when it has begun
    * The arguments 16 and 2 represents the Number of columns and rows respectively of the LCD display
    * For different LCDs this parameters may differ
    */
   lcd.begin (16,2);

}

void loop() {
  // put your main code here, to run repeatedly:


lcd.setCursor(0,0); //used to initiate the start of a string on the LCD at the origin (first column and first row of the grid)
lcd.print("Hello World");   //used to print out data onto the LCD display screen
lcd.setCursor(0,1);
lcd.print("Chikodili's LIT");
//delay(dt);
//lcd.clear(); //used to clear the screen for a new message
//delay(dt);
}
