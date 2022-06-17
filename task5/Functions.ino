void GoSnakeLeft(){
  digitalWrite(LRev,LOW); // Left Reverse Motor Off
  digitalWrite(RRev,LOW); // Right Reverse Motor Off
  analogWrite(LON,100); // Left Motor 
  analogWrite(RON,255);
  digitalWrite(RFor,HIGH);
  digitalWrite(LFor,HIGH); 
}

void GoSnakeRight(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  analogWrite(LON,255);
  analogWrite(RON,100);
  digitalWrite(RFor,HIGH);
  digitalWrite(LFor,HIGH); 
}

void GoForward(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  analogWrite(LON,255);
  analogWrite(RON,255);
  digitalWrite(RFor,HIGH);
  digitalWrite(LFor,HIGH); 
}

void GoStop(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  digitalWrite(LON,HIGH);
  digitalWrite(RON,HIGH);
  digitalWrite(RFor,LOW);
  digitalWrite(LFor,LOW);
}


void GoBack(){
  analogWrite(LRev,255);
  analogWrite(RRev,255);
  analogWrite(LON,HIGH);
  analogWrite(RON,HIGH);
  analogWrite(RFor,0);
  analogWrite(LFor, 0);
}
