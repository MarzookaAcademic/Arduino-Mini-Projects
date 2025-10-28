// LED_Blink.ino
int ledPin = 13; // LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); // turn ON
  delay(1000);                // wait 1000 milliseconds (1 second)
  digitalWrite(ledPin, LOW);  // turn OFF
  delay(1000);                // wait 1 second
}
