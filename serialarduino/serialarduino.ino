#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
char c = ' ';
void setup()
{

Serial.begin(9600);

BTserial.begin(115200);

pinMode(13,OUTPUT);
}

void loop()
{
if (1)
{
BTserial.write('a');
Serial.print('a');
delay(1000);
BTserial.write('b');
digitalWrite(13,0);
delay(1000);
}
}
