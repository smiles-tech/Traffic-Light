/*
  Traffic Light Simulation

   Simulates a traffic light system with red, green, and blinking yellow lights.
  The current state is printed to the serial monitor.

  Circuit Connection:
  - Red LED connected to pin 27
  - Yellow LED connected to pin 26
  - Green LED connected to pin 25

  Wulu (Waveshare Team)
*/

// Pin Definitions
const int redPin = 27;
const int yellowPin = 26;
const int greenPin = 25;

// Timing Definitions (unit: milliseconds)
const unsigned long redDuration = 10000;    // Red light duration
const unsigned long greenDuration = 8000;   // Green light duration
const unsigned long yellowDuration = 3000;  // Total yellow light duration
const unsigned long blinkInterval = 500;    // Blink interval

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  Serial.println("Traffic light simulation program started...");
  Serial.print("Current configuration: Red=");
  Serial.print(redDuration / 1000);
  Serial.print("s, Green=");
  Serial.print(greenDuration / 1000);
  Serial.print("s, Yellow=");
  Serial.println(yellowDuration / 1000);

  // Configure LED pins as output mode
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

// Helper function: Turn off all lights
void allLightsOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void loop() {
  // ---Green Light Phase ---
  Serial.println("Status: Green Light ON");
  allLightsOff();                // Make sure to start with a clean state
  digitalWrite(greenPin, HIGH);
  delay(greenDuration);

  // --- Yellow Blinking Phase ---
  Serial.println("Status: Yellow Light Blinking");
  digitalWrite(greenPin, LOW);

  // Calculate the number of blinks
  // A complete cycle consists of "on" and "off" and lasts for blinkInterval * 2
  int numBlinks = yellowDuration / (blinkInterval * 2);

  // Ensure at least one blink even if the duration is very short
  if (numBlinks == 0) {
    numBlinks = 1;
  }

  for (int i = 0; i < numBlinks; i++) {
    digitalWrite(yellowPin, HIGH);
    delay(blinkInterval);
    digitalWrite(yellowPin, LOW);
    delay(blinkInterval);
  }

  // --- Red Light Phase ---
  Serial.println("Status: Red Light ON");
  // Yellow and green lights are already off, directly turn on the red light
  digitalWrite(redPin, HIGH);
  delay(redDuration);
}