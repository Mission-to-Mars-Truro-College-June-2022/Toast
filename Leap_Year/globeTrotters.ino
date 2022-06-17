#include "Arduino.h"
#include "Motor.h"
#include "Sensor.h"

namespace 
{
  const byte interrupt_pin_2 = 2;
  const byte interrupt_pin_3 = 3;

  auto left_speed = 180;
  auto right_speed = 200;

  // Instantiate the two motor objects, passing in the side of the robot the motor is on
  Motor left_motor{"left"};
  Motor right_motor{"right"};

  // Instantiate a sensor object
  Sensor sensor{};
}

// The void setup is the section of code that runs once only at the start.

void setup()
{
  Serial.begin(115200);
  pinMode(interrupt_pin_2, INPUT_PULLUP);
  pinMode(interrupt_pin_3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin_2), right_motor_pulse_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin_3), left_motor_pulse_interrupt, RISING);
}

// #################################################################

// The void loop is the section that runs in a continuous loop any code placed there.


void loop()
{
 square();
 
  exit(0);
  
} 

void twom(){
    moveForward(2000);
    stop_motors(500);
}

void square()
{

  

  for (int i=0; i<4; i++){
  
  moveForward(2000);
  stop_motors(500);
  turn_right(1150);
  }
  
  
}




void moveForward(int sec){

  // Move robot forward
  left_motor.forward(left_speed);
  right_motor.forward(right_speed);

// delay is a wait until next command runs in milliseconds
  delay(sec);
}



void stop_motors(int sec) {
  // Stop the robots motors
  left_motor.stop();
  right_motor.stop();

  delay(sec);
  
  }

void turn_right(int sec)
{
  // Move robot right
  left_motor.forward(left_speed);
  right_motor.reverse(right_speed);

  delay(sec);

// Stop the robot motors
  left_motor.stop();
  right_motor.stop();
  
  //stop the loop
 }

  
  

/* 
// Move robot backward
  left_motor.forward(speed);
  right_motor.forward(speed);

  delay(2000);

Stop the robot motors
  left_motor.stop();
  right_motor.stop();

  delay(500);
*/

//}

// ######### End of main loop ########################

// ######## New Functions below here #################



// ######## End of New Functions #####################

// LEAVE THESE LINE BELOW ALONE

void left_motor_pulse_interrupt() {
  left_motor.inc_pulse();
}

void right_motor_pulse_interrupt() {
  right_motor.inc_pulse();
}
