void logger(float thetaOutput){
  log_position();
  log_setpoint();
  log_theta(thetaOutput);
}
void log_position(){
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
}

void log_setpoint(){
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
}

void log_theta(float thetaOutput){
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
}
