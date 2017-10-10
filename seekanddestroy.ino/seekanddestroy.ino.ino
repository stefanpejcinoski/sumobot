#define turnspeed 400
#define movespeed 400
#define turntime 6
#define twisttime 1000
int  toggle2=0;
bool enemyfound=false;
#include <ZumoMotors.h>
ZumoMotors motors;
void setup() {
  pinMode(A0, INPUT); 
  pinMode(A3, INPUT); 
  pinMode(11, OUTPUT);
cli();
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2  = 0;
  OCR2A = 24;
  TCCR2A |= (1 << WGM21);
  TCCR2B |= (1 << CS21);   
 TIMSK2 |= (1 << OCIE2A);
sei();
}
ISR(TIMER2_COMPA_vect){
  if (toggle2){
    digitalWrite(11 ,HIGH);
    toggle2 = 0;
  }
  else{
    digitalWrite(11 ,LOW);
    toggle2 = 1;
  }
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
void rightTurn (int speeds)
{
  motors.setLeftSpeed(speeds);
  speeds=-speeds;
  motors.setRightSpeed(speeds);
}
void rew(int speeds)
{
  speeds=-speeds;
  motors.setSpeeds(speeds , speeds);
}
void fwd(int speeds)
{
  
  motors.setSpeeds(speeds , speeds);
}
bool leftonblack()
{
  return digitalRead(2);
}
bool rightonblack()
{
  return digitalRead(4);
}

bool seekbot()
{
  int sensordata=0;
  for(int i=0 ; i<=4 ; i++)
  {
    sensordata=sensordata+(digitalRead(A0)&&digitalRead(A3));
  }
  if((sensordata/2)>=2)
  return true;
  else 
  return false ;
}
void dothetwist()
{
 
 leftTurn(turnspeed*2);
 while(1)
 {
  if(!(rightonblack()||leftonblack()))
  break;
  if(!seekbot())
  {
  enemyfound=true;
  break; 
  }
}
}
void notonblack()
{
  if(!(leftonblack()&&rightonblack()))
  {
    stopall();
    rew(movespeed/2);
    delay(500);
    leftTurn(turnspeed/2);
    delay(500);
  }
  if((!leftonblack())&&rightonblack())
  {
   stopall();
    rew(movespeed/2);
    delay(500);
    rightTurn(turnspeed/2);
    delay(500); 
  }
  if(leftonblack()&&(!(rightonblack())))
  {
    stopall();
    rew(movespeed/2);
    delay(500);
    rightTurn(turnspeed/2);
    delay(500);
  }
  if(!seekbot())
    {
     enemyfound=true; 
    }
  
}
void loop() {
  if(!enemyfound)
  {
  dothetwist();
  notonblack();
  }
else if(enemyfound)
{
  fwd(movespeed);
  if (!(leftonblack()&&rightonblack()))
  {
    stopall();
    enemyfound=false;
    notonblack();
  }
}
}
