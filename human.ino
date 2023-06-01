void humanApproach(){
  while(!humanApproached){
    distanceSensorOn();
    if (distanceToMe > 5 && distanceToMe <= 40 && !humanApproached) {
      Serial.println("human came, NEEDY MODE OOOONNNNN!!!!!!!!!!");
      distanceSensorOff();
      humanApproached = true;
      delay(100); //so i can reach the handle
      //colorStay();
    }
  }
  

  /////BACKUP IF ULTRASONIC DOES NOT WORK
  // if (humanApproached == false) {
  //     Serial.println("human came!!!!!!!!!!");
  //     distanceSensorOff();
  //     delay(5000); //wait for me to approach
  //     humanApproached = true;
  //     delay(5000); //so i can reach the handle
  //     //colorStay();
  //   }

}


void stay(){
  if(humanStayed == false) {
    while(!humanStayed){
      plateMoves=false;
      plateMove();
      distanceSensorOn();
      Serial.println(distanceToMe);
      //here you say that ok i will stay and few secs later sit really close to microwave so if becomes true
      if (distanceToMe > 2 && distanceToMe <= 50 && !humanStayed){
        Serial.println("human stayedd!!!!!!");
        humanStayed = true;
        //distanceSensorOff();
        colorStay();
        timerAfterStay();
      }
    }
  }

}

void pet(){
  if(humanPetted == false && humanStayed){
    int petDetect = analogRead(A0);
    Serial.println("will she pet??");
    Serial.println(petDetect);
    if(petDetect<430){
      humanPetted = true;
      Serial.println("i was petted!!");
      colorPet();
      timerAfterPet();
    }
  }
  
}

void hug(){
  if(humanHugged == false && humanStayed && humanPetted){
    int hugDetect = analogRead(A0);
    Serial.println("will she hug??");
    Serial.println(hugDetect);
    if(hugDetect<500){
      humanHugged = true;
      Serial.println("i was huged!!");
      colorHug();
      timerAfterHug();
    }
  }

  //-------------------OLD HUGGING WITH DELAY---------------------------------
  // if (humanHugged == false && humanStayed && humanPetted){
  //   humanHugged = true;
  //   Serial.println("i was hugged!!!!");
  //   delay(5000); //for hugging properly take place 
  //   colorHug();
  //   timerAfterHug();
  // }

}

void talk(){ //ok this part with detecting does not work. turning sensor on just gives 0 all the time. for now sensor just takes the data from "stay" action :)
  if (humanTalked == false && humanStayed && humanPetted && humanHugged){
     //do not turn the sensor off in stay??
    Serial.println("will she talk???"); 
    //distanceSensorOn();   //and remove this??
    while(!humanTalked){
      plateMoves=false;
      plateMove();
      Serial.println(distanceToMe);
      if(distanceToMe > 2 && distanceToMe <= 50 && !humanTalked){
        Serial.println("SHE TALKED TO ME!!!!");
        humanTalked = true;
        colorTalk();
        timerAfterTalk();
        //plateStop();
        buzz();
        FastLED.clear(true);
        imNeedy = false;
      }
    }
  }
