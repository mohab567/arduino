float sensorValue=0; 
int sensorPin=A0;
unsigned long  t; 
void setup() {
  t = millis();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue =analogRead(sensorPin)*5.00/1023.00;
  if (millis()-t>=1000){
  Serial.println(sensorValue);
  t=millis();
  }
  if(sensorValue>3.00){
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    }
  else if(sensorValue<2.50){
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    }

}
