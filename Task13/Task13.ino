  const int LEFT_ENABLE = 10; 
const int RIGHT_ENABLE = 9; 
const int LEFTFORWARD = 11; 
const int RIGHTFORWARD = 7; 
const int RIGHTREVERSE = 8 ;
const int LEFT_REVERSE = 12 ;
const int LEFT_FEEDBACK = 3;
const int RIGHT_FEEDBACK = 2 ;
const int MID_LDR = A6;
const int RIGHT_LDR = A2;
const int LEFT_LDR = A7;
#include <NewPing.h>


#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


volatile int leftcounter = 0 ;
volatile int rightcounter = 0 ;

int Speed_Left = 95 ;
int Speed_Right = 100 ;


int turnForRDelay = 770 ;// Forward Time Delay for Right Turning
int turnForLDelay = 680;

int turnRevRDelay = 780 ;// Reverse Time Delay for Right Turning
int turnRevLDelay = 680;

long BrightestLight = 10000000;
long MidLDR = 10000000;
long RightLDR = 1000000;
long LeftLDR = 1000000;
int CurrentLight = 0;
int Counter = 0;
int BrightestCount = 0;


void LeftMotorISR(){
  leftcounter++;
}
void RightMotorISR(){
  rightcounter++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
  volatile int leftcounter = 0 ;
  volatile int rightcouner = 0 ;


  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  
  pinMode(LEFT_REVERSE, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(RIGHTFORWARD, OUTPUT);

  sonar.ping_cm();
  RightTurn360();



  
}
void loop() {
  // put your main code here, to run repeatedly:
  

  for (int i=0; i<=36; i++){
    RightTurn90(95);
    StopRover();
    delay(200);
    CurrentLight = analogRead(MID_LDR);
    Counter = Counter+1;
    Serial.println(CurrentLight);
    Serial.println(Counter);
    Serial.println(BrightestCount);
    if (CurrentLight < BrightestLight){
      BrightestLight = CurrentLight;
      BrightestCount = Counter - 1;
    }
  }


  
  RightTurn90(95 * BrightestCount);
  StopRover();
  delay(1000);
  StartRover();
  delay(1000);
  StopRover();
  exit(0);

  /*
   
   LeftTurn90(95);
  
  while (LeftLDR > RightLDR)
  {
    LeftLDR = analogRead(LEFT_LDR);
    RightLDR = analogRead(RIGHT_LDR);
    MidLDR = analogRead(MID_LDR);
    RightTurn90(5);
  }

  delay(1000);

  while ((MidLDR < LeftLDR) && (MidLDR <RightLDR));
  {
    LeftLDR = analogRead(LEFT_LDR);
    RightLDR = analogRead(RIGHT_LDR);
    MidLDR = analogRead(MID_LDR);
    LeftTurn90(5);
  }

  StartRover();
  delay(1000);
  StopRover();
  exit(0);
  
  
  
   
  /*
  
  if (leftcounter < rightcounter){ 
        Speed_Left = Speed_Left +20  ;
        
        Speed_Right = Speed_Right-20 ;
        analogWrite(LEFT_ENABLE, Speed_Left); 
        digitalWrite(LEFTFORWARD, HIGH);
        digitalWrite(LEFT_REVERSE, LOW); 
        analogWrite(RIGHT_ENABLE, Speed_Right);
        digitalWrite(RIGHTFORWARD, HIGH);
        digitalWrite(RIGHTREVERSE, LOW); 
        
        
  }
  if (rightcounter < leftcounter){ 
        Speed_Left = Speed_Left-20 ;
        
        Speed_Right = Speed_Right + 20  ;
        analogWrite(RIGHT_ENABLE, Speed_Right); 
        digitalWrite(RIGHTFORWARD, HIGH);
        digitalWrite(RIGHTREVERSE, LOW); 
        analogWrite(LEFT_ENABLE, Speed_Left);
        digitalWrite(LEFTFORWARD, HIGH);
        digitalWrite(LEFT_REVERSE, LOW); 
  }
  delay(1000) ;

  if (leftcounter==rightcounter ) {
    Speed_Left = 150 ;
    Speed_Right = 150 ;
    StartRover();
    
  }

  */
}
