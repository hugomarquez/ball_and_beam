# define trigPin 13
# define echoPin 12

void initSensor(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float calculateDistance(){
  float distance, duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  distance = (calculateDuration()/2) * 0.0344;
  Serial.print("Real Distance = ");
  Serial.println(distance);

  distance = distance - 2;
  if(distance >= 27){distance = 27;}
  if(distance <= 0){distance = 0;}

  Serial.print("Adjust Distance = ");
  Serial.println(distance);
  
  return distance;
}

float calculateDuration(){
  float duration;
  duration = pulseIn(echoPin, HIGH);
  
  return duration;
}

float calculateVelocity(){
  float velocity,x1,x2,t1,t2;
  x1 = calculateDistance();
  t1 = calculateDuration();

  delay(100);
  
  x2 = calculateDistance();
  t2 = calculateDuration();

  velocity = (x2 - x1)/(t2 - t1);

  return velocity;
}

