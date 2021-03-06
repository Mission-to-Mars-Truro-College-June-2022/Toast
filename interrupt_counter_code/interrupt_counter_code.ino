const int LEFT_FEEDBACK = 2; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 3; 

volatile int leftcounter = 0; // initiate counter to zero for start
volatile int rightcounter = 0;// counter could always be reset

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
}

void loop() {
  //Just print out the values to show counter operating
  Serial.print("Left Counter ");
  Serial.println(leftcounter);

  Serial.print("Right Counter");
  Serial.println(rightcounter);
  
}

void LeftMotorISR(){
  //adds one to counter on each motor revolution
  leftcounter++;
}

void RightMotorISR(){
  //adds one to the counter on each motor revolution
  rightcounter++;
}
