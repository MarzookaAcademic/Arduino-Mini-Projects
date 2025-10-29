int sensorPin = A0; // LM35 output connected to A0

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature Monitor using LM35");
}

void loop() {
  int value = analogRead(sensorPin);
  float voltage = value * (5.0 / 1023.0);
  float temperature = voltage * 100; // LM35: 10mV per °C

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000);
}
