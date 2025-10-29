# Morse Code Flasher

**Short description**  
This project converts typed text into Morse code and flashes it using an LED. You can type a message into the Arduino Serial Monitor and the LED will blink the Morse equivalent.

## Parts
- Arduino Uno (or any Arduino)
- 1 LED (or use built-in LED on pin 13)
- 1 × 220 Ω resistor (if using external LED)
- Breadboard and jumper wires

## Wiring (simple)
- If using built-in LED: no wiring needed.
- If using external LED:
  - LED anode (+ long leg) → digital pin **13** through 220Ω resistor
  - LED cathode (short leg) → **GND**

## How to use
1. Open the Arduino IDE.
2. Open `MorseCodeFlasher.ino`.
3. Upload code to your Arduino.
4. Open **Tools → Serial Monitor** and set baud to **9600**.
5. In the Serial Monitor input box type a message (e.g., `SOS`) and press Enter.
6. The LED will flash the Morse code for the message.

## Morse timing rules used
- Dot = 1 unit (default 200 ms)
- Dash = 3 units
- Between symbols (dot/dash) = 1 unit
- Between letters = 3 units
- Between words = 7 units

## Code notes
- You can change the speed by editing the `DOT` value (in milliseconds).
- Unknown characters are skipped.
- There is a built-in table for A-Z, 0-9 and some punctuation.

## Troubleshooting
- If nothing flashes: check LED wiring, or use the built-in LED (pin 13).
- If messages are too fast or slow: change `DOT` in the code (e.g., 100 or 300).
- If Serial Monitor shows no response: ensure baud is 9600 and correct COM port is selected.

## Next ideas
- Add a buzzer to play Morse audio.
- Store and replay messages with a button.
- Add an OLED/LCD to show text being sent.
