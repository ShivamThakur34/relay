// relay with esp wroom 32 and push button
#define BUTTON_PIN 22  // Digital push button connected to GPIO 22
#define RELAY_PIN 23   // Relay control pin connected to GPIO 23

void setup() {
  Serial.begin(115200);  // Initialize Serial Monitor
  pinMode(RELAY_PIN, OUTPUT);   // Relay as output
  pinMode(BUTTON_PIN, INPUT);   // Digital push button as input

  digitalWrite(RELAY_PIN, LOW); // Ensure relay starts OFF
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // Read digital push button state

  Serial.print("Button State: ");
  Serial.println(buttonState); // Debugging output

  if (buttonState == HIGH) {  // Digital button usually sends HIGH when pressed
    Serial.println("Button Pressed! Relay ON.");
    digitalWrite(RELAY_PIN, HIGH);  // Turn relay ON
  } else {
    Serial.println("Button Not Pressed! Relay OFF.");
    digitalWrite(RELAY_PIN, LOW);   // Turn relay OFF
  }

  delay(100);  // Short delay for stability
}
