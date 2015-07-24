#include <AFMotor.h>

#define TIMEOUTX 1000 // how long motor runs before it times out
#define TIMEOUTY 1000 // how long motor runs before it times out
#define MOTORSPEED 255 // default motor speed

AF_DCMotor motorX(1);
AF_DCMotor motorY(2);

unsigned long lastX = 0; // when X motor was last triggered
unsigned long lastY = 0;
unsigned long timeNow = 0;

char inByte;

void setup() {
  Serial.begin(9600);
  Serial.println("motorserial lets you control two motors with adws as arrowkeys");

  motorX.setSpeed(MOTORSPEED);
  motorY.setSpeed(MOTORSPEED);

  motorX.run(RELEASE);
  motorY.run(RELEASE);
}

void loop() {
  timeNow = millis();

  if (Serial.available() > 0) {
    inByte = Serial.read();
    if (inByte == 'a') {
      motorX.run(BACKWARD);
      lastX = timeNow;
    } else
    if (inByte == 'd') {
      motorX.run(FORWARD);
      lastX = timeNow;
    } else
    if (inByte == 'w') {
      motorY.run(FORWARD);
      lastY = timeNow;
    } else
    if (inByte == 's') {
      motorY.run(BACKWARD);
      lastY = timeNow;
    } else {
      motorX.run(RELEASE);
      motorY.run(RELEASE);
    }
  }

  if (timeNow - lastX > TIMEOUTX) {
    motorX.run(RELEASE);
    lastX = timeNow;
  }
  if (timeNow - lastY > TIMEOUTY) {
    motorY.run(RELEASE);
    lastY = timeNow;
  }
}
