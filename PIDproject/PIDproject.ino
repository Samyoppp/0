/***********************************************************************
 * Exp5_Bumpers -- RedBot Experiment 5
 * 
 * Now let's experiment with the whisker bumpers. These super-simple switches
 * let you detect a collision before it really happens- the whisker will
 * bump something before your robot crashes into it.
 * 
 * This sketch was written by SparkFun Electronics, with lots of help from 
 * the Arduino community.
 * This code is completely free for any use.
 * Visit https://learn.sparkfun.com/tutorials/redbot-inventors-kit-guide 
 * for SIK information.
 * 
 * 8 Oct 2013 M. Hord
 * Revised 30 Oct 2014 B. Huang
 ***********************************************************************/

#include <RedBot.h>
RedBotMotors motors;


RedBotEncoder encoder = RedBotEncoder(A2, 10);  // initializes encoder on pins A2 and 10
int buttonPin = 12;


int amountInInches = 3;   

double sensorPosition;
double error, lastError, outputSpeed;
double setpoint = amountInInches * 23.3;
// variables used to store the left and right encoder counts.


double kP = 3;
double kI;
double kD;





void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("left    right");
  Serial.println("================");
}

void loop(void)
{
  sensorPosition = (encoder.getTicks(LEFT) + encoder.getTicks(RIGHT))/2;

  error = setpoint - sensorPosition;
  
  outputSpeed = kP * error;
  if (outputSpeed > 20) {motors.drive(outputSpeed);        
  }
  

  // print out to Serial Monitor the left and right encoder counts.

  Serial.println(outputSpeed);
    lastError = error;
delay(10);
  
}