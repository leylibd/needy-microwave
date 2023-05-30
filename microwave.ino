void foodDone() {
  plateStop();
  turnTimerOff();
  FastLED.clear(true);
  buzz();
  
  
  //servo_timer move to 0
  //servo_plate stop
  //light off
}

void beNeedy(){
  if(humanApproached==true){
    humanApproached = false;
    Serial.println("NEEDY MODE OOOONNNNN!!!!!!!!");
    colorAlone();
    turnTimerOn();

    //human is far:

    //now human is away = false
    //while human is NOT away:
      //ultrasonic on
        //keep moving the plate
        //wait until/ check if the distance between human and microwave is more than 60 AND human is not away
          
          //food done
          //human is away = true

    
    //other things are in else

    
    
    
    //plateMoves=true;
    
    //needy actions:
    //servo_timer at 15
    //servo_plate moving
    //light blue
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
