/*
 * Memsic 2125
 * https://github.com/fusion94/Memsic2125_Arduino

 * Read the Memsic 2125 two-axis accelerometer and prints them over the serial connection to the computer.
   
 * The circuit:
    * X output of accelerometer to digital pin 2
    * Y output of accelerometer to digital pin 3
    * +V of accelerometer to +5V
    * GND of accelerometer to ground

 *
 * Copyright 2011-2013, http://fusion94.org
 * Licensed under the Mozilla Public License Version 2.0
 */
 
 // these constants won't change:
const int xPin = 2;     // X output of the accelerometer
const int yPin = 3;     // Y output of the accelerometer

void setup() {
  // initialize serial communications:
  Serial.begin(9600);
  // initialize the pins connected to the accelerometer
  // as inputs:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
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

  // print the acceleration
  Serial.print(accelerationX);
  // print a tab character:
  Serial.print("\t");
  Serial.print(accelerationY);
  Serial.println();

  delay(100);
}
