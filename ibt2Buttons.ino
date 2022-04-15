
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

const int rbutton = 11; // right turn button
const int lbutton = 12; // left turn button

const int goRight = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
const int goLeft = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)
// redundant? 10-09-2019

void setup()
{
  pinMode(goRight, OUTPUT);
  pinMode(goLeft, OUTPUT);
  pinMode(rbutton, INPUT);//removed INPUT_PULLUP
  pinMode(lbutton, INPUT);//removed INPUT_PULLUP
}

void loop()
{
  int rbuttonValue = digitalRead(rbutton);
  int lbuttonValue = digitalRead(lbutton);

  if (rbuttonValue == HIGH);
  {
    // forward rotation
    int forward = (rbuttonValue == HIGH);
    digitalWrite(goRight, forward);
    digitalWrite(goLeft, LOW);

  }

  if (lbuttonValue == HIGH);
  {
    // reverse rotation
    int reverse = (lbuttonValue == HIGH);
    digitalWrite(goLeft, reverse);
    digitalWrite(goRight, LOW);
  }
  //delay (100);
}
