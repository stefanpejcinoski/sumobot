/*=
 READ THE LOOP FUNCTION FOR INSTRUCTIONS
 */

boolean toggle2 = 0;

void setup(){
   Serial.begin(9600);
  // definiranje izlezi
  pinMode(A0, INPUT); // A0 e lev goren senzor
  pinMode(A3, INPUT); // A3 e desen goren senzor
  
  //set pins as outputs
  pinMode(11, OUTPUT);
cli();//stop interrupts


//set timer2 interrupt at 80kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 80khz increments
  OCR2A = 24;// = (16*10^6) / (80000*8) - 1 (must be <25)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
 TIMSK2 |= (1 << OCIE2A);


sei();//allow interrupts

}

  
ISR(TIMER2_COMPA_vect){//timer1 interrupt 80kHz toggles pin 11
//generates pulse wave of frequency 80kHz/2 = 40kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle2){
    digitalWrite(11 ,HIGH);
    toggle2 = 0;
  }
  else{
    digitalWrite(11 ,LOW);
    toggle2 = 1;
  }
}





void loop() {
  Serial.print(digitalRead(A0));
  delay(200);
  Serial.println(digitalRead(A3));
  delay(200);
   /*
   * IMPORTANT!!!
   * DO NOT TURN ON THE POWER SWITCH ON THE ARDUINO SHIELD
   * AFTER UPLOADING THE CODE!!!
   * THE SENSORS ARE POWERED BY THE CABLE!
   */
   

  /*
   * OPEN THE SERIAL MONITOR, AND PUT OBSTACLE
   * IN FRONT OF THE ZUMO-BOT NOW AND THEN. 
   * READ THE RESULTS FROM THE MONITOR.
   * LOGIC(1) = NO OBSTACLE
   * LOGIC(0) = OBSTACLE
   */

}
