#include <Servo.h>
Servo servo;

void initServo(){
  servo.attach(9);
  servo.write(initMposition);
}

void moveServo(float theta){
  if(theta <= 10){theta = MIN;}
  if(theta >= 175){theta = MAX;}
  
  servo.write(theta);
}
