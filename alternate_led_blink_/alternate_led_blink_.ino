int LON = 10;
int RON = 9 ;
int LRev = 12 ;
int RRev = 8 ;
int LFor = 11 ; 
int RFor = 7 ;



void setup() {

  pinMode(LON, OUTPUT);
  pinMode(RON, OUTPUT);
  
  pinMode(LRev, OUTPUT);
  pinMode(RRev, OUTPUT);
  
  pinMode(LFor, OUTPUT);
  pinMode(RFor, OUTPUT);
 
  

}

void loop() {
GoForward();
delay(1000);
GoStop();
delay(1000);
GoBack();
delay(1000);
GoStop();
delay(1000);
}


void GoForward(){
  digitalWrite(LRev,LOW);
  digitalWrite(RRev,LOW);
  analogWrite(LON,100);
  digitalWrite(RON,HIGH);
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
  digitalWrite(LRev,HIGH);
  digitalWrite(RRev,HIGH);
  digitalWrite(LON,HIGH);
  digitalWrite(RON,HIGH);
  digitalWrite(RFor,LOW);
  digitalWrite(LFor,LOW);
}
