// Variable allocation
// Left Motor, Right Motor Pin Num
int LON = 10;
int RON = 9 ;
// Left/Right Motor Reverse Pin Num
int LRev = 12 ;
int RRev = 8 ;
// Left/Right Motor Forward Pin Num
int LFor = 11 ; 
int RFor = 7 ;
// Current Time
int currTime = 0;
// Motor Speed Allocation
int lmotspeed = 180;
int rmotspeed = 200;

// Motor Clicker 
const int LEFT_FEEDBACK = 3; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 2; 

// Left/Right Motor Counter Allocation
volatile int leftcounter = 0; // initiate counter to zero for start
volatile int rightcounter = 0;// counter could always be reset

void setup() {
  
  Serial.begin(115200);
  // Interrupt Allocation
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);

  // Turning the Pins on
  pinMode(LON, OUTPUT);
  pinMode(RON, OUTPUT);
  
  pinMode(LRev, OUTPUT);
  pinMode(RRev, OUTPUT);
  
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
  // Ensuring the counters are zero
  rightcounter = 0;
  leftcounter = 0;
}

void loop(){
//delay(250);

// Allocate Current Time to the current time
currTime = millis();
//Just print out the values to show counter operating
Serial.print("Left Counter ");
Serial.println(leftcounter);

Serial.print("Right Counter");
Serial.println(rightcounter);

// Print the values for current motor speed for debug purposes
Serial.print("Right MotSpeed");
Serial.println(rmotspeed);
Serial.print("Left MotSpeed");
Serial.println(lmotspeed);


// If current time is more than 10 seconds then stop, otherwise go forward
if (currTime <= 10000){
  GoFastForward();
}
else{
  GoStop();
}

// Self Correct if turning right
if (leftcounter > rightcounter) {
  lmotspeed = 0;
  rmotspeed = 255;
  
}

// Self Correct if turning left
if (rightcounter > leftcounter){
  lmotspeed = 255;
  rmotspeed = 70;
}

}

/*
void GoSmallForwardLeft(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  analogWrite(LON,100);
  analogWrite(RON,255);
  digitalWrite(RFor,HIGH);
  digitalWrite(LFor,HIGH); 
}



void GoSmallForwardRight(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  analogWrite(LON,255);
  analogWrite(RON,100);
  digitalWrite(RFor,HIGH);
  digitalWrite(LFor,HIGH); 
}
*/

void GoFastForward(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  analogWrite(LON,lmotspeed);
  analogWrite(RON,rmotspeed);
  digitalWrite(RFor,HIGH);
  digitalWrite(LFor,HIGH); 
}

void GoStop(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  digitalWrite(LON,HIGH);
  digitalWrite(RON,HIGH);
  digitalWrite(RFor,LOW);
  digitalWrite(LFor,LOW);
}

/*

void GoBack(){
  analogWrite(LRev,255);
  analogWrite(RRev,255);
  analogWrite(LON,HIGH);
  analogWrite(RON,HIGH);
  analogWrite(RFor,0);
  analogWrite(LFor, 0);
}
*/

void LeftMotorISR(){
  //adds one to counter on each motor revolution
  leftcounter++;
}

void RightMotorISR(){
  //adds one to the counter on each motor revolution
  rightcounter++;
}
