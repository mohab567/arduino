void setup() {                
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);  
  pinMode(6, INPUT); 
  
}
void loop(){
  if(digitalRead(5)==1&&digitalRead(6)==1){
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
  else{
    x=x+1;
    while(digitalRead(5)==0&&digitalRead(6)==0){
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
    if(x==2)
       while()
     
   
