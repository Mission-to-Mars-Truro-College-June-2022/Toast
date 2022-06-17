// Go Forward
void GoForward(){
  digitalWrite(LRev,LOW); // Left Reverse Off
  digitalWrite(RRev,LOW); // Right Reverse Off
  digitalWrite(LON,HIGH); // Left Motor Voltage On
  digitalWrite(RON,HIGH); // Right Motor Voltage On
  digitalWrite(RFor,HIGH); // Right Forward Voltage On
  digitalWrite(LFor,HIGH); // Left Forward Voltage On
}

// Stop
void GoStop(){
  digitalWrite(LRev,LOW); // Left Reverse Voltage Off
  digitalWrite(RRev,LOW); // Right Reverse Voltage Off
  digitalWrite(LON,HIGH); // Left Motor Voltage On
  digitalWrite(RON,HIGH); // Right Motor Voltage On
  digitalWrite(RFor,LOW); // Right Forward Voltage On
  digitalWrite(LFor,LOW); // Left Forward Voltage On
}


void GoBack(){
  digitalWrite(LRev,HIGH); // Left Reverse Voltage On
  digitalWrite(RRev,HIGH); // Left Reverse Voltage On
  digitalWrite(LON,HIGH);  // Left Motor Voltage On
  digitalWrite(RON,HIGH);  // Right Motor Voltage On
  digitalWrite(RFor,LOW);  // Right Forward Voltage Off
  digitalWrite(LFor,LOW);  // Left Forward Voltage Off
}
