#include "DHT.h"
#define DHTPIN 2       // DHT11 signal pin connected to D2
#define DHTTYPE DHT11  // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Temperature and Humidity Monitor");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // in Celsius

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\tHumidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  delay(2000);
}
