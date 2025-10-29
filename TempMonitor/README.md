# Temperature Monitor using Arduino

This project displays the temperature (and humidity, if using DHT11) using Arduino.  
It’s a simple beginner project that teaches sensor interfacing and serial communication.

##  Components
- Arduino Uno or Nano  
- DHT11 or LM35 sensor  
- 16x2 LCD (optional)  
- Jumper wires, Breadboard

## Working
- The sensor measures temperature (and humidity for DHT11).  
- Data is displayed on the Serial Monitor or LCD.

## Code
- `temperature_monitor_dht11.ino` → For DHT11 sensor  
- `temperature_monitor_lm35.ino` → For LM35 sensor

## 🚀 How to Use
1. Connect the sensor to Arduino.  
2. Open Arduino IDE → Upload code.  
3. Open **Serial Monitor** to view temperature readings.  
4. (Optional) Connect LCD to display output.