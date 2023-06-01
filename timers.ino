//turning timer off at the first time when the timer is at 135
void firstTimerOff(){
  if (timerIsOn){
    Serial.println("turning timer OFF for the first time");
    for (timerPos = 135; timerPos <= 180; timerPos += 1) {
      timer.write(timerPos);
      //Serial.println("off");
      delay(10);
    }
    timerIsOn = false;
  }
  plateStop();
  FastLED.clear(true);
  buzz();
}

void turnTimerOff(){ 
  if (timerIsOn){
    Serial.println("turning timer OFF");
    for (timerPos = 0; timerPos <= 180; timerPos += 1) {
      timer.write(timerPos);
      delay(10);
    }
    timerIsOn = false;
  }
  
}

void turnTimerOn(){
  if (timerIsOn == false){
    Serial.println("turning timer ON");
    for (timerPos = 180; timerPos >= 0; timerPos -= 1) {
      timer.write(timerPos);
      delay(10);
    }
    timerIsOn = true;
  }
  
}

//------------------------timers after human action--------------------------------
//originally each action should've been adding 45, but since i don't use the pet action in the final version, i skip its timer change. now timer adds 90 after talk action to make it 180 in total
void timerAfterStay(){
  if(timerIsOn && humanStayed){
    Serial.println("timer to 45");
    for (timerPos = 0; timerPos <= 45; timerPos += 1) {
      timer.write(timerPos);
      delay(40);
      }
  }
}

void timerAfterPet(){
  if(timerIsOn && humanPetted){
    Serial.println("timer to 90");
    for (timerPos = 45; timerPos <= 90; timerPos += 1) {
      timer.write(timerPos);
      delay(40);
      }
  }
}

void timerAfterHug(){
  if(timerIsOn && humanHugged){
    Serial.println("timer to 135");
    for (timerPos = 45; timerPos <= 90; timerPos += 1) {
      timer.write(timerPos);
      delay(40);
      }
  }
}

void timerAfterTalk(){
  if(timerIsOn && humanTalked){
    Serial.println("timer to 180");
    for (timerPos = 90; timerPos <= 180; timerPos += 1) {
      timer.write(timerPos);
      delay(40);
      }
  }
}