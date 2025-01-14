
/* Analog Read command uses only analog pins to read from the arduino, i.e. digital and pwm pins cannot be used for the analog read command
 *  The analog read pins have the letter 'A' preceeding them on the board e.g 'A0' 'A1'.....
 *  The analog read command takes only one argument which is the pin on the controller that you're reading from
 *  The output from the command are multiples of 2 that need to be converted after its read
 *  The read output ranges from 0 (minimum) to 1023 (maximum); 0 (0 volts) and 1023 (5 volts)
 *  To get the actual value, the read value is converted by multiplying it by the conversion factor (5/1023)
 */
 
int blueresPin = A3;
int tanresPin = A2;  // initializng analog pins to read from
int ledreadPin = A9;

int readblue;
int readtan; // variables to store the read value from the controller
int readLed;

float Vblue = 0; 
float Vtan = 0; // variable to store the actual converted voltage value
double Vled = 0;
int timee = 500;

void setup() {
  // put your setup code here, to run once:

pinMode(blueresPin, INPUT);
pinMode(tanresPin, INPUT); // initializing the pin modes to read from the controller
pinMode(ledreadPin, INPUT);

/*To enable reading on the serial monitor of the arduino
 * Serial monitor accepts one argument (a number) which is how fast you want to communicate with the arduino (board rate)
 */

Serial.begin(9600); //initializes the serial monitor
}


void loop() {
  // put your main code here, to run repeatedly:
  readblue = analogRead(A3);
  readtan = analogRead(A2); //reading the values from the analog pin and storing them in the variables
  readLed = analogRead(A9);

  Vblue = (5./1023.)*readblue;  // the dot after the (5 and 1023) registers them as floating values in the arduino IDE cos the output voltage is continuous
  Vtan = (5./1023.)*readtan; // converting the read voltage values to actual voltage values
  Vled = (5./1023.)*readLed; 

 // Used to print the values read on the serial monitor
 
 //Serial.println(Vblue);
  delay (timee);
 Serial.println(Vtan, ' ');
  delay (timee);
 // Serial.println(Vled, ' ');
 // delay (timee);
}
