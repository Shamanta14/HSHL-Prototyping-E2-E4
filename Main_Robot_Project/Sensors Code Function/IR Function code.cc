// Digital input pin connected to IR sensors
int leftSensor = 8;
int rightSensor = 7;

// ==========================
// Function: detectTrack()
// Reads both sensors and prints
// the detected track position
// ==========================
void detectTrack() {

  // Read sensor values
  // LOW  = Black line detected
  // HIGH = White surface detected
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  // Both sensors detect the black line
  if (leftValue == LOW && rightValue == LOW) {
    Serial.println("Track Centered");
  }

  // Left sensor detects the line and Right sensor sees white
  else if (leftValue == LOW && rightValue == HIGH) {
    Serial.println("Move Left");
  }

  // Right sensor detects the line and Left sensor sees white
  else if (leftValue == HIGH && rightValue == LOW) {
    Serial.println("Move Right");
  }

  // Neither sensor detects the line
  else {
    Serial.println("Track Lost");
  }
}

// ==========================
// Setup
// Runs once when Arduino starts
// ==========================
void setup() {

  // Configure sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Start serial communication
  // Used to display sensor status
  Serial.begin(9600);
}

// ==========================
// Main Loop
// Runs continuously
// ==========================
void loop() {

  // Call track detection function
  detectTrack();

  // Small delay for readable output
  delay(200);
}
