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
   analogWrite(RIGHT_ENABLE,100);
  analogWrite(LEFT_ENABLE, 100);
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
// Rover Snakes Left
void leftRover(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  analogWrite(RIGHT_ENABLE, 200);
  analogWrite(LEFT_ENABLE, 80);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
}
// Rover Snakes Right
void rightRover(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  analogWrite(RIGHT_ENABLE, 0);
  analogWrite(LEFT_ENABLE, 200);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
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
// Rover finds a torch
void FollowLight() {
  // If the middle LDR resistance is greater than 175, the torch is a lie
  if (CurrentMidLightLevel > 175) {
    // Turns to the left until...
    leftturn45();
    delay(50);
  }
  // ... the middle LDR resistance is less than 175, the torch exists
  else if (CurrentMidLightLevel <= 175) {
    // Light exists, no lie
    foundLight = true;
    
    }
}
