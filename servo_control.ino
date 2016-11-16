#include <Servo.h>
Servo servo;

void initServo(){
  servo.attach(9);
  servo.write(100);
}

void moveServo(float theta){
  int maximum = 140;
  if(theta <= 10){theta = MIN;}
  if(theta >= 175){theta = MAX;}
  
  servo.write(theta);
}
