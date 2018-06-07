#include <AFMotor.h>

#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

//Add the necessary libraries
#include <SPI.h>      //SPI library for communicate with the nRF24L01+
   //The main library of the nRF24L01+

//Define packet for the direction (X axis and Y axis)
int data;

// motors
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor3(3, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor4(4, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

//Define object from RF24 library - 22 and 24 are a digital pin numbers to which signals CE and CSN are connected
RF24 radio(22,24);

//Create a pipe addresses for the communicate
const byte rxAddr[6] = "00011";

void setup(){

  Serial.begin(9600);
  radio.begin();                    //Start the nRF24 communicate            
  radio.openReadingPipe(0, rxAddr);   //Sets the address of the transmitter to which the program will receive data.
  radio.startListening();   
  motor1.setSpeed(255);   
  motor2.setSpeed(255);          
  motor3.setSpeed(255);          
  motor4.setSpeed(255);          

  }

void loop(){
  if (radio.available()){
    radio.read(&data, sizeof(data));
    Serial.println(data);
    if(data ==1){
      //forward            
      Serial.println("Forward");
      motor1.run(FORWARD);
      motor2.run(RELEASE);
      motor3.run(FORWARD);
      motor4.run(RELEASE);

    }
    
     if(data==2){
      //backward         
      Serial.println("Backward");     
      motor1.run(RELEASE);
      motor2.run(BACKWARD);
      motor3.run(RELEASE);
      motor4.run(BACKWARD);
    }
     
     if(data==3){
      //left
      Serial.println("Left");
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }

     if(data==4){
      //right
      Serial.println("Right");
      motor1.run(BACKWARD);
      motor2.run(RELEASE);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    }

    if(data==0){
      //stop car
      Serial.println("stop");
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);


    }
  }
}
