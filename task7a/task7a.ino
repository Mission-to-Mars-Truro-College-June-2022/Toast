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

void loop() {
  
  // Self Correct if turning right
  if (leftcounter > rightcounter) {
    lmotspeed = 50;
    rmotspeed = 255;
  
  }

// Self Correct if turning left
  if (rightcounter > leftcounter){
    lmotspeed = lmotspeed + 50;
    rmotspeed = rmotspeed - 30;
  }
  
  doSquare();

 }



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

void doSquare(){
  for (int i=0; i=4, i++;){
    GoFastForward();
    delay(2000);
    GoLeft();
    delay(500);
    GoStop();
  }
}
void GoLeft(){
  lmotspeed = 0;
  rmotspeed = 200;
  delay(2000);
  rmotspeed = 200;
  lmotspeed = 180;
}

void LeftMotorISR(){
  //adds one to counter on each motor revolution
  leftcounter++;
}

void RightMotorISR(){
  //adds one to the counter on each motor revolution
  rightcounter++;
}
