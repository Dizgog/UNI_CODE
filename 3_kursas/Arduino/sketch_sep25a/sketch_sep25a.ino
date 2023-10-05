int motorPin = 3;

void setup() {
pinMode(motorPin, OUTPUT);
}

void loop() {
   digitalWrite(motorPin, HIGH);
   delay(100);
   digitalWrite(motorPin, LOW);
   delay(100);
}