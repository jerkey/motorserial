#include <AFMotor.h>

#define TIMEOUTX 500 // how long motor runs before it times out
#define TIMEOUTY 500 // how long motor runs before it times out
int motorSpeed = 255; // default motor speed

AF_DCMotor motorX(1);
AF_DCMotor motorY(2);

unsigned long lastX = 0; // when X motor was last triggered
unsigned long lastY = 0;
unsigned long timeNow = 0;

char inByte;

void setup() {
  Serial.begin(9600);
  Serial.println("motorserial lets you control two motors with adws as arrowkeys");
  Serial.println("= to raise motor speed, - to lower it");
  Serial.println("motorSpeed is now at "+String(motorSpeed));

  motorX.setSpeed(motorSpeed);
  motorY.setSpeed(motorSpeed);

  motorX.run(RELEASE);
  motorY.run(RELEASE);
}

void loop() {
  timeNow = millis();

  if (Serial.available() > 0) {
    inByte = Serial.read();
    Serial.print(inByte);
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
    if (inByte == '=') {
      motorSpeed = constrain(motorSpeed + 5,1,255);
      Serial.println(motorSpeed);
      motorX.setSpeed(motorSpeed);
      motorY.setSpeed(motorSpeed);
    } else
    if (inByte == '-') {
      motorSpeed = constrain(motorSpeed - 5,1,255);
      Serial.println(motorSpeed);
      motorX.setSpeed(motorSpeed);
      motorY.setSpeed(motorSpeed);
    } else
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
