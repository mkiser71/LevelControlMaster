#include <Servo.h>

Servo servoX;

int servoXpin = 4;

int sensorXPin = 2;

int s

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
