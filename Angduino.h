// ensure this library description is only included once
#ifndef Angduino_h
#define Angduino_h

#include <Arduino.h>

#define KEYS 50
class Angduino{
private:
    String commands[KEYS],serialData="";
    int values[KEYS]={0};
    int count=0;
    int available=0;
    boolean notExist(String key);
    //will be called internally to get the command from the nodejs
    String getCommand();
    void sendData(String data);
    void buttonUpdate(String cmd);
public:
    // Use to set new Key values
    void setKey(String key);
    //Returns the values of the according to give key
    boolean getValue(String key);
    //out puts to serial monitor
    void serialOut(String);
    //serial input data
    String serialIn();
    //update all the keys/values pair with the new values
    void update();
};


#endif
