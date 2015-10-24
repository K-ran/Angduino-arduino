/*
    This is an simple example showing how to use the Angduino Library.
*/

#include<Angduino.h>  //including the library

Angduino angduino;
void setup()
{

  Serial.begin(9600);                  //You set this up your sell
  //Important: DO NOT USE the Serial function from this point onwards.
  //instead use the angduino.serialOut and angduino.serialIn.
  //Angduino take the control if Serial channels for communication.

  //NOTE: Always call setKey in the setup. Should be called only once.
  angduino.setKey("led2");            //Setting the key.Default allowed keys: 50
  delay(1000);                        //Its recommended that you set this delay for proper start up
  angduino.serialOut("This String is Straight from the arduino");     // outputs to serial monitor at the webpage
  pinMode(13, OUTPUT);           // set pin to input
}

void loop ()
{
  angduino.update();   //necessary, otherwise changes wont be Updated.
  if(angduino.getValue("led2")==1){    //get the value from the key.
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  };

  String inp=angduino.serialIn();  //reading serial data( from website's serial input)
  if(inp=="hi"){
    angduino.serialOut("hello");   // sending data to website's serial out
  }
}
