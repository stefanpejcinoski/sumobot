
void setup() {
  // put your setup code here, to run once:
  pinMode(A0 , INPUT);
  pinMode(A3 , INPUT);
  pinMode(11 , OUTPUT);
  Serial.begin(9600);
noInterrupts();
TCCR2B=0; //initializing registers
TCCR2A=0;
TCNT2=0; //timer starts counting from 0
OCR2A=24; // timer needs to reach zero to overflow
TCCR2B|=(1<<WGM21); //CTC mode enabled
TCCR2B|=(1<<CS21); //prescalar set to 1
TIMSK2|=(1<<OCIE2A); //overflow enabled

interrupts();

}
ISR(TIMER1_COMPA_vect) //interrupt event set
{
  digitalWrite(11 , digitalRead(11)^1);
 
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(A0));
Serial.println(analogRead(A3));
}
