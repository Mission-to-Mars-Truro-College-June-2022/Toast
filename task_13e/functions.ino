void stopRover(){
    digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, LOW);
  digitalWrite(RIGHT_ENABLE, LOW);
  digitalWrite(LEFT_ENABLE, LOW);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, LOW);
}
void startRover(){ 
    digitalWrite(RIGHTFORWARD, HIGH);
  digitalWrite(RIGHTREVERSE, LOW);
   analogWrite(RIGHT_ENABLE,200);
  analogWrite(LEFT_ENABLE, 200);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
}

void reverseRover(){ 
    digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTREVERSE, HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
}
void leftRover(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  analogWrite(RIGHT_ENABLE, 255);
  analogWrite(LEFT_ENABLE, 80);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  
  
  
}
void rightRover(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  analogWrite(RIGHT_ENABLE, 80);
  analogWrite(LEFT_ENABLE, 255);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
}
void leftturn10(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(84);
}

void rightturn10(){
    digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(84);
}

void varrightturn(int Delaytime){
    digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(Delaytime);
}

void rightturn90(){
    digitalWrite(RIGHTFORWARD,LOW);
  digitalWrite(RIGHTREVERSE,HIGH);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(LEFTREVERSE, LOW);
  delay(760);
} 
void leftturn180(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  analogWrite(RIGHT_ENABLE, 127);
  analogWrite(LEFT_ENABLE, 127);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(3040);
}
void leftturn45(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(380);
}
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



void leftturn360(){
    digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
    digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(2980);
}

void varleftturn(int DelayTime){
  digitalWrite(RIGHTFORWARD,HIGH);
  digitalWrite(RIGHTREVERSE,LOW);
  digitalWrite(RIGHT_ENABLE, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(LEFTREVERSE, HIGH);
  delay(DelayTime);
}
