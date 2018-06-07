
#include<Wire.h>
#include <Servo.h>

Servo servoh;
Servo servov;
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
float angleh = 90;
float anglev = 90;
float oy_acc;
float ox_acc;
float  gyro_scale=1/131,acc_scale =180/(8000*3.14);
int16_t x_acc_offset=0,y_acc_offset=0,x_gyro_offset=-44,y_gyro_offset=200 ;
unsigned long dtx,dty,oldtx=millis(),oldty=millis();
void setup(){
  servov.attach(9);
  servoh.attach(10);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  AcX-=x_acc_offset;
AcY-=y_acc_offset;
  
float x_acc = (float)((AcX - x_acc_offset)*acc_scale)+90;
float gyrox = (float)(GyX - x_gyro_offset) * gyro_scale;
float y_acc = (float)((AcY - y_acc_offset)*acc_scale)+90;
float gyroy = (float) (GyY - y_gyro_offset) * gyro_scale;
if(1){

dtx=millis()-oldtx;
angleh = (gyrox*dtx/1000+angleh)*0.85+0.15*x_acc;
servoh.write((int)angleh);
oldtx=millis();

}



if(1){

dty=millis()-oldty;
anglev = (gyroy*dty/1000+anglev)*0.85+0.15*y_acc;
servov.write((int)anglev);
oldty=millis();

}









  
  
}
