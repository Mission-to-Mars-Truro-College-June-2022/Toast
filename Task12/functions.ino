void StopRover(){
  digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE, LOW) ;
  digitalWrite(RIGHT_ENABLE, LOW) ;
  digitalWrite(LEFT_ENABLE, LOW) ;
  digitalWrite(LEFTFORWARD, LOW) ;
  digitalWrite(LEFT_REVERSE, LOW)  ;
   
}
void StartRover(){ 
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE, LOW) ;
  analogWrite(RIGHT_ENABLE, Speed_Right) ;
  analogWrite(LEFT_ENABLE, Speed_Left) ;
  digitalWrite(LEFTFORWARD, HIGH) ;
  digitalWrite(LEFT_REVERSE, LOW)  ;
}

void ReverseRover(){ 
  digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE, HIGH) ;
  digitalWrite(RIGHT_ENABLE, Speed_Right) ;
  digitalWrite(LEFT_ENABLE, Speed_Left) ;
  digitalWrite(LEFTFORWARD, LOW) ;
  digitalWrite(LEFT_REVERSE, HIGH)  ;
}

int LeftTurn90(int turnDelay){
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE, LOW) ;
  digitalWrite(RIGHT_ENABLE, HIGH) ;
  digitalWrite(LEFT_ENABLE, HIGH) ;
  digitalWrite(LEFTFORWARD, LOW) ;
  digitalWrite(LEFT_REVERSE, HIGH);
  delay(turnDelay)  ;
}

int RightTurn90(int turnDelay){
  digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE, HIGH) ;
  digitalWrite(RIGHT_ENABLE, HIGH) ;
  digitalWrite(LEFT_ENABLE, HIGH) ;
  digitalWrite(LEFTFORWARD, HIGH) ;
  digitalWrite(LEFT_REVERSE, LOW);
  delay(turnDelay)  ;
}
void LeftTurn180(){ 
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE, LOW) ;
  analogWrite(RIGHT_ENABLE, 127) ;
  analogWrite(LEFT_ENABLE, 127) ;
  digitalWrite(LEFTFORWARD, LOW) ;
  digitalWrite(LEFT_REVERSE, HIGH);
  delay(3040)   ;
}

void LeftTurn45(){
   digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE, LOW) ;
  digitalWrite(RIGHT_ENABLE, HIGH) ;
  digitalWrite(LEFT_ENABLE, HIGH) ;
  digitalWrite(LEFTFORWARD, LOW) ;
  digitalWrite(LEFT_REVERSE, HIGH);
  delay(380) ;
}


void RightTurn360(){
   digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE, HIGH) ;
  digitalWrite(RIGHT_ENABLE, HIGH) ;
  digitalWrite(LEFT_ENABLE, HIGH) ;
  digitalWrite(LEFTFORWARD, HIGH) ;
  digitalWrite(LEFT_REVERSE, LOW);
  delay(3040);
  StopRover() ;
}
