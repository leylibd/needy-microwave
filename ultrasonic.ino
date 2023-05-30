void distanceSensorOn() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distanceToMe = duration * 0.0343 / 2;
  
  // Serial.println("distance: ");
  // Serial.println(distanceToMe);


  //Serial.print("Distance to Leyli: ");
  //Serial.println(distanceToMe);
  //Serial.println(" cm");
}

void distanceSensorOff() {

  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
}
