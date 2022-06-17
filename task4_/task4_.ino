// GO FORWARD THEN BACK

// Pin Number Allocation
// Rover Motor Power On
const int LON = 10; //Left
const int RON = 9; //Right

// Rover Motor Reverse On
const int LRev = 12; //Left
const int RRev = 8; //Right

// Rover Motor Forward On
const int LFor = 11; //Left
const int RFor = 7; //Right


void setup() {
  // Setting the motors to output
  pinMode(LON, OUTPUT);
  pinMode(RON, OUTPUT);
  
  pinMode(LRev, OUTPUT);
  pinMode(RRev, OUTPUT);
  
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);

}

// Go forward, stop for a second (1000ms), go back, stop for a second
void loop() {
  GoForward();
  delay(1000);
  GoStop();
  delay(1000);
  GoBack();
  delay(1000);
  GoStop();
  delay(1000);
}
