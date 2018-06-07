void setup() {                
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT);   
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);   
  pinMode(4, OUTPUT);
  
}
void loop (){
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  delay(5000);
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  delay(1000);
  digitalWrite(2,HIGH);
  delay(5000);
  digitalWrite(2,LOW);
  delay(1000);
  digitalWrite(1,HIGH);
  delay(5000);
  digitalWrite(1,LOW);
  delay(1000);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  delay(5000);}
  
  
