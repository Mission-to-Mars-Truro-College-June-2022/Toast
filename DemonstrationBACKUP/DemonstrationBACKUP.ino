// Pin Allocation
// Motor On
const int LEFT_ENABLE = 10; // Pin numbers on Rover
const int RIGHT_ENABLE = 9;

// Forward On
const int LEFTFORWARD = 11;
const int RIGHTFORWARD = 7;

// Reverse On
const int RIGHTREVERSE = 8;
const int LEFTREVERSE = 12;

// Start Speeds of left and right
int Speed_left = 95;
int Speed_right =100;

void setup() {
  // Pin Modes onto Output
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTREVERSE, OUTPUT);
}

void loop() {
  RoundRoundRight();
  delay(50);
  RoundRoundLeft();
  delay(50);
  LeftRightCheck();
  delay(50);
  shakeLR();
  delay(50);
  leftturn180();
  delay(50);
  shakeLR();
  delay(50);
  SnakeySnakeyForward();
  delay(50);
  stopRover();
  
  exit(0);
}
