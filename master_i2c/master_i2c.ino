//master
#include <Wire.h>
String s;
void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}


void loop() {
  if(Serial.available()){
  s=Serial.readString();
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(s.c_str());
  Wire.endTransmission();    // stop transmitting

  }
}
