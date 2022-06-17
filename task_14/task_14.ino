// Pin Allocation
// Motor On
const int LEFT_ENABLE = 10; // Pin numbers on Rover
const int RIGHT_ENABLE= 9;

// Forward On
const int LEFTFORWARD = 11;
const int RIGHTFORWARD = 7;

// Reverse On
const int RIGHTREVERSE= 8;
const int LEFTREVERSE= 12;

// Light Dependent Resistors 
const int MID_LDR = A6 ;
const int LEFT_LDR = A7;
const int RIGHT_LDR = A2; 

// Light above a limit has been discovered
bool foundLight = false;

// Start Speeds of left and right
int Speed_left = 95;
int Speed_right =100;

// Light Resistance of the right, middle, left LDRs
int CurrentLeftLightLevel = 0 ;
int CurrentMidLightLevel = 0 ;
int CurrentRightLightLevel = 0 ;

// Add ping sonars
#include <NewPing.h>

// Sonar Pins
#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

// Vertical sonar and horizontal (normal) sonar
NewPing vsonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar(4, 5, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup(){
  // Pin Modes onto Output
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTREVERSE, OUTPUT);

Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

// Start with a ping to reset sonar
vsonar.ping_cm();
sonar.ping_cm();
}


void loop() {
  // delays before allocating vertical distance
  delay(50);
  int vdistance = vsonar.ping_cm();

  // if vertical distance in front of the rover is greater than 16 then stop
  // != 0 because the sonar defaults to 0 for distances greater than 2m
  if ((vdistance > 16) && (vdistance != 0)){
    stopRover();
    delay(50);
    reverseRover();
    delay(400);
   
  }
  // delays before allocating horizontal distance
  delay(50);
  int distance = sonar.ping_cm();

  // if horizontal distance in front of the rover is less than 7 then stop
  if ((distance < 7) && (distance != 0)){
    stopRover();
    delay(50);
    reverseRover();
    delay(400);
   
  }
  // Light level reads from the respective pins
  CurrentMidLightLevel = analogRead(A6);
  CurrentLeftLightLevel = analogRead(A7);
  CurrentRightLightLevel = analogRead(A2);
  // if the light has been found then don't search for the torch again
  if (foundLight == false) {
    FollowLight();
  }

  // if the light on the left is greater (resistance is less) then move towards that light
  if (CurrentLeftLightLevel < CurrentMidLightLevel) {
    leftturn10();
    delay(10);
  }
  // if the light on the right is greater (resistance is less) then move towards that light
  else if (CurrentRightLightLevel < CurrentMidLightLevel) {
    rightturn10();
    delay(10);
  }
  // if the middle light is greater then go forward
  else {
    startRover();
  }


}
