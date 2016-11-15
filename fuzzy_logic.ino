// NB - Negative Big
// NM - Negative Medium
// NS - Negative Small
// ZO - Zero
// PS - Positive Small
// PM - Positive Medium
// PB - Positive Big

void initFuzzyLogic(){
  FuzzyInput* ballPosition = new FuzzyInput(1);
  
  ballPosition->addFuzzySet(position_nm);
  ballPosition->addFuzzySet(position_ns);
  ballPosition->addFuzzySet(position_zo);
  ballPosition->addFuzzySet(position_ps);
  ballPosition->addFuzzySet(position_pm);
  
  fuzzyObj->addFuzzyInput(ballPosition);

  FuzzyInput* setPoint = new FuzzyInput(2);
  
  setPoint->addFuzzySet(setpoint_nm);
  setPoint->addFuzzySet(setpoint_ns);
  setPoint->addFuzzySet(setpoint_zo);
  setPoint->addFuzzySet(setpoint_ps);
  setPoint->addFuzzySet(setpoint_pm);
  
  fuzzyObj->addFuzzyInput(setPoint); 

  FuzzyOutput* theta = new FuzzyOutput(1);
  
  theta->addFuzzySet(theta_nm);
  theta->addFuzzySet(theta_ns);
  theta->addFuzzySet(theta_zo);
  theta->addFuzzySet(theta_ps);
  theta->addFuzzySet(theta_pm);
  
  fuzzyObj->addFuzzyOutput(theta);

  // Rules Consequents
  FuzzyRuleConsequent* then_thetaPS = new FuzzyRuleConsequent();
  then_thetaPS->addOutput(theta_ps);

  FuzzyRuleConsequent* then_thetaPM = new FuzzyRuleConsequent();
  then_thetaPM->addOutput(theta_pm);

  FuzzyRuleConsequent* then_thetaNM = new FuzzyRuleConsequent();
  then_thetaNM->addOutput(theta_nm);

  FuzzyRuleConsequent* then_thetaNS = new FuzzyRuleConsequent();
  then_thetaNS->addOutput(theta_ns);

  FuzzyRuleConsequent* then_thetaZO = new FuzzyRuleConsequent();
  then_thetaZO->addOutput(theta_zo);

  // Rules Antecedents
  
  FuzzyRuleAntecedent* positionNM_setPointNM = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionNS_setPointNS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionZO_setPointZO = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPS_setPointPS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPM_setPointPM = new FuzzyRuleAntecedent();
  
  positionNM_setPointNM->joinWithAND(position_nm, setpoint_nm);
  positionNS_setPointNS->joinWithAND(position_ns, setpoint_ns);
  positionZO_setPointZO->joinWithAND(position_zo, setpoint_zo);
  positionPS_setPointPS->joinWithAND(position_ps, setpoint_ps);
  positionPM_setPointPM->joinWithAND(position_pm, setpoint_pm);
  
  FuzzyRule* Rule1 = new FuzzyRule(1, positionNM_setPointNM, then_thetaPS);
  FuzzyRule* Rule2 = new FuzzyRule(2, positionNS_setPointNS, then_thetaPS);
  FuzzyRule* Rule3 = new FuzzyRule(3, positionZO_setPointZO, then_thetaZO);
  FuzzyRule* Rule4 = new FuzzyRule(4, positionPS_setPointPS, then_thetaNS);
  FuzzyRule* Rule5 = new FuzzyRule(5, positionPM_setPointPM, then_thetaNS);
  
  FuzzyRuleAntecedent* positionNM_setPointNS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionNM_setPointZO = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionNM_setPointPS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionNM_setPointPM = new FuzzyRuleAntecedent();
  
  positionNM_setPointNS->joinWithAND(position_nm, setpoint_ns);
  positionNM_setPointZO->joinWithAND(position_nm, setpoint_zo);
  positionNM_setPointPS->joinWithAND(position_nm, setpoint_ps);
  positionNM_setPointPM->joinWithAND(position_nm, setpoint_pm);
  
  FuzzyRule* Rule6 = new FuzzyRule(6, positionNM_setPointNS, then_thetaZO);
  FuzzyRule* Rule7 = new FuzzyRule(7, positionNM_setPointZO, then_thetaNS);
  FuzzyRule* Rule8 = new FuzzyRule(8, positionNM_setPointPS, then_thetaNS);
  FuzzyRule* Rule9 = new FuzzyRule(9, positionNM_setPointPM, then_thetaNM);
  
  FuzzyRuleAntecedent* positionNS_setPointNM = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionNS_setPointZO = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionNS_setPointPS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionNS_setPointPM = new FuzzyRuleAntecedent();
  
  positionNS_setPointNM->joinWithAND(position_ns, setpoint_nm);
  positionNS_setPointZO->joinWithAND(position_ns, setpoint_zo);
  positionNS_setPointPS->joinWithAND(position_ns, setpoint_ps);
  positionNS_setPointPM->joinWithAND(position_ns, setpoint_pm);
  
  FuzzyRule* Rule10 = new FuzzyRule(10, positionNS_setPointNM, then_thetaPM);
  FuzzyRule* Rule11 = new FuzzyRule(11, positionNS_setPointZO, then_thetaNS);
  FuzzyRule* Rule12 = new FuzzyRule(12, positionNS_setPointPS, then_thetaNS);
  FuzzyRule* Rule13 = new FuzzyRule(13, positionNS_setPointPM, then_thetaNM);
  
  FuzzyRuleAntecedent* positionZO_setPointNM = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionZO_setPointNS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionZO_setPointPS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionZO_setPointPM = new FuzzyRuleAntecedent();
  
  positionZO_setPointNM->joinWithAND(position_zo, setpoint_nm);
  positionZO_setPointNS->joinWithAND(position_zo, setpoint_ns);
  positionZO_setPointPS->joinWithAND(position_zo, setpoint_ps);
  positionZO_setPointPM->joinWithAND(position_zo, setpoint_pm);
  
  FuzzyRule* Rule14 = new FuzzyRule(14, positionZO_setPointNM, then_thetaPS);
  FuzzyRule* Rule15 = new FuzzyRule(15, positionZO_setPointNS, then_thetaPS);
  FuzzyRule* Rule16 = new FuzzyRule(16, positionZO_setPointPS, then_thetaNS);
  FuzzyRule* Rule17 = new FuzzyRule(17, positionZO_setPointPM, then_thetaNS);
  
  FuzzyRuleAntecedent* positionPS_setPointNM = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPS_setPointNS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPS_setPointZO = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPS_setPointPM = new FuzzyRuleAntecedent();
  
  positionPS_setPointNM->joinWithAND(position_ps, setpoint_nm);
  positionPS_setPointNS->joinWithAND(position_ps, setpoint_ns);
  positionPS_setPointZO->joinWithAND(position_ps, setpoint_zo);
  positionPS_setPointPM->joinWithAND(position_ps, setpoint_pm);
  
  FuzzyRule* Rule18 = new FuzzyRule(18, positionPS_setPointNM, then_thetaPM);
  FuzzyRule* Rule19 = new FuzzyRule(19, positionPS_setPointNS, then_thetaPS);
  FuzzyRule* Rule20 = new FuzzyRule(20, positionPS_setPointZO, then_thetaPS);
  FuzzyRule* Rule21 = new FuzzyRule(21, positionPS_setPointPM, then_thetaNM);
  
  FuzzyRuleAntecedent* positionPM_setPointNM = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPM_setPointNS = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPM_setPointZO = new FuzzyRuleAntecedent();
  FuzzyRuleAntecedent* positionPM_setPointPS = new FuzzyRuleAntecedent();

  positionPM_setPointNM->joinWithAND(position_pm, setpoint_nm);
  positionPM_setPointNS->joinWithAND(position_pm, setpoint_ns);
  positionPM_setPointZO->joinWithAND(position_pm, setpoint_zo);
  positionPM_setPointPS->joinWithAND(position_pm, setpoint_ps);
  
  FuzzyRule* Rule22 = new FuzzyRule(22, positionPM_setPointNM, then_thetaPM);
  FuzzyRule* Rule23 = new FuzzyRule(23, positionPM_setPointNS, then_thetaPM);
  FuzzyRule* Rule24 = new FuzzyRule(24, positionPM_setPointZO, then_thetaPS);
  FuzzyRule* Rule25 = new FuzzyRule(25, positionPM_setPointPS, then_thetaZO);
    
  fuzzyObj->addFuzzyRule(Rule1);
  fuzzyObj->addFuzzyRule(Rule2);
  fuzzyObj->addFuzzyRule(Rule3);
  fuzzyObj->addFuzzyRule(Rule4);
  fuzzyObj->addFuzzyRule(Rule5);
  fuzzyObj->addFuzzyRule(Rule6);
  fuzzyObj->addFuzzyRule(Rule7);
  fuzzyObj->addFuzzyRule(Rule8);
  fuzzyObj->addFuzzyRule(Rule9);
  fuzzyObj->addFuzzyRule(Rule10);

  fuzzyObj->addFuzzyRule(Rule11);
  fuzzyObj->addFuzzyRule(Rule12);
  fuzzyObj->addFuzzyRule(Rule13);
  fuzzyObj->addFuzzyRule(Rule14);
  fuzzyObj->addFuzzyRule(Rule15);
  fuzzyObj->addFuzzyRule(Rule16);
  fuzzyObj->addFuzzyRule(Rule17);
  fuzzyObj->addFuzzyRule(Rule18);
  fuzzyObj->addFuzzyRule(Rule19);
  fuzzyObj->addFuzzyRule(Rule20);

  fuzzyObj->addFuzzyRule(Rule21);
  fuzzyObj->addFuzzyRule(Rule22);
  fuzzyObj->addFuzzyRule(Rule23);
  fuzzyObj->addFuzzyRule(Rule24);
  fuzzyObj->addFuzzyRule(Rule25);
  
}

