// FUNCTIONS
// Shuts everything off
void stopRover(){
    digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, LOW);
  digitalWrite(RIGHT_ENABLE, LOW);
  digitalWrite(LEFT_ENABLE, LOW);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, LOW);
}
// Rover Goes Forward
void startRover(){ 
    digitalWrite(RIGHTFORWARD, HIGH);
  digitalWrite(RIGHTREVERSE, LOW);
   analogWrite(RIGHT_ENABLE,255);
  analogWrite(LEFT_ENABLE, 255);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
}
// Rover Goes Backward
void reverseRover(){ 
    digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
}
// Rover Turns Left by 10 degrees
void leftturn10(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    analogWrite(LEFTFORWARD, 80);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(84);
}
// Rover Turns Right by 10 degrees
void rightturn10(){
    analogWrite(RIGHTFORWARD, 80);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(84);
}
// Rover Turns to the Right by a variable delay time
void varrightturn(int Delaytime){
    digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(Delaytime);
}
// Rover turns to the left by variable degree
void varleftturn(int DelayTime){
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(DelayTime);
  
}
// Rover Turns to the right by 90 degrees
void rightturn90(){
    digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(760);
} 
// Rover Turns to the left by 90 degrees
void leftturn90(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, LOW);
  delay(700);
} 

// Rover Turns to the left by 180 degrees
void leftturn180(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  analogWrite(RIGHT_ENABLE, 127);
  analogWrite(LEFT_ENABLE, 127);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(3040);
}
// Rover Turns to the left by 45 degrees
void leftturn45(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(380);
}
// Rover Turns to the right by 45 degrees
void rightturn45(){
    digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(380);
}
// Rover Turns to the left by 360 degrees
void rightturn360(){
    digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(3040);
  stopRover();
}


// Rover turns to the left by 360 degrees
void leftturn360(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(2980);
}
void GoSnakeLeft(){
  digitalWrite(LEFTREVERSE,LOW); // Left Reverse Motor Off
  digitalWrite(RIGHTREVERSE,LOW); // Right Reverse Motor Off
  analogWrite(LEFT_ENABLE,80); // Left Motor 
  analogWrite(RIGHT_ENABLE,255);
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(LEFTFORWARD,HIGH); 
}

void GoSnakeRight(){
  digitalWrite(LEFTREVERSE,LOW);
  digitalWrite(RIGHTREVERSE,LOW);
  analogWrite(LEFT_ENABLE,255);
  analogWrite(RIGHT_ENABLE,80);
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(LEFTFORWARD,HIGH); 
}


// Rover goes forward, then backward, then turns right
void DanceyDanceyFUNctionA() {
  startRover();
  delay(500);
  stopRover();
  delay(50);
  reverseRover();
  delay(500);
  stopRover();
  delay(50);
  rightturn90(); 
}

void RoundRoundRight() {
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
   digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(3040);
}

void RoundRoundLeft() {
  digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(2980);
}

void LeftRightCheck() {
  startRover();
  delay(500);
  stopRover();
  delay(250);
  leftturn45();
  stopRover();
  delay(250);
  rightturn45();
  rightturn45();
  stopRover();
  delay(250);
  leftturn45();
  stopRover();
}

void SnakeySnakeyForward() {
  for (int i = 0; i < 2; i++) {
    GoSnakeLeft();
    delay(500);
    GoSnakeRight();
    delay(500);
  }
}


void shakeLR() {
  for (int i = 0; i < 15; i++){
  varleftturn(50);
  delay(10);
  varrightturn(50);
  delay(10);
  }
  
  stopRover();
 
}
