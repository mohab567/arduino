#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>




#include <SPI.h>      //SPI library for communicate with the nRF24L01


RF24 radio(22,24);
int data;
int led = 2;
const byte rxAddr[6] = "00001";

void setup(){
pinMode(led,OUTPUT);
  Serial.begin(9600);
  radio.begin();                    //Start the nRF24 communicate            
  radio.openReadingPipe(0, rxAddr);   //Sets the address of the transmitter to which the program will receive data.
  radio.startListening();
  }

void loop(){
 // Serial.println("here");
  if (radio.available()){
    // Serial.println("-----------------------------");
    radio.read(&data, sizeof(data)); 
   //Serial.println(data);
    if(data==0||data==1){
       digitalWrite (led, !digitalRead (led));
       //Serial.println("-----------------------------");
}
  }
//Serial.println(data);

}
