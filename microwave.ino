void foodDone() {
  plateStop();
  turnTimerOff();
  FastLED.clear(true);
  buzz();

void beNeedy(){
  if(humanApproached==true){
    humanApproached = false;
    Serial.println("NEEDY MODE OOOONNNNN!!!!!!!!");
    colorAlone();
    turnTimerOn();
  }
}

//////////////////////////////////////////////BUZZER//////////////////////////////////////////////////
void buzz(){
  for(b = 0; b<3; b++) {
    Serial.println("beep");
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
}
