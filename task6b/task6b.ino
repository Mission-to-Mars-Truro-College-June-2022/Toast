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
int lmotspeed = 100;
int rmotspeed = 100;

// Motor Clicker 
const int LEFT_FEEDBACK = 3; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 2; 

// Left/Right Motor Counter Allocation
volatile int leftcounter = 0; // initiate counter to zero for start
volatile int rightcounter = 0;// counter could always be reset

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);

  pinMode(LON, OUTPUT);
  pinMode(RON, OUTPUT);
  
  pinMode(LRev, OUTPUT);
  pinMode(RRev, OUTPUT);
  
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
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
void LeftMotorISR(){
  //adds one to counter on each motor revolution
  leftcounter++;
}

void RightMotorISR(){
  //adds one to the counter on each motor revolution
  rightcounter++;
}

void loop() {
  // put your main code here, to run repeatedly:
  currTime = millis();

  if (currTime <= 10000){
    GoFastForward();
}
  else{
    GoStop();
}

  if (leftcounter > rightcounter) {
    lmotspeed = 0;
  }
  else if (rightcounter > leftcounter) {
    rmotspeed = 0;
  }
  else {
    rmotspeed = 100;
    lmotspeed = 100;

  }
}
