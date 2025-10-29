// MorseCodeFlasher.ino
// Blink an LED to send text as Morse code.
// Uses built-in LED (pin 13) by default. Send text via Serial Monitor (type and press Enter).

const int LED_PIN = 13;       // LED pin
const unsigned int DOT = 200; // duration of a dot in ms (adjustable)

// Morse timing:
// dot = 1 unit, dash = 3 units
// gap between symbols = 1 unit
// gap between letters = 3 units
// gap between words = 7 units

// Morse map (A-Z, 0-9, basic punctuation)
struct MorseMap { char c; const char *m; };
const MorseMap morseTable[] = {
  {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
  {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
  {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
  {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
  {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
  {'Z', "--.."},
  {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
  {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
  {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'/', "-..-."}, {'@', ".--.-."},
  {'-', "-....-"}, {'(', "-.--."}, {')', "-.--.-"}
};
const int MORSE_TABLE_SIZE = sizeof(morseTable) / sizeof(MorseMap);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
  delay(200);
  Serial.println("Morse Code Flasher ready.");
  Serial.println("Type a message and press Enter to flash it in Morse code.");
  Serial.println("Or uncomment the example message in code.");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.length() > 0) {
      Serial.print("Sending: ");
      Serial.println(input);
      sendMorse(input);
      Serial.println("Done.");
    }
  }
  // If you want an automatic message, uncomment below:
  // sendMorse("HELLO WORLD");
  delay(100);
}

void sendMorse(String text) {
  text.toUpperCase();
  for (int i = 0; i < text.length(); i++) {
    char ch = text.charAt(i);
    if (ch == ' ') {
      delay(DOT * 7); // word gap
      continue;
    }
    const char* code = lookupMorse(ch);
    if (code == NULL) {
      // unknown character — skip
      continue;
    }
    // send each symbol in code
    for (int j = 0; code[j] != '\0'; j++) {
      if (code[j] == '.') {
        flashDot();
      } else if (code[j] == '-') {
        flashDash();
      }
      // gap between symbols
      delay(DOT);
    }
    // gap between letters
    delay(DOT * 3);
  }
}

const char* lookupMorse(char ch) {
  for (int i = 0; i < MORSE_TABLE_SIZE; i++) {
    if (morseTable[i].c == ch) return morseTable[i].m;
  }
  return NULL;
}

void flashDot() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT);
  digitalWrite(LED_PIN, LOW);
}

void flashDash() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT * 3);
  digitalWrite(LED_PIN, LOW);
}
