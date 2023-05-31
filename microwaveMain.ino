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
bool humanPetted = false;
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

//millis delay

unsigned long stayInterval = 10000; //waiting for 10 secs
unsigned long startTime = 0;

unsigned long petInterval = 3000; //waiting for 10 secs
unsigned long petStartTime = 0;

//CHANGE THESE AS WELL
int periodHug = 3000;
unsigned long timeHug = 0;

int periodTalk = 3000;
unsigned long timeHTalk = 0;



void setup() {
  Serial.begin(9600);

  //servo
  timer.attach(11);

  

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

  //millis
  //startTime = millis(); //store current time

}

void loop() {
  //---------------------CHECKING COLORS HERE----------------
  colorAlone();
  delay(10000);
///////////////////////////DEBUGGING STUFF IGNORE/////////////////////
  //   int petDetect = analogRead(A1);
  //   Serial.println("will she pet??");
  //   Serial.print(petDetect);
  //   if(petDetect < 10){
  //     Serial.println("i was petted!!");
  //   }

  // delay(10000);
  //plateMove();
  
  // stay();//talk a bit here
  // pet();//talk a bit here
  // hug();//talk a bit here
  // talk();//talk more here


  //FastLED.clear(true);
  
  
  //humanStayed = true;
  //timerAfterStay();
  //delay(5000);

  //foodDone();
  //delay(5000);
  //pet();

  //colorStay();
  
/////////////////////////////////DEBUGGING ENDS///////////////////////////////

////////////////////////////////BEGINNING!!!!!!////////////////////////////////
 
  //beginning:
  //servo_timer at 135
  //servo_plate moving
  //light white??
  //foodDone();
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
      if (distanceToMe > 40){ //i decided to leave
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
      pet();
      hug();
      talk();
      //imNeedy = false;
      //VERY END: imNeedy = false;
    }


  delay(1000000);

  //ultrasonic distance
    //if close to microwave
    //delay 3 secs so i can put my hand to the handle
    //start needy actions:

  //needy actions:
    //servo_timer at 15
    //servo_plate moving
    //light blue

  //you leave

  //foodDone();
  //you approach:
  //ultrasonic distance
    //if close to microwave
    //delay 3 secs so i can put my hand to the handle
    //start needy actions:

  //needy actions:
    //servo_timer at 15
    //servo_plate moving
    //light blue

  //you interacting:
    //1. you stay:
    //"allright, i'll stay here with you"
      //delay 5 secs
      //light softer (define)
      //(optional) servo_timer move 10 degrees?

    //2. you pet:
      //check light stuff
      //light softer (define)
      //(optional) servo_timer move 10 degrees?

    //3. you hug:
      //motion detector check motion
      //light softer (define)
      //(optional) servo_timer move 10 degrees?

    //4. you talk:
      //sounddetector?? check if there is sound
      //delay 5 secs or so while i talk
      //iTalked=true
      //light white
      //servo_timer move to 0
    
  //microwave happy:
    //random happy lights for 5 secs
    //beep
    //servo_plate stop
    //light off


  //i take the food and eat there

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

//-----------------------------------------MICROWAVE ACTIONS-------------------------------------------------


//------------------------------------------HUMAN ACTIONS---------------------------------------------------


//------------------------------------------COLORS----------------------------------------


//-------------------------------------ULTRASONIC----------------------------------


/////////////////////////////////////////////////////////////////////////////////////////////////////

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



//to-dos
  //add melody to buzzer
  //see why petting doesnt work inside the function - SOLVED
  //FastLED.clear(); NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
  //smooth transitions between colors?

