#include "Angduino.h"

boolean Angduino::notExist(String key){
  for(int k=0;k<count;k++){
    if(commands[k]==key){
      return false;
    }
  }
  return true;
}

//will be called internally to get the command from the nodejs
String Angduino::getCommand(){
  String a="";
  int flag =0;
  delay(10);
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
      return a;
     }
}

void Angduino::sendData(String data){
    Serial.println(data);
}

void Angduino::setKey(String key){
  if(notExist(key)){
    commands[count++]=key;
  }
}

//Returns the values of the according to give key
boolean Angduino::getValue(String key){
 for(int k=0;k<count;k++){
     if(commands[k]==key){
       return values[k];
     }
 }
 return false;
}

void Angduino::buttonUpdate(String cmd){
   for(int k=0;k<count;k++){
     if(cmd==commands[k]){
       values[k]=!(values[k]);
       sendData("{\"button\":\"scope." +cmd+"="+String(values[k])+"\"}");
     }
   }
}

void Angduino::update(){
      serialData="";
      String cmd=getCommand();
      if(cmd=="") return;
      else if(cmd=="button")
        buttonUpdate(getCommand());
      else if(cmd=="serial"){
        available=1;
        serialData=getCommand();
      }
}

void Angduino::serialOut(String inp){
     sendData("{\"serial\":\""+inp+"\"}");
}

String Angduino::serialIn(){
  String temp="";
  if(available==1){
    temp=serialData;
    serialData="";
    available=0;
 }
  return temp;
}
