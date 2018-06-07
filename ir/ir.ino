#include <IRremote.h>
IRrecv irrecv(9);
IRsend irsend;
decode_results results;
unsigned long  t;

int th = 20;
int temp = 0;
void setup() {
  t = millis();
  Serial.begin(9600);
  Serial.println("entered the temp number");
  irrecv.enableIRIn();
  pinMode(13, OUTPUT);
}

void loop() {
 if (irrecv.decode(&results)) {
   if(to_num(results)==-1){
    Serial.println("entered if you want to change enter a number again");
    th = temp;
    temp = 0;
    }else if (to_num(results)==-3) {
      Serial.println("_");
      }
    
    
    else if (to_num(results)==-2) {
      Serial.println("error try again");
      }
    else {
      temp = temp * 10 + to_num(results);
      Serial.print(temp);
    }
 irrecv.resume(); 
 // resume receiver
 
 }
if((analogRead(A0) * 0.48828125) > th){
    digitalWrite(13,HIGH);
 } else{
    digitalWrite(13,LOW);
 }
 if (millis()-t>=1000){
  Serial.print("temp in C = ");
  Serial.println(analogRead(A0) * 0.48828125);
  t=millis();
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
   case 0xFFFFFFFF:
    return -3;
    break;
  default: 
    return -2;
  break;
}
}

