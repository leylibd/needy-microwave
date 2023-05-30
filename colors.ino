void colorAlone(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB::Navy;
	}
	FastLED.show();
}

void colorStay(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB::CadetBlue;  //THIS COLOR IS TOO COLD
	}
	FastLED.show();
}

void colorPet(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB::LightSalmon; //TOO RED
	}
	FastLED.show();
}

void colorHug(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB::Moccasin;  // THIS COLOR IS BARELY DISTIQUSHABLE FROM THE LAST
	}
	FastLED.show();
}

void colorTalk(){
  for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB::Ivory;
	}
	FastLED.show();
}