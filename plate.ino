void plateMove(){
  if(plateMoves==false){
    plate.attach(7);
    platePos = 180;
    Serial.println("plate moves");    
    for (platePos = 180; platePos >= 0; platePos -= 1) {
        plate.write(platePos);
        delay(20);
    }

    for (platePos = 0; platePos <= 180; platePos += 1) {
        plate.write(platePos);
        delay(20);
    }
    
    plateMoves=true;
  }
  
    
}

void plateStop(){
  if(plateMoves){
    plate.detach();
    plateMoves=false;    
  }
}