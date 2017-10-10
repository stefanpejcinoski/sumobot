#include <ZumoMotors.h>

ZumoMotors motors;

void setup() {
  // put your setup code here, to run once:
pinMode(2 , INPUT);
pinMode(4 , INPUT);
}
void fwd(int speeds)
{
  motors.setSpeeds(speeds , speeds);
}
void stopall()
{
  motors.setSpeeds(0 , 0);
}
void leftTurn(int speeds)
{
  motors.setRightSpeed(speeds);
  speeds=-speeds;
  motors.setLeftSpeed(speeds);
}
void rightTurn(int speeds)
{
  motors.setLeftSpeed(speeds);
  speeds=-speeds;
  motors.setRightSpeed(speeds);
}

void loop() {
isonblack();
 

}
void isonblack()
{
  if(digitalRead(2)&&(digitalRead(4)))
  {
    fwd(400);
  }
  else if(digitalRead(2)&&(!digitalRead(4)))
  {
    stopall();
    leftTurn(400);
    delay(4);
  }
  else if((!digitalRead(2))&&digitalRead(4))
  {
    stopall();
    leftTurn(400);
    delay(4);
  }
  else if (!(digitalRead(2)||digitalRead(4)))
  {
    stopall();
    rew(400);
    delay(20);
    leftTurn(400);
    delay(4);
  }
}

void rew(int speeds)
{
  speeds=-speeds;
  motors.setSpeeds(speeds , speeds);
}

  

  





