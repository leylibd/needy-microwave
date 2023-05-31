void humanApproach(){
  while(!humanApproached){
    distanceSensorOn();
    if (distanceToMe > 5 && distanceToMe <= 30 && !humanApproached) {
      Serial.println("human came, NEEDY MODE OOOONNNNN!!!!!!!!!!");
      distanceSensorOff();
      humanApproached = true;
      delay(2000); //so i can reach the handle
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
  ////////////////////////////////////////////////////


    //you approach:
    //ultrasonic distance
    //if close to microwave
    //delay 3 secs so i can put my hand to the handle
    //start needy actions:
}


void stay(){
  if(humanStayed == false) {
    while(!humanStayed){
      plateMoves=false;
      plateMove();
      distanceSensorOn();
      //here you say that ok i will stay and few secs later sit really close to microwave so if becomes true
      if (distanceToMe > 5 && distanceToMe <= 30 && !humanStayed){
        Serial.println("human stayedd!!!!!!");
        humanStayed = true;
        distanceSensorOff();
        colorStay();
        timerAfterStay();
      }
    }
  }

  //1. you stay:
      //light softer (define)
      //(optional) servo_timer move 10 degrees?
}

void pet(){
  if(humanPetted == false && humanStayed){
    int petDetect = analogRead(A1);
    Serial.println("will she pet??");
    Serial.println(petDetect);
    if(petDetect<600){
      humanPetted = true;
      Serial.println("i was petted!!");
      colorPet();
      timerAfterPet();
    }
  }
  

  //colorPet();
  //you pet:
      //if no light anymore:
      //light softer (define)
      //(optional) servo_timer move 10 degrees?

}

void hug(){
  if(humanHugged == false && humanStayed && humanPetted){
    int hugDetect = analogRead(A0);
    Serial.println("will she hug??");
    if(hugDetect<600){
      humanHugged = true;
      Serial.println("i was huged!!");
      Serial.println(hugDetect);
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

  //3. you hug:
      //motion detector check motion
      //light softer (define)
      //(optional) servo_timer move 10 degrees?

}

void talk(){
  if (humanTalked == false && humanStayed && humanPetted && humanHugged){
    //distanceSensorOff();
    Serial.println("will she talk???");    
    while(!humanTalked){
      plateMoves=false;
      plateMove();
      distanceSensorOn();
      Serial.println(distanceToMe);
      if(distanceToMe > 5 && distanceToMe <= 20 && !humanTalked){
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


  //4. you talk:
      //sounddetector?? check if there is sound
      //delay 5 secs or so while i talk
      //iTalked=true
      //light white
      //servo_timer move to 0

}