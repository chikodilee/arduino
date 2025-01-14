#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRRemoteControl.h>
#include <IRRemoteControlInt.h>


#include <IRremote.h>
int IRpin = 5;             //Infrared control pin on the microcontroller
IRrecv IR(IRpin);          // Created infrared receiver object IR that takes in the control pin as an argument
decode_results cmd;       // decode results is a library command that is used to create an object to receive the signal/information from the infrared sensor when transmitted

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  IR.enableIRIn();      //Beginning the Infrared Sensor Module

}

void loop() {
  // put your main code here, to run repeatedly:

  
  while(IR.decode(&cmd) == 0){      //using the ampersand signifies whatever data is stored in the address of CMD
                                    // The IR.decode command is a fucntion that accepts an address as its argument. Its a pass by address function
    
  }

  Serial.println(cmd.value, HEX);    //printing out the sent info/data/value stored in the CMD address

  delay(500);
  IR.resume();

}
