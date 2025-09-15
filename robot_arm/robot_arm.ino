#include <ESP32Servo.h>
#include <math.h>

const int servoPin13 = 13; // base servo pin
const int servoPin12 = 12; // shoulder servo pin
const int servoPin14 = 14; // elbow servo pin
const int servoPin27 = 27; // pitch servo pin
const int servoPin26 = 26; // roll servo pin
const int servoPin25 = 25; // gripper servo pin

const float L = 8.5;

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

}

void origin(){
  baseServo.write(90);
  shoulderServo.write(25);
  elbowServo.write(120);
  pitchServo.write(90);
  rollServo.write(0);
  delay(1000);
}


void open(){
  delay(500);
  gripperServo.write(0);
  delay(500);
}

void close(){
  delay(500);
  gripperServo.write(180);
  delay(500);
}

void twistOpposite(){
  delay(500);
  rollServo.write(180);
  delay(500);
}

void twistNormal(){
  delay(500);
  rollServo.write(0);
  delay(500);
}

void move1(){
  shoulderServo.write(125);
  elbowServo.write(98);
  pitchServo.write(130);

  delay(1000);

}

void move2(){

  baseServo.write(15);
  shoulderServo.write(120);
  elbowServo.write(30);
  pitchServo.write(65);

}

void sky(){

baseServo.write(135);
shoulderServo.write(90);
elbowServo.write(45);
pitchServo.write(180);


}

void pitchRange(){
  pitchServo.write(100);
  delay(250);
  pitchServo.write(180);
  delay(250);
  }

void wave(){
  twistOpposite();
  delay(50);
  twistNormal();
  delay(50);
  twistOpposite();
  delay(50);
  pitchRange();
  delay(100);
  pitchRange();
  delay(100);
}


void loop() {
  open();
  delay(50);
  close();
  delay(1000);

  origin();
  delay(50);
  open();
  delay(100);

  move1();
  close();

  origin();

  delay(500);

  sky();

  delay(200);

  wave();



  move2();
  delay(1000);
  open();
  delay(500);

  sky();
  delay(1000);
  delay(50);
  pitchRange();
  delay(100);
  pitchRange();
  delay(100);
  delay(50);
  pitchRange();
  delay(100);
  pitchRange();
  delay(100);

  
  close();
  rollServo.write(0);
  origin();
  delay(5000);

   
}
