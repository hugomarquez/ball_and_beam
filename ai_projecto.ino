#include <FuzzyIO.h>
#include <FuzzyRule.h>
#include <FuzzyOutput.h>
#include <FuzzyComposition.h>
#include <FuzzySet.h>
#include <FuzzyRuleAntecedent.h>
#include <Fuzzy.h>
#include <FuzzyRuleConsequent.h>
#include <FuzzyInput.h>

int const L = 27;       // Longitude of beam
int const R = 2;        // Radius of ball
int const MIN = 50;     // Minimum theta angle
int const MAX = 140;    // Maximum theta angle
int const mspeed = 100; // Motor Speed in ms
float set_point = 15;    // Set point


Fuzzy* fuzzyObj = new Fuzzy();

FuzzySet* position_nm = new FuzzySet(0, 0, 2.7, 5.4);
FuzzySet* position_ns = new FuzzySet(2.7, 7, 7, 10.8);
FuzzySet* position_zo = new FuzzySet(6, 11, 11, 16.2);
FuzzySet* position_ps = new FuzzySet(11, 15, 15, 21.6);
FuzzySet* position_pm = new FuzzySet(15, 19, 19, 30);

FuzzySet* setpoint_nm = new FuzzySet(0, 0, 2.7, 5.4);
FuzzySet* setpoint_ns = new FuzzySet(2.7, 7, 7, 10.8);
FuzzySet* setpoint_zo = new FuzzySet(6, 11, 11, 16.2);
FuzzySet* setpoint_ps = new FuzzySet(11, 15, 15, 21.6);
FuzzySet* setpoint_pm = new FuzzySet(15, 19, 19, 30);

FuzzySet* theta_nm = new FuzzySet(0, 35, 35, 50);
FuzzySet* theta_ns = new FuzzySet(35, 45, 45, 90);
FuzzySet* theta_zo = new FuzzySet(50, 80, 80, 110);
FuzzySet* theta_ps = new FuzzySet(80, 100, 100, 130);
FuzzySet* theta_pm = new FuzzySet(90, 110, 110, MAX);

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
  
  moveServo(thetaOutput);

  delay(mspeed);
}
