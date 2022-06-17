const int LEFT_ENABLE = 10; // Pin numbers on Rover
const int RIGHT_ENABLE= 9;

const int LEFTFORWARD = 11;
const int RIGHTFORWARD = 7;

const int RIGHTREVERSE= 8;
const int LEFTREVERSE= 12;

const int LEFT_FEEDBACK = 3; // Pin numbers on Rover
const int RIGHT_FEEDBACK = 2;

volatile int leftcounter = 0; // initiate counter to zero for start
volatile int rightcounter = 0; // counter could always be reset

int Speed_left =95;
int Speed_right =100;

const int MID_LDR = A6 ;
const int LEFT_LDR = A7;
const int RIGHT_LDR = A2; 

const int x = 20 ;
int counter = 0; 

long int LowestLightLevel = 10000000;
 int LightPos = 0 ;
 
int CurrentLightLevel = 0 ;
int HighestLight = 0 ;


void setup(){
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTREVERSE, OUTPUT );
 // attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
 // attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

leftturn360(); 
stopRover();
delay(2000);
}

void loop() {
  for (int i = 0; i <= x; i++){
    leftturn10(); 
    stopRover();
    delay(300);
    counter = counter +1 ;
    CurrentLightLevel = analogRead(A6);
    
    if (CurrentLightLevel < LowestLightLevel); {
      HighestLight = LowestLightLevel;
      LightPos = counter -1;   
    }
    
  }
  delay(2000); 
  for(int y = 0; y <= LightPos; y++){
    leftturn10();
     
    
  }
  stopRover();
  exit(0);
}
