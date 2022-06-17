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


int Speed_Left = 95 ;
int Speed_Right = 100 ;


int turnForRDelay = 775 ;// Forward Time Delay for Right Turning
int turnForLDelay = 678;

int turnRevRDelay = 780 ;// Reverse Time Delay for Right Turning
int turnRevLDelay = 680;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  
  pinMode(LEFT_REVERSE, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(RIGHTFORWARD, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  leftLDR = analogRead(LEFT_LDR)
  rightLDR = analogRead(RIGHT_LDR)
  midLDR = analogRead(MID_LDR)
  
  if (leftLDR < midLDR) {
    LeftTurn90(5)
  }
  
  if (rightLDR < midLDR) {
    RightTurn90(5)
  }

  if (midLDR < rightLDR) && (midLDR < leftLDR) {
    StopRover()
  }
  
}
