#define irpin=
void setup() {
  // put your setup code here, to run once:
  pinMode(irpin , OUTPUT);
noInterrupts();
TCCR1B=0; //initializing registers
TCCR1A=0;
TCNT1=0; //timer starts counting from 0
OCR1A=200; // timer needs to reach zero to overflow
TCCR1B|=(1<<WGM12); //CTC mode enabled
TCCR1B|=(1<<CS10); //prescalar set to 1
TIMSK1|=(1<<OCIE1A); //overflow enabled

interrupts();

}
ISR(TIMER1_COMPA_vect) //interrupt event set
{
  digitalWrite(irpin , digitalRead(irpin)^1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
