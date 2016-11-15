#include <Servo.h>
Servo servo;

void initServo(){
  servo.attach(9);
  servo.write(99);
}

void moveServo(float theta){
  servo.write(theta);
}
