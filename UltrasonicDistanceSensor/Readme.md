# Ultrasonic Distance Sensor using Arduino

This project measures the distance of an object using the **HC-SR04 Ultrasonic Sensor** and displays the result on the **Serial Monitor**.

## 🧩 Components
- Arduino Uno or Nano  
- HC-SR04 Ultrasonic Sensor  
- Jumper Wires  
- Breadboard (optional)

## ⚡ Working
1. The HC-SR04 sends an ultrasonic pulse via the **TRIG** pin.  
2. The pulse reflects off an object and is received on the **ECHO** pin.  
3. Arduino calculates the time taken and converts it to distance.  
4. The result is printed on the Serial Monitor.

## 📟 Circuit Connections

| HC-SR04 Pin | Connect To (Arduino) | Description         |
|--------------|----------------------|---------------------|
| VCC          | 5V                   | Power supply        |
| GND          | GND                  | Ground connection   |
| TRIG         | D9                   | Trigger signal pin  |
| ECHO         | D10                  | Echo signal pin     |

## 🖼️ Circuit Diagram
![Ultrasonic Sensor Circuit](circuit_diagram.png)

## ▶️ How to Run
1. Connect the circuit as per the table.  
2. Upload the code to Arduino.  
3. Open the Serial Monitor (Ctrl + Shift + M).  
4. Observe the distance readings in cm.

---

**Created for beginners to learn sensor interfacing and serial communication.**
