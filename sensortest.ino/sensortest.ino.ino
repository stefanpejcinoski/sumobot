int led=13;
void setup() {
  // put your setup code here, to run once:
pinMode(13 , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led , HIGH);
delay(10);
digitalWrite(led ,LOW);
delay(10);
}
