#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

//Add the necessary libraries
#include <SPI.h>        //SPI library for communicate with the nRF24L01+
      //The main library of the nRF24L01+

//  put pins of button here
int forword=3;
int backword=4;
int left=5;
int right=6;

//----------------------

int data;

//Define object from RF24 library - 9 and 10 are a digital pin numbers to which signals CE and CSN are connected.
RF24 radio(9, 10);

//Create a pipe addresses for the communicate                                    
const byte rxAddr[6] = "00011";

void setup(void){
  Serial.begin(9600);
  pinMode(forword, INPUT_PULLUP);  
  pinMode(backword, INPUT_PULLUP); 
  pinMode(left, INPUT_PULLUP); 
  pinMode(right, INPUT_PULLUP); 
  radio.begin();                 //Start the nRF24 communicate     
  radio.openWritingPipe(rxAddr); 
  radio.stopListening();
}

void loop(void){
    data=0;
    if(digitalRead(forword)==LOW){
     
     data=1;
    } 
    else if(digitalRead(backword)==LOW){
     data=2;
    }
    else if(digitalRead(left)==LOW){
     data=3;
    }
    else if(digitalRead(right)==LOW){
     data=4;
    }
  Serial.println(data);
  radio.write(&data, sizeof(data));
}
