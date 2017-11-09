int digitalSensor = 2;
int pumpPin = 8; //relay pin

void setup() {
  pinMode(digitalSensor, INPUT);
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  if(digitalRead(digitalSensor) == HIGH){
    digitalWrite(pumpPin, HIGH);
    delay(1500);
    digitalWrite(pumpPin, LOW);
  }
  delay(3600000); // 1hour
}
