#include <LiquidCrystal.h>

int sensorPin=A5;
float temp;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
  lcd.begin(16,2);
 // Serial.begin(9600);
  lcd.setCursor(0,0); 
  pinMode(13, OUTPUT);
}

void loop() {
  delay(1000);
  temp=analogRead(sensorPin)*0.48828125;
 
  if(temp>30){
    lcd.setCursor(0,1);
    lcd.print("Warning temp>30");
    digitalWrite(13,HIGH);
    }else{
      lcd.clear();
      digitalWrite(13,LOW);
      }
  lcd.setCursor(0,0);  
  //Serial.println(temp); 
  lcd.print(temp);

}
