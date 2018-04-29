
int sensor1 = 2, sensor2 = 3 // sensors pins 
int pump1 = 7, pump2 = 8 // relays pins

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
}

void loop() {
    // 1st sensor and pump:
  if(digitalRead(sensor1) == HIGH){
    digitalWrite(pump1, HIGH);
    delay(1500);
    digitalWrite(pump1, LOW);
  }
    // 2nd sensor and pump:
  if(digitalRead(sensor2) == HIGH){
    digitalWrite(pump2, HIGH);
    delay(1500);
    digitalWrite(pump2, LOW);
  }

  delay(3600000); // 1hour
}
