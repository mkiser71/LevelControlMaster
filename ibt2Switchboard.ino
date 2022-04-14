/*
IBT-2 Motor Control Board driven by Arduino.
 
Speed and direction controlled by a potentiometer attached to analog input 0.
One side pin of the potentiometer (either one) to ground; the other side pin to +5V
 
Connection to the IBT-2 board:
IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V pin
IBT-2 pin 8 (GND) to Arduino GND
IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
*/
 
//int SENSOR_PIN = 0; // center pin of the potentiometer
int forwardButton = 2;
int reverseButton = 3;
int forward = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
int reverse = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)
 
void setup()
{
  pinMode(forward, OUTPUT);
  pinMode(reverse, OUTPUT);
}
 
void loop()
{
  //int sensorValue = analogRead(SENSOR_PIN);
 
  // sensor value is in the range 0 to 1023
  // the lower half of it we use for reverse rotation; the upper half for forward rotation
  //if (sensorValue < 512)
  {
    // reverse rotation
    int reversePWM = (reverseButton, HIGH);
    analogWrite(LPWM_Output, 0);
    analogWrite(RPWM_Output, reversePWM);
  }
  else
  {
    // forward rotation
    int forwardPWM = (forwardButton, HIGH) ;
    analogWrite(LPWM_Output, forwardPWM);
    analogWrite(RPWM_Output, 0);
  }
}


/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

/*

// constants won't change. They're used here to set pin numbers:
const int forwardButtonPin = 2;     // the number of the pushbutton pin
const int motorForwardPin =  3;      // the number of the LED pin
const int reverseButtonPin = 7;
const int motorReversePin = 8;
// variables will change:
int forwardButtonState = 0;     
int reverseButtonState = 0; 
// variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(motorForwardPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(forwardButtonPin, INPUT);
  pinMode(reverseButtonPin, INPUT);
  pinMode(motorReversePin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  forwardButtonState = digitalRead(forwardButtonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (forwardButtonState == HIGH) {
    // turn LED on:
    digitalWrite(motorForwardPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(motorForwardPin, LOW);

    // read the state of the pushbutton value:
  reverseButtonState = digitalRead(reverseButtonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (reverseButtonState == HIGH) {
    // turn LED on:
    digitalWrite(motorReversePin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(motorReversePin, LOW);
  }
  }
  }
  */
