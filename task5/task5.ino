// SNAKE LEFT AND RIGHT WHILE GOING FORWARD
// Pin Allocation
const int LON = 10; // Left Motor On Pin
const int RON = 9;  // Right Motor On Pin
const int LRev = 12; // Left Reverse On Pin
const int RRev = 8; // Right Reverse On Pin
const int LFor = 11; // Left Forward On Pin
const int RFor = 7; // Right Forward On Pin


void setup() {
  // Turning the motor pins into outputs
  pinMode(LON, OUTPUT);
  pinMode(RON, OUTPUT);
  
  pinMode(LRev, OUTPUT);
  pinMode(RRev, OUTPUT);
  
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
 
  GoSnakeRight();
  delay(1000);

}

void loop() {
GoSnakeLeft();
delay(2000);

GoSnakeRight();
delay(2000);

}
