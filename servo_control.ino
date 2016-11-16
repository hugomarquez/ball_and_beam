#include <Servo.h>
Servo servo;

void initServo(){
  servo.attach(9);
  servo.write(100);
}

void moveServo(float theta){
  // Min&Max theta
  // note cetner = 100
  int minimum = 50;
  int maximum = 140;
  if(theta <= 10){theta = minimum;}
  if(theta >= 175){theta = maximum;}
  
  servo.write(theta);
}
