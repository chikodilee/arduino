/* button transitions when its pressed and released, i.e. when it changes from 0 to 1
 *  Therefore have to keep track of the previous and current state of te button for the switching action
 *  The led state is also monitored so when the switching of the button is done, the current state of the led is updated accordingly
 *  The present states of the button and led respectively are:
 *  button = 1 (not pressed)  & led = 0 (starts off)
 */

int ledPin = 7;
int buttonPin = 9;
int buttonNew;
int delayTime = 500;
int ledState =0;
int buttonOld =1;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

buttonNew = digitalRead(buttonPin);      // can be either 1 (not pressed) or 0 (pressed)
Serial.print("ButtonVolt is: ");
Serial.println(buttonNew);

if (buttonOld == 0 && buttonNew == 1){
  if(ledState == 0){
     digitalWrite(ledPin, HIGH);
       ledState = 1;
  
  }

   else{
       digitalWrite(ledPin, LOW);
        ledState = 0;
      }

}
 buttonOld = buttonNew;
 delay (delayTime);
}
