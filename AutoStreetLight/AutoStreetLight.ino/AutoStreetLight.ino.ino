int sensorPin = A0;   // LDR connected to analog pin A0
int ledPin = 13;      // LED connected to digital pin 13
int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);  // Check value in Serial Monitor

  if (sensorValue < 500) { // Adjust this threshold based on light
    digitalWrite(ledPin, HIGH);  // Turn ON LED when dark
  } else {
    digitalWrite(ledPin, LOW);   // Turn OFF LED when bright
  }

  delay(100);
}
