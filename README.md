# Angduino-arduino
This is the Angduino library. This library is in its very primitive stage. It can be used to easily make webpage controller for arduino. Its uses Angularjs for client side and a [nodejs server](https://github.com/K-ran/Angduino-nodejs) running on the pc, connected to the Arduino. The server can run on any machine running nodejs with proper dependencies.

###[Visit here to see how to install an arduino library](https://www.arduino.cc/en/Guide/Libraries)

##Usage
This library has been developed on linux based platform, so it works best on the linux based platforms.
Using this library is really simple specially on the arduino part (also checkout the the example folder)

1. Install the library. 
2. Install the [nodejs server](https://github.com/K-ran/Angduino-nodejs)
3. Include the library ` #include <Angduino.h>`
4. Create an object `Angduino angduino;` 
5. In the setup, set your *key* values `angduino.setKey("led2");`. These are the same values as you assign in you web page. (the example if you dont the this point).
6. Its recommende that you add a small delay after setup.
7. *That's it !!* Now when ever you want to check the value, use `angduino.getValue("led2");`. In case you have define it as a button in you site (which is the only available option write now). The value will toggle between one or zero.

### Serial monitors
Serial monitor can be ported to the webpage as well. To write to serial port use `angduino.serialOut()` function and to read from serial inpu use `angduino.serialIn()` function. 
* _NOTE_ : The serial data is sent in form of compelete string and not byte by byte. 

##Licence
The MIT License (MIT)

#Contributers
[Karan Purohit](https://github.com/K-ran/)

More contributers required. 

