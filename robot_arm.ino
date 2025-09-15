#include <ESP32Servo.h>

const int servoPin13 = 13; // base servo pin
const int servoPin12 = 12; // shoulder servo pin
const int servoPin14 = 14; // elbow servo pin
const int servoPin27 = 27; // pitch servo pin
const int servoPin26 = 26; // roll servo pin
const int servoPin25 = 25; // gripper servo pin

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo pitchServo;
Servo rollServo;
Servo gripperServo;

void setup() {
  Serial.begin(115200);
  
  baseServo.attach(servoPin13, 500, 2500);
  shoulderServo.attach(servoPin12, 500, 2500);
  elbowServo.attach(servoPin14, 500, 2500);
  pitchServo.attach(servoPin27, 500, 2500);
  rollServo.attach(servoPin26, 500, 2500);
  gripperServo.attach(servoPin25, 500, 2500);

  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  pitchServo.write(90);
  rollServo.write(90);
  gripperServo.write(90);

}

void loop() {        
}
