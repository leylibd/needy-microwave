void colorAlone(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB::Navy; //330099
	}
	FastLED.show();
}

void colorStay(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB(51, 255, 204);  //33ffcc
	}
	FastLED.show();
}

void colorPet(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB(255, 153, 51); //FF9933
	}
	FastLED.show();
}

void colorHug(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB(255, 255, 0);  //FFFF00 
  }
  FastLED.show();
}

void colorTalk(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB(255, 255, 204); 
	}
	FastLED.show();
}