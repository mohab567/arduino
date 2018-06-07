#include <SoftwareSerial.h>
SoftwareSerial BTserial(13, 15); // RX | TX
char c = ' ';
void setup()
{

Serial.begin(9600);
BTserial.begin(115200);

pinMode(LED_BUILTIN,OUTPUT);
}
void loop()
{
if (Serial.available())
{ digitalWrite(LED_BUILTIN,HIGH);
c=Serial.read();
Serial.print(c);
}
}
