# Automatic Street Light

This Arduino project automatically turns ON an LED in darkness and turns it OFF in bright light using an LDR (Light Dependent Resistor).

## Components
- Arduino UNO
- 1 × LDR
- 1 × LED
- 1 × 220Ω resistor
- 1 × 10kΩ resistor
- Breadboard and jumper wires

## Circuit Connections
| Component | Arduino Pin |
|------------|--------------|
| LDR | A0 |
| LED | 13 |
| Resistors | 220Ω (LED), 10kΩ (LDR divider) |

## How it Works
- The LDR detects light intensity.
- When light decreases, analog value drops below threshold → LED turns ON.
- When light increases, LED turns OFF.

## Code
See [AutoStreetLight.ino](./AutoStreetLight.ino)
