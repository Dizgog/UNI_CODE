int motorSpeed = 30;

int motorPin = 9;

void setup(){
  
}
void loop(){
  analogWrite(motorPin, motorSpeed);
  delay(2);
}