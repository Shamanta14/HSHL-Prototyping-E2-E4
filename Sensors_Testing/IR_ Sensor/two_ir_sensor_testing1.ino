// ==========================
// Track Detection (2cm)
// ==========================

// Arduino UNO + Two IR Sensors
// Battery powered system with Slide switch
// Switch mechanism that turns the system ON and OFF
// Detect the position of the track
// Display sensor detection results (Arduino Serial Monitor)

// ==========================
// Sensor Spacing Track(2cm)
// ==========================
// The sensors should be spaced slightly less than 2 cm apart
// Usually around 1.2–1.8 cm center-to-center
// Typical arrangement:
     // Left sensor sees white
     // Right sensor sees black
     // Robot corrects direction
  
// ==========================
// IR Sensor Reading
// ==========================
// LOW when detecting black track
// HIGH when detecting white surface

int leftSensor = 9;
int rightSensor = 6;

void setup() {
  // Set sensor pins as input
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Serial monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  // Display sensor readings
  Serial.print("Left: ");
  Serial.print(leftValue);

  Serial.print("   Right: ");
  Serial.println(rightValue);

  // ==========================
  // TRACK DETECTION LOGIC
  // ==========================
  
  // Both sensors detect black line
  if (leftValue == LOW && rightValue == LOW) {
    Serial.println("Track centered");
  }

  // Left sensor detects line
  else if (leftValue == LOW && rightValue == HIGH) {
    Serial.println("Move Left");
  }

  // Right sensor detects line
  else if (leftValue == HIGH && rightValue == LOW) {
    Serial.println("Move Right");
  }

  // No line detected
  else {
    Serial.println("Track Lost");
  }

  delay(200);
}

// ==========================
// Quick Debug Version
// ==========================
// What values appear over black
// What values appear over white

/*

int leftSensor = 9;
int rightSensor = 6;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  Serial.begin(9600);
}

void loop() {

  Serial.print("Left: ");
  Serial.print(digitalRead(leftSensor));

  Serial.print("  Right: ");
  Serial.println(digitalRead(rightSensor));

  delay(200);
}

*/