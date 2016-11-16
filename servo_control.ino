#include <Servo.h>
Servo servo;

void initServo(){
  servo.attach(9);
  servo.write(99);
}

void moveServo(float theta){
  if(theta <= 10){theta = 50;}
  if(theta >= 175){theta = 170;}
  servo.write(theta);
}
