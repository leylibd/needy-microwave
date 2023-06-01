//libraries 
#include <Servo.h>
#include <FastLED.h>

//servo
Servo timer;
Servo plate;
int timerPos = 0;
int platePos = 0;
bool timerIsOn = true;
bool plateMoves = false;

//light
#define light 5
#define NUM_LEDS 24
CRGB leds[NUM_LEDS];

//------------------------HUMAN ACTIONS-----------------------------------
//staying
bool humanStayed = false;
//petting
bool humanPetted = true; //originally should be false, but in final version pet is not used, so i made it true so that other functions afterwards can be called
//hugging
bool humanHugged = false;
//talking
bool humanTalked = false;


//sound
int buzzer = 2;
int b = 0; //buzzing count

//ultrasonic
const int trigPin = 3; //green
const int echoPin = 4; //yellow
int distanceToMe;
long duration;  //wave travel time
bool humanApproached = false;
bool humanIsAway = false;

bool imNeedy = true;


void setup() {
  Serial.begin(9600);

  //servo
  timer.attach(11);
  //plate servo is attached when servo should start to move


  //ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //light
  // Neopixel ring is WS2812B chipset, GRB ordering
	FastLED.addLeds<WS2812B, light, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(100);
	FastLED.clear(true);

  //sound
  pinMode(buzzer, OUTPUT);


}

void loop() {
  //---------------------CHECKING COLORS HERE----------------
  // colorAlone();
  // delay(5000);

  // colorStay();
  // delay(5000);

  // colorPet();
  // delay(5000);

  // colorHug();
  // delay(5000);

  // colorTalk();

  // delay(10000);



////////////////////////////////BEGINNING!!!!!!////////////////////////////////
 

  colorTalk(); // normal color at the beginning
  timerIsOn = true; //delete after everything is done -- here only to have loop for now
  Serial.println("-----------------hi!---------------------");
  timer.write(135); 
  plateMove(); 
  firstTimerOff(); 
  

  //you approach:
  humanApproach(); // make the distance a bit far 
  //there is 3 secs delay while im reaching the handle
  beNeedy();
  //be needy should work while i am not around. so check while im not there, do the loop. when i left, do food done
  while (!humanIsAway){
      plateMoves=false;
      plateMove();
      distanceSensorOn();
      if (distanceToMe > 30){ //i decided to leave
        Serial.println("human left :(((((((");
        humanIsAway = true;
        distanceSensorOff();
      }
    }
  foodDone(); //when human is away, exit while loop and do food done
  humanApproach(); //waiting for human approach
  beNeedy(); // i wanna take food but it acts needy again - timer+light
  

  while (imNeedy){ //this while loop will move the plate continiously until the end. it will end when imNeedy = false - after all love signs
      plateMoves=false;
      plateMove();
      stay();
      //pet();
      hug();
      talk();
    }


  delay(1000000);

}

void debug(){
   //debugging
  bool buzzed = false;

  if (buzzed == false){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    Serial.println("buzzed");    
  }
  buzzed = true;
}

//refs:
  // moving 2 servos: 
    //https://forum.arduino.cc/t/can-i-control-two-servos-simultaneously/4909/3
  //sound detector:
    //https://randomnerdtutorials.com/guide-for-microphone-sound-sensor-with-arduino/
  //light detector:
    //https://arduinogetstarted.com/tutorials/arduino-light-sensor
  //buzzer:
    //https://maker.pro/arduino/projects/buzzer
  //colors:
    //https://www.w3schools.com/colors/colors_names.asp


