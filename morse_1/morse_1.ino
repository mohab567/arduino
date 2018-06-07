
int led =13;
int unit=100;
char input[100];
int c=0;
void setup () {
  pinMode (led,OUTPUT);
  Serial.begin(9600);
}

void loop () {
  if (Serial.available()) {
    input[c] = Serial.read();
    Serial.print (input[c]);
    if(input[c]!= '\n'){
    c++;
    }
    else {
    int i=0;
    for(i=0;i<c;i++){
    if (input[i] == 'a' || input[i] == 'A') {lA();}
    if (input[i] == 'b' || input[i] == 'B') {lB();}
    if (input[i] == 'c' || input[i] == 'C') {lC();}
    if (input[i] == 'd' || input[i] == 'D') {lD();}
    if (input[i] == 'e' || input[i] == 'E') {lE();}
    if (input[i] == 'f' || input[i] == 'F') {lF();}
    if (input[i] == 'g' || input[i] == 'G') {lG();}
    if (input[i] == 'h' || input[i] == 'H') {lH();}
    if (input[i] == 'i' || input[i] == 'I') {lI();}
    if (input[i] == 'j' || input[i] == 'J') {lJ();}
    if (input[i] == 'k' || input[i] == 'K') {lK();}
    if (input[i] == 'l' || input[i] == 'L') {lL();}
    if (input[i] == 'm' || input[i] == 'M') {lM();}
    if (input[i] == 'n' || input[i] == 'N') {lN();}
    if (input[i] == 'o' || input[i] == 'O') {lO();}
    if (input[i] == 'p' || input[i] == 'P') {lP();}
    if (input[i] == 'q' || input[i] == 'Q') {lQ();}
    if (input[i] == 'r' || input[i] == 'R') {lR();}
    if (input[i] == 's' || input[i] == 'S') {lS();}
    if (input[i] == 't' || input[i] == 'T') {lT();}
    if (input[i] == 'u' || input[i] == 'U') {lU();}
    if (input[i] == 'v' || input[i] == 'V') {lV();}
    if (input[i] == 'w' || input[i] == 'W') {lW();}
    if (input[i] == 'x' || input[i] == 'X') {lX();}
    if (input[i] == 'y' || input[i] == 'Y') {lY();}
    if (input[i] == 'z' || input[i] == 'Z') {lZ();}
    if (input[i] == '1') {n1();}// the numbers
    if (input[i] == '2') {n2();}
    if (input[i] == '3') {n3();}
    if (input[i] == '4') {n4();}
    if (input[i] == '5') {n5();}
    if (input[i] == '6') {n6();}
    if (input[i] == '7') {n7();}
    if (input[i] == '8') {n8();}
    if (input[i] == '9') {n9();}
    if (input[i] == '0') {n0();}
    if (input[i] == ' ') {space();}
    
    }
    c=0;
    }
    
  }
}
//fonctions for the letters and the numbers
void lA () {dot();dash();shortspace();}//letter A in morse code!
void lB () {dash();dot();dot();dot();shortspace();}//same for B
void lC () {dash();dot();dash();dot();shortspace();}
void lD () {dash();dot();dot();shortspace();}
void lE () {dot();shortspace();}
void lF () {dot();dot();dash();dot();shortspace();}
void lG () {dash();dash();dot();shortspace();}
void lH () {dot();dot();dot();dot();shortspace();}
void lI () {dot();dot();shortspace();}
void lJ () {dot();dash();dash();dash();shortspace();}
void lK () {dash();dot();dash();shortspace();}
void lL () {dot();dash();dot();dot();shortspace();}
void lM () {dash();dash();shortspace();}
void lN () {dash();dot();shortspace();}
void lO () {dash();dash();dash();shortspace();}
void lP () {dot();dash();dash();dot();shortspace();}
void lQ () {dash();dash();dot();dash();shortspace();}
void lR () {dot();dash();dot();shortspace();}
void lS () {dot();dot();dot();shortspace();}
void lT () {dash();shortspace();}
void lU () {dot();dot();dash();shortspace();}
void lV () {dot();dot();dot();dash();shortspace();}
void lW () {dot();dash();dash();shortspace();}
void lX () {dash();dot();dot();dash();shortspace();}
void lY () {dash();dot();dash();dash();shortspace();}
void lZ () {dash();dash();dot();dot();shortspace();}
void n1 () {dot();dash();dash();dash();dash();shortspace();}
void n2 () {dot();dot();dash();dash();dash();shortspace();}
void n3 () {dot();dot();dot();dash();dash();shortspace();}
void n4 () {dot();dot();dot();dot();dash();shortspace();}
void n5 () {dot();dot();dot();dot();dot();shortspace();}
void n6 () {dash();dot();dot();dot();dot();shortspace();}
void n7 () {dash();dash();dot();dot();dot();shortspace();}
void n8 () {dash();dash();dash();dot();dot();shortspace();}
void n9 () {dash();dash();dash();dash();dot();shortspace();}
void n0 () {dash();dash();dash();dash();dash();shortspace();}
void space () {delay (7*unit);}
void dot () {digitalWrite(led,HIGH); delay (unit); digitalWrite(led,LOW); gap();}
void dash () {digitalWrite(led,HIGH); delay (3*unit); digitalWrite(led,LOW); gap();}
void gap() {delay(unit);}
void shortspace () {delay(3*unit);}
