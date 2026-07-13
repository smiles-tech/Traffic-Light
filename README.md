# Traffic-Light
# Simulating traffic light with esp32 and led
# Project Introduction
This project demonstrates a simulation of a traffic light. It controls three LED lights connected to the GPIO pins of an ESP32 to simulate the switching sequence of red, yellow, and green traffic lights.

# Hardware Connection
The components required are: 

LED * 3 

330Ω resistor * 3 

Breadboard * 1

Jumper Wires

ESP32 development board

Connect the circuit according to the wiring diagram below:
<img width="1622" height="1320" alt="image" src="https://github.com/user-attachments/assets/e9530bd2-8a33-4780-a362-ed79479a8e2a" />

# Code Implementation
refere to the trafficlight.ino
# Code Analysis
Constant Definitions:

redPin, yellowPin, greenPin: Defines the GPIO pin numbers connected to the LEDs.

redDuration, greenDuration, yellowDuration: Defines the duration each light stays on (unit: milliseconds).

blinkInterval: Defines the interval time for the yellow light blinking.

# Initialization (setup):

Serial.begin(115200): Initializes serial communication with a baud rate of 115200, used to view the program status in the serial monitor.

pinMode(pin, OUTPUT): Configures the pins connected to the LEDs as output mode to control the LED state (ON/OFF).
Helper Function (allLightsOff):

This is a custom function used to set all LED pins to LOW, turning off all lights. This helps ensure that no lights remain on before switching states.
Main Loop (loop):

Green Light Phase: First, call allLightsOff() to turn off all lights, then turn on the green light (digitalWrite(greenPin, HIGH)) and hold for greenDuration milliseconds.

Yellow Blinking Phase:

Turn off the green light.

Calculate the number of blinks: numBlinks = yellowDuration / (blinkInterval * 2).

Use a for loop to control the yellow light alternating between ON and OFF (HIGH -> delay -> LOW -> delay).

Red Light Phase: Turn on the red light (digitalWrite(redPin, HIGH)) and hold for redDuration milliseconds.
# Results
<img width="1080" height="810" alt="image" src="https://github.com/user-attachments/assets/af74b1f7-a61a-468a-b818-2b7a4b299242" />
<img width="810" height="1080" alt="image" src="https://github.com/user-attachments/assets/410ea6aa-81a2-437d-aeb8-7f5bde415a2e" />
<img width="810" height="1080" alt="image" src="https://github.com/user-attachments/assets/f64f5357-04fd-4cfc-9c57-0b0a8f74790e" />

Reference Link
https://docs.waveshare.com/ESP32-Arduino-Tutorials/13-1-Traffic-Light#code-implementation
