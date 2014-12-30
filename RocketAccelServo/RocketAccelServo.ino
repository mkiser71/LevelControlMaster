 /*

This scketch is based upon the Memsic 2125 accelerometer read code from http://www.arduino.cc/en/Tutorial/Memsic2125

and the  RCServoMotorsControlledWithAccelMeter2

   based on the ITP's sample code

   http://itp.nyu.edu/physcomp/Labs/Servo

These sketches have been modified and reworked by Chris Barta.

therocketgeek.wordpress.com

 

  This example code is in the public domain.

*/

#include <Servo.h>

 

Servo myservo;

 

const int xPin = 3;           // X output of the accelerometer

const int yPin = 2;           // Y output of the accelerometer

 

long lastPulse = 0;    // Time in milliseconds of the last pulse

int refreshTime = 10;  // Time needed in between pulses

 

int minSensorValue[xPin] = {-180, -180}; // the least value the accelerometer can read

int maxSensorValue[yPin] = {180, 180}; // the greatest value the accelerometer can read

int pulseWidth[xPin][yPin] = { 0, 0 };  // Pulse width for the servo motors

 

int sensorRange[xPin][yPin] = { maxSensorValue[0] - minSensorValue[0],

                               maxSensorValue[1] - minSensorValue[1] };

int i = 0;

 

int phase = 0;    // variable to select the servo motor to drive

 

void setup()

{

  myservo.attach(10, 45, 135); // define what pin the servos are on

  myservo.attach(11, 45, 135); // the minimum angle

  myservo.attach(3, 45, 135); // that can be rotated

  myservo.attach(4, 45, 135); // and the maximum angle

  myservo.attach(5, 45, 135); // that can be rotated

  myservo.attach(6, 45, 135);

  myservo.attach(7, 45, 135);

  myservo.attach(8, 45, 135);

    myservo.write(90);  // set servo to mid-point (90 degrees)

 

         pinMode(xPin, INPUT); // set x value from accelerometer as an input

         pinMode(yPin, INPUT); // set y value from accelerometer as an input

}

 

void loop()

{

      // variables to read the pulse widths:

  int pulseX, pulseY;

  // variables to contain the resulting accelerations

  int accelerationX, accelerationY;

 

  // read pulse from x- and y-axes:

  pulseX = pulseIn(xPin,HIGH); 

  pulseY = pulseIn(yPin,HIGH);

 

  // convert the pulse width into acceleration

  // accelerationX and accelerationY are in milli-g's:

  // earth's gravity is 1000 milli-g's, or 1g.

  accelerationX = ((pulseX / 10) - 500) * 8;

  accelerationY = ((pulseY / 10) - 500) * 8;

    

       // pulse the servo again if the refresh time (20ms) have passed:

    if (millis() - lastPulse >= refreshTime) {

 

       if (accelerationX < 0) // if the rocket moves off the X-axis then

     {

       myservo.attach(1); // the two servos 1,3 will move to oppose the movement

       myservo.write(135); //the direction of servo 1

       myservo.attach(3); // the two servos are facing each other

       myservo.write(45); // so they have to move "opposite" directions

        

     } else if (accelerationX > 0); // if the rocket goes in

                   (accelerationY > 0); // the x,y direction

                 {

                   myservo.attach(5); // then the servos in the uppersection

                   myservo.write(135); // (5,7) sill counteract the motion in that direction

                   myservo.attach(7);

                   myservo.write(45);

                 }

                

     }else if (accelerationX = 0); //if there is no movement then

                              (accelerationY = 0); // keep the servos aligned with the rocket

                            {

                              myservo.attach(5);

                              myservo.write(90);

                              myservo.attach(7);

                              myservo.write(90);

                            }

                    

  {    

    if (accelerationX > 0) // same thing only in the other direction

     {

       myservo.attach(1);

       myservo.write(45);

       myservo.attach(3);

       myservo.write(135);

      

     }else if (accelerationX < 0);

                  (accelerationY < 0);

                {

                  myservo.attach(5);

                  myservo.write(45);

                  myservo.attach(7);

                  myservo.write(135);

                 

                    if (accelerationX = 0);

                            (accelerationY = 0);

                          {

                            myservo.attach(5);

                            myservo.write(90);

                            myservo.attach(7);

                            myservo.write(90);

                          }

                  }

    

     

     if (accelerationX = 0); //if there is no movement

     {

       myservo.attach(1); // then keep the servos aligned with the rocket

       myservo.write(90);

       myservo.attach(3);

       myservo.write(90);

     }

  }

     if (accelerationY < 0)

     {

       myservo.attach(2);

       myservo.write(45);

       myservo.attach(4);

       myservo.write(135);

 

     }else if (accelerationX > 0);

                 (accelerationY < 0);

               {

                 myservo.attach(6);

                 myservo.write(135);

                 myservo.attach(8);

                 myservo.write(45);

               }

                 {

                   if (accelerationX = 0);

                        (accelerationY = 0);

                      {

                        myservo.attach(6);

                        myservo.write(90);

                        myservo.attach(8);

                        myservo.write(90);

                     }

                 }     

                   

{    

     if (accelerationY > 0)

     {

       myservo.attach(2);

       myservo.write(135);

       myservo.attach(4);

       myservo.write(45);

 

     }else if (accelerationX < 0);

                 (accelerationY > 0);

               {

                 myservo.attach(6);

                 myservo.write(45);

                 myservo.attach(135);

                 myservo.write(135);

               }

                 {

                   if (accelerationX = 0);

                            (accelerationY = 0);

                          {

                            myservo.attach(6);

                            myservo.write(90);

                            myservo.attach(8);

                            myservo.write(90);

                          }

                 }

     }

     if (accelerationY = 0);

     {

       myservo.attach(2);

       myservo.write(90);

       myservo.attach(4);

       myservo.write(90);

     }

    {

     delay(100); // this is to delay repeat time so the servos can catch up

    }

}