#include<Angduino.h>

Angduino angduino;
void setup()
{

  Serial.begin(9600);
  Serial.println("Hello Terminal");
  //NOTE: Always call setKey in the setup. Should be called only once.
  angduino.setKey("led1");
    delay(1000);
  pinMode(13, OUTPUT);           // set pin to input
}

void loop ()
{
  angduino.update();
  delay(100);
  if(angduino.getValue("led1")==1)
    digitalWrite(13,HIGH);
  else
    digitalWrite(13,LOW);
}
