#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
LiquidCrystal_PCF8574 lcd(0x27);
const int MPU_addr = 0x68;
int16_t AcX,AcY,AcZ;
int counter;
int16_t all_axis[3][100];
int16_t axis_select;
int16_t minX, maxX, minY, maxY, minZ, maxZ;
int steps;
float dist,vel,cal;
bool flag;
unsigned long Time;
int avx;
float hight = 1.8;
int step2;
int stepold;
float stride;

void setup() {
 Wire.begin();
 Wire.beginTransmission(0x27);
  //error = Wire.endTransmission();
 lcd.begin(16, 2);
 lcd.setBacklight(255); 
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)

  Wire.endTransmission(true);
  Serial.begin(9600);
   axis_select = 0;
  flag = false;
  Time = millis();
  minX = 32000; maxX = -32000; minY = 32000; maxY =  -32000;
  minZ = 32000; maxZ = -32000;
  
}
 
 
void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  all_axis[0][counter%100]=AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)  
  //Serial.println(AcX);  
  all_axis[1][counter%100]=AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  all_axis[2][counter%100]=AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  counter++;
  //Serial.println(counter);
  if(counter%30==0){
    
    //lcd.home();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("step=");
    lcd.print(steps);
    lcd.setCursor(8, 0);
    lcd.print("dist=");
    lcd.print(dist);
    lcd.setCursor(0, 1);
    lcd.print("vel=");
    lcd.print(vel);
    lcd.setCursor(8, 1);
    lcd.print("cal=");
    lcd.print(cal);
    
  }
  if(counter%200==0){
    step2=steps-stepold;
    stepold=steps;
    if(step2<7)
      stride=hight/(7-step2);
    else
      stride=hight*1.2;
    dist+=stride*step2;
    vel=(step2*stride)/2;
    
    if(step2==0)
      cal+=(75/1800);
    else
     cal+=(vel*75)/400;
    }
  if(AcY > maxY)
    maxY = AcY;
  else if(AcY < minY)
    minY = AcY;
 
   if(AcZ > maxZ)
    maxZ = AcZ;
  else if(AcZ < minZ)
    minZ = AcZ;
 

/*  if(1){
    if(maxX - minX > maxY - minY && maxX - minX > maxZ - minZ){
      axis_select = 0;
      avx=(maxX + minX)/2;}
    else if(maxY - minY > maxX - minX && maxY - minY > maxZ - minZ){
      axis_select = 1;
      avx=(maxY+minY)/2;}
    else if(maxZ - minZ > maxY - minY && maxZ - minZ > maxX - minX){
      axis_select = 2;
      avx=(maxZ+minZ)/2;}
  }
*/
//Serial.println(axis_select);
//Serial.println("avx");
//Serial.println(avx);
  if(counter >16){
    int average1 = 0, average2 = 0;
    int m=0;
    for(int i =(counter-16+100)%100;m<15  ; i=(i+1+100)%100){
      average1 += all_axis[axis_select][i];
      average2 += all_axis[axis_select][(i-1+100)%100];
      m++;
    }
     if(average1 > maxX)
    maxX = average1;
  else if(average1 < minX)
    minX = average1;
    // Serial.println(average1/15);
    avx=(maxX+minX)/2;
    int diff = average2 - average1;
    if(diff < 0 && !flag && millis() - Time > 200&&average2/15>avx+50){
      steps++;
      Serial.println("steps---------------------------------");
     Serial.println(steps);
      flag = true;  
      Time = millis();
    } else if(diff > 0&& average2/15<avx-50){
      flag = false;
    }
  }
 
  //Serial.print16_t(AcX);
  //Serial.print16_t(',');
  //Serial.print16_t(AcY);
  //Serial.print16_t(',');
  //Serial.print16_tln(AcZ);
 
  delay(10);
}
