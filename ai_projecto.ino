#include <FuzzyIO.h>
#include <FuzzyRule.h>
#include <FuzzyOutput.h>
#include <FuzzyComposition.h>
#include <FuzzySet.h>
#include <FuzzyRuleAntecedent.h>
#include <Fuzzy.h>
#include <FuzzyRuleConsequent.h>
#include <FuzzyInput.h>

// Longitude of beam
int const L = 31;
// Radius of ball
int const R = 1;
// Minimum theta angle
int const MIN = 50;
// Maximum theta angle
int const MAX = 175;
// Reaction Speed in ms
int const rspeed = 50;
// Initial Motor Position
int const initMposition = 100;
// Move Motor?
bool moveMotor = true;

// Set point
float set_point = 10;


Fuzzy* fuzzyObj = new Fuzzy();

FuzzySet* position_nm = new FuzzySet(0, 0, 3, 6);
FuzzySet* position_ns = new FuzzySet(3, 6, 9, 12);
FuzzySet* position_zo = new FuzzySet(9, 12, 15, 18);
FuzzySet* position_ps = new FuzzySet(15, 18, 21, 24);
FuzzySet* position_pm = new FuzzySet(21, 24, 26, L);

FuzzySet* setpoint_nm = new FuzzySet(0, 0, 3, 6);
FuzzySet* setpoint_ns = new FuzzySet(3, 6, 9, 12);
FuzzySet* setpoint_zo = new FuzzySet(9, 12, 15, 18);
FuzzySet* setpoint_ps = new FuzzySet(15, 18, 21, 24);
FuzzySet* setpoint_pm = new FuzzySet(21, 24, 27, L);

FuzzySet* theta_nm = new FuzzySet(MIN, 50, 60, 80);
FuzzySet* theta_ns = new FuzzySet(60, 80, 90, 100);
FuzzySet* theta_zo = new FuzzySet(90, 100, 110, 120);
FuzzySet* theta_ps = new FuzzySet(110, 120, 120, 130);
FuzzySet* theta_pm = new FuzzySet(130, 140, 160, MAX);

void setup() {
  Serial.begin(9600);
  initSensor();
  initServo();
  initFuzzyLogic();
}

void loop() {
  float ball_position = calculateDistance();
  
  fuzzyObj->setInput(1,ball_position);
  fuzzyObj->setInput(2,set_point);
  
  fuzzyObj->fuzzify();
  
  float thetaOutput = fuzzyObj->defuzzify(1);
  
  logger(thetaOutput);
  
  if(moveMotor){
    moveServo(thetaOutput);
  }

  delay(rspeed);
}
