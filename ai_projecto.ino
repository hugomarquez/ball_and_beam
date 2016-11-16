#include <FuzzyIO.h>
#include <FuzzyRule.h>
#include <FuzzyOutput.h>
#include <FuzzyComposition.h>
#include <FuzzySet.h>
#include <FuzzyRuleAntecedent.h>
#include <Fuzzy.h>
#include <FuzzyRuleConsequent.h>
#include <FuzzyInput.h>


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
FuzzySet* theta_pm = new FuzzySet(90, 110, 110, 140);

void setup() {
  Serial.begin(9600);
  initSensor();
  initServo();
  initFuzzyLogic();
}

void loop() {
  float ball_position = calculateDistance();
  float set_point = 5;
  
  fuzzyObj->setInput(1,ball_position);
  fuzzyObj->setInput(2,set_point);
  
  fuzzyObj->fuzzify();
  
  Serial.println("");
  Serial.print("Ball Position: ");  
  Serial.print(position_nm->getPertinence());
  Serial.print(",");
  Serial.print(position_ns->getPertinence());
  Serial.print(",");
  Serial.print(position_zo->getPertinence());
  Serial.print(",");
  Serial.print(position_ps->getPertinence());
  Serial.print(",");
  Serial.println(position_pm->getPertinence());

  Serial.print("Set Point: ");
  Serial.print(setpoint_nm->getPertinence());
  Serial.print(",");
  Serial.print(setpoint_ns->getPertinence());
  Serial.print(",");
  Serial.print(setpoint_zo->getPertinence());
  Serial.print(",");
  Serial.print(setpoint_ps->getPertinence());
  Serial.print(",");
  Serial.println(setpoint_pm->getPertinence());
  
  float thetaOutput = fuzzyObj->defuzzify(1);
  

  Serial.print("Theta: ");
  Serial.println(thetaOutput);

  Serial.print("Output pertinence: ");
  Serial.print(theta_nm->getPertinence());
  Serial.print(",");
  Serial.print(theta_ns->getPertinence());
  Serial.print(",");
  Serial.print(theta_zo->getPertinence());
  Serial.print(",");
  Serial.print(theta_ps->getPertinence());
  Serial.print(",");
  Serial.println(theta_pm->getPertinence());
  
  //moveServo(thetaOutput);

  delay(1000);
}

