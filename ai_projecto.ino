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

FuzzySet* position_nm = new FuzzySet(1, 1, 3, 7);
FuzzySet* position_ns = new FuzzySet(3, 9, 9, 14);
FuzzySet* position_zo = new FuzzySet(9, 15, 15, 21);
FuzzySet* position_ps = new FuzzySet(15, 22, 22, 28);
FuzzySet* position_pm = new FuzzySet(22, 30, 30, 35);

FuzzySet* setpoint_nm = new FuzzySet(1, 1, 3, 7);
FuzzySet* setpoint_ns = new FuzzySet(3, 9, 9, 14);
FuzzySet* setpoint_zo = new FuzzySet(9, 15, 15, 21);
FuzzySet* setpoint_ps = new FuzzySet(15, 22, 22, 28);
FuzzySet* setpoint_pm = new FuzzySet(22, 30, 30, 35);

FuzzySet* theta_nm = new FuzzySet(1, 20, 20, 47.5);
FuzzySet* theta_ns = new FuzzySet(20, 60, 60, 95);
FuzzySet* theta_zo = new FuzzySet(60, 95, 95, 120.5);
FuzzySet* theta_ps = new FuzzySet(95, 142, 142, 160);
FuzzySet* theta_pm = new FuzzySet(142, 142, 180, 1);

void setup() {
  Serial.begin(9600);
  initSensor();
  initServo();
  initFuzzyLogic();
}

void loop() {
  float ball_position = calculateDistance();
  float set_point = 15;
  
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

  delay(200);
}

