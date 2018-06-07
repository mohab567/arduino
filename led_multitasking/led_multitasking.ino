int b1=5;
int b2=6;
int led1=2;
int led2=3;
unsigned long delay1=1000;
unsigned long delay2=1000;
unsigned long buttonDebounce=50;
unsigned long T1=0;
unsigned long T2=0;
unsigned long Tb1=0;
unsigned long Tb2=0;
void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if(digitalRead(b1)==LOW&&millis()-Tb1>buttonDebounce){
    Tb1=millis();
    delay1-=100;;
  }
  if(digitalRead(b2)==LOW&&millis()-Tb2>buttonDebounce){
    Tb2=millis();
    delay2-=100;
  }
  if(millis()-T1>delay1){
    T1=millis();
    digitalWrite (led1, !digitalRead (led1));
  }
  if(millis()-T2>delay2){
    T2=millis();
    digitalWrite (led2, !digitalRead (led2));
  }

}
