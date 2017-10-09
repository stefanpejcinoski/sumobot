
//ovoj stil na vrtenje e dokolku robotot nema H-bridge driver , dokolku ima , ke ima uste eden fajl so digital write komandi za left/right pinot
void setup() {
  int sensor1=
  int sensor2=
  int sensorpwr1=
  int sensorpwr2=
  int motor1=
  int motor2=
  pinMode(sensor1 , INPUT);
  pinMode(sensor1 , INPUT);
  pinMode(sensorpwr1 , OUTPUT);
  pinMode(sensorwpr2 , OUTPUT);
  Serial.begin(9600);
}
void RightTurn(int turnspeed , int timeinmicroseconds , bool isstanding) //turnspeed se dvizi od 1-10 i e parametar za brzina na vrtenjeto , vo zavisnost dali robotot istrazuva ili pravi napaden manevar
{
  int defspeed=255;
  turnspeed=turnspeed/10;
  if (isstanding) //dokolku pocnuva od stoecka polozba i treba da vrti vo mesto , nema smisla dvata motori da se dvizat 
    analogWrite(motor1 , defspeed*turnspeed);
    analogWrite(motor2 , 0); //ne e ugasena , samo 0v out , treba vo C i so registri za da se ugasi :(
  }
  analogWrite(motor1 , defspeed*turnspeed);
  analogWrite(motor2 , (defspeed/2)*turnspeed);
  delayMicroseconds(timeinmicroseconds);
}
void LeftTurn(int turnspeed , int timeinmicroseconds , bool isstanding) //turnspeed se dvizi od 1-10 i e parametar za brzina na vrtenjeto , vo zavisnost dali robotot istrazuva ili pravi napaden manevar
{
  int defspeed=255;
  turnspeed=turnspeed/10;
  if (isstanding) //dokolku pocnuva od stoecka polozba i treba da vrti vo mesto , nema smisla dvata motori da se dvizat 
  {
    analogWrite(motor2 , defspeed*turnspeed);
    analogWrite(motor1 , 0); //ne e ugasena , samo 0v out , treba vo C i so registri za da se ugasi :(
  }
  analogWrite(motor2 , defspeed*turnspeed);
  analogWrite(motor1 , (defspeed/2)*turnspeed);
  delayMicroseconds(timeinmicroseconds);
}
void Halt ()
{
  analogWrite(motor1 , 0);
  analogWrite(motor2 , 0);
}
void Forward(int speed); //speed , slicno kako turnspeed e od 1-10 , komanda za dvizenje vo dadena nasoka sto ke se podesi so turn i eksperimentalni vrednosti na timeinmicroseconds
{
  speed=speed/10;
  analogWrite(motor1 , (255*speed));
  analogWrite(motor2 , (255*speed));
}
void loop() {
  // put your main code here, to run repeatedly:

}
