/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo neservo;  // create servo object to control a servo
Servo seservo;
Servo nwservo;
Servo swservo;

int nepotpin = 3;// analog pin used to connect the potentiometer
int sepotpin = 1;
int nwpotpin = 2;
int swpotpin = 0;

int neval;    // variable to read the value from the analog pin
int seval;            //DOES EACH POTPIN NEED A SEPERATE int val? ANSWER IS "YES!".
int nwval;
int swval;

void setup()
{
  neservo.attach(11);  // attaches the servo on pin 9 to the servo object
  seservo.attach(10);
  nwservo.attach(3);
  swservo.attach(9);
}


void loop() 
{ 
  neval = analogRead(nepotpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  seval = analogRead(sepotpin);
  nwval = analogRead(nwpotpin);
  swval = analogRead(swpotpin);  
  
  neval = map(neval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  seval = map(seval, 0, 1023, 0, 180);
  nwval = map(nwval, 0, 1023, 0, 180);
  swval = map(swval, 0, 1023, 0, 180);
  
  neservo.write(neval);                  // sets the servo position according to the scaled value 
  seservo.write(seval);
  nwservo.write(nwval);
  swservo.write(swval);
  
  
  delay(15);                           // waits for the servo to get there 
} 

