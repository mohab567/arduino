int led=9;
void setup() {                
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT); 
  pinMode(7,OUTPUT); 
  pinMode(8,OUTPUT); 
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  }
 
void loop() {
  if (digitalRead(9)==HIGH){ 
    digitalWrite(1,HIGH);
    delay(1000);  // wait for a second
    digitalWrite(1, LOW);
    digitalWrite(2,HIGH);  // turn the LED off by making the voltage LOW
    delay(1000);  
    digitalWrite(2, LOW);
    digitalWrite(3,HIGH); 
    delay(1000); 
    digitalWrite(3, LOW);
    digitalWrite(4,HIGH); 
    delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(5,HIGH); 
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(6,HIGH); 
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(7,HIGH); 
    delay(1000);
    digitalWrite(7, LOW);
    digitalWrite(8,HIGH); 
    delay(1000);
    digitalWrite(8, LOW);
    digitalWrite(7,HIGH); 
    delay(1000);
    digitalWrite(7, LOW);
    digitalWrite(6,HIGH); 
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(5,HIGH); 
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(4,HIGH); 
    delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(3,HIGH); 
    delay(1000);
    digitalWrite(3, LOW);
    digitalWrite(2,HIGH); 
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(1,HIGH); 
    delay(1000);// wait for a second
 }
   if(digitalRead(10)==HIGH){
    digitalWrite(1, HIGH); 
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000);
    digitalWrite(1, LOW);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(1, HIGH);
    digitalWrite(4, LOW);
    delay(1000); // wait for a second
}
  if(digitalRead(11)==HIGH){
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(1000);
  }
   if(digitalRead(12)==HIGH){
     digitalWrite(1, HIGH); 
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000);
    digitalWrite(1, LOW);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
    delay(1000); 
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(1, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(8,LOW);
   }
    }

