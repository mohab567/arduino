#include <SPI.h>
String s;

void setup() {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
SPI.begin();
}

void loop() {
 if(Serial.available()>0){
    s=Serial.readString();
    digitalWrite(10, LOW);
  //  send in the address and value via SPI:
  for(int i=0;i<s.length();i++){
  SPI.transfer(s.charAt(i));
  }
  // take the SS pin high to de-select the chip:
  digitalWrite(10, HIGH);
    }else{
     for(int i=0;i<s.length();i++){
  Serial.print(SPI.transfer(0));
  }
      }

}
