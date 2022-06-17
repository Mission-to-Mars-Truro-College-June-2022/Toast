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

int Speed_left = 95;
int Speed_right =100;

const int MID_LDR = A6 ;
const int LEFT_LDR = A7;
const int RIGHT_LDR = A2; 

const int x = 20 ;

int LowestLightLevel = 10000;
 
int CurrentLightLevel = 0 ;
int StartLightTime = 0;
int BrightLightTime = 0;
int EndLightTime = 0;
int counter = 0;
int BrightCount = 0;
long Delay = 0;
int EndMillis = 0;

void setup(){
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTREVERSE, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTREVERSE, OUTPUT);
 // attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
 // attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

StartLightTime = millis();
}

void loop() {
  CurrentLightLevel = analogRead(A6);
  Serial.println(CurrentLightLevel);
  if (CurrentLightLevel > 175) {
    leftturn45();
    delay(50);
  }
  else if (CurrentLightLevel <= 175) {
    startRover();
    delay(500);
    stopRover();
    exit(0);
  }
  
  /*
  for (int i = 0; i <= x; i++){
    leftturn10(); 
    //stopRover();
    //delay(500);
    CurrentLightLevel = analogRead(A6);
    //counter = counter +1;
    Serial.print("Current light: ") ;
    Serial.println(CurrentLightLevel);
    if (CurrentLightLevel < LowestLightLevel){
      Serial.print("Current light2: ") ;
      Serial.println(CurrentLightLevel);
      Serial.print("lowest light: ") ;
      Serial.println(LowestLightLevel);
      LowestLightLevel = CurrentLightLevel;
      BrightLightTime = millis(); 
      //BrightCount = counter;
      Serial.print("New lowest light: ") ;
      Serial.println(LowestLightLevel);
      Serial.print("bright time: ") ;
      Serial.println(BrightLightTime);
    }
    
  }
  
  EndMillis = millis();
  delay(2000); 
  EndLightTime = BrightLightTime - StartLightTime;
  Delay = EndMillis - BrightLightTime;
  //Delay = EndLightTime / BrightCount;
  Serial.println("end time: ");
  Serial.println(EndLightTime);
  
  //for (int i = 0; i <= BrightCount; i++){
    //varleftturn(Delay);
  //}

  varrightturn(Delay);
  stopRover();
  delay(50);
  startRover();
  delay(1000);
  stopRover();
  exit(0);
  */
  }
