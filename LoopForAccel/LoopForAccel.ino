
void loop for the X axis:

sensorValX = analogRead(sensorXPin);
sensorValX = constrain(sensorValX, calibrateXMin, calibrateXMax);
tiltX = map(sensorValX, calibrateXMin, calibrateXMax, 0, 179);
servoValX = constrain(servoValX - (tiltX - 89),0,179);
servoX.write(servoValX);
delay(150);
