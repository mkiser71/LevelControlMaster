<<<<<<< HEAD
/*
=======



/*12/23/2014 TESTING GIT COMMIT
>>>>>>> origin/master
This Sketch Written By Mike Hal
Feel Free to distribute and alter this code!

Using Memsic 2125 Accelerometer, Standard Hobby Servos, and Arduino Uno.
Matches tilt from accelerometer to servos. Video at http://www.youtube.com/watch?v=i_1c97m_p0I
*/
TESTING BRANCHES HERE
#include <Servo.h> //Include Servo Library

Servo BowBoard;  //Declares servos
Servo SternBoard;
Servo BowPort;
Servo SternPort;
int BowBoardPin = 10;  //Pin for Servos
int SternBoardPin = 5;
int BowPortPin = 9;
int SternPortPin = 6;
int xPin = 7;  //Pins for Accelerometer
int yPin = 8;
int sensitivity = 5;  //If > 2, will require a larger movement before activating servos
boolean setServo = false;  //Flag for whether to change servo position or not
int temp;  //temporary calculations value
int BowBoardAccel = 90;  //Servo positions
int SternBoardAccel = 180;  
int BowPortAccel = 90;
int SternPortAccel = 180;

void setup()
{   
  Serial.begin(9600);    // initialize serial communications
  BowBoard.attach(BowBoardPin);  //Initializes Servos
  SternBoard.attach(SternBoardPin);//REMOVED 5/9/14-NEED SERIAL FROM MEMSIC, NOT SERVO'S
  BowPort.attach(BowPortPin);
  SternPort.attach( SternPortPin);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop()
{
  //int pulseBowBoard, pulseSternBoard, pulseBowPort, pulseSternPort;  //Resets and declares input variables
  int pulseX, pulseY;	// 5/15/14 Placed back to receive input from Memsic
  setServo = false;  //Resets flags
  digitalWrite(13, LOW);  //Turns Uno LED off
    
  pulseX = (((pulseIn(xPin, HIGH) - 3700) * 18.0) / 250);  //reading from accelerometer and converting value to 0-180
  pulseY = (((pulseIn(yPin, HIGH) - 3698) * 18.0) / 250);
 
  
  temp = (BowPortAccel - pulseX);  //Determines difference between new readings and current position
  temp = abs(temp);
  if (temp > sensitivity)  //Checks difference to sensitivity value set above
  {
    BowPortAccel = pulseX;
    setServo = true;
  }
  if (BowPortAccel > 180)  //Sets max value
  {
    BowPortAccel = 180;
    digitalWrite(13, HIGH);
  }
  if (BowPortAccel < 0)  //Sets min value
  {
    BowPortAccel = 0;
    digitalWrite(13, HIGH);
  }
  
  temp = (BowBoardAccel - pulseY);  //Determines difference between new readings and current position
  temp = abs(temp);
  if (temp > sensitivity)  //Checks difference to sensitivity value set above
  {
    BowBoardAccel = pulseY;
    setServo = true;
  }
  if (BowBoardAccel > 180)  //Sets max value
  {
    BowBoardAccel = 180;
    digitalWrite(13, HIGH);
  }
  if (BowBoardAccel < 0)  //Sets min value
  {
    BowBoardAccel = 0;
    digitalWrite(13, HIGH);
  }
  
  if (setServo)  //Adjusts Servo Positions
  {
    BowBoard.write(BowBoardAccel);
    BowPort.write(BowPortAccel);
    
     // print the acceleration
  Serial.print(pulseX);
  // print a tab character:
  Serial.print("\t");
  Serial.print(pulseY);
  Serial.println();
  }
  
  delay(100);  //Tiny delay to reduce electrical noise.
      
}
