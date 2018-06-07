#include <Servo.h>
#include <IRremote.h>
IRrecv irrecv(9);
IRsend irsend;
decode_results results;
Servo myservo;
int temp = 0;
int degree=0;
void setup() {

  Serial.begin(9600);
  Serial.println("entered the degree of rotation");
  irrecv.enableIRIn();
  myservo.attach(10);
  myservo.write(degree);
}

void loop() {
 if (irrecv.decode(&results)) {
   if(to_num(results)==-1){
    Serial.println("entered if you want to change enter a number again");
    degree=temp%180;
    myservo.write(degree);
    temp = 0;
    }else if (to_num(results)==-3) {
      //Serial.println("_");
      }else if (to_num(results)==-4) {
      Serial.println("increased 10 degree");
      degree+=10;
      if(degree>180){
           degree=180;
        }
      myservo.write(degree);
      }else if (to_num(results)==-5) {
        Serial.println("decreased 10 degree");
        degree-=10;
        if(degree<0){
           degree=0;
        }
        myservo.write(degree);
      }
    
    
    else if (to_num(results)==-2) {
     // Serial.println("error try again");
      }
    else {
      temp = temp * 10 + to_num(results);
      Serial.println(temp);
    }
 irrecv.resume(); 
 // resume receiver
 
 }

 
}


int to_num(decode_results results){
  switch (results.value) {
  case 0x20DF08F7:
    return 0;
    break;
  case 0x20DF8877:
    return 1;
    break;
  case 0x20DF48B7:
    return 2;
    break;
  case 0x20DFC837:
    return 3;
    break;
  case 0x20DF28D7:
    return 4;
    break;
  case 0x20DFA857:
    return 5;
    break;
  case 0x20DF6897:
    return 6;
    break;
  case 0x20DFE817:
    return 7;
    break;
   case 0x20DF18E7:
    return 8;
    break;
   case 0x20DF9867:
    return 9;
    break;
   case 0x20DF22DD:
    return -1;
    break;
    case 0x20DF40BF:
    return -4;
    break;
    case 0x20DFC03F:
    return -5;
    break;
   case 0xFFFFFFFF:
    return -3;
    break;
  default: 
    return -2;
  break;
}
}

