#include <ZumoMotors.h>

/*
 * This example uses the ZumoMotors library to drive each motor on the Zumo
 * forward, then backward. The yellow user LED is on when a motor should be
 * running forward and off when a motor should be running backward. If a
 * motor on your Zumo has been flipped, you can correct its direction by
 * uncommenting the call to flipLeftMotor() or flipRightMotor() in the setup()
 * function.
 */

#define LED_PIN 13

ZumoMotors motors;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);
}

void loop()
{
  for(int i=0 ; i<=400 ; i++)
  {
    motors.setSpeeds(i , i);
    delay(2);
  }
  for(int i=400 ; i>=0 ; i--)
  {
    motors.setSpeeds(i , i);
    delay(2);
  }
  for(int i=0 ; i>= -400 ; i--)
  {
    motors.setSpeeds(i , i);
    delay(2);
  }
  for(int i=-400 ; i<=0 ; i++)
  {
    motors.setSpeeds(i , i);
    delay(2);
  }
  }

