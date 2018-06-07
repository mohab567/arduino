#include <IRremote.h>
IRrecv irrecv(9);
IRsend irsend;
decode_results results;
int th=20;
int temp=0;
void setup() {
 Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (irrecv.decode(&results)) {
  Serial.println(results.value,HEX);
  irrecv.resume();
  
  
  }
}
