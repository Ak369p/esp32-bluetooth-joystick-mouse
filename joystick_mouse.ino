joystick_mouse.ino
#include <BleMouse.h>

// BLE Mouse instance
BleMouse bleMouse("Joystick Mouse", "AkashTech", 100);

// Joystick pins
const int joyX = 34;
const int joyY = 35;
const int joyButton = 27;

// Variables for button press logic
bool scrollMode = false;
unsigned long lastPressTime = 0;
unsigned long lastButtonDownTime = 0;
bool buttonPreviouslyPressed = false;
int pressCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(joyButton, INPUT_PULLUP);
  bleMouse.begin();
  Serial.println("🟢 BLE Joystick Mouse Initialized");
}

void loop() {
  if (bleMouse.isConnected()) {
    int xVal = analogRead(joyX);
    int yVal = analogRead(joyY);
    int deltaX = map(xVal, 0, 4095, -10, 10);
    int deltaY = map(yVal, 0, 4095, -10, 10);

    bool buttonPressed = digitalRead(joyButton) == LOW;
    unsigned long currentTime = millis();

    // Check for single or double press
    if (buttonPressed && !buttonPreviouslyPressed) {
      if (currentTime - lastPressTime < 400) {
        pressCount++;
      } else {
        pressCount = 1;
      }

      lastPressTime = currentTime;

      if (pressCount == 2) {
        scrollMode = !scrollMode;
        Serial.println(scrollMode ? "🔄 Scroll Mode ON" : "🖱️ Move Mode ON");
        pressCount = 0;
      } else {
        // Single press = click (if not in scroll mode)
        if (!scrollMode) {
          bleMouse.click(MOUSE_LEFT);
          Serial.println("🖱️ Left Click");
        }
      }
    }

    buttonPreviouslyPressed = buttonPressed;

    // Scrolling or movement
    if (scrollMode) {
      if (abs(deltaY) > 4) {
        int scrollDir = (deltaY > 0) ? -1 : 1;
        bleMouse.move(0, 0, scrollDir);  // Scroll
        Serial.println(scrollDir > 0 ? "🔼 Scroll Up" : "🔽 Scroll Down");
        delay(100);
      }
    } else {
      if (abs(deltaX) > 3 || abs(deltaY) > 3) {
        bleMouse.move(deltaX, deltaY);
        Serial.print("🖱️ Move X: ");
        Serial.print(deltaX);
        Serial.print(" | Y: ");
        Serial.println(deltaY);
      }
    }

    delay(20);
  }
}
