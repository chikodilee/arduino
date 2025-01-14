/*using analog write command to control the brightness of the leds based on the voltage passed to the command
analog write takes in two commands: The pin to write to and the value (from 0 - 255) of the voltage to be passed
Unlike the digital write command, the analog write makes use of numbers not high and low 
0 being 0 volts (the minimum) and 255 being 5 volts (the maximum).
The in between numbers from 0 - 255 represents other voltage values like 2.5V, 3.37V.... 4V and more
*/

int yellowled = 10;
int whiteled = 7;
int blueled = 3;  // initializing pins in use
int greenled = 2;

int first = 225;
int sec = 125;
int third = 75; // Different voltage values to be passed to the different pins
int fourth = 0;


void setup() {
  // put your setup code here, to run once:
  
pinMode(yellowled, OUTPUT);
pinMode(whiteled, OUTPUT);
pinMode(blueled, OUTPUT); //initializing pinModes....
pinMode(greenled, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  
analogWrite(yellowled, first);
analogWrite(whiteled, sec);
analogWrite(blueled, third);  // lighting the LEDs with different voltage brightness........
analogWrite (greenled, fourth);
}
