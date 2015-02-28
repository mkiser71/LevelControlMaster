#include <Arduino.h>
#include <Servo.h>	//Include Servo Library

Servo servoX;	//Declare Servo

int servoXpin = 4;	//Pin for Servo

int sensorXPin = 2;	//Pin for Accelerometer



int s

void setup() {

	Serial.begin (9600);

	pinMode(sensorXpin, INPUT);
}

//void loop for the X axis:
void loop(){
//int sensorXPin = 2;

sensorValX = digitalRead(sensorXPin);
sensorValX = constrain(sensorValX, calibrateXMin, calibrateXMax);
tiltX = map(sensorValX, calibrateXMin, calibrateXMax, 0, 179);
servoValX = constrain(servoValX - (tiltX - 89),0,179);
servoX.write(servoValX);
delay(150);
}
