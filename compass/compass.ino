#include <Adafruit_LSM303.h>
#include <Adafruit_LSM303_U.h>

/*           Ardumotive Project Corner
   Arduino digital magnetic Compass with two display modes
   using 3-Axis Digital Compass IC HMC5883L board
   Code,libraries,circuit and more info here: http://bit.ly/1CqSsMF
   Dev. Vasilakis Michalis / Ver. 1.0 / Date:17/3/2015      */

//Include libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//Init Display (SCLK, DIN, D/C, CS, RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 5, 7, 6);
//Init HMC5883L sensor
sensors_event_t event;  
Adafruit_LSM303_Mag_Unified compass = Adafruit_LSM303_Mag_Unified(12345);

//Constants
float heading;
int r = 24; // radius of compass rose
int x0= 60; // x-origin
int y0= 24; // y-origin
int qibla=135;
void setup() {
  Serial.begin(9600);
  compass.begin();
  Wire.begin();
  display.begin();
  display.setContrast(60);
  display.clearDisplay();   // clears the screen and buffer
  display.setTextColor(BLACK);
  display.setCursor(0,2);
  display.print("  Starting  ");
  display.display(); // show splashscreen
  display.clearDisplay();
  delay(2000);
  compass.getEvent(&event);
  heading = atan2(event.magnetic.z,-1* event.magnetic.y);
  display.setCursor(0,2);
  display.print("  compass OK  ");
  display.display(); // show splashscreen
   delay(2000);
}

void loop() {

 

 
  //Reading and calculate degrees:   /////////////////////////////////////
  //Get new sensor value every time that loop starting again
  
  compass.getEvent(&event);
  //Variable heading stores value in radians
   heading = atan2(-1*event.magnetic.z,-1*event.magnetic.y );
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the compassnetic field in your location.
  // Find yours here: http://www.compassnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  float declinationAngle = radians(4.43333333333333);  //<--Change 0.22 with yours. If you can't find your declination juct delete those lines ;)
  heading += declinationAngle;
  // Correct for when signs are reversed.
  if(heading < 0)   heading += 2*PI;
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)heading -= 2*PI;
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  //Convert float to int
  int angle=roundf(headingDegrees);
  //angle=(angle+244)%360;
  //////////////////////////////////////////////////////////////////////////
 
  
  
  
   display.clearDisplay(); // Just in case...
 
  // Calculation of compass needle on lcd pointing to the direction 
  DrawCircle(angle); //call DrawCircle function
  // Display actual heading
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(angle);
  
  display.setTextSize(1);
 
  display.setCursor(x0-2,0);
  display.println("N");
  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor((x0+r)-5,y0-3);
  display.println("E");
  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(x0-2,y0+r-8);
  display.println("S");
  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor((x0-r)+5,y0-3);
  display.println("W");

  
  float x= sin(radians(180+qibla))*r+x0;
  float y= cos(radians(180+qibla))*r+y0;
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(roundf(x-1),roundf(y-1));
  display.println("Q");
  
  // Triangle for direction
  display.drawTriangle(0, 46, 20, 46, 10, 18, BLACK);
  //display.fillTriangle (0, 46, 20, 46, 10, 18, BLACK);
  display.display();
  delay(500); //print new value every 0.5sec
}/// end of program

////////////      Functions    ////////////

////Draw circle and print letters to display - 1st Display Mode
void DrawCircle(int angle) {
        
    float x= sin(radians(180+angle))*r+x0;
    float y= cos(radians(180+angle))*r+y0;
    display.drawLine(x0, y0,  roundf(x),  roundf(y), BLACK);
}

