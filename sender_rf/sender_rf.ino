#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

//senderl

#include <SPI.h>     
int data=0;
unsigned long T;
unsigned long debounce =200;
RF24 radio(9, 10);
int button =2 ;                              
const byte rxAddr[6] = "00001";

void setup(void){
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);  
  radio.begin();   
  radio.openWritingPipe(rxAddr); 
  radio.stopListening();
}

void loop(void){
  
 if(digitalRead(button)==LOW&&millis()-T>debounce){
  //Serial.println("here");
  T=millis();
  data=(data+1)%2;
  //Serial.println(data);
  radio.write(&data, sizeof(data));
 }
}
