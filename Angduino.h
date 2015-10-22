// ensure this library description is only included once
#ifndef Test_h
#define Test_h

#include <Arduino.h>

#define KEYS 50
class Angduino{
private:
    String commands[KEYS];
    boolean values[KEYS]={false};
    int i=0;
    boolean notExist(String key);
    //will be called internally to get the command from the nodejs
    void getCommand();
public:
    // Use to set new Key values
    void setKey(String key);
    //Returns the values of the according to give key
    boolean getValue(String key);
    //update all the keys/values pair with the new values
    void update();
};


#endif
