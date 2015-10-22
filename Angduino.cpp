
// include this library's description file
#include "Angduino.h"

boolean Angduino::notExist(String key){
  for(int k=0;k<i;k++){
    if(commands[k]==key){
      return false;
    }
  }
  return true;
}

//will be called internally to get the command from the nodejs
void Angduino::getCommand(){
  String a="";
  int flag =0;
  while( Serial.available()>0){
    flag =1;
    char inp =Serial.read();
    if(inp=='\n'){
      break;
    }
    a+=char(inp);
    delay(1);
  }
  if(flag){
     for(int k=0;k<i;k++){
       if(a==commands[k]){
         values[k]=!(values[k]);
       }
     }
  }
}

void Angduino::setKey(String key){
  if(notExist(key)){
    commands[i++]=key;
  }
}

//Returns the values of the according to give key
boolean Angduino::getValue(String key){
 for(int k=0;k<i;k++){
     if(commands[k]==key){
       return values[k];
     }
 }
 return false;
}

void Angduino::update(){
  getCommand();
}

