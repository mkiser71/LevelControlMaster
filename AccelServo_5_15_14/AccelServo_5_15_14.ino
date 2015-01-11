<<<<<<< HEAD
/*
=======
/*
>>>>>>> origin/master
This Sketch Written By Mike Hal
Feel Free to distribute and alter this code!

Using Memsic 2125 Accelerometer, Standard Hobby Servos, and Arduino Uno.
Matches tilt from accelerometer to servos. Video at http://www.youtube.com/watch?v=i_1c97m_p0I
*/
//!!!CHANGE MOTOR NAMES TO DIRECTIONS!!! Done - 01-11-2015
#include <Servo.h> //Include Servo Library

Servo NorthEast;  //Declares servos
Servo SouthEast;
Servo NorthWest;
Servo SouthWest;
int NorthEastPin = 10;  //Pin for Servos
int SouthEastPin = 5;
int NorthWestPin = 9;
int SouthWestPin = 6;
int xPin = 7;  //Pins for Accelerometer
int yPin = 8;
int sensitivity = 5;  //If > 2, will require a larger movement before activating servos
boolean setServo = false;  //Flag for whether to change servo position or not
int temp;  //temporary calculations value
int NorthEastAccel = 90;  //Servo positions
int SouthEastAccel = 180;  
int NorthWestAccel = 90;
int SouthWestAccel = 180;

void setup()
{   
  Serial.begin(9600);    // initialize serial communications
  NorthEast.attach(NorthEastPin);  //Initializes Servos
  SouthEast.attach(SouthEastPin);//REMOVED 5/9/14-NEED SERIAL FROM MEMSIC, NOT SERVO'S
  NorthWest.attach(NorthWestPin);
  SouthWest.attach( SouthWestPin);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop()
{
  //int pulseNorthEast, pulseSouthEast, pulseNorthWest, pulseSouthWest;  //Resets and declares input variables
  int pulseX, pulseY;	// 5/15/14 Placed back to receive input from Memsic
  setServo = false;  //Resets flags
  digitalWrite(13, LOW);  //Turns Uno LED off
    
  pulseX = (((pulseIn(xPin, HIGH) - 3700) * 18.0) / 250);  //reading from accelerometer and converting value to 0-180
  pulseY = (((pulseIn(yPin, HIGH) - 3698) * 18.0) / 250);
 
  
  temp = (NorthWestAccel - pulseX);  //Determines difference between new readings and current position
  temp = abs(temp);
  if (temp > sensitivity)  //Checks difference to sensitivity value set above
  {
    NorthWestAccel = pulseX;
    setServo = true;
  }
  if (NorthWestAccel > 180)  //Sets max value
  {
    NorthWestAccel = 180;
    digitalWrite(13, HIGH);
  }
  if (NorthWestAccel < 0)  //Sets min value
  {
    NorthWestAccel = 0;
    digitalWrite(13, HIGH);
  }
  
  temp = (NorthEastAccel - pulseY);  //Determines difference between new readings and current position
  temp = abs(temp);
  if (temp > sensitivity)  //Checks difference to sensitivity value set above
  {
    NorthEastAccel = pulseY;
    setServo = true;
  }
  if (NorthEastAccel > 180)  //Sets max value
  {
    NorthEastAccel = 180;
    digitalWrite(13, HIGH);
  }
  if (NorthEastAccel < 0)  //Sets min value
  {
    NorthEastAccel = 0;
    digitalWrite(13, HIGH);
  }
  
  if (setServo)  //Adjusts Servo Positions
  {
    NorthEast.write(NorthEastAccel);
    NorthWest.write(NorthWestAccel);
    
     // print the acceleration
  Serial.print(pulseX);
  // print a tab character:
  Serial.print("\t");
  Serial.print(pulseY);
  Serial.println();
  }
  
  delay(100);  //Tiny delay to reduce electrical noise.
      
}
