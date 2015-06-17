// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(255);
  motor2.setSpeed(255);
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  Serial.print("tick");
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
 
  delay(1000);
  
  Serial.print("tock");

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
 
  delay(1000);

  Serial.print("tech");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(1000);
}
